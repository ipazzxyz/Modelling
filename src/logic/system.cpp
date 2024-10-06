#include "system.hpp"

#include <iostream>

System::System(int month_count, double capitalization, double tax,
               double spread)
    : month_cnt(1), month_amount(month_count), tax(tax), fund(capitalization, month_count),
      market(spread, month_count) {}

int System::GetMonthCount() const {
    return month_cnt;
}

int System::GetMonthAmount() const {
    return month_amount;
}

double System::GetCapitalization() const {
  return fund.GetCapitalization();
}

double System::GetConventionalUnits() const {
    return fund.GetConventionalUnits();
}

double System::GetAmount(Currency currency) const {
    return fund.GetAmount(currency);
}

std::pair<double, double> System::GetBuyRate(Currency currency) const {
  return market.GetBuyRate(currency);
}

std::pair<double, double> System::GetSellRate(Currency currency) const {
  return market.GetSellRate(currency);
}

void System::Buy(Currency currency, int amount) {
    fund.Buy(market, currency, amount);
}
void System::Sell(Currency currency, int amount) {
    fund.Sell(market, currency, amount);
}

void System::MakeDeposit(double sumDeposit, int month) {
    if (month + month_cnt > month_amount) {
        throw std::out_of_range("слишком далеко ваш депозит зашел");
    }

    fund.MakeDeposit(market, sumDeposit, month + month_cnt);
}

void System::Iterate() {
  if (month_cnt < month_amount) {
    market.Iterate();
    fund.Iterate(market, month_cnt, tax);
    ++month_cnt;
    // TODO: Вычет налога
    // TODO: Выплата вкладчикам (если можем)
    // TODO: Новые вкладчики
  }
}
std::vector<std::pair<std::string, Asset>> System::GetAllCost() const {
    return market.GetAllCost();
}
