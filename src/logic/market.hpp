#pragma once

#include <ctime>
#include <random>
#include <map>
#include "currency.hpp"
#include "asset.hpp"
#include "bond.hpp"
#include "unique_bond.hpp"
#include "stock.hpp"
#include "depositor.hpp"

class Market {
public:
    Market();
    const std::map<Currency, Bond>& GetAllBonds() const;
    const std::map<Currency, Stock>& GetAllStocks() const;
    const std::map<Currency, Asset>& GetAllAssets() const;
    double GetDepositPercent() const;
    const Bond& GetBond(Currency currency) const;
    double GetBuyRateBond(Currency currency) const;
    const std::vector<std::pair<int, double>>& GetGraphBond(Currency currency) const;
    double GetTrueCostBond(Currency currency) const;
    double GetPercentBond(Currency currency) const;
    int GetPeriod(Currency currency) const;
    int GetLifeSpan(Currency currency) const;
    double GetBuyRateStock(Currency currency) const;
    double GetSellRateStock(Currency currency) const;
    double GetDividendsStock(Currency currency) const;
    const std::vector<std::pair<int, double>>& GetGraphStock(Currency currency) const;
    int WhenIsThePaymentStock(Currency currency) const;
    double GetBuyRateAsset(Currency currency) const;
    double GetSellRateAsset(Currency currency) const;
    const std::vector<std::pair<int, double>>& GetGraphAsset(Currency currency) const;
    void Iterate(double spread, double tax, int month);

    class DoesNotExistBond: public std::exception {
    public:
        const char *what() const noexcept;
    };
    class DoesNotExistStock: public std::exception {
    public:
        const char *what() const noexcept;
    };
    class DoesNotExistAsset: public std::exception {
    public:
        const char *what() const noexcept;
    };
private:
    double GetRandNum();
    int percent;
    std::map<Currency, Bond> bonds;
    std::map<Currency, Stock> stocks;
    std::map<Currency, Asset> assets;
    std::mt19937 rng;
};