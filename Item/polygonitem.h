#ifndef POLYGONITEM_H
#define POLYGONITEM_H

#include <QGraphicsPolygonItem>
#include "itembase.h"
class PolygonItem : public QGraphicsPolygonItem, public ItemBase {
 public:
  PolygonItem(QGraphicsItem* parent = nullptr);
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget = nullptr) override;
  void addPoint(const QPointF& point);
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
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

#endif  // POLYGONITEM_H
