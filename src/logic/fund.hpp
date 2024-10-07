#pragma once

#include "market.hpp"
#include "depositors.hpp"
#include <queue>
#include <list>
#include <random>
#include <ctime>
#include <utility>

class Fund {
public:
  Fund(double capitalization_, int month_amount);

  double GetConventionalUnits() const;
  int GetAmount(Currency currency) const;
  double GetCapitalization() const;
  const std::vector<Depositor> &GetALlDepositors() const;

  double GetRandNum();

  void Buy(const Market &market, Currency currency, int amount);
  void Sell(const Market &market, Currency currency, int amount);
  void MakeDeposit(const Market &market, double deposit_money, int month);

  void Iterate(const Market& market, int month, double tax, double dividend);

  class NotEnoughConventionalUnitsToBuy : public std::exception {
  public:
    const char *what();
  };

  class NotEnoughConventionalUnitsToMakeDeposit : public std::exception {
  public:
    const char *what();
  };

  class NotEnoughCurrencyToSell : public std::exception {
  public:
    const char *what();
  };

  class NotEnoughConventionalUnitsToIterate : public std::exception {
  public:
    const char *what();
  };

private:
  std::string GenName();
  std::string GenSurname();

  double conventional_units, capitalization, delta_capitalization;
  std::map<Currency, int> currency_amount;
  std::vector<double> deposit;
  std::vector<Depositor> depositors;
  std::mt19937 rng;
};
