#pragma once

#include <exception>
#include <map>

#include "currency.hpp"
#include "market.hpp"

class Fund {
 public:
  class NotEnoughMoney : public std::exception {
   public:
    const char* what();
  };

  Fund(double capitalization);

  void Buy(Market&);
  void Sell(Market&);

  double GetCapitalization(Market&) const;

 private:
  std::map<Currency, int> currency_amount_;
};