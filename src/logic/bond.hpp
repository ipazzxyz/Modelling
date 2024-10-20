#pragma once
#include "asset.hpp"

class Bond : public Asset {
public:
    Bond(double cost, double true_cost_, double percent_, int period_, int life_span_);
    double GetTrueCost() const;
    double GetPercent() const;
    int GetPeriod() const;
    int GetLifeSpan() const;
protected:
    double true_cost, percent;
    int period, life_span;
};