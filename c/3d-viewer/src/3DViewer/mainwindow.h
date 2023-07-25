#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>

#include "qtgifimage/src/gifimage/qgifimage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_uploadFileButton_clicked();

  void on_doubleSpinBox_move_x_valueChanged(double arg1);

  void on_doubleSpinBox_move_y_valueChanged(double arg1);

  void on_doubleSpinBox_move_z_valueChanged(double arg1);

  void on_doubleSpinBox_rotate_x_valueChanged(double arg1);

  void on_doubleSpinBox_rotate_y_valueChanged(double arg1);

  void on_doubleSpinBox_rotate_z_valueChanged(double arg1);

  void on_doubleSpinBox_zoom_valueChanged(double arg1);

  void record_gif();

  void save_gif();

  void on_pushButton_vertices_set_color_clicked();

  void on_pushButton_facets_set_color_clicked();

  void on_pushButton_background_set_color_clicked();

  void on_comboBox_projection_type_activated(int index);

  void on_comboBox_facets_type_activated(int index);

  void on_pushButton_screenshot_clicked();

  void on_pushButton_gif_clicked();

  void on_doubleSpinBox_size_of_vertices_valueChanged(double arg1);

  void on_doubleSpinBox_thickness_of_facets_valueChanged(double arg1);

  void on_comboBox_way_to_display_currentIndexChanged(int index);

  void SettingsSave();

  void SettingsLoad(const QString &typeSettings);

  void on_pushButton_save_settings_clicked();

  void on_pushButton_load_settings_clicked();

  void modelInfo();

  QString path_of_the_program();

  void on_pushButton_default_settings_clicked();

 private:
  Ui::MainWindow *ui;
  QTimer *timer;
  QGifImage gif;
  QVector<QImage> img_vector;
  double giftime = 0;
};
#endif  // MAINWINDOW_H
