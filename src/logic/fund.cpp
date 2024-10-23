#include "fund.hpp"

Fund::Fund(double conventional_units_, int amount_month):
    conventional_units(conventional_units_), capitalization(0),
    prev_cost_share(10000), amount_share(0), rng(std::time(0)),
    deposits(amount_month + 1, 0) {}

double Fund::GetCapitalization() const {
    return capitalization + conventional_units;
}

double Fund::GetConventionalUnits() const {
    return conventional_units;
}

int Fund::GetAmountShare() const {
    return amount_share;
}

const std::vector<Depositor> &Fund::GetDepositors() const {
    return depositors;
}

const std::vector<UniqueBond> &Fund::GetBonds() const {
    return bonds;
}

int Fund::GetStockAmount(Currency currency) const {
    if (!stocks.count(currency))
        return 0;
    return stocks.at(currency);
}

double Fund::GetAssetAmount(Currency currency) const {
    if (!assets.count(currency))
        return 0;
    return assets.at(currency);
}

std::vector<std::pair<int, double>> Fund::GetDeposit(int month) const {
    std::vector<std::pair<int, double>> res;
    for (int i = month + 1; i < deposits.size(); i++)
        if (deposits[i] != 0)
            res.push_back({i - month, deposits[i]});
    return res;
}

void Fund::MakeDeposit(const Market &market, double deposit, int term, int month) {
    if (deposit > conventional_units)
        throw NotEnoughConventionalUnits();
    if (month + term >= deposits.size())
        throw UnreachableDeposit();
    conventional_units -= deposit;
    deposits[month + term] = deposit * std::pow(market.GetDepositPercent() + 1, term);
}

void Fund::BuyBond(const Market &market, Currency currency, int amount) {
    double price = amount * market.GetBuyRateBond(currency);
    if (price > conventional_units)
        throw NotEnoughConventionalUnits();
    conventional_units -= price;
    bonds.emplace_back(market.GetBond(currency), amount);
    capitalization += amount * market.GetTrueCostBond(currency);
}

void Fund::BuyStock(const Market &market, Currency currency, int amount) {
    double price = amount * market.GetBuyRateStock(currency);
    if (price > conventional_units)
        throw NotEnoughConventionalUnits();
    conventional_units -= price;
    stocks[currency] += amount;
    capitalization += amount * market.GetSellRateStock(currency);
}

void Fund::BuyAsset(const Market &market, Currency currency, double amount) {
    double price = amount * market.GetBuyRateAsset(currency);
    if (price > conventional_units)
        throw NotEnoughConventionalUnits();
    conventional_units -= price;
    assets[currency] += amount;
    capitalization += amount * market.GetSellRateAsset(currency);
}

void Fund::SellStock(const Market &market, Currency currency, int amount) {
    if (amount > GetStockAmount(currency))
        throw NotEnoughStockToSell();
    conventional_units += amount * market.GetSellRateStock(currency);
    stocks[currency] -= amount;
    capitalization -= amount * market.GetSellRateStock(currency);
}

void Fund::SellAsset(const Market &market, Currency currency, double amount) {
    if (amount > GetAssetAmount(currency))
        throw NotEnoughAssetToSell();
    conventional_units += amount * market.GetSellRateAsset(currency);
    assets[currency] -= amount;
    capitalization -= amount * market.GetSellRateAsset(currency);
}

void Fund::Iterate(const Market& market, double spread, double tax, int month) {
    capitalization = 0;

    for (auto& [currency, amount] : assets)
        capitalization += amount * market.GetSellRateAsset(currency);

    for (auto& [currency, amount] : stocks) {
        capitalization += amount * market.GetSellRateStock(currency);
        conventional_units += amount * market.GetDividendsStock(currency);
    }

    std::vector<UniqueBond> new_bonds;

    for (auto& bond : bonds) {
        bond.Iterate(spread, tax, GetRandNum(), month);
        conventional_units += bond.GetDividends();
        if (!bond.HasLeft()) {
            capitalization += bond.GetTrueCost();
            new_bonds.emplace_back(std::move(bond));
        }
    }
    bonds = new_bonds;

    double cost_share = GetCapitalization() / static_cast<double>(amount_share + 1);

    std::vector<Depositor> new_depositors;

    for (auto& depositor : depositors) {
        int delta_amount_share = depositor.Iterate(prev_cost_share, cost_share, GetRandNum(), GetRandNum());
        amount_share += delta_amount_share;

        double delta_conventional_units = static_cast<double>(delta_amount_share) * cost_share;
        conventional_units += delta_conventional_units;

        if (conventional_units < 0)
            throw NotEnoughConventionalUnitsToIterate();

        if (!depositor.HasLeft())
            new_depositors.emplace_back(std::move(depositor));
    }
    depositors = new_depositors;
    prev_cost_share = cost_share;

    GenNewDepositors(0.5 + (cost_share - prev_cost_share) / (2. * prev_cost_share));
}

void Fund::GenNewDepositors(double chance) {
    double rand_num1 = GetRandNum(), rand_num2 = GetRandNum();
    if (rand_num1 <= chance) {
        int amount_new_depositors = ceil(rand_num2 * static_cast<double>(depositors.size()) / 2.);
        for (int i = 0; i < amount_new_depositors; i++) {
            int delta_amount_share = GetRandNum() * 10;
            depositors.emplace_back(GenName(), GenSurname(), delta_amount_share);
            amount_share += delta_amount_share;
            conventional_units += prev_cost_share * delta_amount_share;
        }
    }
}

std::string Fund::GenName() {
    return "Егор";
}

std::string Fund::GenSurname() {
    return "Трифонов";
}

double Fund::GetRandNum() {
    return static_cast<double>(rng()) / static_cast<double>(rng.max());
}

const char *Fund::NotEnoughConventionalUnits::what() const noexcept {
    return "Недостаточно свободной валюты";
}

const char *Fund::NotEnoughConventionalUnitsToIterate::what() const noexcept {
    return "Недостаточно свободной валюты для итерации";
}

const char *Fund::NotEnoughStockToSell::what() const noexcept {
    return "Недостаточно акций, чтобы продать";
}

const char *Fund::NotEnoughAssetToSell::what() const noexcept {
    return "Недостаточно активов, чтобы продать";
}

const char *Fund::UnreachableDeposit::what() const noexcept {
    return "Сделан вклад на недостижимый месяц";
}