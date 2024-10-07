#pragma once
#include <string>

class Depositor {
public:
    double SetDepositor(double rand_num, std::string name_, std::string surname);
    double Iterate(double dividends, double rand_num, double spread);
    double GetDeposit() const;
    std::pair<std::string, std::string> GetFullName() const;
    bool HasLeft() const;
private:
    double deposit, desired_dividends;
    std::string name, surname;
};

