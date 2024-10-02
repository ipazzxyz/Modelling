#pragma once

#include "fund.hpp"

class System {
public:
  System(int month_amount, double capitalization, double tax, double spread);

  int GetMonthCount() const;
  int GetMonthAmount() const;
  int GetMonthLeft() const;

  double GetConventionalUnits() const;
  double GetCapitalization() const;
  double GetAmount(Currency currency) const;

  double GetBuyRate(Currency currency) const;
  double GetSellRate(Currency currency) const;

  void Buy(Currency currency, double amount);
  void Sell(Currency currency, double amount);

  void Iterate();

private:
  int month_amount;
  double tax;

  Fund fund;
  Market market;

  int month_cnt;
};
