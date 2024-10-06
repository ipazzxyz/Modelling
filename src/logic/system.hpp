#pragma once

#include "fund.hpp"

class System {
public:
  System(int month_amount, double capitalization, double tax, double spread);

  int GetMonthCount() const;
  int GetMonthAmount() const;

  double GetConventionalUnits() const;
  double GetCapitalization() const;
  double GetAmount(Currency currency) const;

  std::pair<double, double> GetBuyRate(Currency currency) const;
  std::pair<double, double> GetSellRate(Currency currency) const;

  std::vector<std::pair<std::string, Asset>> GetAllCost() const;

  void Buy(Currency currency, int amount);
  void Sell(Currency currency, int amount);
  void MakeDeposit(double sumDeposit, int month);

  void Iterate();

private:
  int month_amount;
  double tax;

  Fund fund;
  Market market;

  int month_cnt;
};
