#ifndef SELECTIONSINGLETON_H
#define SELECTIONSINGLETON_H
#include "graphicsscene.h"
#include "itembase.h"
class Layer;
class SelectionSingleton {
 public:
  enum OPTION { SELECT, MOVE, DRAW_BOX, DRAW_TEXT, DRAW_PATH, DRAW_POLYGON };
  static SelectionSingleton *GetInstance();
  Layer *GetCurrentLayer() { return mLayer; }
  void SetCurrentLayer(Layer *l) { mLayer = l; }
  OPTION GetSelectedOption() { return mOp; }
  void SetSelectedOption(OPTION op);
  void SetCurrentScene(GraphicsScene *s) { m_scene = s; }
  GraphicsScene *Scene() { return m_scene; }

 protected:
  SelectionSingleton();
  Layer *mLayer;
  ItemBase::ItemType mItemType;
  OPTION mOp;
  GraphicsScene *m_scene;
};

#endif  // SELECTIONSINGLETON_H
