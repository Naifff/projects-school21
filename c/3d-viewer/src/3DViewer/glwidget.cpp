#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) {
  backgroundColor.setRgb(0, 0, 0);
  verticesColor.setRgb(255, 255, 255);
  facetsColor.setRgb(255, 255, 255);
}

void GLWidget::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  model = {0, 0, NULL, NULL, 0};
}

void GLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}
void GLWidget::paintGL() {
  glClearColor(backgroundColor.redF(), backgroundColor.greenF(),
               backgroundColor.blueF(), 1.0f);  // 1
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  if (isParallel) {
    glFrustum(-10, 10, -10, 10, 1, 500);
  } else {
    glOrtho(-10, 10, -10, 10, -10, 500);
  }
  glTranslated(
      0, 0,
      0);  //  применяет трансляцию (смещение) к текущей матрице преобразования
  glRotated(xRot, 1, 0, 0);
  glRotated(yRot, 0, 1, 0);
  glRotated(zRot, 0, 0, 1);
  paintModel();
}

void GLWidget::paintPoints() {
  if (displayPoint) {
    glColor3d(verticesColor.redF(), verticesColor.greenF(),
              verticesColor.blueF());
    glPointSize(sizeOfVertices);
    if (displayPoint == 1) {
      glEnable(GL_POINT_SMOOTH);
      glDrawArrays(GL_POINTS, 0, model.verticesAmount);  // рисуем точки
      glDisable(GL_POINT_SMOOTH);
    } else {
      glDrawArrays(GL_POINTS, 0, model.verticesAmount);
    }
  }
}

void GLWidget::paintLines() {
  glColor3d(facetsColor.redF(), facetsColor.greenF(),
            facetsColor.blueF());  // цвет линии
  glLineWidth(thicknessOfFacets);  // толщина линии
  if (isSolid) {
    glLineStipple(1, 0x3333);  // пунктир
    glEnable(GL_LINE_STIPPLE);
  }
  glDrawElements(GL_LINES, model.facetsAmount * 2, GL_UNSIGNED_INT,
                 model.facets);  // соединяем точки
  glDisable(GL_LINE_STIPPLE);
}

void GLWidget::paintModel() {
  glVertexPointer(3, GL_DOUBLE, 0, model.vertices);
  glEnableClientState(GL_VERTEX_ARRAY);
  paintPoints();
  paintLines();
  glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget::openFile(const char *filenameForC, int *error) {
  freeData(&model);
  *error = parsingFile(&model, filenameForC);
  if (!*error) {
    decreaseModel();
    update();
  }
}

void GLWidget::decreaseModel() {
  int amountVertices = model.verticesAmount * 3;
  int maxCoord = 0;
  for (int i = 0; i < amountVertices; i++) {
    if (maxCoord < fabs(model.vertices[i])) maxCoord = fabs(model.vertices[i]);
  }
  if (maxCoord > 10) {
    maxCoord /= 10;
    for (int i = 0; i < amountVertices; i++) {
      model.vertices[i] /= maxCoord;
    }
  }
}

void GLWidget::mousePressEvent(QMouseEvent *mo) { mousePosition = mo->pos(); }

void GLWidget::mouseMoveEvent(QMouseEvent *mo) {
  xRot = 1 / M_PI * (mo->pos().y() - mousePosition.y());
  yRot = 1 / M_PI * (mo->pos().x() - mousePosition.x());
  update();
}
