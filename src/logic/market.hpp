#pragma once

#include "currency.hpp"
#include "asset.hpp"
#include <map>
#include <random>

class Market {
public:
  Market(double spread);

  double GetBuyRate(Currency currency) const;
  double GetSellRate(Currency currency) const;
  double GetDepositPercent(double amount, int month) const;

  void Iterate();

private:
  double spread;
  std::mt19937 rng;

  std::map<Currency, double> currency_exchange_rate; //TODO: std::vector<Currency>
  double deposit_percent;
  // TODO: vector<double> deposit(M);
};
