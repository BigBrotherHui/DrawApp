#include "graphicsview.h"
#include <QScrollBar>
GraphicsView::GraphicsView(QWidget *parent) : QGraphicsView(parent) {
  this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->verticalScrollBar()->blockSignals(true);
  this->horizontalScrollBar()->blockSignals(true);

  this->horizontalScrollBar()->setEnabled(false);
  this->verticalScrollBar()->setEnabled(false);
  this->verticalScrollBar()->setValue(this->verticalScrollBar()->minimum());
  this->horizontalScrollBar()->setValue(this->horizontalScrollBar()->minimum());

  this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
  this->setDragMode(QGraphicsView::RubberBandDrag);
  this->setRubberBandSelectionMode(Qt::ContainsItemBoundingRect);
  this->setAcceptDrops(true);
}
