#include "gamewindow.hpp"

GameWindow::GameWindow() {
  ui.setupUi(this);
  connect(ui.next, &QPushButton::clicked, this, &GameWindow::next);
}
void GameWindow::next() { system->Iterate(); }
void GameWindow::setup() {
  system = new System(month_cnt, capitalization, tax, spread);
}
