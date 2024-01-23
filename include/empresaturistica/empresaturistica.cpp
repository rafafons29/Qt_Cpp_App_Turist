#include "empresaturistica.hpp"

#include <algorithm>
#include <qstringview.h>
#include <stdexcept>
#include <string>

EmpresaTuristica::Excursion::Excursion(exc_parameters &&parameters)
    : exc_number_(std::get<0>(parameters)),
      exc_cant_turistas_(std::get<1>(parameters)),
      exc_name_(std::get<2>(parameters)), exc_precio_(std::get<3>(parameters)),
      exc_cant_recaudado_(static_cast<double>(exc_cant_turistas_) *
                          exc_precio_),
      yn_((exc_precio_ <= precio_minimo_ &&
           exc_cant_turistas_ >= cantidad_maxima_turistas)
              ? true
              : false) {}
EmpresaTuristica::Excursion::~Excursion() {}

std::string EmpresaTuristica::Excursion::its_in(
    exc_parameters const *parameter) const noexcept {

  if (this->exc_number_ == std::get<0>(*parameter))
    return EmpresaTuristica::SAME_NUMBER;
  else if (this->exc_name_ == std::get<2>(*parameter))
    return EmpresaTuristica::SAME_NAME;
  else if (this->exc_number_ == std::get<0>(*parameter) &&
           this->exc_name_ == std::get<2>(*parameter))
    return EmpresaTuristica::SAME_NAME_NUMBER;
  return "";
}

//=================================================================================================

EmpresaTuristica::~EmpresaTuristica() {}

EmpresaTuristica::Excursion *
EmpresaTuristica::order_list(Excursion &&parameters) noexcept {
  // Con esta funcion insertamos un objeto a la lista, pero manteniendo esta
  // ordenada ascendentemente.

  auto it =
      std::lower_bound(excursiones_.begin(), excursiones_.end(), parameters,
                       [](Excursion const &e1, Excursion const &e2) -> bool {
                         return e1.exc_cant_recaudado_ < e2.exc_cant_recaudado_;
                       }

      );

  exc_iter ptr = excursiones_.insert(it, std::move(parameters));
  return &(*ptr);
}

void EmpresaTuristica::max_turist(Excursion *excursion) noexcept {
  // Con esta funcion vamos vamos teniendo controlado cual es la excursion
  // con mayor cant de turistas
  if (exc_max_ == nullptr)
    exc_max_ = excursion;
  else if (exc_max_->exc_cant_turistas_ < excursion->exc_cant_turistas_)
    exc_max_ = excursion;
  else
    return;
}

void EmpresaTuristica::set_excursion(
    EmpresaTuristica::exc_parameters &&parameters) {
  // En esta funcion agregamos a la lista una nueva Excursion, siempre y cuando
  // se compruebe que de los parametros pasados, el nombre o el numero no esten
  // ya registrados.

  std::for_each(excursiones_.begin(), excursiones_.end(),
                [parameters](Excursion const &excursion) {
                  auto message = excursion.its_in(&parameters);
                  if (!message.empty())
                    throw std::invalid_argument(message);
                });

  auto pos = order_list(Excursion(std::move(parameters)));
  max_turist(pos);
  total_turist_ += pos->exc_cant_turistas_;
  total_money_ += pos->exc_cant_recaudado_;
  exc_cant_inf_sup_ += ((pos->yn_) ? 1 : 0);
}

const std::size_t EmpresaTuristica::size() noexcept {
  return excursiones_.size();
}
const EmpresaTuristica::Excursion *EmpresaTuristica::get_max_turist() noexcept {
  return exc_max_;
}

const EmpresaTuristica::Excursion *
EmpresaTuristica::get_excursion(QStringView name) noexcept {
  // Comprobamos que dado un nombre esa excursion esta registrada,
  // en caso afirmativo retornamos un puntero a dicha excursion
  // en caso contrario retornamos nullptr.

  auto it =
      std::find_if(excursiones_.begin(), excursiones_.end(),
                   [name](Excursion const &e) { return e.exc_name_ == name; });
  return (it != excursiones_.end()) ? &(*it) : nullptr;
}

const double EmpresaTuristica::get_money() const noexcept {
  return total_money_;
}

bool EmpresaTuristica::empty() const noexcept { return excursiones_.empty(); }

const std::size_t EmpresaTuristica::get_tturist() const noexcept {
  return total_turist_;
}

const int EmpresaTuristica::get_cant_inf_sup() const noexcept {
  return exc_cant_inf_sup_;
}
