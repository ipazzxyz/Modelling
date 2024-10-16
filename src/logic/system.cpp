#include "system.hpp"


System::System(int month_count, double capitalization, double tax,
               double spread)
        : month_cnt(1), month_amount(month_count), tax(tax), fund(capitalization, month_count),
          market(spread) {}

int System::GetMonthCount() const {
    return month_cnt;
}

int System::GetMonthAmount() const {
    return month_amount;
}

double System::GetCapitalization() const {
    return fund.GetCapitalization();
}

double System::GetDeltaCapitalization() const {
    return fund.GetDeltaCapitalization();
}

double System::GetConventionalUnits() const {
    return fund.GetConventionalUnits();
}

double System::GetAmount(Currency currency) const {
    return fund.GetAmount(currency);
}

std::pair<double, double> System::GetBuyRate(Currency currency) const {
    return market.GetBuyRate(currency);
}

std::pair<double, double> System::GetSellRate(Currency currency) const {
    return market.GetSellRate(currency);
}

std::vector<std::pair<int, double>> System::GetDeposit() const {
    return fund.GetDeposit(month_cnt);
}

void System::Buy(Currency currency, double amount) {
    fund.Buy(market, currency, amount);
}

void System::Sell(Currency currency, double amount) {
    fund.Sell(market, currency, amount);
}

void System::MakeDeposit(double sumDeposit, int duration) {
    if (duration + month_cnt > month_amount) {
        throw UnreachableDeposit();
    }

    fund.MakeDeposit(market, sumDeposit, duration + month_cnt, duration);
}

void System::Iterate(double dividend) {
    if (month_cnt >= month_amount) {
        throw IterationBeyondTheTimeLimit();
    }
    if (month_cnt < month_amount) {
        market.Iterate();
        fund.Iterate(market, month_cnt, tax, dividend);
        ++month_cnt;
    }
}

const std::map<Currency, Asset> &System::GetAllCost() const {
    return market.GetAllCost();
}

const std::vector<Depositor> &System::GetAllDepositors() const {
    return fund.GetAllDepositors();
}

const char *System::IterationBeyondTheTimeLimit::what() {
    return "Iteration beyond the time limit.";
}

const char *System::UnreachableDeposit::what() {
    return "Unreachable deposit.";
}