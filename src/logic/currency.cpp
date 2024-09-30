#include "currency.hpp"

inline std::string ToString(Currency currency) {
  switch (currency) {
    case Currency::kDollar:
      return "Dollar";
    case Currency::kHamster:
      return "Hamster Coin";
    case Currency::kRuble:
      return "Ruble";
  }
  return "";
}