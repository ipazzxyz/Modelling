#include "depositor.hpp"

double Depositor::GetDeposit() const { return deposit; }
std::string Depositor::GetFullName() const { return name + ' ' + surname; }
bool Depositor::HasLeft() const { return deposit <= 0; }

double Depositor::SetDepositor(double rand_num, std::string name_,
                               std::string surname_) {
  deposit = rand_num * 100.;
  desired_dividends = deposit * rand_num / 8;
  name = std::move(name_);
  surname = std::move(surname_);
  return deposit;
}

double Depositor::Iterate(double dividends, double rand_num, double spread) {
  dividends *= deposit / 100.;
  double lastDeposit = deposit;
  if (dividends > desired_dividends) {
    deposit += 2 * desired_dividends * rand_num * spread -
               spread * desired_dividends * 0.7;
  } else {
    deposit -= rand_num * (desired_dividends - dividends) + deposit * rand_num;
  }
  if (deposit < 1) deposit = 0;
  desired_dividends = (deposit / 12) * (rand_num + 0.2);
  return deposit - lastDeposit - dividends;
}
