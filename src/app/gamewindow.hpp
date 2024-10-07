#pragma once

#include "ui_gamewindow.h"

#include "system.hpp"

class GameWindow : public QMainWindow {
  Q_OBJECT
  friend class SetupForm;

 public:
  GameWindow();

 private slots:
  void next();

 private:
  Ui::GameWindow ui;
  System *system;

  int month_cnt;
  double capitalization;
  double tax;
  double spread;

  void setup();
};
