#ifndef GLVIEW_HPP
#define GLVIEW_HPP

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <QColor>
// #include <QOpenGLFunctions>
extern "C" {

#include "parcer.h"
#include "affine_transformations.h"
}
typedef enum { none = 0, circle, square } VerticeTypes;
typedef enum { dashed = 0,  solid } LinesTypes;
class glView : public QOpenGLWidget
    // , protected QOpenGLFunctions
{
    // Q_OBJECT
public:
    glView(QWidget *parent = nullptr);
    // ~glView();
    virtual ~glView(){};
    QColor backgroundColor;
    QColor linesColor;
    QColor verticesColor;
    int verticesType;
    int linesType;
    float lineWidth;
    float verticesWidth;
    obj_data data;
    obj_data copy_data;
    int exist;
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    GLfloat *vertices;
    GLuint *indices;
    GLuint *vertex_indices;
public slots:
    void onBackColorChange(const QColor &color);
    void onLinesColorChange(const QColor &color);
    void onVerticesColorChange(const QColor &color);
    void onVerticesTypeChange(const int &type);
    void onLinesTypeChange(const int &type);
    void onLinesWidthChange(const float &type);
    void onVerticesWidthChange(const float &type);
    void newArraysAdded();
    void scaleChanged(const double &value);
    void xSpinChanged(const double &angle);
    void ySpinChanged(const double &angle);
    void zSpinChanged(const double &angle);
    void xPosChanged(const double &value);
    void yPosChanged(const double &value);
    void zPosChanged(const double &value);
};

#endif // GLVIEW_HPP
