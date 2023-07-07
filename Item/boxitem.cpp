#include "boxitem.h"
#include <QCursor>
BoxItem::BoxItem(QGraphicsItem *parent) : QGraphicsRectItem(parent) { init(); }

BoxItem::BoxItem(const QRectF &rect, QGraphicsItem *parent)
    : QGraphicsRectItem(rect, parent) {
  init();
}

BoxItem::BoxItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, w, h, parent) {
  init();
}

void BoxItem::SetZValue(int p) { QGraphicsRectItem::setZValue(p); }

void BoxItem::SetMovable(bool p) {
  QGraphicsRectItem::setFlag(QGraphicsItem::ItemIsMovable, p);
}

void BoxItem::SetSelectable(bool p) {
  QGraphicsRectItem::setFlag(QGraphicsItem::ItemIsSelectable, p);
}

void BoxItem::SetBrush(QBrush b) { QGraphicsRectItem::setBrush(b); }

void BoxItem::SetPen(QPen p) { QGraphicsRectItem::setPen(p); }

void BoxItem::Update() { QGraphicsRectItem::setSelected(1); }

void BoxItem::SetVisible(bool v) { QGraphicsRectItem::setVisible(v); }

void BoxItem::init() { m_type = BOX; }
