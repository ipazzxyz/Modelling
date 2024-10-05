#pragma once

#include "market.hpp"
#include <queue>
#include <utility>

class Fund {
public:
  Fund(double capitalization);

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
  int __cnt; // TODO: удалить нахуй

  double conventional_units;
  // TODO: общая капитализация
  std::map<Currency, double> currency_amount;
  std::queue<std::pair<int, double>> deposit;
};
