#include "sellform.hpp"

SellForm::SellForm(GameWindow* gamewindow) : gamewindow(gamewindow) {
  ui.setupUi(this);
  connect(ui.confirm, &QPushButton::clicked, this, &SellForm::Confirm);
}
SellForm::SellForm(QString str, double max, GameWindow* gamewindow)
    : gamewindow(gamewindow) {
  ui.setupUi(this);
  connect(ui.confirm, &QPushButton::clicked, this, &SellForm::Confirm);
  ui.label->setText("Продать " + str);
  ui.amount->setMaximum(max);
}
void SellForm::Confirm() {
  gamewindow->Sell(ui.amount->value());
  close();
}
