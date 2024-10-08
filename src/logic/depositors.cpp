#include "depositors.hpp"

double Depositor::GetDeposit() const {
    return deposit;
}

std::pair<std::string, std::string> Depositor::GetFullName() const {
    return {name, surname};
}

bool Depositor::HasLeft() const {
    return deposit <= 0;
}

double Depositor::SetDepositor(double rand_num, std::string name_, std::string surname_) {
    deposit = rand_num * 100.0;
    desired_dividends = deposit * rand_num / 8;

    name = std::move(name_);
    surname = std::move(surname_);

    return deposit;
}

double Depositor::Iterate(double dividends, double rand_num, double spread) {
    dividends *= deposit / 100.0;

    double lastDeposit = deposit;

    if (dividends > desired_dividends) {
        deposit += dividends * rand_num + deposit * spread * rand_num + deposit * rand_num * (dividends - desired_dividends) / desired_dividends;
    }
    else {
        deposit += dividends * (rand_num - spread) - dividends;
    }

    desired_dividends = (deposit / 12) * rand_num;

    if (deposit < 0) deposit = 0;

    return deposit - lastDeposit - dividends;
}
