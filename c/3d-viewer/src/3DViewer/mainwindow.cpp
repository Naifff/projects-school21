#include "mainwindow.h"

#include <QColorDialog>
#include <QDir>
#include <QFileDialog>
#include <iostream>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  SettingsLoad("new");
  QCoreApplication::instance()->connect(QCoreApplication::instance(),
                                        &QCoreApplication::aboutToQuit, this,
                                        &MainWindow::SettingsSave);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_uploadFileButton_clicked() {
  QString filename = QFileDialog::getOpenFileName(
      this, tr("Open File"), "../../../", "All files (*.obj)");
  QByteArray byt = filename.toLocal8Bit();
  const char *filenameForC = byt.data();
  qDebug() << "Test" << filenameForC;
  //  printf("%s", filenameForC);
  if (!QString(filenameForC).isEmpty()) {
    int error = 0;
    this->ui->GLwidget->openFile(filenameForC, &error);
    filenameForC = NULL;
    if (!error) {
      QFileInfo fileInfo(filename);
      QString basename = fileInfo.fileName();
      QMessageBox::information(this, tr("File Name"), basename);
      ui->label_filename_value->setText(basename);
      modelInfo();
    } else {
      QMessageBox::information(this, tr("Error"),
                               "File is corrupt or you don't have permission");
    }
  } else {
    QMessageBox::information(this, tr("Error"),
                             "File path entered incorrectly");
  }
}

void MainWindow::modelInfo() {
  if (ui->GLwidget->model.verticesAmount != 0) {
    ui->label_number_of_vertices_info->setText(
        QString::number(ui->GLwidget->model.verticesAmount));
  } else {
    ui->label_number_of_vertices_info->setText("");
  }

  if (ui->GLwidget->model.facetsAmount != 0) {
    ui->label_number_of_facets_info->setText(
        QString::number(ui->GLwidget->model.countEdge));
  } else {
    ui->label_number_of_facets_info->setText("");
  }
}

void MainWindow::on_doubleSpinBox_move_x_valueChanged(double arg1) {
  if (ui->GLwidget->moveX != arg1) {
    moveModel(&ui->GLwidget->model, arg1 - ui->GLwidget->moveX,
              ui->GLwidget->x);
    ui->GLwidget->update();
    ui->GLwidget->moveX = arg1;
  }
}

void MainWindow::on_doubleSpinBox_move_y_valueChanged(double arg1) {
  if (ui->GLwidget->moveY != arg1) {
    moveModel(&ui->GLwidget->model, arg1 - ui->GLwidget->moveY,
              ui->GLwidget->y);
    ui->GLwidget->update();
    ui->GLwidget->moveY = arg1;
  }
}

void MainWindow::on_doubleSpinBox_move_z_valueChanged(double arg1) {
  if (ui->GLwidget->moveZ != arg1) {
    moveModel(&ui->GLwidget->model, arg1 - ui->GLwidget->moveZ,
              ui->GLwidget->z);
    ui->GLwidget->update();
    ui->GLwidget->moveZ = arg1;
  }
}

void MainWindow::on_doubleSpinBox_rotate_x_valueChanged(double arg1) {
  rotate(&ui->GLwidget->model, arg1 - ui->GLwidget->rotateX, ui->GLwidget->x);
  ui->GLwidget->update();
  ui->GLwidget->rotateX = arg1;
}

void MainWindow::on_doubleSpinBox_rotate_y_valueChanged(double arg1) {
  rotate(&ui->GLwidget->model, arg1 - ui->GLwidget->rotateY, ui->GLwidget->y);
  ui->GLwidget->update();
  ui->GLwidget->rotateY = arg1;
}

void MainWindow::on_doubleSpinBox_rotate_z_valueChanged(double arg1) {
  rotate(&ui->GLwidget->model, arg1 - ui->GLwidget->rotateZ, ui->GLwidget->z);
  ui->GLwidget->update();
  ui->GLwidget->rotateZ = arg1;
}

void MainWindow::on_doubleSpinBox_zoom_valueChanged(double arg1) {
  if (arg1 > ui->GLwidget->zoom) {
    for (int i = 1; i <= arg1 - ui->GLwidget->zoom; i++)
      zoom(&ui->GLwidget->model, 1.1);
  } else {
    for (int i = 1; i <= ui->GLwidget->zoom - arg1; i++)
      zoom(&ui->GLwidget->model, 0.9);
  }
  ui->GLwidget->zoom = arg1;
  ui->GLwidget->update();
}

void MainWindow::on_pushButton_vertices_set_color_clicked() {
  ui->GLwidget->verticesColor = QColorDialog::getColor(Qt::gray);
}

void MainWindow::on_pushButton_facets_set_color_clicked() {
  ui->GLwidget->facetsColor = QColorDialog::getColor(Qt::gray);
}

void MainWindow::on_pushButton_background_set_color_clicked() {
  ui->GLwidget->backgroundColor = QColorDialog::getColor(Qt::gray);
}

void MainWindow::on_comboBox_projection_type_activated(int index) {
  ui->GLwidget->isParallel = index;
  ui->GLwidget->update();
}

void MainWindow::on_comboBox_facets_type_activated(int index) {
  ui->GLwidget->isSolid = index;
  ui->GLwidget->update();
}

