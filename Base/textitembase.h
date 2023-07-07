#ifndef TEXTITEMBASE_H
#define TEXTITEMBASE_H

#include <qgraphicsitem.h>
#include <QColor>
#include <QFontMetricsF>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QPen>
#include <QPointF>
#include <QTextCursor>

class TextItemBase : public QGraphicsTextItem {
 public:
  explicit TextItemBase(const QRectF &rt, QGraphicsItem *parent = nullptr);
  ~TextItemBase();
  void init();

  void setRect(const QRectF &rect);
  void updateFontInfo();
  void setText(QString text);

 protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;
  QRectF boundingRect() const override;

  int type() const;
  virtual void focusInEvent(QFocusEvent *focusEvent) override;  //焦点进入事件
  void focusOutEvent(QFocusEvent *focusEvent) override;
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

  QPainterPath shape() const;

 private:
  QRectF m_rect;
  QPen m_pen;
  QString m_text;

  QFontMetricsF *m_fontMetricsF = NULL;
  qreal m_fontWidth;
  qreal m_fontHeight;

  bool isMousePress = false;
  QColor m_color;
  QFont m_font;
  bool m_focus;
};

#endif  // TEXTITEMBASE_H
