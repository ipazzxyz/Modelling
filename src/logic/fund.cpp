#include "fund.hpp"
#include <utility>

Fund::Fund(double capitalization)
    : __cnt(0), conventional_units(capitalization) {}

double Fund::GetConventionalUnits() const { return conventional_units; }
double Fund::GetAmount(Currency currency) { return currency_amount[currency]; }
double Fund::GetCapitalization(Market &market) const {
  double capitalization = 0;
  for (std::pair<const Currency, int> i : currency_amount) {
    capitalization += market.GetSellPrice(i.first) * i.second;
  }
  return capitalization;
}

void Fund::Buy(Market &market, Currency currency, double amount) {
  double price = conventional_units * market.GetBuyPrice(currency);
  if (conventional_units < price) {
    throw NotEnoughConventionalUnits();
  }
  conventional_units -= price;
  currency_amount[currency] += amount;
}
void Fund::Sell(Market &market, Currency currency, double amount) {
  if (GetAmount(currency) < amount) {
    throw NotEnoughCurrency();
  }
  conventional_units += GetAmount(currency) * market.GetSellPrice(currency);
  currency_amount[currency] -= amount;
}
void Fund::MakeDeposit(Market &market, double amount, int month) {
  if (GetConventionalUnits() < amount) {
    throw NotEnoughConventionalUnits();
  }
  conventional_units -= amount;
  deposit.push(
      std::make_pair(__cnt + month, market.GetDepositPercent(amount, month)));
}

void Fund::Iterate() {
  if (deposit.front().first == ++__cnt) {
    conventional_units += deposit.front().second;
    deposit.pop();
  }
}

const char *Fund::NotEnoughConventionalUnits::what() {
  return "Not enough units to buy.";
}
const char *Fund::NotEnoughCurrency::what() {
  return "Not enoughs currency to sell.";
}
