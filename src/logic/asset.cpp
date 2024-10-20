#include "asset.hpp"

Asset::Asset(double cost_) : cost(cost_), graph{{1, cost}} {}


double Asset::GetBuyRate() const {
    return cost * 1.1;
}

double Asset::GetSellRate() const {
    return cost;
}

const std::vector<std::pair<int, double>> &Asset::GetGraph() const {
    return graph;
}

double Asset::GetDividends() const {
    return dividends;
}

void Asset::Iterate(double spread, double tax, double rand_num, int month) {
    cost = cost * (2. * spread * rand_num - spread + 1.);
    graph.emplace_back(month, cost);
}