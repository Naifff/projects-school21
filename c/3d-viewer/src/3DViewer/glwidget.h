#ifndef GLWIDGET_H
#define GLWIDGET_H

#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>
#include <OpenGL/gl.h>

#include <QColor>
#include <QFileDialog>
#include <QOpenGLWidget>
#include <QtGui/QColor>
#include <QtOpenGL>

extern "C" {
#include "./transform/s21_affine_transform.h"
}

class GLWidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  GLWidget(QWidget *parent = nullptr);
  const char *filename;
  data_t model;
  data_t defModel;
  void decreaseModel();
  void openFile(const char *filename, int *error);
  void paintModel();
  double zoom = 1;
  double moveX, moveY, moveZ = 0;
  double rotateX, rotateY, rotateZ = 0;
  QColor backgroundColor;
  QColor verticesColor;
  QColor facetsColor;
  int isSolid = 0;
  int isParallel = 0;
  int displayPoint = 0;
  float sizeOfVertices, thicknessOfFacets = 0;
  int x = 0;
  int y = 1;
  int z = 2;

 private:
  void getEdges();
  float xRot, yRot, zRot = 0;
  QPoint mousePosition;
  char *file = NULL;
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();
  void paintLines();
  void paintPoints();
  void mousePressEvent(QMouseEvent *);
  void mouseMoveEvent(QMouseEvent *);

 protected:
  void closeEvent(QCloseEvent *event) {
    freeData(&model);
    QOpenGLWidget::closeEvent(event);
  }
};

#endif  // GLWIDGET_H
