#include "gamewindow.hpp"

#include <currency.hpp>
#include <iostream>

#include "buyform.hpp"
#include "depositform.hpp"
#include "sellform.hpp"
#include "setupform.hpp"
#include "iterateform.hpp"

GameWindow::GameWindow() : form(new SetupForm(this)) {
  ui.setupUi(this);
  connect(ui.buy, &QPushButton::clicked, this, &GameWindow::OpenBuyForm);
  connect(ui.sell, &QPushButton::clicked, this, &GameWindow::OpenSellForm);
  connect(ui.iterate, &QPushButton::clicked, this, &GameWindow::OpenIterateForm);
  connect(ui.deposit, &QPushButton::clicked, this,
          &GameWindow::OpenIterateForm);
}
void GameWindow::OpenSetupForm() { form->show(); }
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
  } catch (std::exception& exception) {
    exception.what();
  }
}
void GameWindow::Sell(double amount) {
  try {
    system->Sell(Currency(ui.table->selectionModel()->selectedRows()[0].row()),
                 amount);
    Update();
  } catch (std::exception& exception) {
    exception.what();
  }
}
void GameWindow::Deposit(int month, double amount) {
  try {
    system->MakeDeposit(amount, month);
    Update();
  } catch (std::exception& exception) {
    std::cout << exception.what();
  }
}
void GameWindow::OpenBuyForm() {
  delete form;
  form = new BuyForm(this);
  form->show();
}
void GameWindow::OpenSellForm() {
  delete form;
  form = new SellForm(this);
  form->show();
}
void GameWindow::OpenDepositForm() {
  delete form;
  form = new DepositForm(this);
  form->show();
}
void GameWindow::OpenIterateForm() {
  delete form;
  form = new IterateForm(this);
  form->show();
}
void GameWindow::Iterate(double amount) {
  try {
    system->Iterate(amount);
  } catch (std::exception&) {
    Alert("Игра окончена, итоговая капиталиация: " +
          QString::number(system->GetCapitalization())+"$.");
  }
  Update();
}
void GameWindow::Update() {
  UpdateTable();
  UpdateText();
}
void GameWindow::UpdateTable() {
  ui.table->setRowCount(CurrencySize + 1);
  SetTableItemText(0, 0, "Dollar");
  SetTableItemText(0, 1, "1 / 1");
  SetTableItemText(0, 2, QString::number(system->GetConventionalUnits()));
  for (int i = 1; Currency(i) != Currency::__Last; ++i) {
    SetTableItemText(i, 0, QString::fromStdString(ToString(Currency(i))));
    SetTableItemText(
        i, 1,
        QString::number(system->GetSellRate(Currency(i)).first) + " / " +
            QString::number(system->GetBuyRate(Currency(i)).first));
    SetTableItemText(i, 2, QString::number(system->GetAmount(Currency(i))));
  }
}
void GameWindow::UpdateText() {
  if (system) {
    QString lol = QString("Месяц: %1 / %2\n\nКапитализация: %3$\n\nВклады:\n")
                      .arg(QString::number(system->GetMonthCount()),
                           QString::number(system->GetMonthAmount()),
                           QString::number(system->GetCapitalization()));
    auto a = system->GetDeposit();
    for (int i = 0; i < a.size(); ++i) {
      lol.append(QString::number(a[i].second) + "$ начислится через " +
                 QString::number(a[i].first) + " мес.\n");
    }
    ui.textBrowser->setText(lol);
  }
}
void GameWindow::SetTableItemText(int row, int column, const QString& text) {
  if (ui.table->item(row, column) == nullptr) {
    ui.table->setItem(row, column, new QTableWidgetItem);
  }
  ui.table->item(row, column)->setText(text);
}
void GameWindow::Alert(const QString& message) {
  msg.setText(message);
  msg.exec();
}
