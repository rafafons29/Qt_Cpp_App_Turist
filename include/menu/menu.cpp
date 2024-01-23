#include "menu.hpp"
#include "ui_menu.h"

#include "../aditionalinfo/aditionalinfo.hpp"

Menu::Menu(QWidget *parent) : QWidget(parent), ui(new Ui::Menu) {
  ui->setupUi(this);
  buttons.at(0) = ui->list_btn;
  buttons.at(1) = ui->lists_btn;
  buttons.at(2) = ui->sname_btn;
  buttons.at(3) = ui->adinfo_btn;

  destroy_all();

  optain_data = new OptainData(this);
  show_widget(optain_data);
}

Menu::~Menu() {
  delete ui;
  destroy_all();
}

void Menu::on_list_btn_clicked() {
  destroy_all();
  Menu::set_color(ui->list_btn, this);

  optain_data = new OptainData(this);
  show_widget(optain_data);
}

void Menu::on_lists_btn_clicked() {
  destroy_all();
  Menu::set_color(ui->lists_btn, this);

  order_list = new OrderList(this);
  show_widget(order_list);
}

void Menu::on_sname_btn_clicked() {
  destroy_all();
  Menu::set_color(ui->sname_btn, this);

  search_excursion = new SearchExcursion(this);
  show_widget(search_excursion);
}

void Menu::on_adinfo_btn_clicked() {
  destroy_all();
  Menu::set_color(ui->adinfo_btn, this);

  aditional_info = new AditionalInfo(this);
  show_widget(aditional_info);
}

void Menu::set_color(QPushButton *btn, Menu *this_) noexcept {
  static constexpr char const *style_active{
      "background-color: #98c379;color: #ffffff; border: 0px"};
  static constexpr char const *style_incative{
      "background-color: rgba(33, 37, 42, 0);border: 0px"};

  btn->setStyleSheet(style_active);
  for (auto *button : this_->buttons) {
    if (button->styleSheet().toStdString() == style_active && btn != button) {
      button->setStyleSheet(style_incative);
      return;
    }
  }
}

void Menu::destroy_all() {

  if (optain_data != nullptr) {
    delete optain_data;
    optain_data = nullptr;
  } else if (order_list != nullptr) {
    delete order_list;
    order_list = nullptr;
  } else if (search_excursion != nullptr) {
    delete search_excursion;
    search_excursion = nullptr;
  } else if (aditional_info != nullptr) {
    delete aditional_info;
    aditional_info = nullptr;
  } else
    return;
}
