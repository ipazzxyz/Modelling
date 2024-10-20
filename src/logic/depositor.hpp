#pragma once

#include <string>

class Depositor {
public:
    Depositor(std::string name_, std::string surname_, int amount_);
    int GetAmountShare() const;
    std::pair<std::string, std::string> GetFullName() const;
    bool HasLeft() const;
    int Iterate(double prev_cost, double cost, double rand_num1, double rand_num2);
private:
    int amount;
    std::string name, surname;
};