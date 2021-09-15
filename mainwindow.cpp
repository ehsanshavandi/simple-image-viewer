#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  createSignalSlots();
  setCentralWidget(ui->scrollArea);
  bootsrapIcon();
  bootsrapViewer();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::open()
{
  m_path = QFileDialog::getOpenFileName(this, "Open", QString(),
                                        "All Files (*.*);;JPG (*.jpg);;PNG (*.png)");

  if (m_path.isEmpty()) return;

  if (!m_img.load(m_path))
  {
    QMessageBox::critical(this, "Error", "Could not load the image");
    return;
  }

  m_lblImage->setPixmap(m_img);
}

void MainWindow::zoomIn()
{
  int w = m_lblImage->width();
  int h = m_lblImage->height();

  w += 10;
  h += 10;
  m_lblImage->resize(w, h);
  m_lblImage->setPixmap(m_img.scaled(w, h));
}

void MainWindow::zoomOut()
{
  int w = m_lblImage->width();
  int h = m_lblImage->height();

  w -= 10;
  h -= 10;

  if ( w < 10 ) w = 10;

  if ( h < 10 ) h = 10;

  m_lblImage->resize(w, h);
  m_lblImage->setPixmap(m_img.scaled(w, h));
}

void MainWindow::createSignalSlots()
{
  connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::open);
  connect(ui->actionZoom_In, &QAction::triggered, this, &MainWindow::zoomIn);
  connect(ui->actionZoom_out, &QAction::triggered, this, &MainWindow::zoomOut);
}

void MainWindow::bootsrapIcon()
{
  ui->actionOpen->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogOpenButton));
  ui->actionZoom_In->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowUp));
  ui->actionZoom_out->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowDown));
}

void MainWindow::bootsrapViewer()
{
  m_lblImage = new QLabel(this);
  ui->scrollArea->setWidget(m_lblImage);
}

