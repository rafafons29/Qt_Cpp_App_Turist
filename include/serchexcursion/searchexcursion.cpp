#include "searchexcursion.hpp"
#include "ui_searchexcursion.h"

#include "../../mainwindow.h"
#include <qnamespace.h>
#include <qtablewidget.h>

SearchExcursion::SearchExcursion(QWidget *parent)
    : QWidget(parent), ui(new Ui::SearchExcursion) {
  ui->setupUi(this);

  ui->exc_name->setPlaceholderText(" Name");
  ui->exc_name->setStyleSheet(OptainData::STANDAR_LINE_STYLE);
}

SearchExcursion::~SearchExcursion() { delete ui; }

void SearchExcursion::on_pushButton_clicked() {
  auto excursion = MainWindow::empt->get_excursion(ui->exc_name->text());
  QString style = OptainData::STANDAR_LINE_STYLE;
  if (excursion != nullptr) {
    ui->exc_info->setItem(
        0, 0, new QTableWidgetItem(QString::number(excursion->exc_number_)));
    ui->exc_info->setItem(
        0, 1,
        new QTableWidgetItem(QString::number(excursion->exc_cant_turistas_)));
    ui->exc_info->setItem(
        0, 2, new QTableWidgetItem(QString::number(excursion->exc_precio_)));
    ui->exc_info->setItem(
        0, 3,
        new QTableWidgetItem(QString::number(excursion->exc_cant_recaudado_)));

    ui->exc_name->setStyleSheet(style);
  } else {
    style.append("color: red");
    ui->exc_name->setText("");
    ui->exc_name->setPlaceholderText("No encontrado");
    ui->exc_name->setStyleSheet(style);
  }
}
