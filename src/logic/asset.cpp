#include "asset.hpp"

std::pair<double, double> Asset::GetBuyRate() const {
  return {cost * 1.1, delta_cost * 1.1};
}
std::pair<double, double> Asset::GetSellRate() const {
  return {cost, delta_cost};
}
double Asset::GetDividends() const { return cost * percent; }

void Asset::SetAsset(double cost_, double percent_) {
  cost = cost_;
  percent = percent_;
}

void Asset::Iterate(double rand_num, double spread) {
  delta_cost = -cost;
  delta_cost += cost *= 2 * spread * rand_num - spread + 1;
}
