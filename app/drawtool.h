#ifndef DRAWTOOL
#define DRAWTOOL

#include "drawobj.h"
#include "drawscene.h"
#include "graphicsinstanceitem.h"
#include "graphicsitemgroup.h"
QT_BEGIN_NAMESPACE
class QGraphicsScene;
class QGraphicsSceneMouseEvent;
class QMenu;
class QPoint;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;
class QAbstractGraphicsShapeItem;
QT_END_NAMESPACE

class DrawScene;
class GraphicsItem;
class GraphicsPolygonItem;
enum DrawShape {
  selection,
  drag,
  rotation,
  line,
  rectangle,
  roundrect,
  ellipse,
  bezier,
  polygon,
  polyline,
  text,
  instance
};

class DrawTool : public QObject {
  Q_OBJECT
 public:
  DrawTool(DrawShape shape);
  virtual void mousePressEvent(QGraphicsSceneMouseEvent *event,
                               DrawScene *scene);
  virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event,
                              DrawScene *scene);
  virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event,
                                 DrawScene *scene);
  virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event,
                                     DrawScene *scene);
  virtual void focusInEvent(QFocusEvent *focusEvent, DrawScene *scene) {}
  virtual void focusOutEvent(QFocusEvent *focusEvent, DrawScene *scene) {}
  DrawShape m_drawShape;
  bool m_hoverSizer;

  static DrawTool *findTool(DrawShape drawShape);
  static QList<DrawTool *> c_tools;
  static QPoint c_down;
  static quint32 c_nDownFlags;
  static QPoint c_last;
  static DrawShape c_drawShape;
  QMenu *menu{nullptr};
};

class SelectTool : public DrawTool {
 public:
  SelectTool();
  virtual void mousePressEvent(QGraphicsSceneMouseEvent *event,
                               DrawScene *scene);
  virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event,
                              DrawScene *scene);
  virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event,
                                 DrawScene *scene);
  QPointF initialPositions;
  QPointF opposite_;
  QGraphicsPathItem *dashRect;
  GraphicsItemGroup *selLayer;
};

class RotationTool : public DrawTool {
 public:
  RotationTool();
  virtual void mousePressEvent(QGraphicsSceneMouseEvent *event,
                               DrawScene *scene);
  virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event,
                              DrawScene *scene);
  virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event,
                                 DrawScene *scene);
  qreal lastAngle;
  QGraphicsPathItem *dashRect;
};

class RectTool : public DrawTool {
  Q_OBJECT
 public:
  RectTool(DrawShape drawShape);
  virtual void mousePressEvent(QGraphicsSceneMouseEvent *event,
                               DrawScene *scene);
  virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event,
                              DrawScene *scene);
  virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event,
                                 DrawScene *scene);
  virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event,
                                     DrawScene *scene) override;
  GraphicsItem *item;
 signals:
  void signal_instanceItemDoubleClicked(GraphicsInstanceItem *);
};

class PolygonTool : public DrawTool {
 public:
  PolygonTool(DrawShape shape);
  virtual void mousePressEvent(QGraphicsSceneMouseEvent *event,
                               DrawScene *scene);
  virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event,
                              DrawScene *scene);
  virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event,
                                 DrawScene *scene);
  virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event,
                                     DrawScene *scene);
  GraphicsPolygonItem *item;
  int m_nPoints;
  QPoint initialPositions;
};
#endif  // DRAWTOOL
