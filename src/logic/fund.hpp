#pragma once

#include <ctime>
#include <random>
#include <map>
#include "currency.hpp"
#include "asset.hpp"
#include "bond.hpp"
#include "stock.hpp"
#include "depositor.hpp"
#include "market.hpp"

class Fund {
public:
    Fund(double conventional_units_, int amount_month);
    double GetCapitalization() const;
    double GetConventionalUnits() const;
    int GetAmountShare() const;
    const std::vector<Depositor>& GetDepositors() const;
    const std::vector<UniqueBond>& GetBonds() const;
    int GetStockAmount(Currency currency) const;
    double GetAssetAmount(Currency currency) const;
    std::vector<std::pair<int, double>> GetDeposit(int month) const;
    void MakeDeposit(const Market& market, double deposit, int term, int month);
    void BuyBond(const Market& market, Currency currency, int amount);
    void BuyStock(const Market& market, Currency currency, int amount);
    void BuyAsset(const Market& market, Currency currency, double amount);
    void SellStock(const Market& market, Currency currency, int amount);
    void SellAsset(const Market& market, Currency currency, double amount);
    void Iterate(const Market& market, double spread, double tax, int month);

    class NotEnoughConventionalUnits: public std::exception {
    public:
        const char *what() const noexcept;
    };

    class NotEnoughConventionalUnitsToIterate: public std::exception {
    public:
        const char *what() const noexcept;
    };

    class NotEnoughStockToSell: public std::exception {
    public:
        const char *what() const noexcept;
    };


    class NotEnoughAssetToSell: public std::exception {
    public:
        const char *what() const noexcept;
    };

    class UnreachableDeposit : public std::exception {
        const char *what() const noexcept;
    };
private:
    void GenNewDepositors(double chance);
    std::string GenName();
    std::string GenSurname();
    double GetRandNum();
    double capitalization, conventional_units, prev_cost_share;
    int amount_share;
    std::vector<Depositor> depositors;
    std::vector<UniqueBond> bonds;
    std::map<Currency, int> stocks;
    std::map<Currency, double> assets;
    std::vector<double> deposits;
    std::mt19937 rng;
};