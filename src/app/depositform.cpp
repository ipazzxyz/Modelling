#include "depositform.hpp"

DepositForm::DepositForm(GameWindow* gamewindow) : gamewindow(gamewindow) {
  ui.setupUi(this);
  connect(ui.confirm, &QPushButton::clicked, this, &DepositForm::Confirm);
}
DepositForm::DepositForm(double max, GameWindow* gamewindow)
    : gamewindow(gamewindow) {
  ui.setupUi(this);
  connect(ui.confirm, &QPushButton::clicked, this, &DepositForm::Confirm);
  ui.amount->setMaximum(max);
}

void DepositForm::Confirm() {
  gamewindow->Deposit(ui.month->value(), ui.amount->value());
  close();
}
