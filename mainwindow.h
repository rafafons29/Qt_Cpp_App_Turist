#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "./include/empresaturistica/empresaturistica.hpp"
#include "./include/menu/menu.hpp"

#include <QMainWindow>
#include <QMessageBox>
#include <QStringView>

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

  static std::unique_ptr<EmpresaTuristica> empt;

private:
  Ui::MainWindow *ui;
  Menu *menu;
};

#endif // MAINWINDOW_H
