﻿#include "layermanager.h"
#include <QDebug>
#include <QListWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTreeWidgetItem>
#include "drawobj.h"
#include "drawtool.h"
#include "layer.h"
//LayerManager *LayerManager::GetInstance() {
//  static LayerManager instance;
//  return &instance;
//}

void LayerManager::SetLayerWidget(QTreeWidget *w) {
//    if(/*layerwidget==w ||*/ !w)
//        return;
//    layerwidget = w;
//    layerwidget->clear();
//    disconnect(layerwidget,&QTreeWidget::itemClicked,0,0);
//    connect(layerwidget, &QTreeWidget::itemClicked, this,
//            &LayerManager::slot_cellClicked,static_cast<Qt::ConnectionType>(Qt::DirectConnection|Qt::UniqueConnection));
//    std::vector<Layer *> ls;
//    for(auto iter=layermap.begin();iter!=layermap.end();iter++)
//    {
//        ls.push_back(iter->second);
//    }
//    layermap.clear();
//    for(int i=0;i<ls.size();i++)
//    {
//        int row = layerwidget->topLevelItemCount();
//        QTreeWidgetItem *item = new QTreeWidgetItem(layerwidget);
//        item->setText(0, QString::number(ls[i]->GetZValue()));
//        layerwidget->insertTopLevelItem(row, item);
//        layermap[item] = ls[i];
//        int row = layerwidget->topLevelItemCount();
//        layerwidget->insertTopLevelItem(row, iter->first);
//        if(row==0)
//            layerwidget->setItemSelected(iter->first, 1);
//    }
}

void LayerManager::SetItemWidget(QListWidget *w)
{
    if(/*itemwidget==w ||*/ !w)
        return;
    itemwidget = w;
    itemwidget->clear();
}

LayerManager::LayerManager(DrawScene *scene,QObject *parent) : QObject(parent){
    m_scene=scene;
    if(!layerwidget)
        layerwidget = new QTreeWidget();
    layerwidget->setStyleSheet("color:black;");
    layerwidget->setColumnCount(1);
    layerwidget->setSelectionBehavior(QTreeWidget::SelectRows);
    layerwidget->setSelectionMode(QTreeWidget::SingleSelection);
    layerwidget->setEditTriggers(QTreeWidget::NoEditTriggers);
    layerwidget->setHeaderLabel("layer");
    connect(layerwidget, &QTreeWidget::itemClicked, this,&LayerManager::slot_cellClicked);

    connect(scene, &DrawScene::itemAdded,  this,&LayerManager::refreshItemWidget);
    connect(scene, &DrawScene::itemRemoved,  this,&LayerManager::refreshItemWidget);
}

LayerManager::~LayerManager()
{
    if(layerwidget)
    {
        delete layerwidget;
        layerwidget=nullptr;
    }
}

Layer *LayerManager::GetLayer(int rowNo) {
  if (rowNo < 0 || rowNo > layerwidget->topLevelItemCount() - 1) return nullptr;
  return layermap[layerwidget->topLevelItem(rowNo)];
}

void LayerManager::slot_cellClicked(QTreeWidgetItem *item, int) {
  QString t = item->text(0);
  if (t == "rectangle" || t == "polygon" || t == "path" || t=="text" || t=="instance") {
    selectItemByType(t);
    return;
  }
  auto l = GetLayer(layerwidget->indexOfTopLevelItem(item));
  if (!l) return;
  SetCurrentLayer(l);
  l->selectAll();
  if (itemwidget) refreshItemWidget();
  emit layerChanged();
}

void LayerManager::refreshItemWidget() {
  if (!itemwidget) return;
  if (!GetCurrentLayer()) return;
  auto items = GetCurrentLayer()->GetAllItems();
  QStringList s;
  QList<QTreeWidgetItem *> itemss = layerwidget->selectedItems();
  QStringList strs;
  for (int i = 0; i < items.size(); i++) {
    s << items[i]->objectName();
    QString t;
    switch (items[i]->itemtype()) {
      case rectangle: {
        t = "rectangle";
        break;
      }
      case polygon: {
        t = "polygon";
        break;
      }
      case polyline: {
        t = "path";
        break;
      }
      case text:
      {
        t="text";
        break;
      }
      case instance:
      {
        t="instance";
        break;
    }
    }
    if (!strs.contains(t)) {
      strs.append(t);
    }
  }
  if (itemss.size() > 0) {
    auto ii = itemss.first();
    while (ii->parent()) ii = ii->parent();
    ii->takeChildren();
    for (int i = 0; i < strs.size(); i++) {
      QTreeWidgetItem *it = new QTreeWidgetItem;
      ii->addChild(it);
      it->setText(0, strs[i]);
    }
  }
  itemwidget->clear();
  itemwidget->addItems(s);
}

