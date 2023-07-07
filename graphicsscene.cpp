#include "graphicsscene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "boxitem.h"
#include "global.h"
#include "graphicsview.h"
#include "layer.h"
#include "pathitem.h"
#include "polygonitem.h"
#include "selectionsingleton.h"
#include "textitem.h"
GraphicsScene::GraphicsScene(QObject *parent) : QGraphicsScene(parent) {}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  m_startPos = event->scenePos().toPoint();
  if (event->button() == Qt::LeftButton) {
    SelectionSingleton::OPTION t =
        SelectionSingleton::GetInstance()->GetSelectedOption();
    switch (t) {
      case SelectionSingleton::SELECT: {
        break;
      }
      case SelectionSingleton::DRAW_BOX: {
        m_item = new BoxItem;
        break;
      }
      case SelectionSingleton::DRAW_TEXT: {
        m_item = new TextItem;
        break;
      }
      case SelectionSingleton::DRAW_PATH: {
        m_item = new PathItem;
        break;
      }
      case SelectionSingleton::DRAW_POLYGON: {
        m_item = new PolygonItem;
        static_cast<PolygonItem *>(m_item)->mousePressEvent(event);
        break;
      }
      default: {}
    }
  }
  return QGraphicsScene::mousePressEvent(event);
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  m_endPos = event->scenePos().toPoint();
  if (event->button() == Qt::LeftButton) {
    SelectionSingleton::OPTION t =
        SelectionSingleton::GetInstance()->GetSelectedOption();
    switch (t) {
      case SelectionSingleton::DRAW_BOX: {
        if (!m_item) break;
        static_cast<BoxItem *>(m_item)->setRect(QRectF(m_startPos, m_endPos));
        addItem(m_item);
        break;
      }
      case SelectionSingleton::DRAW_TEXT: {
        if (!m_item) break;
        static_cast<TextItem *>(m_item)->setPos(m_startPos);
        addItem(m_item);
        break;
      }
      case SelectionSingleton::DRAW_PATH: {
        if (!m_item) break;
        static_cast<PathItem *>(m_item)->setPos(m_startPos);
        addItem(m_item);
        break;
      }
      case SelectionSingleton::DRAW_POLYGON: {
        if (!m_item) break;
        static_cast<PolygonItem *>(m_item)->setPos(m_startPos);
        addItem(m_item);
        break;
      }
      default: {}
    }
    m_item = nullptr;
  }
  return QGraphicsScene::mouseReleaseEvent(event);
}

void GraphicsScene::addItem(ItemBase *item) {
  switch (item->m_type) {
    case ItemBase::BOX: {
      QGraphicsScene::addItem(dynamic_cast<QGraphicsRectItem *>(item));
      m_layer->AddItem(m_item);
      break;
    }
    case ItemBase::TEXT: {
      QGraphicsScene::addItem(dynamic_cast<QGraphicsTextItem *>(item));
      m_layer->AddItem(m_item);
      break;
    }
    case ItemBase::PATH: {
      QGraphicsScene::addItem(dynamic_cast<QGraphicsPathItem *>(item));
      m_layer->AddItem(m_item);
      break;
    }
    case ItemBase::POLYGON: {
      QGraphicsScene::addItem(dynamic_cast<QGraphicsPolygonItem *>(item));
      m_layer->AddItem(m_item);
      break;
    }
    default:
      break;
  }
}
