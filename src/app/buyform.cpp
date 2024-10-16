#include "buyform.hpp"

BuyForm::BuyForm(GameWindow* gamewindow) : gamewindow(gamewindow) {
  ui.setupUi(this);
  connect(ui.confirm, &QPushButton::clicked, this, &BuyForm::Confirm);
}
BuyForm::BuyForm(QString str, double max, GameWindow* gamewindow)
    : gamewindow(gamewindow) {
  ui.setupUi(this);
  connect(ui.confirm, &QPushButton::clicked, this, &BuyForm::Confirm);
  ui.__->setText("Купить " + str);
  ui.amount->setMaximum(max);
}
void BuyForm::Confirm() {
  gamewindow->Buy(ui.amount->value());
  close();
}
