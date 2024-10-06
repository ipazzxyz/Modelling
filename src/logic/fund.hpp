#pragma once

#include "market.hpp"
#include <queue>
#include <utility>

class Fund {
public:
  Fund(double capitalization_, int month_amount);

  double GetConventionalUnits() const;
  int GetAmount(Currency currency) const;
  double GetCapitalization(const Market &market) const;

  void Buy(const Market &market, Currency currency, int amount);
  void Sell(const Market &market, Currency currency, int amount);
  void MakeDeposit(const Market &market, double deposit_money, int month);

  void Iterate(const Market& market);

  class NotEnoughConventionalUnits : public std::exception {
  public:
    const char *what();
  };

  class NotEnoughCurrency : public std::exception {
  public:
    const char *what();
  };

private:

  double conventional_units, capitalization, delta_capitalization;
  std::map<Currency, int> currency_amount;
  std::vector<double> deposit;
};
