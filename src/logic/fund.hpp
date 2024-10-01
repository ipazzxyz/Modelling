#pragma once

#include "market.hpp"

class Fund {
public:
  Fund(double capitalization);

  double GetUnits() const;
  double GetAmount(Currency currency);
  double GetCapitalization(Market &market) const;

  void Buy(Market &market, Currency currency, double amount);
  void Sell(Market &market, Currency currency, double amount);

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
  double conventional_units;
  std::map<Currency, double> currency_amount;
};
