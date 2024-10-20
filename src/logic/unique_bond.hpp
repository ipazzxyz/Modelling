#include "bond.hpp"

class UniqueBond final : public Bond {
public:
    UniqueBond(const Bond & other, int amount);
    int GetAmount() const;
    std::pair<int, double> WhenIsThePayment() const;
    std::pair<int, double> WhenIsTheEnd() const;
    bool HasLeft() const;
    void Iterate(double spread, double tax, double rand_num, int month) override final;
private:
    int amount, how_month;
};
