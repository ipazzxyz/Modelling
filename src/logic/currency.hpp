#pragma once

#include <string>

enum class Currency { kDollar, kHamster, kRuble };

inline std::string ToString(Currency currency);