#pragma once

#include "currency.hpp"
#include "asset.hpp"
#include <map>
#include <random>

class Market {
public:
  Market(double spread, int cnt_months);

  std::pair<double, double> GetBuyRate(Currency currency) const;
  std::pair<double, double> GetSellRate(Currency currency) const;
  double GetDepositPercent() const;

  void Iterate();

private:
  double spread;
  std::mt19937 rng;
  std::map<Currency, Asset> currency_exchange_rate;
  double deposit_percent;
  std::vector<double> deposit;
};
