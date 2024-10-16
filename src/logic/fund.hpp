#pragma once

#include <ctime>
#include <list>
#include <queue>
#include <random>
#include <utility>

#include "depositor.hpp"
#include "market.hpp"

class Fund {
 public:
  Fund(double capitalization_, int month_amount);

  double GetConventionalUnits() const;
  double GetAmount(Currency currency) const;
  double GetCapitalization() const;
  double GetDeltaCapitalization() const;
  const std::vector<Depositor> &GetAllDepositors() const;
  std::vector<std::pair<int, double>> GetDeposit(int month_count) const;

  double GetRandNum();  // FIXME: same method in market.hpp

  void Buy(const Market &market, Currency currency, double amount);
  void Sell(const Market &market, Currency currency, double amount);
  void MakeDeposit(const Market &market, double deposit_money, int month,
                   int duration);

  void Iterate(const Market &market, int month, double tax, double dividend);

  class NotEnoughConventionalUnitsToBuy : public std::exception {
   public:
    const char *what() const noexcept;
  };
  class NotEnoughConventionalUnitsToMakeDeposit : public std::exception {
   public:
    const char *what() const noexcept;
  };
  class NotEnoughCurrencyToSell : public std::exception {
   public:
    const char *what() const noexcept;
  };
  class NotEnoughConventionalUnitsToIterate : public std::exception {
   public:
    const char *what() const noexcept;
  };

 private:
  std::string GenName();
  std::string GenSurname();

  double conventional_units, capitalization, delta_capitalization;
  std::map<Currency, double> currency_amount;
  std::vector<double> deposit;
  std::vector<Depositor> depositors;
  std::vector<std::string> names, surnames;
  std::mt19937 rng;
};
