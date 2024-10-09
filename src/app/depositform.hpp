#pragma once

#include "gamewindow.hpp"
#include "ui_depositform.h"

class DepositForm : public QWidget {
  Q_OBJECT

 public:
  DepositForm(GameWindow* gamewindow);

 private slots:
  void Confirm();

 private:
  Ui::DepositForm ui;
  GameWindow* gamewindow;
};
