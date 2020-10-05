#include "fsutils.h"
#include "mast2.h"
#include "secutils.h"
#include <KDESu/kdesu/client.h>
#include <KF5/KCrash/kcrash.h>
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  KCrash::initialize();
  KCrash::setDrKonqiEnabled(true);
  if (not mast2_sec::got_root_privileges()) {
    std::cout << "Starts only as root!" << std::endl;
    return 1;
  }
  //  std::cout << "Running as root? " << mast2_sec::got_root_privileges()
  //            << std::endl
  //            /*! <<
  //            mast2_fs::Conf::get_param("/home/titoffklim/99-sysctl.conf",
  //                                         "vm.swappiness")
  //                   .toStdString()
  //            << std::endl */ ;
  //  auto su_client = KDESu::KDEsuClient();
  //  su_client.startServer();
  //  su_client.setPass("asaclouasd1t", 360);
  //  std::cout << su_client.exec("pacman", "root", "-Syu") << std::endl;
  //  su_client.stopServer();
  //  mast2_fs::Conf::set_param("/etc/sysctl.d/99-sysctl.conf", "vm.swappiness",
  //  " 1");
  MaST w;
  w.show();
  return a.exec();
}
