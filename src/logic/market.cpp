#include "market.hpp"

#include <ctime>

Market::Market(double spread, int cnt_months)
    : deposit_percent(20), spread(spread), rng(std::time(nullptr)), deposit(cnt_months+1, 0) {}

std::pair<double, double> Market::GetBuyRate(Currency currency) const {
    if (!currency_exchange_rate.count(currency)) {
        throw std::out_of_range("нет такого Currency");
    }
    return currency_exchange_rate.at(currency).GetBuyRate();
}
std::pair<double, double> Market::GetSellRate(Currency currency) const {
    if (!currency_exchange_rate.count(currency)) {
        throw std::out_of_range("нет такого Currency");
    }
    return currency_exchange_rate.at(currency).GetSellRate();
}

void Market::Iterate() {
  for (int i = 1; static_cast<Currency>(i) != Currency::__Last; ++i) {
      currency_exchange_rate.at(static_cast<Currency>(i)).Iterate(static_cast<double>(rng()) /
      static_cast<double>(rng.max()), spread);
  }

  deposit_percent *= (static_cast<double>(rng()) / static_cast<double>(rng.max())) *
          spread / 10 + 1;

  if (deposit_percent > 0.17)
      deposit_percent = 0.17;
}

double Market::GetDepositPercent() const {
    return deposit_percent;
}

const std::vector<std::pair<std::string, const Asset&>>& Market::GetAllCost() const {
    std::vector<std::pair<std::string, const Asset&>> result;
    for (auto [currency, asset] : currency_exchange_rate) {
        result.push_back({ToString(currency), asset});
    }
    return result;
}