#pragma once
#include <string>

enum class Currency { __First, Hamster, Ruble, __Last};


std::string ToString(const Currency &currency);