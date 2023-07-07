#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
class ItemBase;
class Layer;
class GraphicsScene : public QGraphicsScene {
 public:
  GraphicsScene(QObject *parent = nullptr);
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
  void addItem(ItemBase *item);
  void SetCurrentLayer(Layer *p) { m_layer = p; }

 private:
  QPoint m_startPos;
  QPoint m_endPos;
  ItemBase *m_item;
  Layer *m_layer;
};

#endif  // GRAPHICSSCENE_H
