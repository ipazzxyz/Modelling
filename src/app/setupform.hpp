#pragma once

#include "gamewindow.hpp"
#include "ui_setupform.h"

class SetupForm : public QWidget {
  Q_OBJECT

 public:
  SetupForm(GameWindow* gamewindow);

 private slots:
  void Confirm();

 private:
  Ui::SetupForm ui;
  GameWindow* gamewindow;
};
