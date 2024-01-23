#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "./include/menu/menu.hpp"

#include <memory>

std::unique_ptr<EmpresaTuristica> MainWindow::empt{
    std::make_unique<EmpresaTuristica>()};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  menu = new Menu(this);
  setCentralWidget(menu);
}

MainWindow::~MainWindow() {
  delete ui;
  delete menu;
}
