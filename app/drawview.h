﻿#ifndef DRAWVIEW_H
#define DRAWVIEW_H
#include <QGraphicsView>

#include "drawobj.h"
#include "graphicsitemgroup.h"
#include "rulebar.h"
#include "ruler.h"
class Ruler;
class QMouseEvent;
class MapView;
class DrawView : public QGraphicsView {
  Q_OBJECT
 public:
  DrawView(QGraphicsScene *scene);
  ~DrawView();
  void zoomIn();
  void zoomOut();

  void newFile();
  bool loadFile(const QString &fileName);
  bool save();
  bool saveAs();
  bool saveFile(const QString &fileName);
  QString userFriendlyCurrentFile();
  void show();
  QString currentFile() { return curFile; }
  void setModified(bool value) { modified = value; }
  bool isModified() const { return modified; }
  void setToSubView() { m_isSubView=1; }
  LayerManager *layerManager{nullptr};
 signals:
  void positionChanged(int x, int y);
  void sizeChanged();
  void updateScene(QPixmap pixmap);
 protected:
  void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;
  void wheelEvent(QWheelEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
  void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
  void scrollContentsBy(int dx, int dy) Q_DECL_OVERRIDE;
  void updateRuler();
  QtRuleBar *m_hruler;
  QtRuleBar *m_vruler;
  QtCornerBox *box;

 private:
  bool maybeSave();
  void setCurrentFile(const QString &fileName);
  QString strippedName(const QString &fullFileName);
  void loadCanvas(QXmlStreamReader *xml);
  void loadCanvas(QString gdsfilepath);
  GraphicsItemGroup *loadGroupFromXML(QXmlStreamReader *xml);
  double m_scale{1.0};
  QString curFile;
  bool isUntitled;
  bool modified;
  // used to drag view
  QPointF m_lastPointF;
  bool isPressed;
  Ruler *ruler;
  bool m_isSubView{0};
  bool m_isSaved{0};
public:
  MapView *mapView{nullptr};
};

#endif  // DRAWVIEW_H
