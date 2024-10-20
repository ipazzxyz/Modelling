#include "unique_bond.hpp"

UniqueBond::UniqueBond(const Bond &other, int amount_):
    amount(amount_), how_month(0), Bond(other) {}

int UniqueBond::GetAmount() const {
    return amount;
}

std::pair<int, double> UniqueBond::WhenIsThePayment() const {
    return {period - (how_month % period), true_cost * percent};
}

std::pair<int, double> UniqueBond::WhenIsTheEnd() const {
    return {life_span - how_month, true_cost};
}

bool UniqueBond::HasLeft() const {
    return life_span <= how_month;
}

void UniqueBond::Iterate(double spread, double tax, double rand_num, int month) {
    how_month++;
    if (how_month < 1 || how_month > life_span)
        throw std::out_of_range("облегаций уже не существует!");

    dividends = 0;
    if (how_month % period == 0)
        dividends += amount * true_cost * percent;
    if (how_month == life_span)
        dividends += amount *true_cost;
}