#include "setupform.hpp"

SetupForm::SetupForm(GameWindow &gamewindow) : gamewindow(gamewindow) {
  ui.setupUi(this);
  connect(ui.start, &QPushButton::clicked, this, &SetupForm::start);
}
void SetupForm::start() {
  gamewindow.month_cnt = ui.month->value();
  gamewindow.capitalization = ui.capitalization->value();
  gamewindow.tax = ui.tax->value();
  gamewindow.spread = ui.spread->value();
  gamewindow.setup();
  gamewindow.show();
  close();
}
