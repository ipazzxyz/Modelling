#include "app.hpp"

#include "gamewindow.hpp"

App::App(int argc, char **argv) {
  QApplication app(argc, argv);

  GameWindow gamewindow;
  gamewindow.show();
  gamewindow.RunSetup();

  app.exec();
}
