#pragma once

#include "fund.hpp"
#include "market.hpp"

class System {
 public:
  System(int month_count, double capitalization, double tax, double spread);

  void Buy(Currency amount);
  void Sell(Currency amount);

  void NextMonth();

 private:
  int month_count_;
  double tax_;

  Fund fund_;
  Market market_;

  int current_month_;
};