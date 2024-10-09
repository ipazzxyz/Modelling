#include "sellform.hpp"

SellForm::SellForm(GameWindow* gamewindow) : gamewindow(gamewindow) {
  ui.setupUi(this);
  connect(ui.confirm, &QPushButton::clicked, this, &SellForm::Confirm);
}
void SellForm::Confirm() {
  gamewindow->Sell(ui.amount->value());
  close();
}
