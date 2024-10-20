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
    int GetStockAmount() const;
    int GetAssetAmount() const;
    int GetAmountShare() const;
    void BuyBond(int amount);
    void BuyStock(int amount);
    void BuyAsset(double amount);
    void SellStock(int amount);
    void SellAsset(double amount);
    void Iterate();
private:
    int month, amount_month;
    double spread, tax;
    Fund fund;
    Market market;
};