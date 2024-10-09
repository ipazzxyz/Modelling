#include "market.hpp"

Market::Market(double spread)
    : deposit_percent(0.07), spread(spread), rng(std::time(nullptr)) {
    currency_exchange_rate[Currency::Hamster].SetAsset(50, 0.00000001);
    currency_exchange_rate[Currency::Ruble].SetAsset(10, 0);
    currency_exchange_rate[Currency::$TGR].SetAsset(10, 0);
    currency_exchange_rate[Currency::Gold].SetAsset(500, 0);
    currency_exchange_rate[Currency::MemCoin].SetAsset(81.5, 0);
    currency_exchange_rate[Currency::SpaceY].SetAsset(300, 0.2);
    currency_exchange_rate[Currency::BerBank].SetAsset(200, 0.25);
    currency_exchange_rate[Currency::DomikVDerevne].SetAsset(1, 0.111);
    currency_exchange_rate[Currency::PineApple].SetAsset(250, 0.17);
}

std::pair<double, double> Market::GetBuyRate(Currency currency) const {
    if (!currency_exchange_rate.count(currency)) {
        throw DoesNotExistCurrency();
    }
    return currency_exchange_rate.at(currency).GetBuyRate();
}

std::pair<double, double> Market::GetSellRate(Currency currency) const {
    if (!currency_exchange_rate.count(currency)) {
        throw DoesNotExistCurrency();
    }
    return currency_exchange_rate.at(currency).GetSellRate();
}

double Market::GetDepositPercent() const {
    return deposit_percent;
}

const std::map<Currency, Asset> &Market::GetAllCost() const {
    return currency_exchange_rate;
}

double Market::GetDividends(Currency currency) const {
    if (!currency_exchange_rate.count(currency)) {
        throw DoesNotExistCurrency();
    }
    return currency_exchange_rate.at(currency).GetDividends();
}

double Market::GetSpread() const {
    return spread;
}

double Market::GetRandNum() {
    return static_cast<double>(rng()) / static_cast<double>(rng.max());
}

void Market::Iterate() {
  for (int i = 1; static_cast<Currency>(i) != Currency::__Last; ++i) {
      currency_exchange_rate.at(static_cast<Currency>(i)).Iterate(GetRandNum(), spread);
  }

  deposit_percent *= 2 * (GetRandNum()) * spread / 10 + 1 - spread;

  if (deposit_percent > 0.17)
      deposit_percent = 0.17;
}

const char *Market::DoesNotExistCurrency::what() {
  return "There is no such currency.";
}