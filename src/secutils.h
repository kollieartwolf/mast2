#ifndef SECUTILS_H
#define SECUTILS_H

#include <KF5/KDESu/kdesu/client.h>
#include <QtCore/QProcess>
#include <unistd.h>

namespace mast2_sec {
auto got_root_privileges() { return not getegid(); }
auto init_kdesu(KDESu::KDEsuClient *su_client) {
  return su_client->startServer();
}
auto set_su_password(KDESu::KDEsuClient *su_client, const QString &password) {
  return su_client->setPass(password.toLocal8Bit(), 300);
}
auto got_su_privileges(KDESu::KDEsuClient *su_client) {
  return !su_client->exec("/usr/bin/whoami", "");
}
} // namespace mast2_sec

#endif
