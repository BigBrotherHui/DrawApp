#include "textitem.h"

TextItem::TextItem(const QRectF &rt, QGraphicsItem *parent)
    : TextItemBase(rt, parent) {
  init();
}

void TextItem::SetZValue(int p) { QGraphicsTextItem::setZValue(p); }

void TextItem::SetMovable(bool p) {
  QGraphicsTextItem::setFlag(QGraphicsItem::ItemIsMovable, p);
}

void TextItem::SetSelectable(bool p) {
  QGraphicsTextItem::setFlag(QGraphicsItem::ItemIsSelectable, p);
}

void TextItem::Update() { TextItemBase::setSelected(1); }

void TextItem::SetVisible(bool v) { TextItemBase::setVisible(v); }

void TextItem::init() { m_type = TEXT; }
