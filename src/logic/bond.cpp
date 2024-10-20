#include "bond.hpp"

Bond::Bond(double cost_, double true_cost_, double percent_, int period_, int life_span_): Asset(cost_),
    true_cost(true_cost_), percent(percent_), period(period_), life_span(life_span_) {}

double Bond::GetTrueCost() const {
    return true_cost;
}

double Bond::GetPercent() const {
    return percent;
}

int Bond::GetPeriod() const {
    return period;
}

int Bond::GetLifeSpan() const {
    return life_span;
}