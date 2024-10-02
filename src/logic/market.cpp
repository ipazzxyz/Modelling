#include "market.hpp"

#include <ctime>

Market::Market(double spread)
    : deposit_percent(20), spread(spread), rng(std::time(nullptr)) {}

double Market::GetBuyPrice(Currency currency) {
  return currency_exchange_rate[currency];
}
double Market::GetSellPrice(Currency currency) {
  return currency_exchange_rate[currency];
}
double Market::GetDepositPercent(double amount, int month) const {
  return deposit_percent;
}

void Market::Iterate() {
  for (int i = 1; static_cast<Currency>(i) != Currency::__Last; ++i) {
    currency_exchange_rate[static_cast<Currency>(i)] *=
        2 * spread * static_cast<double>(rng()) /
            static_cast<double>(rng.max()) +
        1 - spread;
  }
}