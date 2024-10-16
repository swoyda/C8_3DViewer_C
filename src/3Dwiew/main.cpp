#include <QApplication>
#include <QScreen>
#include <QWidget>

#include "mainwindow.h"
int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  w.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  w.setMinimumSize(921, 621);
  w.setMaximumSize(2000, 4000);
  return a.exec();
}
