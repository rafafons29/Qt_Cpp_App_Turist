#ifndef EMPRESATURISTICA_HPP
#define EMPRESATURISTICA_HPP

#include <list>

#include <QString>
#include <QStringView>

class EmpresaTuristica {
  using exc_parameters = std::tuple<std::size_t, std::size_t, QString, double>;
  struct Excursion {
    std::size_t exc_number_;        // <0>
    std::size_t exc_cant_turistas_; // <1>
    QString exc_name_;              // <2>
    double exc_precio_;             // <3>
    double exc_cant_recaudado_;
    bool yn_;

    Excursion() = default;
    Excursion(exc_parameters &&); // Move constructor
    ~Excursion();

    std::string its_in(exc_parameters const *) const noexcept;
  };

  using exc_iter = std::list<Excursion>::iterator;
  std::list<Excursion> excursiones_;

  Excursion *exc_max_{nullptr};
  std::size_t total_turist_{0};
  double total_money_{0};
  int exc_cant_inf_sup_;
  constexpr static int precio_minimo_{15};
  constexpr static int cantidad_maxima_turistas{50};

  Excursion *order_list(Excursion &&) noexcept;
  void max_turist(Excursion *) noexcept; // Inciso b)

public:
  EmpresaTuristica() = default;
  ~EmpresaTuristica();

  void set_excursion(exc_parameters &&); // Inciso a)
  const std::size_t size() noexcept;
  const Excursion *get_max_turist() noexcept;
  const Excursion *get_excursion(QStringView) noexcept; // Inciso c)
  const double get_money() const noexcept;              // Inciso e)
  const std::size_t get_tturist() const noexcept;       // Inciso f)
  const int get_cant_inf_sup() const noexcept;          // Inciso d)

  bool empty() const noexcept;

  exc_iter begin() { return excursiones_.begin(); }
  exc_iter end() { return excursiones_.end(); }

  inline static constexpr char const *SAME_NAME{"That name it's on the list"};
  inline static constexpr char const *SAME_NUMBER{
      "The number it's on the list"};
  inline static constexpr char const *SAME_NAME_NUMBER{
      "That name and that number it's on the list"};
};

#endif // EMPRESATURISTICA_HPP
