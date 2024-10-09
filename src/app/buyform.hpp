#pragma once

#include "gamewindow.hpp"
#include "ui_buyform.h"

class BuyForm : public QWidget {
  Q_OBJECT

 public:
  BuyForm(GameWindow* gamewindow);

 private slots:
  void Confirm();

 private:
  Ui::BuyForm ui;
  GameWindow* gamewindow;
};
