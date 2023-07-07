#include "textitembase.h"
#include <QDebug>
TextItemBase::TextItemBase(const QRectF &rt, QGraphicsItem *parent)
    : QGraphicsTextItem(parent) {
  m_rect = rt;
  init();
}

TextItemBase::~TextItemBase() {
  if (m_fontMetricsF != NULL) {
    delete m_fontMetricsF;
    m_fontMetricsF = NULL;
  }
}

void TextItemBase::init() {
  m_text = "";
  m_color = QColor(0, 0, 0);
  m_font = QFont("SimSun", 20);
  // m_font.setPixelSize(30);
  m_focus = false;
  setFont(m_font);

  setDefaultTextColor(QColor(0, 0, 0));  //设置默认文本颜色
  setEnabled(true);
  setTextInteractionFlags(Qt::TextEditorInteraction);  //设置item可编辑
  //  setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable |
  //           QGraphicsItem::ItemIsFocusable);
}

void TextItemBase::paint(QPainter *painter,
                         const QStyleOptionGraphicsItem *option,
                         QWidget *widget) {
  painter->save();  //保存painter初始状态

  painter->setPen(QPen(QBrush(m_color), 2, Qt::SolidLine));
  //当选择该item时，背景颜色变为白色透明

  if (isSelected()) {
    painter->setBrush(QColor(0, 0, 0));  //颜色是rgb 240 240 240 透明度为60
  }
  painter->setFont(m_font);
  painter->setRenderHint(QPainter::Antialiasing,
                         true);  //防止出现锯齿现象（反锯齿绘制）
  painter->drawRect(boundingRect());  //画框
  QString text = toPlainText();
  setText(text);  //更新文本框长度

  painter->restore();  //恢复painter状态
  QGraphicsTextItem::paint(painter, option, widget);
}

QRectF TextItemBase::boundingRect() const {
  // qreal labelwidth = 50;
  return QRectF(m_rect.x(), m_rect.y(), m_rect.width(), m_rect.height());
}

//类对象可调用此函数实现自定义编辑框大小
void TextItemBase::setRect(const QRectF &rect) { m_rect = rect; }

//计算m_fontWidth,m_fontHeight给自定义的boundingRect使用，同时为QGraphicsTextItem设置font和plainTex
void TextItemBase::updateFontInfo() {
  if (Q_NULLPTR != m_fontMetricsF) delete m_fontMetricsF;

  m_fontMetricsF = new QFontMetricsF(m_font);
  m_fontWidth = m_fontMetricsF->width(m_text);
  m_fontHeight = m_fontMetricsF->height();
  //当输入文字大于文本框时
  if (m_fontWidth > boundingRect().width()) {
    qreal adjust = 5;
    this->setRect(QRectF(boundingRect().x(), boundingRect().y(),
                         m_fontWidth + adjust, boundingRect().height()));
    this->setFont(m_font);
    this->setPlainText(m_text);

    //当更新文本框后，光标的位置设置，文本的末尾
    QTextCursor cursor = this->textCursor();
    cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor, 1);
    this->setTextCursor(cursor);
  }
  //当输入文字小于文本框时
  if (m_fontHeight > boundingRect().height()) {
    qreal adjust = 5;
    this->setRect(QRectF(boundingRect().x(), boundingRect().y(),
                         boundingRect().width(), m_fontHeight + adjust));
    this->setFont(m_font);
    this->setPlainText(m_text);
  }
}

void TextItemBase::setText(QString text) {
  m_text = text;
  updateFontInfo();
}

//设置自定义的TextItem的类型
int TextItemBase::type() const { return UserType + 5; }

//获取焦点事件
void TextItemBase::focusInEvent(QFocusEvent *focusEvent) {
  setTextInteractionFlags(Qt::TextEditorInteraction);
  QGraphicsTextItem::focusInEvent(focusEvent);
}

//失去焦点事件
void TextItemBase::focusOutEvent(QFocusEvent *focusEvent) {
  // setTextInteractionFlags(Qt::NoTextInteraction);
  QGraphicsTextItem::focusOutEvent(focusEvent);
  isMousePress = false;
}

void TextItemBase::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsTextItem::mousePressEvent(event);
  Q_UNUSED(event);
  if (!isMousePress) {
    QTextCursor cursor = this->textCursor();
    cursor.select(QTextCursor::Document);  //选中文本
    this->setTextCursor(cursor);
    isMousePress = true;
  }
}

void TextItemBase::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsTextItem::mouseReleaseEvent(event);
  Q_UNUSED(event);
}

QPainterPath TextItemBase::shape() const {
  QPainterPath path;
  path.addRect(boundingRect());
  return path;
}
