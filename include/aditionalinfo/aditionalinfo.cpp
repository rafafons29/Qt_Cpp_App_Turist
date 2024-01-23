#include "aditionalinfo.hpp"
#include "ui_aditionalinfo.h"

#include "../../mainwindow.h"
#include <qchar.h>

AditionalInfo::AditionalInfo(QWidget *parent)
    : QWidget(parent), ui(new Ui::AditionalInfo) {
  ui->setupUi(this);

  if (MainWindow::empt->empty())
    return;

  AditionalInfo::show_results(ui->max_turist,
                              MainWindow::empt->get_max_turist()->exc_name_);
  AditionalInfo::show_results(
      ui->infer_sup, QString::number(MainWindow::empt->get_cant_inf_sup()));
  AditionalInfo::show_results(ui->total_money,
                              QString::number(MainWindow::empt->get_money()));
  AditionalInfo::show_results(ui->total_turist,
                              QString::number(MainWindow::empt->get_tturist()));
}

AditionalInfo::~AditionalInfo() { delete ui; }

void AditionalInfo::show_results(QLineEdit *line, QString const &result) {
  line->setText(result);
  line->setEnabled(false);
}
