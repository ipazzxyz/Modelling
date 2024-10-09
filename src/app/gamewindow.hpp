#pragma once

#include <system.hpp>

#include "ui_gamewindow.h"

class GameWindow : public QMainWindow {
  Q_OBJECT

 public:
  GameWindow();

  void RunSetup();

  void Setup(int month, double capitalization, double tax, double spread);
  void Buy(double amount);
  void Sell(double amount);
  void MakeDeposit(int month, double amount);

 private slots:
  void AskBuy();
  void AskSell();
  void AskDeposit();
  void Iterate();

 private:
  Ui::GameWindow ui;
  System* system;
  QWidget* form;

  void Update();
  void UpdateTable();
  void UpdateText();
};
