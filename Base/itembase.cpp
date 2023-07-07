#include "itembase.h"
#include <QDateTime>
#include <QGraphicsRectItem>
ItemBase::ItemBase() { m_id = QDateTime::currentDateTime().toTime_t(); }
ItemBase::~ItemBase() {}

void ItemBase::Register(ItemBase *item) {
  if (!item) return;
  auto rt = std::find(m_items.begin(), m_items.end(), item);
  if (rt == m_items.end()) {
    m_items.push_back(item);
  }
}

void ItemBase::UnRegister(ItemBase *item) {
  if (!item) return;
  auto rt = std::find(m_items.begin(), m_items.end(), item);
  if (rt == m_items.end()) {
    m_items.push_back(item);
  }
}

void ItemBase::Notify() {
  for (int i = 0; i < m_items.size(); i++) {
    m_items[i]->Update();
  }
}
