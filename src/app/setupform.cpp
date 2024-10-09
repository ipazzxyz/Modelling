#include "setupform.hpp"

SetupForm::SetupForm(GameWindow* gamewindow) : gamewindow(gamewindow) {
  ui.setupUi(this);
  connect(ui.start, &QPushButton::clicked, this, &SetupForm::Confirm);
}
void SetupForm::Confirm() {
  gamewindow->Setup(ui.month->value(), ui.capitalization->value(),
                   ui.tax->value(), ui.spread->value());
  close();
}
