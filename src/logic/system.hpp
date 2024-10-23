#pragma once

#include "fund.hpp"
#include "market.hpp"

class System {
public:
    System(double spread_, double tax_, double conventional_units_, int amount_month_);
    const std::map<Currency, Bond>& GetAllBonds() const;
    const std::map<Currency, Stock>& GetAllStocks() const;
    const std::map<Currency, Asset>& GetAllAssets() const;
    const std::vector<UniqueBond>& GetAllYourBonds() const;
    const std::vector<Depositor>& GetAllYourDepositors() const;
    double GetConventionalUnits() const;
    double GetCapitalization() const;
    int GetStockAmount(Currency currency) const;
    int GetAssetAmount(Currency currency) const;
    int GetAmountShare(Currency currency) const;
    void MakeDeposit(double deposit, int term);
    void BuyBond(Currency currency, int amount);
    void BuyStock(Currency currency, int amount);
    void BuyAsset(Currency currency, double amount);
    void SellStock(Currency currency, int amount);
    void SellAsset(Currency currency, double amount);
    void Iterate();

    class IterationReachLimit : public std::exception {
        const char *what() const noexcept;
    };
private:
    int month, amount_month;
    double spread, tax;
    Fund fund;
    Market market;
};