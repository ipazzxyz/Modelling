#pragma once

#include <ctime>
#include <map>
#include <random>

#include "asset.hpp"
#include "currency.hpp"

class Market {
 public:
  Market(double spread);

  std::pair<double, double> GetBuyRate(Currency currency) const;
  std::pair<double, double> GetSellRate(Currency currency) const;
  double GetDividends(Currency currency) const;
  double GetDepositPercent() const;
  double GetSpread() const;
  const std::map<Currency, Asset> &GetAllCost() const;

  void Iterate();

  double GetRandNum();  // TODO: move this function to something like namespace
                        // "utility" not a method

  class DoesNotExistCurrency : public std::exception {
   public:
    const char *what() const noexcept;
  };

 private:
  double spread;
  std::mt19937 rng;
  std::map<Currency, Asset> currency_exchange_rate;
  double deposit_percent;
};
