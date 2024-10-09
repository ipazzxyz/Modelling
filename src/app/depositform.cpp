#include "depositform.hpp"

DepositForm::DepositForm(GameWindow* gamewindow) : gamewindow(gamewindow) {
  ui.setupUi(this);
  connect(ui.confirm, &QPushButton::clicked, this, &DepositForm::Confirm);
}
void DepositForm::Confirm() {
  gamewindow->MakeDeposit(ui.month->value(),
                          ui.amount->value());
  close();
}
