#include "mainwindow.h"
#include <QColorDialog>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include "global.h"
#include "graphicsscene.h"
#include "graphicsview.h"
#include "layer.h"
#include "selectionsingleton.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  GraphicsView *view = new GraphicsView(this);
  Global::GetInstance()->SetGraphicsView(view);
  GraphicsScene *scene = new GraphicsScene(this);
  Global::GetInstance()->SetGraphicsScene(scene);
  scene->setSceneRect(0, 0, 200, 200);
  view->setScene(scene);
  setCentralWidget(view);
  Layer *l = Global::GetInstance()->AddLayer();
  SelectionSingleton::GetInstance()->SetCurrentLayer(l);

  ui->layercontainer->setColumnCount(2);
  ui->layercontainer->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->layercontainer->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  ui->layercontainer->insertRow(0);
  ui->layercontainer->setCellWidget(0, 0, new QLabel(0));
  QPushButton *colorBtn = new QPushButton(this);
  connect(colorBtn, &QPushButton::clicked, this, [=] {
    QColorDialog d;
    if (d.exec() == QColorDialog::Rejected) {
      return;
    }
  });
  ui->layercontainer->setCellWidget(0, 1, colorBtn);
  scene->SetCurrentLayer(l);
  SelectionSingleton::GetInstance()->SetCurrentScene(scene);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_box_clicked() {
  SelectionSingleton::GetInstance()->SetSelectedOption(
      SelectionSingleton::DRAW_BOX);
}

void MainWindow::on_pushButton_select_clicked() {
  SelectionSingleton::GetInstance()->SetSelectedOption(
      SelectionSingleton::SELECT);
}

void MainWindow::on_pushButton_text_clicked() {
  SelectionSingleton::GetInstance()->SetSelectedOption(
      SelectionSingleton::DRAW_TEXT);
}

void MainWindow::on_pushButton_path_clicked() {
  SelectionSingleton::GetInstance()->SetSelectedOption(
      SelectionSingleton::DRAW_PATH);
}

void MainWindow::on_pushButton_polygon_clicked() {
  SelectionSingleton::GetInstance()->SetSelectedOption(
      SelectionSingleton::DRAW_POLYGON);
}

void MainWindow::on_layercontainer_itemClicked(QTableWidgetItem *item) {}

void MainWindow::on_pushButton_move_clicked() {
  SelectionSingleton::GetInstance()->SetSelectedOption(
      SelectionSingleton::MOVE);
}

void MainWindow::on_pushButton_addlayer_clicked() {
  Global::GetInstance()->AddLayer();
}
