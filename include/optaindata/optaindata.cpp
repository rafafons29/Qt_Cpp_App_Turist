#include "optaindata.hpp"
#include "ui_optaindata.h"

#include "../../mainwindow.h"

#include <cctype>
#include <qcursor.h>
#include <qlineedit.h>
#include <qmainwindow.h>
#include <qpoint.h>
#include <qpushbutton.h>
#include <string>

OptainData::OptainData(QWidget *parent)
    : QWidget(parent), ui(new Ui::OptainData) {
  ui->setupUi(this);

  set_style_sheet();
  set_placeholder_text();
}

OptainData::~OptainData() { delete ui; }

bool OptainData::comp_isalpha(std::string const &input) {
  for (auto c : input)
    if (std::isalpha(c))
      return false;

  return true;
};

void OptainData::set_placeholder_text() {
  static constexpr char const *NUMBER{" Number"};
  static constexpr char const *CANT_TURI{" Cantidad Turistas"};
  static constexpr char const *NAME{" Name"};
  static constexpr char const *PRECIO{" Precio"};

  ui->exc_number_le->setText("");
  ui->exc_cant_turist_le->setText("");
  ui->exc_name_le->setText("");
  ui->exc_precio_le->setText("");

  ui->exc_number_le->setPlaceholderText(NUMBER);
  ui->exc_cant_turist_le->setPlaceholderText(CANT_TURI);
  ui->exc_name_le->setPlaceholderText(NAME);
  ui->exc_precio_le->setPlaceholderText(PRECIO);
}

void OptainData::set_style_sheet() {
  ui->exc_number_le->setStyleSheet(OptainData::STANDAR_LINE_STYLE);
  ui->exc_name_le->setStyleSheet(OptainData::STANDAR_LINE_STYLE);
  ui->exc_cant_turist_le->setStyleSheet(OptainData::STANDAR_LINE_STYLE);
  ui->exc_precio_le->setStyleSheet(OptainData::STANDAR_LINE_STYLE);
}

void OptainData::on_add_btn_clicked() {
  if (!ui->exc_number_le->text().isEmpty() &&
      !ui->exc_cant_turist_le->text().isEmpty() &&
      !ui->exc_name_le->text().isEmpty() &&
      !ui->exc_precio_le->text().isEmpty()) {

    // {number, cant_turistas, name, precio}
    std::tuple<std::size_t, std::size_t, QString, double> data{
        ui->exc_number_le->text().toInt(),
        ui->exc_cant_turist_le->text().toInt(), ui->exc_name_le->text(),
        ui->exc_precio_le->text().toDouble()};
    try {
      MainWindow::empt->set_excursion(std::move(data));
      set_placeholder_text();
      ui->add_btn->setEnabled(true);
    } catch (std::invalid_argument const &exc) {
      auto error_message = [](QLineEdit *line, QString const &message) {
        QString style{OptainData::STANDAR_LINE_STYLE};
        style.append("color: red");
        line->setText("");
        line->setPlaceholderText(message);
        line->setStyleSheet(style);
      };

      if (std::string(exc.what()) ==
          std::string(EmpresaTuristica::SAME_NAME_NUMBER)) {

        error_message(ui->exc_name_le, EmpresaTuristica::SAME_NAME);
        error_message(ui->exc_number_le, EmpresaTuristica::SAME_NUMBER);

      } else if (std::string(exc.what()) ==
                 std::string(EmpresaTuristica::SAME_NUMBER)) {

        error_message(ui->exc_number_le, EmpresaTuristica::SAME_NUMBER);

      } else if (std::string(exc.what()) ==
                 std::string(EmpresaTuristica::SAME_NAME)) {

        error_message(ui->exc_name_le, EmpresaTuristica::SAME_NAME);

      } else {
        return;
      }
    }
  } else {
  }
}

void OptainData::on_exc_number_le_textEdited(const QString &arg1) {
  set_style_sheet();

  if (!comp_isalpha(arg1.toStdString()))
    ui->exc_number_le->setText("");
}

void OptainData::on_exc_name_le_textEdited(const QString &arg1) {
  set_style_sheet();

  if (arg1 == "Nombre")
    ui->exc_name_le->setText("");
}

void OptainData::on_exc_cant_turist_le_textEdited(const QString &arg1) {
  set_style_sheet();

  if (!comp_isalpha(arg1.toStdString()))
    ui->exc_cant_turist_le->setText("");
}

void OptainData::on_exc_precio_le_textEdited(const QString &arg1) {
  set_style_sheet();

  if (!comp_isalpha(arg1.toStdString()))
    ui->exc_precio_le->setText("");
}
