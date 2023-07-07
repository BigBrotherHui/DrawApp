#ifndef TEXTITEM_H
#define TEXTITEM_H

#include "itembase.h"
#include "textitembase.h"
class TextItem : public TextItemBase, public ItemBase {
 public:
  explicit TextItem(const QRectF &rt = QRectF(),
                    QGraphicsItem *parent = nullptr);
  void SetZValue(int z) override;
  virtual void SetMovable(bool p) override;
  virtual void SetSelectable(bool p) override;
  virtual void Update();
  void SetVisible() {}
  virtual void SetVisible(bool v);

 protected:
  virtual void init() override;
};

#endif  // TEXTITEM_H
