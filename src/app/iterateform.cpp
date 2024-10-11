#include "iterateform.hpp"

IterateForm::IterateForm(GameWindow* gamewindow) : gamewindow(gamewindow) {
  ui.setupUi(this);
  connect(ui.confirm, &QPushButton::clicked, this, &IterateForm::Confirm);
}
void IterateForm::Confirm() {
  gamewindow->Iterate(ui.amount->value());
  close();
}
