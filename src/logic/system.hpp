#pragma once

#include "fund.hpp"

class System {
public:
    System(int month_amount, double capitalization, double tax, double spread);

    int GetMonthCount() const;

    int GetMonthAmount() const;

    double GetConventionalUnits() const;

    double GetCapitalization() const;

    double GetDeltaCapitalization() const;

    double GetAmount(Currency currency) const;

    std::vector<std::pair<int, double>> GetDeposit() const;

    std::pair<double, double> GetBuyRate(Currency currency) const;

    std::pair<double, double> GetSellRate(Currency currency) const;

    const std::map<Currency, Asset> &GetAllCost() const;

    const std::vector<Depositor> &GetAllDepositors() const;

    void Buy(Currency currency, double amount);

    void Sell(Currency currency, double amount);

    void MakeDeposit(double sumDeposit, int month);

    void Iterate(double dividend);

    class IterationBeyondTheTimeLimit : public std::exception {
        const char *what();
    };

    class UnreachableDeposit : public std::exception {
        const char *what();
    };

private:
    int month_amount;
    double tax;

    Fund fund;
    Market market;

    int month_cnt;
};
