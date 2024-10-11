#pragma once
#include <exception>
#include <string>

const int CurrencySize = 9; // Do not count __First & __Last

enum class Currency {
  __First,
  Hamster,
  Ruble,
  $TGR,
  Gold,
  MemCoin,
  SpaceY,
  BerBank,
  DomikVDerevne,
  PineApple,
  __Last
};

std::string ToString(const Currency &currency);