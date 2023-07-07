#ifndef ITEMBASE_H
#define ITEMBASE_H
#include <QBrush>
#include <QGraphicsItem>
#include <QPen>
class ItemBase {
  using Flag = QGraphicsItem::GraphicsItemFlag;

 public:
  ItemBase();
  virtual ~ItemBase();
  enum ItemType { POLYGON, BOX, TEXT, PATH };
  ItemType m_type;
  void Register(ItemBase *b);
  void UnRegister(ItemBase *b);
  virtual void SetZValue(int p) = 0;
  virtual void SetMovable(bool p) {}
  virtual void SetSelectable(bool p) {}
  virtual void SetBrush(QBrush) {}
  virtual void SetPen(QPen) {}
  void Notify();
  virtual void Update() {}
  virtual void SetVisible(bool v) {}

 protected:
  virtual void init() {}

 private:
  //用于级联选中
  std::vector<ItemBase *> m_items;
  QString m_name;
  unsigned int m_id;
};

#endif  // ITEMBASE_H
