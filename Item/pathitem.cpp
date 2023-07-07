#include "pathitem.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
PathItem::PathItem(QGraphicsItem *parent) : QGraphicsPathItem(parent) {
  init();
  QPainterPath p;
  p.moveTo(0, 0);
  p.lineTo(100, 0);
  p.lineTo(100, 100);
  setPath(p);
}

PathItem::PathItem(const QPainterPath &path, QGraphicsItem *parent)
    : QGraphicsPathItem(path, parent) {
  init();
}

void PathItem::SetZValue(int p) { QGraphicsPathItem::setZValue(p); }

void PathItem::SetMovable(bool p) {
  QGraphicsPathItem::setFlag(QGraphicsItem::ItemIsMovable, p);
}

void PathItem::SetSelectable(bool p) {
  QGraphicsPathItem::setFlag(QGraphicsItem::ItemIsSelectable, p);
}

void PathItem::SetBrush(QBrush b) { QGraphicsPathItem::setBrush(b); }

void PathItem::SetPen(QPen p) { QGraphicsPathItem::setPen(p); }

void PathItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget) {
  qDebug() << "&&&";
  painter->setRenderHint(QPainter::Antialiasing);
  painter->setPen(pen());
  painter->drawPath(path());
}

void PathItem::addPoint(const QPointF &point) { path().lineTo(point); }

void PathItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    addPoint(mapToScene(event->pos()));
    update();
    event->accept();
  } else {
    QGraphicsPathItem::mousePressEvent(event);
  }
}

void PathItem::Update() { QGraphicsPathItem::setSelected(1); }

void PathItem::SetVisible(bool v) { QGraphicsPathItem::setVisible(v); }

void PathItem::init() { m_type = PATH; }
