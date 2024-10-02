#include "system.hpp"

#include <iostream>

System::System(int month_count, double capitalization, double tax,
               double spread)
    : month_cnt(0), month_amount(month_count), tax(tax), fund(capitalization),
      market(spread) {}

int System::GetMonthCount() const { return month_cnt + 1; }
int System::GetMonthAmount() const { return month_amount; }
int System::GetMonthLeft() const { return month_amount - month_cnt; }

double System::GetCapitalization() const {
  return fund.GetCapitalization(market);
}
double System::GetAmount(Currency currency) const { return fund.GetAmount(currency); }

double System::GetBuyRate(Currency currency) const {
  return market.GetBuyRate(currency);
}
double System::GetSellRate(Currency currency) const {
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
    fund.Iterate();
    ++month_cnt;
  }
}
