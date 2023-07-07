#include "layer.h"
#include <QDebug>
#include "itembase.h"
Layer::Layer(int z, QObject *parent) : QObject(parent), m_z(z) {}

void Layer::SetZValue(int z) {
  m_z = z;
  for (size_t i = 0; i < m_items.size(); i++) {
    m_items[i]->SetZValue(m_z);
  }
}

void Layer::AddItem(ItemBase *item) {
  if (!item) return;
  auto rt = std::find(m_items.begin(), m_items.end(), item);
  if (rt == m_items.end()) {
    m_items.push_back(item);
    item->SetZValue(m_z);
    item->SetBrush(m_brush);
    item->SetPen(m_pen);
  }
  qDebug() << "Layer " << m_z << ":item size" << m_items.size();
}

void Layer::RemoveItem(ItemBase *item) {
  if (!item) return;
  auto rt = std::find(m_items.begin(), m_items.end(), item);
  if (rt != m_items.end()) m_items.erase(rt);
}

void Layer::SetVisible(bool b) {
  for (int i = 0; i < m_items.size(); i++) m_items[i]->SetVisible(b);
}
