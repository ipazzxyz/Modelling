#pragma once

#include "gamewindow.hpp"
#include "ui_iterateform.h"

class IterateForm : public QWidget {
  Q_OBJECT

 public:
  IterateForm(GameWindow* gamewindow);

 private slots:
  void Confirm();

 private:
  Ui::IterateForm ui;
  GameWindow* gamewindow;
};
