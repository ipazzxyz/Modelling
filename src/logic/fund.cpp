#include "fund.hpp"

const char* Fund::NotEnoughMoney::what() { return "Not enough money to buy"; }

Fund::Fund(double capitalization) {
  currency_amount_[Currency::kDollar] = capitalization;
}

double Fund::GetCapitalization(Market& market) const {
  double capitalization = 0;
  for (std::pair<const Currency, int> i : currency_amount_) {
    capitalization += i.second * market[i.first];
  }
  return capitalization;
}