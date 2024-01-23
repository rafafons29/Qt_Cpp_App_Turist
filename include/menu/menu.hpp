#ifndef MENU_HPP
#define MENU_HPP

#include "../aditionalinfo/aditionalinfo.hpp"
#include "../optaindata/optaindata.hpp"
#include "../orderlist/orderlist.hpp"
#include "../serchexcursion/searchexcursion.hpp"

#include <array>

#include <QPushButton>
#include <QString>

void kas(int);

namespace Ui {
class Menu;
}

class Menu : public QWidget {
  Q_OBJECT

public:
  explicit Menu(QWidget *parent = nullptr);
  ~Menu();

private slots:
  void on_list_btn_clicked();
  void on_lists_btn_clicked();
  void on_sname_btn_clicked();
  void on_adinfo_btn_clicked();

  static void set_color(QPushButton *, Menu *) noexcept;

private:
  Ui::Menu *ui;
  std::array<QPushButton *, 4> buttons;
  OptainData *optain_data{nullptr};
  OrderList *order_list{nullptr};
  SearchExcursion *search_excursion{nullptr};
  AditionalInfo *aditional_info{nullptr};

  void destroy_all();
  template <typename PTR> void show_widget(PTR *) noexcept;
};

template <typename PTR> void Menu::show_widget(PTR *ptr) noexcept {
  ptr->setGeometry(QRect(QPoint(200, 50), QSize(531, 471)));
  ptr->show();
}

#endif // MENU_HPP
