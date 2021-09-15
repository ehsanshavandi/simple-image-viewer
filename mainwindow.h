#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QStyle>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private slots:
  void open();
  void zoomIn();
  void zoomOut();

 private:
  Ui::MainWindow* ui;

  QLabel* m_lblImage;
  QString m_path;
  QPixmap m_img;

  void createSignalSlots();
  void bootsrapIcon();
  void bootsrapViewer();
};
#endif // MAINWINDOW_H
