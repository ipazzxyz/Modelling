#include "system.hpp"

#include <iostream>

System::System(int month_count, double capitalization, double tax,
               double spread)
    : month_cnt(0), month_amount(month_count), tax(tax), fund(capitalization, month_count),
      market(spread, month_count) {}

int System::GetMonthCount() const { return month_cnt + 1; }
int System::GetMonthAmount() const { return month_amount; }
int System::GetMonthLeft() const { return month_amount - month_cnt; }

double System::GetCapitalization() const {
  return fund.GetCapitalization(market);
}

double System::GetConventionalUnits() const {
    return fund.GetConventionalUnits();
}

double System::GetAmount(Currency currency) const { return fund.GetAmount(currency); }

std::pair<double, double> System::GetBuyRate(Currency currency) const {
  return market.GetBuyRate(currency);
}
std::pair<double, double> System::GetSellRate(Currency currency) const {
  return market.GetSellRate(currency);
}



void System::Buy(Currency currency, double amount) {
  try {
    fund.Buy(market, currency, amount);
  } catch (std::exception &exception) {
    std::cout << exception.what() << std::endl;
  }
}
void System::Sell(Currency currency, double amount) {
  fund.Sell(market, currency, amount);
}

void System::Iterate() {
  if (month_cnt < month_amount) {
    market.Iterate();
    fund.Iterate(market);
    ++month_cnt;
    // TODO: Начисление девидентов
    // TODO: Проверка окончания срока депозита
    // TODO: Пересчёт капитализации (прошлое +- изменение)
    // TODO: Вычет налога
    // TODO: Выплата вкладчикам (если можем)
    // TODO: Новые вкладчики
  }
}

std::vector<std::pair<std::string, Asset>> System::GetAllCost() const {
    return market.GetAllCost();
}
