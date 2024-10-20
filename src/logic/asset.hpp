#pragma once
#include <string>
#include <vector>

class Asset {
public:
    Asset(double cost_);
    double GetBuyRate() const;
    double GetSellRate() const;
    const std::vector<std::pair<int, double>>& GetGraph() const;
    double GetDividends() const;
    virtual void Iterate(double spread, double tax, double rand_num, int month);
protected:
    double cost, dividends;
    std::vector<std::pair<int, double>> graph;
};