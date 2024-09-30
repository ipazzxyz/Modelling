#pragma once

#include <map>

#include "currency.hpp"

class Market {
 public:
  Market(double spread);

  double operator[](Currency currency);

 private:
  double spread_;

  std::map<Currency, int> currency_exchange_rate_;
};