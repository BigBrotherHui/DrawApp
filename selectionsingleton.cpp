#include "selectionsingleton.h"
#include <QApplication>
#include "global.h"
SelectionSingleton *SelectionSingleton::GetInstance() {
  static SelectionSingleton instance;
  return &instance;
}

void SelectionSingleton::SetSelectedOption(SelectionSingleton::OPTION op) {
  mOp = op;
  switch (op) {
    case SelectionSingleton::DRAW_BOX: {
      qApp->setOverrideCursor(Qt::CrossCursor);
      break;
    }
    default: {}
  }
  if (mOp == SelectionSingleton::SELECT) {
    Global::GetInstance()->SetSelectEnable(1);
  } else {
    Global::GetInstance()->SetSelectEnable(0);
  }

  if (mOp == SelectionSingleton::MOVE) {
    Global::GetInstance()->SetMoveEnable(1);
  } else {
    Global::GetInstance()->SetMoveEnable(0);
  }
}

SelectionSingleton::SelectionSingleton() {}