void LayerManager::selectItemByType(QString t) {
  QList<GraphicsItem *> items = GetCurrentLayer()->GetAllItems();
  int type = rectangle;
  if (t == "polygon") {
    type = polygon;
  } else if (t == "path") {
    type = polyline;
  }else if(t=="text"){
      type=text;
      }
    else if(t=="instance"){
    type=instance;
    }
  QStringList names;
  for (int i = 0; i < items.size(); i++) {
    if (items[i]->itemtype() == type) {
      items[i]->setSelected(1);
      names<<items[i]->objectName();
    } else {
      items[i]->setSelected(0);
    }
  }
  itemwidget->clear();
  itemwidget->addItems(names);
}

void LayerManager::refreshLayerWidget()
{
    for(auto l=layermap.begin();l!=layermap.end();l++)
    {
        int row = layerwidget->topLevelItemCount();
        QTreeWidgetItem *item = new QTreeWidgetItem(layerwidget);
        item->setText(0, QString::number(l->second->GetZValue()));
        layerwidget->insertTopLevelItem(row, item);
        if(row==0)
            layerwidget->setItemSelected(item, 1);
    }
}

void LayerManager::RemoveLayer(Layer *l) {
  if (!l || !m_layers.contains(l)) return;
  m_layers.removeOne(l);
  QTreeWidgetItem *item;
  for (auto i : layermap) {
    if (i.second == l) {
      item = i.first;
      layermap.erase(item);
      break;
    }
  }
  layerwidget->removeItemWidget(item, 0);
  delete l;
  l = nullptr;
}

bool LayerManager::isCurrentLayerValid() {
  return layerwidget->selectedItems().size();
}

void LayerManager::AddItem(GraphicsItem *i)
{
    if(GetCurrentLayer()->GetZValue()==i->zValue())
    {
        GetCurrentLayer()->AddItem(i);
    }
    else
    {
        qDebug()<<"current layer is not same as input item's zvalue";
    }
}

void LayerManager::AddToSpecifiedLayer(int z, GraphicsItem *item) {
  qDebug() << "AddToSpecifiedLayer:" << z;
  for (int i = 0; i < m_layers.size(); i++) {
    if (m_layers[i]->GetZValue() == z) {
      m_layers[i]->AddItem(item);
      break;
    }
  }
}

Layer *LayerManager::loadFromXml(QXmlStreamReader *r, DrawScene *scene) {
  Layer *l = new Layer(-1, scene);
  return l->loadFromXml(r);
}

Layer *LayerManager::AddLayer() {
  if (!m_scene) return nullptr;
  Layer *l = new Layer(++maxlayer, m_scene);
  m_curlayer = l;
  m_layers.push_back(l);
  if (layerwidget) {
    int row = layerwidget->topLevelItemCount();
    QTreeWidgetItem *item = new QTreeWidgetItem(layerwidget);
    item->setText(0, QString::number(l->GetZValue()));
    layerwidget->insertTopLevelItem(row, item);
    layermap[item] = l;
    layerwidget->setItemSelected(item, 1);
  }
  return l;
}

void LayerManager::AddLayer(Layer *l) {
  if (!l) return;
  for (int i = 0; i < m_layers.size(); i++) {
    if (l->GetZValue() == m_layers[i]->GetZValue()) return;
  }
  m_curlayer = l;
  m_layers.push_back(l);
  if (layerwidget) {
    int row = layerwidget->topLevelItemCount();
    QTreeWidgetItem *item = new QTreeWidgetItem(layerwidget);
    item->setText(0, QString::number(l->GetZValue()));
    layerwidget->insertTopLevelItem(row, item);
    layermap[item] = l;
    layerwidget->setItemSelected(item, 1);
  }
}
