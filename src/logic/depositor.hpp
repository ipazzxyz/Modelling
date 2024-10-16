#pragma once

#include <string>

class Depositor {
 public:
  double GetDeposit() const;
  std::string GetFullName() const;

  double SetDepositor(double deposit_amount, std::string name,
                      std::string surname);  // TODO: use constructor for this?

  bool HasLeft() const;

  double Iterate(double dividends, double rand_num, double spread);

 private:
  double deposit;
  double desired_dividends;
  std::string name, surname;
};
