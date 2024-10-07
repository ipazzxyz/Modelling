#include "app.hpp"

#include <QApplication>

#include "gamewindow.hpp"
#include "setupform.hpp"

App::App(int argc, char **argv) {
  QApplication app(argc, argv);

  GameWindow gamewindow;
  SetupForm setup(gamewindow);
  setup.show();

  app.exec();
}
