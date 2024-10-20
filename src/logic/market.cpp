#include "market.hpp"

Market::Market(): rng(std::time(0)) {
    bonds.insert({Currency::DomikVDerevne, Bond(100, 100, 0.1, 4, 12)});
    bonds.insert({Currency::SpaceY, Bond(123, 123, 0.1, 4, 12)});
    stocks.insert({Currency::BerBank, Stock(123, 4)});
    stocks.insert({Currency::PineApple, Stock(200, 6)});
    assets.insert({Currency::Ruble, Asset(12)});
    assets.insert({Currency::$TGR, Asset(32)});
}

const std::map<Currency, Bond> &Market::GetAllBonds() const {
    return bonds;
}

const std::map<Currency, Stock> &Market::GetAllStocks() const {
    return stocks;
}

const std::map<Currency, Asset> &Market::GetAllAssets() const {
    return assets;
}

const Bond &Market::GetBond(Currency currency) const {
    if (!bonds.count(currency))
        throw std::out_of_range("");
    return bonds.at(currency);
}

double Market::GetBuyRateBond(Currency currency) const {
    if (!bonds.count(currency))
        throw std::out_of_range("");
    return bonds.at(currency).GetBuyRate();
}

const std::vector<std::pair<int, double>>& Market::GetGraphBond(Currency currency) const {
    if (!bonds.count(currency))
        throw std::out_of_range("");
    return bonds.at(currency).GetGraph();
}

double Market::GetTrueCostBond(Currency currency) const {
    if (!bonds.count(currency))
        throw std::out_of_range("");
    return bonds.at(currency).GetTrueCost();
}

double Market::GetPercentBond(Currency currency) const {
    if (!bonds.count(currency))
        throw std::out_of_range("");
    return bonds.at(currency).GetPercent();
}

int Market::GetPeriod(Currency currency) const {
    if (!bonds.count(currency))
        throw std::out_of_range("");
    return bonds.at(currency).GetPeriod();
}

int Market::GetLifeSpan(Currency currency) const {
    if (!bonds.count(currency))
        throw std::out_of_range("");
    return bonds.at(currency).GetLifeSpan();
}

double Market::GetBuyRateStock(Currency currency) const {
    if (!stocks.count(currency))
        throw std::out_of_range("");
    return stocks.at(currency).GetBuyRate();
}

double Market::GetSellRateStock(Currency currency) const {
    if (!stocks.count(currency))
        throw std::out_of_range("");
    return stocks.at(currency).GetSellRate();
}

double Market::GetDividendsStock(Currency currency) const {
    if (!stocks.count(currency))
        throw std::out_of_range("");
    return stocks.at(currency).GetDividends();
}

const std::vector<std::pair<int, double>> &Market::GetGraphStock(Currency currency) const {
    if (!stocks.count(currency))
        throw std::out_of_range("");
    return stocks.at(currency).GetGraph();
}

int Market::WhenIsThePaymentStock(Currency currency) const {
    if (!stocks.count(currency))
        throw std::out_of_range("");
    return stocks.at(currency).WhenIsThePayment();
}

double Market::GetBuyRateAsset(Currency currency) const {
    if (!assets.count(currency))
        throw std::out_of_range("");
    return assets.at(currency).GetBuyRate();
}

double Market::GetSellRateAsset(Currency currency) const {
    if (!assets.count(currency))
        throw std::out_of_range("");
    return assets.at(currency).GetSellRate();
}

const std::vector<std::pair<int, double>> &Market::GetGraphAsset(Currency currency) const {
    if (!assets.count(currency))
        throw std::out_of_range("");
    return assets.at(currency).GetGraph();
}

void Market::Iterate(double spread, double tax, int month) {
    for (auto& [currency, bond] : bonds)
        bond.Iterate(spread, tax, GetRandNum(), month);
    for (auto& [currency, stock] : stocks)
        stock.Iterate(spread, tax, GetRandNum(), month);
    for (auto& [currency, asset] : assets)
        asset.Iterate(spread, tax, GetRandNum(), month);
}

double Market::GetRandNum() {
    return static_cast<double>(rng()) / static_cast<double>(rng.max());
}