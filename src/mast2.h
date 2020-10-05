#ifndef MAST_H
#define MAST_H

#include <QDir>
#include <QFile>
#include <QMainWindow>
#include <QPair>
#include <QSettings>
#include <QTemporaryDir>

class MaST : public QMainWindow {
  Q_OBJECT

public:
  /*! Constructor. */
  MaST(QWidget *parent = nullptr);

  /*! Destructor. */
  ~MaST();

private:
  // Objects:
  QSettings *settings = nullptr;
  QTemporaryDir *tmp = nullptr;

  // Options:
  /*!< Width and height. */
  QPair<int, int> window_size = QPair<int, int>(640, 480);
};
#endif
