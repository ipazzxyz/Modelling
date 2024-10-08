#include "currency.hpp"


std::string ToString(const Currency &currency) {
    switch (currency) {
        case Currency::Hamster:
            return "Hamster Coin";
        case Currency::Ruble:
            return "Ruble";
        case Currency::__First:
            throw std::bad_exception();
        case Currency::__Last:
            throw std::bad_exception();
    }
    return "";
}
