#pragma once

#include "market.hpp"
#include <queue>
#include <utility>

class Fund {
public:
  Fund(double capitalization);

  double GetConventionalUnits() const;
  double GetAmount(Currency currency);
  double GetCapitalization(Market &market) const;

  void Buy(Market &market, Currency currency, double amount);
  void Sell(Market &market, Currency currency, double amount);
  void MakeDeposit(Market &market, double amount, int month);

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
  int __cnt;

  double conventional_units;
  std::map<Currency, double> currency_amount;
  std::queue<std::pair<int, double>> deposit;
};
