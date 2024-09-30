#include "market.hpp"

Market::Market(double spread) : spread_(spread) {}

double Market::operator[](Currency currency) {
  return currency_exchange_rate_[currency];
}