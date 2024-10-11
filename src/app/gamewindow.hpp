#pragma once

#include <QMessageBox>
#include <system.hpp>

#include "ui_gamewindow.h"

class GameWindow : public QMainWindow {
  Q_OBJECT

 public:
  GameWindow();

  void OpenSetupForm();

  void Iterate(double amount);
  void Setup(int month, double capitalization, double tax, double spread);
  void Buy(double amount);
  void Sell(double amount);
  void Deposit(int month, double amount);

 private slots:
  void OpenBuyForm();
  void OpenSellForm();
  void OpenDepositForm();
  void OpenIterateForm();

 private:
  Ui::GameWindow ui;
  System* system;
  QWidget* form;
  QMessageBox msg;

  void Update();
  void UpdateTable();
  void UpdateText();
  void SetTableItemText(int row, int column, const QString& text);
  void Alert(const QString& message);
};
