#ifndef LAYER_H
#define LAYER_H

#include <QBrush>
#include <QObject>
#include <QPen>
#include <vector>
class ItemBase;
class Layer : public QObject {
 public:
  explicit Layer(int z, QObject *parent = nullptr);
  void SetZValue(int z);
  void AddItem(ItemBase *item);
  void RemoveItem(ItemBase *item);
  int GetZValue() { return m_z; }
  std::vector<ItemBase *> GetAllItems() { return m_items; }
  void SetVisible(bool b);

 private:
  int m_z;
  std::vector<ItemBase *> m_items;
  QBrush m_brush{Qt::red};
  QPen m_pen{Qt::green};
};

#endif  // LAYER_H
