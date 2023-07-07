#ifndef BOXITEM_H
#define BOXITEM_H

#include <QGraphicsRectItem>
#include "itembase.h"
class BoxItem : public QGraphicsRectItem, public ItemBase {
 public:
  explicit BoxItem(QGraphicsItem *parent = nullptr);
  explicit BoxItem(const QRectF &rect, QGraphicsItem *parent = nullptr);
  explicit BoxItem(qreal x, qreal y, qreal w, qreal h,
                   QGraphicsItem *parent = nullptr);
  void SetZValue(int z) override;
  virtual void SetMovable(bool p);
  virtual void SetSelectable(bool p);
  virtual void SetBrush(QBrush);
  virtual void SetPen(QPen);
  virtual void Update();
  virtual void SetVisible(bool v);

 protected:
  virtual void init() override;
};

#endif  // BOXITEM_H
