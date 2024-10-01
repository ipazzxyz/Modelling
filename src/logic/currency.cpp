#include "currency.hpp"

inline const char *ToString(Currency currency) {
  switch (currency) {
  case Currency::Hamster:
    return "Hamster Coin";
  case Currency::Ruble:
    return "Ruble";
  }
  return "";
}
