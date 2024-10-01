#include "system.hpp"

#include <iostream>

System::System(int month_count, double capitalization, double tax,
               double spread)
    : month_amount(month_count), tax(tax), fund(capitalization),
      market(spread) {}

Fund System::GetFund() const { return fund; }
Market System::GetMarket() const { return market; }

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
  market.Iterate();
  fund.Iterate();
}
