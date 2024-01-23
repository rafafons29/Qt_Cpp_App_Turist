#ifndef SEARCHEXCURSION_HPP
#define SEARCHEXCURSION_HPP

#include <QWidget>
#include <qtablewidget.h>

namespace Ui {
class SearchExcursion;
}

class SearchExcursion : public QWidget {
  Q_OBJECT

public:
  explicit SearchExcursion(QWidget *parent = nullptr);
  ~SearchExcursion();

private slots:
  void on_pushButton_clicked();

private:
  Ui::SearchExcursion *ui;
};

#endif // SEARCHEXCURSION_HPP
