#include "currency.hpp"

std::string ToString(const Currency &currency) {
  switch (currency) {
    case Currency::Hamster:
      return "Hamster Coin";
    case Currency::Ruble:
      return "Ruble";
    case Currency::$TGR:
      return "$TGR";
    case Currency::Gold:
      return "Gold";
    case Currency::MemCoin:
      return "MemCoin";
    case Currency::SpaceY:
      return "SpaceY";
    case Currency::BerBank:
      return "BerBank";
    case Currency::DomikVDerevne:
      return "DomikVDerevne";
    case Currency::PineApple:
      return "PineApple";
    case Currency::__First:
      throw std::bad_exception();
    case Currency::__Last:
      throw std::bad_exception();
  }
  return "";
}
