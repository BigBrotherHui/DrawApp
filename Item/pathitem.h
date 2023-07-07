#ifndef PATHITEM_H
#define PATHITEM_H

#include <QGraphicsPathItem>
#include "itembase.h"
class PathItem : public QGraphicsPathItem, public ItemBase {
 public:
  explicit PathItem(QGraphicsItem* parent = nullptr);
  explicit PathItem(const QPainterPath& path, QGraphicsItem* parent = nullptr);
  void SetZValue(int z) override;
  virtual void SetMovable(bool p);
  virtual void SetSelectable(bool p);
  virtual void SetBrush(QBrush);
  virtual void SetPen(QPen);
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget = nullptr) override;
  void addPoint(const QPointF& point);
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
  virtual void Update();
  virtual void SetVisible(bool v);

 protected:
  virtual void init() override;
};

#endif  // PATHITEM_H
