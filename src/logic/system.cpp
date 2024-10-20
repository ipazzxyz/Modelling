
#include "system.hpp"

System::System(double spread_, double tax_, double conventional_units_, int amount_month_): fund(conventional_units_),
    market(), spread(spread_), tax(tax_), amount_month(amount_month_), month(1) {}

const std::map<Currency, Bond> &System::GetAllBonds() const {
    return market.GetAllBonds();
}

const std::map<Currency, Stock> &System::GetAllStocks() const {
    return market.GetAllStocks();
}

const std::map<Currency, Asset> &System::GetAllAssets() const {
    return market.GetAllAssets();
}

const std::vector<UniqueBond> &System::GetAllYourBonds() const {
    return fund.GetBonds();
}

const std::vector<Depositor> &System::GetAllYourDepositors() const {
    return fund.GetDepositors();
}

int System::GetStockAmount(Currency currency) const {
    return fund.GetStockAmount(currency);
}

int System::GetAssetAmount(Currency currency) const {
    return fund.GetAssetAmount(currency);
}

int System::GetAmountShare(Currency currency) const {
    return fund.GetAmountShare();
}

void System::BuyBond(Currency currency, int amount) {
    fund.BuyBond(market, currency, amount);
}

void System::BuyStock(Currency currency, int amount) {
    fund.BuyStock(market, currency, amount);
}

void System::BuyAsset(Currency currency, double amount) {
    fund.BuyAsset(market, currency, amount);
}

void System::SellStock(Currency currency, int amount) {
    fund.SellStock(market, currency, amount);
}

void System::SellAsset(Currency currency, double amount) {
    fund.SellAsset(market, currency, amount);
}

void System::Iterate() {
    if (++month > amount_month)
        throw std::out_of_range("");

    market.Iterate(spread, tax, month);
    fund.Iterate(market, spread, tax, month);
}