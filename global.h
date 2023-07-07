#ifndef GLOBAL_H
#define GLOBAL_H

#include <vector>
class Layer;
class GraphicsView;
class GraphicsScene;
class Global {
 public:
  static Global *GetInstance();
  Layer *AddLayer();

  void SetGraphicsView(GraphicsView *view) { mView = view; }
  GraphicsView *GetGraphicsView() { return mView; }
  void SetGraphicsScene(GraphicsScene *scene) { mScene = scene; }
  GraphicsScene *GetGraphicsScene() { return mScene; }
  void SetSelectEnable(bool enable);
  void SetMoveEnable(bool enable);
  int maxlayer = -1;

 protected:
  Global();
  Layer *addLayer(Layer *l);

 private:
  std::vector<Layer *> m_layers;
  GraphicsView *mView;
  GraphicsScene *mScene;
};

#endif  // GLOBAL_H
