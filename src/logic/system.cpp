
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