#pragma once

#include "gamewindow.hpp"
#include "ui_sellform.h"

class SellForm : public QWidget {
  Q_OBJECT

 public:
  SellForm(GameWindow* gamewindow);
  SellForm(QString str, double max, GameWindow* gamewindow);

 private slots:
  void Confirm();

 private:
  Ui::SellForm ui;
  GameWindow* gamewindow;
};
