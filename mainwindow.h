#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_box_clicked();

  void on_pushButton_select_clicked();

  void on_pushButton_text_clicked();

  void on_pushButton_path_clicked();

  void on_pushButton_polygon_clicked();

  void on_layercontainer_itemClicked(QTableWidgetItem *item);

  void on_pushButton_move_clicked();

  void on_pushButton_addlayer_clicked();

 private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
