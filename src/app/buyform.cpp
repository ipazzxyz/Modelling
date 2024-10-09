#include "buyform.hpp"

BuyForm::BuyForm(GameWindow* gamewindow) : gamewindow(gamewindow) {
  ui.setupUi(this);
  connect(ui.confirm, &QPushButton::clicked, this, &BuyForm::Confirm);
}
void BuyForm::Confirm() {
  gamewindow->Buy(ui.amount->value());
  close();
}
