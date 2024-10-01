#pragma once

#include "currency.hpp"
#include <map>
#include <random>

class Market {
public:
  Market(double spread);

  double GetBuyPrice(Currency currency);
  double GetSellPrice(Currency currency);

  void Iterate();

private:
  double spread;
  std::mt19937 rng;

  std::map<Currency, double> currency_exchange_rate;
};
