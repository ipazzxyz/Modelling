#pragma once

#include "currency.hpp"
#include "asset.hpp"
#include <map>
#include <random>
#include <ctime>

class Market {
public:
    Market(double spread);

    std::pair<double, double> GetBuyRate(Currency currency) const;

    std::pair<double, double> GetSellRate(Currency currency) const;

    double GetDividends(Currency currency) const;

    double GetDepositPercent() const;

    double GetRandNum();

    double GetSpread() const;

    const std::map<Currency, Asset> &GetAllCost() const;

    void Iterate();

    class DoesNotExistCurrency : public std::exception {
    public:
        const char *what();
    };

private:
    double spread;
    std::mt19937 rng;
    std::map<Currency, Asset> currency_exchange_rate;
    double deposit_percent;

};
