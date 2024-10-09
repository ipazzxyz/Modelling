#include "gamewindow.hpp"

#include <currency.hpp>
#include <iostream>

#include "buyform.hpp"
#include "depositform.hpp"
#include "sellform.hpp"
#include "setupform.hpp"

GameWindow::GameWindow() : form(new SetupForm(this)) {
  ui.setupUi(this);
  connect(ui.buy, &QPushButton::clicked, this, &GameWindow::AskBuy);
  connect(ui.sell, &QPushButton::clicked, this, &GameWindow::AskSell);
  connect(ui.iterate, &QPushButton::clicked, this, &GameWindow::Iterate);
  connect(ui.deposit, &QPushButton::clicked, this, &GameWindow::AskDeposit);
}
void GameWindow::RunSetup() { form->show(); }
void GameWindow::Setup(int month, double capitalization, double tax,
                       double spread) {
  system = new System(month, capitalization, tax / 100., spread / 100.);
  Update();
}
void GameWindow::Buy(double amount) {
  try {
    system->Buy(Currency(ui.table->selectionModel()->selectedRows()[0].row()),
                amount);
    Update();
  } catch (std::exception&) {
  }
}
void GameWindow::Sell(double amount) {
  try {
    system->Sell(Currency(ui.table->selectionModel()->selectedRows()[0].row()),
                 amount);
    Update();
  } catch (std::exception&) {
  }
}
void GameWindow::MakeDeposit(int month, double amount) {
  system->MakeDeposit(month, amount);
}
void GameWindow::AskBuy() {
  delete form;
  form = new BuyForm(this);
  form->show();
}
void GameWindow::AskSell() {
  delete form;
  form = new SellForm(this);
  form->show();
}
void GameWindow::AskDeposit() {
  delete form;
  form = new DepositForm(this);
  form->show();
}
void GameWindow::Iterate() {
  system->Iterate(0);
  UpdateTable();
}
void GameWindow::Update() {
  UpdateTable();
  UpdateText();
}
void GameWindow::UpdateTable() {
  ui.table->setRowCount(3);
  delete ui.table->item(0, 0);
  ui.table->setItem(0, 0, new QTableWidgetItem);
  ui.table->item(0, 0)->setText("Dollar");
  delete ui.table->item(0, 1);
  ui.table->setItem(0, 1, new QTableWidgetItem);
  ui.table->item(0, 1)->setText("1 / 1");
  delete ui.table->item(0, 2);
  ui.table->setItem(0, 2, new QTableWidgetItem);
  ui.table->item(0, 2)->setText(
      QString::number(system->GetConventionalUnits()));
  for (int i = 1; Currency(i) != Currency::__Last; ++i) {
    delete ui.table->item(i, 0);
    ui.table->setItem(i, 0, new QTableWidgetItem);
    ui.table->item(i, 0)->setText(
        QString::fromStdString(ToString(Currency(i))));
    delete ui.table->item(i, 1);
    ui.table->setItem(i, 1, new QTableWidgetItem);
    ui.table->item(i, 1)->setText(
        QString::number(system->GetSellRate(Currency(i)).first) + " / " +
        QString::number(system->GetBuyRate(Currency(i)).first));
    delete ui.table->item(i, 2);
    ui.table->setItem(i, 2, new QTableWidgetItem);
    ui.table->item(i, 2)->setText(
        QString::number(system->GetAmount(Currency(i))));
  }
}
void GameWindow::UpdateText() {
  ui.textBrowser->setText(
      QString("Месяц: %1 / %2\n\nКапитализация: %3\n\nВклады ИМЕЮТСЯ))))")
          .arg(QString::number(system->GetMonthCount()),
               QString::number(system->GetMonthAmount()),
               QString::number(system->GetCapitalization())));
}