void MainWindow::on_pushButton_screenshot_clicked() {
  QString desktopPath =
      QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

  QFileDialog dialog(this);
  QString screenshot_filename =
      dialog.getSaveFileName(this, "Save screenshot as...", desktopPath,
                             "BMP (*.bmp);; JPEG (*.jpeg)");

  ui->GLwidget->setStyleSheet(
      "background-color: " + ui->GLwidget->backgroundColor.name() + ";");
  QPixmap screenshot = ui->GLwidget->grab();

  screenshot.save(screenshot_filename);
}

void MainWindow::on_pushButton_gif_clicked() {
  timer = new QTimer(0);
  timer->start(100);
  connect(timer, SIGNAL(timeout()), this, SLOT(record_gif()));
}

// гифка
void MainWindow::record_gif() {
  if (giftime < 5.0) {
    ui->GLwidget->setStyleSheet(
        "background-color: " + ui->GLwidget->backgroundColor.name() + ";");
    img_vector.push_back(ui->GLwidget->grab().toImage());
    giftime += 0.1;
    // if (giftime <= 5.0)
    // ui->label_gif_timer->setText(QString::number(giftime));
  } else if (giftime >= 5.0) {
    save_gif();
    timer->stop();
  }
}

void MainWindow::save_gif() {
  QString desktopPath =
      QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

  QFileDialog dialog(this);
  QString gif_filename = dialog.getSaveFileName(this, "Save gif as...",
                                                desktopPath, "GIF (*.gif);;");

  gif.setDefaultDelay(100);

  for (QVector<QImage>::Iterator img = img_vector.begin();
       img != img_vector.end(); ++img) {
    QImage imgScaled = img->scaled(640, 480);
    gif.addFrame(imgScaled);
  }

  gif.save(gif_filename);
  img_vector.clear();
  giftime = 0.0;
}

void MainWindow::on_doubleSpinBox_size_of_vertices_valueChanged(double arg1) {
  ui->GLwidget->sizeOfVertices = arg1;
  ui->GLwidget->update();
}

void MainWindow::on_doubleSpinBox_thickness_of_facets_valueChanged(
    double arg1) {
  ui->GLwidget->thicknessOfFacets = arg1;
  ui->GLwidget->update();
}

void MainWindow::on_comboBox_way_to_display_currentIndexChanged(int index) {
  ui->GLwidget->displayPoint = index;
  ui->GLwidget->update();
}

void MainWindow::SettingsSave() {
  QString settingFile = path_of_the_program() + "3DViewer/setting/settings.ini";
  QSettings settings(settingFile, QSettings::IniFormat);

  settings.setValue("backgroundColor", ui->GLwidget->backgroundColor);
  settings.setValue("verticesColor", ui->GLwidget->verticesColor);
  settings.setValue("facetsColor", ui->GLwidget->facetsColor);

  settings.setValue("projection_type",
                    ui->comboBox_projection_type->currentIndex());
  settings.setValue("facets_type", ui->comboBox_facets_type->currentIndex());
  settings.setValue("thickness_of_facets",
                    ui->doubleSpinBox_thickness_of_facets->value());
  settings.setValue("way_to_display",
                    ui->comboBox_way_to_display->currentIndex());
  settings.setValue("size_of_vertices",
                    ui->doubleSpinBox_size_of_vertices->value());
}

void MainWindow::SettingsLoad(const QString &typeSettings) {
  QString settingFile;
  if (typeSettings == "new") {
    settingFile = path_of_the_program() + "3DViewer/setting/settings.ini";
  } else if (typeSettings == "default") {
    settingFile =
        path_of_the_program() + "3DViewer/setting/defaultsettings.ini";
  }

  QSettings settings(settingFile, QSettings::IniFormat);

  ui->GLwidget->backgroundColor =
      settings.value("backgroundColor").value<QColor>();
  ui->GLwidget->verticesColor = settings.value("verticesColor").value<QColor>();
  ui->GLwidget->facetsColor = settings.value("facetsColor").value<QColor>();

  ui->comboBox_projection_type->setCurrentIndex(
      settings.value("projection_type", "").toInt());
  ui->GLwidget->isParallel = ui->comboBox_projection_type->currentIndex();
  ui->comboBox_facets_type->setCurrentIndex(
      settings.value("facets_type", "").toInt());
  ui->GLwidget->isSolid = ui->comboBox_facets_type->currentIndex();
  ui->doubleSpinBox_thickness_of_facets->setValue(
      settings.value("thickness_of_facets", "").toInt());
  ui->GLwidget->thicknessOfFacets =
      ui->doubleSpinBox_thickness_of_facets->value();
  ui->comboBox_way_to_display->setCurrentIndex(
      settings.value("way_to_display", "").toInt());
  ui->GLwidget->displayPoint = ui->comboBox_way_to_display->currentIndex();

  ui->doubleSpinBox_size_of_vertices->setValue(
      settings.value("size_of_vertices", "").toInt());
  ui->GLwidget->sizeOfVertices = ui->doubleSpinBox_size_of_vertices->value();
}

void MainWindow::on_pushButton_save_settings_clicked() { SettingsSave(); }

void MainWindow::on_pushButton_load_settings_clicked() { SettingsLoad("new"); }

QString MainWindow::path_of_the_program() {
  QString filePath = QApplication::applicationDirPath();
  QDir dir(filePath);
  QString baseDir = dir.absolutePath();
  int number = baseDir.lastIndexOf("/src/");
  QString result = baseDir.left(number + 5);
  return result;
}

void MainWindow::on_pushButton_default_settings_clicked() {
  SettingsLoad("default");
}
