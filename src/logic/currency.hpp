#pragma once
#include <exception>
#include <string>

enum class Currency {
    __First, Hamster, Ruble, $TGR, Gold, MemCoin, SpaceY, BerBank, DomikVDerevne, PineApple, __Last
};


std::string ToString(const Currency &currency);