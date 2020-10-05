#ifndef FSUTILS_H
#define FSUTILS_H

#include <QDir>
#include <QFile>
#include <QObject>
#include <QString>
#include <QTextStream>
#include <cstring>
#include <iostream>

namespace mast2_fs {
class Conf {
public:
  auto static get_param(QString filepath, QString param) {
    QFile data(filepath);
    if (data.open(QIODevice::ExistingOnly | QIODevice::ReadOnly)) {
      QTextStream stream(&data);
      QString line;
      while (stream.readLineInto(&line)) {
        if (line.contains(param)) {
          data.close();
          line.remove(param);
          line.remove('=');
          return line.trimmed();
        }
      }
      data.close();
    }
    return QString();
  }
  auto static set_param(QString filepath, QString param, QString value) {
    QFile data(filepath);
    QDir tmp_dir("/tmp");
    if (data.copy(tmp_dir.filePath("mast2-tmpfile"))) {
      QFile copy(tmp_dir.filePath("mast2-tmpfile"));
      if (data.open(QIODevice::WriteOnly) and copy.open(QIODevice::ReadOnly)) {
        QTextStream instream(&copy);
        QTextStream outstream(&data);
        QString line;
        bool found = false;
        while (instream.readLineInto(&line)) {
          if (line.contains(param)) {
            found = true;
            line = line.left(line.indexOf("=") + 1) + value;
          }
          outstream << line << '\n';
        }
        if (not found)
          outstream << param << "=" << value << '\n';
        data.close();
        copy.close();
        QFile::remove(tmp_dir.filePath("mast2-tmpfile"));
        return found;
      }
    }
    return false;
  }
};
} // namespace mast2_fs

#endif
