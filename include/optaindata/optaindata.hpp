#ifndef OPTAINDATA_HPP
#define OPTAINDATA_HPP

#include <QWidget>
#include <qlineedit.h>

namespace Ui {
class OptainData;
}

class OptainData : public QWidget {
  Q_OBJECT

public:
  explicit OptainData(QWidget *parent = nullptr);
  ~OptainData();

  static constexpr char const *STANDAR_LINE_STYLE{
      "border-radius: 2px;background-color: rgb(82, 89, 103);"};
private slots:
  void on_add_btn_clicked();
  void on_exc_number_le_textEdited(const QString &arg1);
  void on_exc_name_le_textEdited(const QString &arg1);
  void on_exc_cant_turist_le_textEdited(const QString &arg1);
  void on_exc_precio_le_textEdited(const QString &arg1);

private:
  Ui::OptainData *ui;

  static bool comp_isalpha(std::string const &);
  void set_placeholder_text();
  void set_style_sheet();
};

#endif // OPTAINDATA_HPP
