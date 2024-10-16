#include "fund.hpp"

Fund::Fund(double capitalization, int months_amount)
    : conventional_units(capitalization),
      capitalization(capitalization),
      delta_capitalization(0),
      deposit(months_amount + 1, 0),
      rng(std::time(nullptr)),
      names{"Егор",    "Konstantin", "Damir", "Maksim", "Nikita",
            "Leonard", "Федор",      "Polin", "Arsen",  "Mikhail"},
      surnames{"Osipov", "Yusupov", "Tursunov", "Alimov", "Saidov",
               "Alimov", "Yunusov", "ТрифонОв", "Kan",    "Ivanov"} {}

double Fund::GetConventionalUnits() const { return conventional_units; }

double Fund::GetAmount(Currency currency) const {
  if (!currency_amount.count(currency)) {
    return 0;
  }
  return currency_amount.at(currency);
}

double Fund::GetCapitalization() const { return capitalization; }

double Fund::GetDeltaCapitalization() const { return delta_capitalization; }

const std::vector<Depositor> &Fund::GetAllDepositors() const {
  return depositors;
}

std::vector<std::pair<int, double>> Fund::GetDeposit(int month_count) const {
  std::vector<std::pair<int, double>> res;
  for (int i = month_count + 1; i < deposit.size(); i++)
    if (deposit[i] != 0) res.push_back({i - month_count, deposit[i]});

  return res;
}

double Fund::GetRandNum() {
  return static_cast<double>(rng()) / static_cast<double>(rng.max());
}

void Fund::Buy(const Market &market, Currency currency, double amount) {
  double price = amount * market.GetBuyRate(currency).first;

  if (conventional_units < price) {
    throw NotEnoughConventionalUnitsToBuy();
  }
  conventional_units -= price;

  capitalization += market.GetSellRate(currency).first * amount - price;
  delta_capitalization += market.GetSellRate(currency).first * amount - price;

  currency_amount[currency] += amount;
}

void Fund::Sell(const Market &market, Currency currency, double amount) {
  if (GetAmount(currency) < amount) {
    throw NotEnoughCurrencyToSell();
  }
  conventional_units += amount * market.GetSellRate(currency).first;
  currency_amount[currency] -= amount;
}

void Fund::MakeDeposit(const Market &market, double deposit_money, int month,
                       int duration) {
  if (GetConventionalUnits() < deposit_money) {
    throw NotEnoughConventionalUnitsToMakeDeposit();
  }

  conventional_units -= deposit_money;
  capitalization -= deposit_money;
  delta_capitalization -= deposit_money;

  deposit[month] +=
      deposit_money * std::pow(market.GetDepositPercent() + 1, duration);
}

void Fund::Iterate(const Market &market, int month, double tax,
                   double dividends) {
  delta_capitalization = -capitalization;

  capitalization = 0;

  for (auto [currency, amount] : currency_amount) {
    capitalization += market.GetSellRate(currency).first * amount;
    conventional_units += market.GetDividends(currency) * amount;
  }

  double out_come = 0;
  for (auto& depositor : depositors)
      out_come += depositor.GetDeposit();

  out_come *= dividends / 100;
  if (out_come > conventional_units)
      throw NotEnoughConventionalUnitsToIterate();

  std::vector<Depositor> newDepositors;

  for (auto& depositor : depositors) {
    conventional_units +=
        depositor.Iterate(dividends, GetRandNum(), market.GetSpread());
    if (!depositor.HasLeft()) {
      newDepositors.push_back(depositor);
    }
  }

  depositors = newDepositors;

  conventional_units += deposit[month];
  capitalization += conventional_units;
  delta_capitalization += capitalization;

  if (delta_capitalization > 0) {
    int cntNewDepositors =
        delta_capitalization * 88.0 / capitalization * GetRandNum();
    for (int i = 0; i < cntNewDepositors; i++) {
      Depositor newDepositor;
      double depositor_money =
          newDepositor.SetDepositor(GetRandNum(), GenName(), GenSurname());

      conventional_units += depositor_money;
      capitalization += depositor_money;
      delta_capitalization += depositor_money;

      depositors.push_back(newDepositor);
    }
  }

  if (delta_capitalization > 0) {
    conventional_units -= delta_capitalization * tax;
    capitalization -= delta_capitalization * tax;
    delta_capitalization -= delta_capitalization * tax;
  }

  if (conventional_units < 0) {
      conventional_units = 0;
      throw NotEnoughConventionalUnitsToIterate();
  }
}

std::string Fund::GenName() {
  int k = rng() % names.size();
  return names[k];
}

std::string Fund::GenSurname() {
  int k = rng() % surnames.size();
  return surnames[k];
}

const char *Fund::NotEnoughConventionalUnitsToBuy::what() const noexcept {
  return "Not enough units to buy.";
}

const char *Fund::NotEnoughConventionalUnitsToMakeDeposit::what()
    const noexcept {
  return "Not enough units to make deposit.";
}

const char *Fund::NotEnoughCurrencyToSell::what() const noexcept {
  return "Not enoughs currency to sell.";
}

const char *Fund::NotEnoughConventionalUnitsToIterate::what() const noexcept {
  return "Not enoughs currency to iterate.";
}