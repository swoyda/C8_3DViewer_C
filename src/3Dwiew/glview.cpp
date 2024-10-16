#include "glview.hpp"

#include <QApplication>
#include <QWidget>
// #include <Qt3DCore/QEntity>
// #include <Qt3DCore/QTransform>
// #include <Qt3DRender/QPointLight>
// #include <Qt3DExtras/QPhongMaterial>
// #include <Qt3DExtras/QCuboidMesh>
// #include <Qt3DExtras/Qt3DWindow>

#include <QDebug>

glView::glView(QWidget *parent) : QOpenGLWidget(parent) {
  exist = 0;
  // backgroundColor = Qt::red;
}
// virtual glView::~glView() {};
void glView::initializeGL() {
  float a = 1.0f;
  glClearColor(backgroundColor.redF(), backgroundColor.greenF(),
               backgroundColor.blueF(), a);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
  glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);
  glClear(GL_COLOR_BUFFER_BIT);
}
void glView::onLinesColorChange(const QColor &color) {
  linesColor = color;
  update();
}
void glView::onBackColorChange(const QColor &color) {
  backgroundColor = color;
  update();
}
void glView::onVerticesColorChange(const QColor &color) {
  verticesColor = color;
  update();
}
void glView::onVerticesTypeChange(const int &type) {
  verticesType = type;
  update();
}
void glView::onLinesTypeChange(const int &type) {
  linesType = type;
  update();
}
void glView::onLinesWidthChange(const float &type) {
  // qDebug() << type;
  lineWidth = type;
  update();
}
void glView::onVerticesWidthChange(const float &type) {
  // qDebug() << type;
  verticesWidth = type;
  update();
}
void glView::newArraysAdded() {
  if (exist) {
    delete[] vertex_indices;
  }

  vertex_indices = new GLuint[data.vertices_count];
  for (size_t i = 0; i < data.vertices_count; i++) {
    vertex_indices[i] = i;
  }
  exist = 1;
  paintGL();
}
void glView::paintGL() {
  if (exist) {
    glClearColor(backgroundColor.redF(), backgroundColor.greenF(),
                 backgroundColor.blueF(), 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glVertexPointer(3, GL_DOUBLE, 0, data.vertices_arr);
    glEnableClientState(GL_VERTEX_ARRAY);
    if (verticesType) {
      glColor3f(verticesColor.redF(), verticesColor.greenF(),
                verticesColor.blueF());
      if (verticesType == circle)
        glEnable(GL_POINT_SMOOTH);
      else
        glDisable(GL_POINT_SMOOTH);
      glPointSize(verticesWidth);

      glDrawElements(GL_POINTS, data.vertices_count, GL_UNSIGNED_INT,
                     vertex_indices);
    }

    glColor3f(linesColor.redF(), linesColor.greenF(), linesColor.blueF());
    if (linesType) {
      glDisable(GL_LINE_STIPPLE);
    } else {
      glEnable(GL_LINE_STIPPLE);
    }
    glLineWidth(lineWidth);
    glLineStipple(1, 0x00F0);
    glDrawElements(GL_LINES, data.indices_count * 2, GL_UNSIGNED_INT,
                   data.indices_arr);

    glDisableClientState(GL_VERTEX_ARRAY);
  }
}

void glView::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  // glMatrixMode(GL_PROJECTION);
  // glLoadIdentity();
  // glMatrixMode(GL_MODELVIEW);
  // glLoadIdentity();
}
void glView::scaleChanged(const double &value) {
  if (exist) {
    for (size_t i = 0; i < data.indices_count; i++) {
      data.indices_arr[i] = copy_data.indices_arr[i];
    }
    for (size_t i = 0; i < data.vertices_count * 3; i++) {
      data.vertices_arr[i] = copy_data.vertices_arr[i];
    }
    scale(&data, value);
    update();
  }
}

void glView::xSpinChanged(const double &angle) {
  if (exist) {
    rotate_Y(&copy_data, angle);
    rotate_Y(&data, angle);
    update();
  }
}
void glView::ySpinChanged(const double &angle) {
  if (exist) {
    rotate_X(&copy_data, angle);
    rotate_X(&data, angle);
    update();
  }
}
void glView::zSpinChanged(const double &angle) {
  if (exist) {
    rotate_Z(&copy_data, angle);
    rotate_Z(&data, angle);
    update();
  }
}

void glView::xPosChanged(const double &value) {
  if (exist) {
    move_X(&copy_data, value);
    move_X(&data, value);
    update();
  }
}
void glView::yPosChanged(const double &value) {
  if (exist) {
    move_Y(&copy_data, value);
    move_Y(&data, value);
    update();
  }
}
void glView::zPosChanged(const double &value) {
  if (exist) {
    move_Z(&copy_data, value);
    move_Z(&data, value);
    update();
  }
}
