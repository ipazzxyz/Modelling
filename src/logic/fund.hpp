#pragma once

#include "market.hpp"
#include <queue>
#include <utility>

class Fund {
public:
  Fund(double capitalization_);

  double GetConventionalUnits() const;
  double GetAmount(Currency currency) const;
  double GetCapitalization(const Market &market) const;

  void Buy(const Market &market, Currency currency, double amount);
  void Sell(const Market &market, Currency currency, double amount);
  void MakeDeposit(const Market &market, double amount, int month);

  void Iterate();

  class NotEnoughConventionalUnits : public std::exception {
  public:
    const char *what();
  };
  class NotEnoughCurrency : public std::exception {
  public:
    const char *what();
  };

private:

  double conventional_units, capitalization;
  std::map<Currency, double> currency_amount;

};
