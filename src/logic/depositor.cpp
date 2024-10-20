#include "depositor.hpp"

Depositor::Depositor(std::string name_, std::string surname_, int amount_):
    amount(amount_), name(std::move(name_)), surname(std::move(surname_)) {}

int Depositor::GetAmountShare() const {
    return amount;
}

std::pair<std::string, std::string> Depositor::GetFullName() const {
    return {name, surname};
}

bool Depositor::HasLeft() const {
    return amount <= 0;
}

int Depositor::Iterate(double prev_cost, double cost, double rand_num1, double rand_num2) {
    int prev_amount = amount;
    double chance = 0.5 + (cost - prev_cost) / (2. * cost);
    if (rand_num1 <= chance) {
        amount = ceil((1. + rand_num2) * static_cast<double>(amount));
    }
    else {
        amount = ceil((1. - rand_num2) * static_cast<double>(amount));
    }
    return amount - prev_amount;
}