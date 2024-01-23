#ifndef ADITIONALINFO_HPP
#define ADITIONALINFO_HPP

#include <QLineEdit>
#include <QWidget>

namespace Ui {
class AditionalInfo;
}

class AditionalInfo : public QWidget {
  Q_OBJECT

public:
  explicit AditionalInfo(QWidget *parent = nullptr);
  ~AditionalInfo();

private:
  Ui::AditionalInfo *ui;

  static void show_results(QLineEdit *, QString const &);
};

#endif // ADITIONALINFO_HPP
