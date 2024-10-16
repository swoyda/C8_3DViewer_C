#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include <QDir>
#include <QTimer>
#include <QColorDialog>

#include "glview.hpp"
#include "qgifimage.h"

typedef enum { bmp = 0,  jpg } SettingsType;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void saveSettings();
    void loadSettings();

private:
    Ui::MainWindow *ui;
    QSettings* myGlSettings;
    QTimer *gifTimer;
    int scrinshot_settings;
    obj_data data;
    QGifImage *gif;
    int count_frames;
private slots:
    void recordGIF();
    void open_file();
    void onSliderLinesValueChanged(int value);
    void onSliderVerticesValueChanged(int value);
    void onScaleSliderValueChanged(int value);
    void actionSet_background_color_triggered();
    void actionSet_color_lines_triggered();
    void actionSet_color_vertices_triggered();
    void action_None_triggered();
    void actionSquere_triggered();
    void actionCircle_triggered();
    void actionSet_Dashed_triggered();
    void actionSet_Solid_triggered();
    void onDecreaseLinesButtonClicked();
    void onIncreaseLinesButtonClicked();
    void onDecreaseVerticesButtonClicked();
    void onIncreaseVerticesButtonClicked();
    void onScrinshotButtonClicked();
    void onGIFButtonClicked();
    void action_bmp_triggered();
    void action_jpg_triggered();
    void onIncreaseScaleButtonClicked();
    void onDecreaseScaleButtonClicked();
    void onMoveXDoubleSpinBoxChanged(double value);
    void onMoveYDoubleSpinBoxChanged(double value);
    void onMoveZDoubleSpinBoxChanged(double value);
    void onSpinXDoubleSpinBoxChanged(double value);
    void onSpinYDoubleSpinBoxChanged(double value);
    void onSpinZDoubleSpinBoxChanged(double value);
signals:
    void backColorChanged(const QColor &color);
    void verticesColorChanged(const QColor &color);
    void linesColorChanged(const QColor &color);
    void verticeTypeChanged(const int &type);
    void linesTypeChanged(const int &type);
    void linesWidthChanged(const float &width);
    void verticesWidthChanged(const float &width);
    void scaleChanged(const double &scale);
    void transform_arrays();
    void xPosChanged(const double &value);
    void yPosChanged(const double &value);
    void zPosChanged(const double &value);
    void xSpinChanged(const double &value);
    void ySpinChanged(const double &value);
    void zSpinChanged(const double &value);
};
#endif // MAINWINDOW_H
