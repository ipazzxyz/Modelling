#include "fund.hpp"
#include <utility>
#include <iostream>

Fund::Fund(double capitalization, int months_amount)
    : conventional_units(capitalization), capitalization(0), delta_capitalization(0), deposit(months_amount+1, 0) {}

double Fund::GetConventionalUnits() const {
    return conventional_units;
}

int Fund::GetAmount(Currency currency) const {
    if (!currency_amount.count(currency)) {
        return 0;
    }
    return currency_amount.at(currency);
}

double Fund::GetCapitalization() const {
    return capitalization + conventional_units;
}

void Fund::Buy(const Market &market, Currency currency, int amount) {
    double price = amount * market.GetBuyRate(currency).first;
    if (conventional_units < price) {
        throw NotEnoughConventionalUnits();
    }
    conventional_units -= price;
    capitalization += market.GetSellRate(currency).first;
    currency_amount[currency] += amount;
}

void Fund::Sell(const Market &market, Currency currency, int amount) {
  if (GetAmount(currency) < amount) {
    throw NotEnoughCurrency();
  }
  capitalization -= amount * market.GetSellRate(currency).first;
  conventional_units += amount * market.GetSellRate(currency).first;
  currency_amount[currency] -= amount;
}

void Fund::MakeDeposit(const Market &market, double deposit_money, int month) {
  if (GetConventionalUnits() < deposit_money) {
    throw NotEnoughConventionalUnits();
  }
  conventional_units -= deposit_money;
  deposit[month] += deposit_money * (market.GetDepositPercent() + 1.0);
}

void Fund::Iterate(const Market& market, int month, double tax) {
    delta_capitalization = -capitalization;
    capitalization = 0;
    for (auto [currency, amount] : currency_amount) {
        capitalization += market.GetSellRate(currency).first * amount;
        conventional_units += market.GetDividends(currency) * amount;
    }
    std::cout << conventional_units << " ||\n";
    conventional_units -= capitalization * tax;

    std::cout << conventional_units << " ||\n";
    conventional_units += deposit[month];
    delta_capitalization -= capitalization;
}

const char *Fund::NotEnoughConventionalUnits::what() {
  return "Not enough units to buy.";
}
const char *Fund::NotEnoughCurrency::what() {
  return "Not enoughs currency to sell.";
}
