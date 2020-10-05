#include "mast2.h"

#include <QDebug>

MaST::MaST(QWidget *parent) : QMainWindow(parent) {
  settings = new QSettings(QSettings::UserScope, "mast2");
  if (QFile::exists(settings->fileName())) {
    this->resize(settings->value("mast2/width").toInt(),
                 settings->value("mast2/height").toInt());
  } else {
    this->resize(640, 480);
  }
  QDir tmp_dir("/tmp");
  tmp = new QTemporaryDir(tmp_dir.filePath("mast2-XXXXXX"));
  setWindowTitle("MaST2");
}

MaST::~MaST() {
  settings->setValue("mast2/width", this->width());
  settings->setValue("mast2/height", this->height());
  settings->sync();
  delete settings;
  tmp->remove();
  delete tmp;
}
