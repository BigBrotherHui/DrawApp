#include "global.h"
#include <QDebug>
#include "graphicsscene.h"
#include "graphicsview.h"
#include "itembase.h"
#include "layer.h"
Global *Global::GetInstance() {
  static Global g;
  return &g;
}

Layer *Global::AddLayer() {
  Layer *l = new Layer(++maxlayer);
  return addLayer(l);
}

Layer *Global::addLayer(Layer *l) {
  if (!l) return nullptr;
  auto rt = std::find(m_layers.begin(), m_layers.end(), l);
  if (rt == m_layers.end()) m_layers.push_back(l);
  return l;
}

void Global::SetSelectEnable(bool enable) {
  for (size_t i = 0; i < m_layers.size(); i++) {
    Layer *la = m_layers[i];
    auto items = la->GetAllItems();
    for (size_t j = 0; j < items.size(); j++) {
      items[j]->SetSelectable(enable);
    }
  }
}

void Global::SetMoveEnable(bool enable) {
  for (size_t i = 0; i < m_layers.size(); i++) {
    Layer *la = m_layers[i];
    auto items = la->GetAllItems();
    for (size_t j = 0; j < items.size(); j++) {
      items[j]->SetMovable(enable);
    }
  }
}

Global::Global() {}
