#include "polygonitem.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPainterPath>
PolygonItem::PolygonItem(QGraphicsItem *parent)
    : QGraphicsPolygonItem(parent) {}

void PolygonItem::paint(QPainter *painter,
                        const QStyleOptionGraphicsItem *option,
                        QWidget *widget) {
  painter->setRenderHint(QPainter::Antialiasing);
  painter->setPen(Qt::red);
  painter->setBrush(Qt::green);
  painter->drawPolygon(polygon());
}

void PolygonItem::addPoint(const QPointF &point) { polygon() << point; }

void PolygonItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    addPoint(event->scenePos().toPoint());
    update();
    event->accept();
  } else {
    QGraphicsPolygonItem::mousePressEvent(event);
  }
}
void PolygonItem::SetZValue(int p) { QGraphicsPolygonItem::setZValue(p); }

void PolygonItem::SetMovable(bool p) {
  QGraphicsPolygonItem::setFlag(QGraphicsItem::ItemIsMovable, p);
}

void PolygonItem::SetSelectable(bool p) {
  QGraphicsPolygonItem::setFlag(QGraphicsItem::ItemIsSelectable, p);
}

void PolygonItem::SetBrush(QBrush b) { QGraphicsPolygonItem::setBrush(b); }

void PolygonItem::SetPen(QPen p) { QGraphicsPolygonItem::setPen(p); }

void PolygonItem::Update() { QGraphicsPolygonItem::setSelected(1); }

void PolygonItem::SetVisible(bool v) { QGraphicsPolygonItem::setVisible(v); }

void PolygonItem::init() { m_type = POLYGON; }
