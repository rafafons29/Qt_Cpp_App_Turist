#include "orderlist.hpp"
#include "ui_orderlist.h"

#include "../../mainwindow.h"
#include <qtablewidget.h>

OrderList::OrderList(QWidget *parent) : QWidget(parent), ui(new Ui::OrderList) {
  ui->setupUi(this);

  ui->exc_list->setRowCount(MainWindow::empt->size());
  ui->exc_list->setColumnCount(4);

  int i{0};
  for (auto const &excursion : *MainWindow::empt) {
    ui->exc_list->setItem(i, 0, new QTableWidgetItem(excursion.exc_name_));
    ui->exc_list->setItem(
        i, 1,
        new QTableWidgetItem(QString::number(excursion.exc_cant_turistas_)));
    ui->exc_list->setItem(
        i, 2, new QTableWidgetItem(QString::number(excursion.exc_precio_)));
    ui->exc_list->setItem(
        i, 3,
        new QTableWidgetItem(QString::number(excursion.exc_cant_recaudado_)));
    ++i;
  }
}

OrderList::~OrderList() { delete ui; }
