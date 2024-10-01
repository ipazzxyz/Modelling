#pragma once

#include "fund.hpp"
#include "market.hpp"

class System {
public:
  System(int month_count, double capitalization, double tax, double spread);

  Fund GetFund() const;
  Market GetMarket() const;

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
