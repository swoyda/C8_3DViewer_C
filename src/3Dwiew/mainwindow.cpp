#include "mainwindow.h"

#include "ui_mainwindow.h"
// #include "glview.hpp"
#include <QDebug>
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setWindowTitle("3DViewer");
  myGlSettings = new QSettings("S21", "3DViewer", this);
  loadSettings();

  ui->linesThiknessSlider->setMinimum(1);
  ui->linesThiknessSlider->setMaximum(10);

  ui->verticesThiknessSlider->setMinimum(1);
  ui->verticesThiknessSlider->setMaximum(20);

  ui->scaleSlider->setMinimum(1);
  ui->scaleSlider->setMaximum(200);

  ui->moveXDoubleSpinBox->setSingleStep(0.01);
  ui->moveYDoubleSpinBox->setSingleStep(0.01);
  ui->moveZDoubleSpinBox->setSingleStep(0.01);

  ui->gridWidget_5->setSizePolicy(QSizePolicy::Expanding,
                                  QSizePolicy::Expanding);

  connect(ui->fileInputButton, SIGNAL(clicked()), this, SLOT(open_file()));
  connect(ui->actionSet_background_color, SIGNAL(triggered()), this,
          SLOT(actionSet_background_color_triggered()));
  connect(ui->actionSet_color_lines, SIGNAL(triggered()), this,
          SLOT(actionSet_color_lines_triggered()));
  connect(ui->actionSet_color_vertices, SIGNAL(triggered()), this,
          SLOT(actionSet_color_vertices_triggered()));

  connect(ui->actionSolid, SIGNAL(triggered()), this,
          SLOT(actionSet_Solid_triggered()));
  connect(ui->actionDashed, SIGNAL(triggered()), this,
          SLOT(actionSet_Dashed_triggered()));

  connect(ui->action_None, SIGNAL(triggered()), this,
          SLOT(action_None_triggered()));
  connect(ui->actionCircle, SIGNAL(triggered()), this,
          SLOT(actionCircle_triggered()));
  connect(ui->actionSquere, SIGNAL(triggered()), this,
          SLOT(actionSquere_triggered()));

  connect(ui->action_bmp, SIGNAL(triggered()), this,
          SLOT(action_bmp_triggered()));
  connect(ui->action_jpeg, SIGNAL(triggered()), this,
          SLOT(action_jpg_triggered()));

  connect(this, &MainWindow::backColorChanged, ui->GLWidget,
          &glView::onBackColorChange);
  connect(this, &MainWindow::linesColorChanged, ui->GLWidget,
          &glView::onLinesColorChange);

  connect(this, &MainWindow::verticesColorChanged, ui->GLWidget,
          &glView::onVerticesColorChange);
  connect(this, &MainWindow::verticeTypeChanged, ui->GLWidget,
          &glView::onVerticesTypeChange);

  connect(this, &MainWindow::linesTypeChanged, ui->GLWidget,
          &glView::onLinesTypeChange);
  connect(this, &MainWindow::linesWidthChanged, ui->GLWidget,
          &glView::onLinesWidthChange);

  connect(this, &MainWindow::verticesWidthChanged, ui->GLWidget,
          &glView::onVerticesWidthChange);

  connect(this, &MainWindow::transform_arrays, ui->GLWidget,
          &glView::newArraysAdded);

  connect(this, &MainWindow::scaleChanged, ui->GLWidget, &glView::scaleChanged);

  connect(this, &MainWindow::xSpinChanged, ui->GLWidget, &glView::xSpinChanged);
  connect(this, &MainWindow::ySpinChanged, ui->GLWidget, &glView::ySpinChanged);
  connect(this, &MainWindow::zSpinChanged, ui->GLWidget, &glView::zSpinChanged);

  connect(this, &MainWindow::xPosChanged, ui->GLWidget, &glView::xPosChanged);
  connect(this, &MainWindow::yPosChanged, ui->GLWidget, &glView::yPosChanged);
  connect(this, &MainWindow::zPosChanged, ui->GLWidget, &glView::zPosChanged);

  connect(ui->linesThiknessSlider, &QSlider::valueChanged, this,
          &MainWindow::onSliderLinesValueChanged);
  connect(ui->linesThiknessLessButton, &QPushButton::clicked, this,
          &MainWindow::onDecreaseLinesButtonClicked);
  connect(ui->linesThiknessMoreButton, &QPushButton::clicked, this,
          &MainWindow::onIncreaseLinesButtonClicked);

  connect(ui->verticesThiknessSlider, &QSlider::valueChanged, this,
          &MainWindow::onSliderVerticesValueChanged);
  connect(ui->verticesThiknessLessButton, &QPushButton::clicked, this,
          &MainWindow::onDecreaseVerticesButtonClicked);
  connect(ui->verticesThiknessMoreButton, &QPushButton::clicked, this,
          &MainWindow::onIncreaseVerticesButtonClicked);

  connect(ui->scrinshotButton, &QPushButton::clicked, this,
          &MainWindow::onScrinshotButtonClicked);
  connect(ui->gifButton, &QPushButton::clicked, this,
          &MainWindow::onGIFButtonClicked);

  connect(ui->scaleSlider, &QSlider::valueChanged, this,
          &MainWindow::onScaleSliderValueChanged);
  connect(ui->scaleToLessButton, &QPushButton::clicked, this,
          &MainWindow::onDecreaseScaleButtonClicked);
  connect(ui->scaleToMoreButton, &QPushButton::clicked, this,
          &MainWindow::onIncreaseScaleButtonClicked);

  connect(ui->moveXDoubleSpinBox,
          static_cast<void (QDoubleSpinBox::*)(double)>(
              &QDoubleSpinBox::valueChanged),
          this, &MainWindow::onMoveXDoubleSpinBoxChanged);
  connect(ui->moveYDoubleSpinBox,
          static_cast<void (QDoubleSpinBox::*)(double)>(
              &QDoubleSpinBox::valueChanged),
          this, &MainWindow::onMoveYDoubleSpinBoxChanged);
  connect(ui->moveZDoubleSpinBox,
          static_cast<void (QDoubleSpinBox::*)(double)>(
              &QDoubleSpinBox::valueChanged),
          this, &MainWindow::onMoveZDoubleSpinBoxChanged);

  connect(ui->spinXdoubleSpinBox,
          static_cast<void (QDoubleSpinBox::*)(double)>(
              &QDoubleSpinBox::valueChanged),
          this, &MainWindow::onSpinXDoubleSpinBoxChanged);
  connect(ui->spinYdoubleSpinBox,
          static_cast<void (QDoubleSpinBox::*)(double)>(
              &QDoubleSpinBox::valueChanged),
          this, &MainWindow::onSpinYDoubleSpinBoxChanged);
  connect(ui->spinZdoubleSpinBox,
          static_cast<void (QDoubleSpinBox::*)(double)>(
              &QDoubleSpinBox::valueChanged),
          this, &MainWindow::onSpinZDoubleSpinBoxChanged);
}
MainWindow::~MainWindow() {
  if (ui->GLWidget->exist) {
    clean_mem_obj(&data);
    clean_mem_obj(&ui->GLWidget->copy_data);
  }
  saveSettings();
  delete ui;
}

void MainWindow::onScaleSliderValueChanged(int value) {
  double scale = (double)value / 100;
  emit scaleChanged(scale);
}
void MainWindow::onSpinXDoubleSpinBoxChanged(double value) {
  emit xSpinChanged(value);
}
void MainWindow::onSpinYDoubleSpinBoxChanged(double value) {
  emit ySpinChanged(value);
}
void MainWindow::onSpinZDoubleSpinBoxChanged(double value) {
  emit zSpinChanged(value);
}
void MainWindow::onMoveXDoubleSpinBoxChanged(double value) {
  emit xPosChanged(value);
}
void MainWindow::onMoveYDoubleSpinBoxChanged(double value) {
  emit yPosChanged(value);
}
void MainWindow::onMoveZDoubleSpinBoxChanged(double value) {
  emit zPosChanged(value);
}
void MainWindow::action_jpg_triggered() { scrinshot_settings = jpg; }
void MainWindow::action_bmp_triggered() { scrinshot_settings = bmp; }
void MainWindow::onIncreaseScaleButtonClicked() {
  int sliderValue = ui->scaleSlider->value();
  sliderValue++;
  if (sliderValue > ui->scaleSlider->maximum()) {
    sliderValue = ui->scaleSlider->maximum();
  }
  ui->scaleSlider->setValue(sliderValue);
}

void MainWindow::onDecreaseScaleButtonClicked() {
  int sliderValue = ui->scaleSlider->value();
  sliderValue--;
  if (sliderValue < ui->scaleSlider->minimum()) {
    sliderValue = ui->scaleSlider->minimum();
  }
  ui->scaleSlider->setValue(sliderValue);
}
void MainWindow::onScrinshotButtonClicked() {
  QPixmap pixmap = ui->GLWidget->grab();

  QString imagePath = NULL;
  if (scrinshot_settings) {
    imagePath = QFileDialog::getSaveFileName(this, NULL, NULL, "JPEG (*.jpg)");
    if (!imagePath.isNull()) pixmap.save(imagePath, "JPEG", 100);
  } else {
    imagePath = QFileDialog::getSaveFileName(this, NULL, NULL, "BMP (*.bmp)");
    if (!imagePath.isNull()) pixmap.save(imagePath, "BMP", 100);
  }
}
void MainWindow::onGIFButtonClicked() {
  gif = new QGifImage;
  gifTimer = new QTimer;
  connect(gifTimer, SIGNAL(timeout()), this, SLOT(recordGIF()));
  count_frames = 0;
  gifTimer->start(100);
}
void MainWindow::recordGIF() {
  count_frames++;
  QList<QImage> frames;
  QPixmap pixmap = ui->GLWidget->grab();
  frames.append(pixmap.toImage());
  gif->setDefaultDelay(100);

  foreach (const QImage& frame, frames) {
    gif->addFrame(frame);
  }
  if (count_frames == 50) {
    gifTimer->stop();
    QString gifSavePath = NULL;
    gifSavePath = QFileDialog::getSaveFileName(this, NULL, NULL, "GIF (*.gif)");
    if (!gifSavePath.isNull()) gif->save(gifSavePath);
  }
}
void MainWindow::onDecreaseVerticesButtonClicked() {
  int sliderValue = ui->verticesThiknessSlider->value();
  sliderValue--;
  if (sliderValue < ui->verticesThiknessSlider->minimum()) {
    sliderValue = ui->verticesThiknessSlider->minimum();
  }
  ui->verticesThiknessSlider->setValue(sliderValue);
}
void MainWindow::onIncreaseVerticesButtonClicked() {
  int sliderValue = ui->verticesThiknessSlider->value();

  sliderValue++;
  if (sliderValue > ui->verticesThiknessSlider->maximum()) {
    sliderValue = ui->verticesThiknessSlider->maximum();
  }
  ui->verticesThiknessSlider->setValue(sliderValue);
}
void MainWindow::onSliderVerticesValueChanged(int value) {
  float thikness = static_cast<float>(value);
  emit verticesWidthChanged(thikness);
}

void MainWindow::onDecreaseLinesButtonClicked() {
  int sliderValue = ui->linesThiknessSlider->value();

  sliderValue--;
  if (sliderValue < ui->linesThiknessSlider->minimum()) {
    sliderValue = ui->linesThiknessSlider->minimum();
  }
  ui->linesThiknessSlider->setValue(sliderValue);
}
void MainWindow::onIncreaseLinesButtonClicked() {
  int sliderValue = ui->linesThiknessSlider->value();

  sliderValue++;
  if (sliderValue > ui->linesThiknessSlider->maximum()) {
    sliderValue = ui->linesThiknessSlider->maximum();
  }
  ui->linesThiknessSlider->setValue(sliderValue);
}

void MainWindow::onSliderLinesValueChanged(int value) {
  float thikness = static_cast<float>(value);
  emit linesWidthChanged(thikness);
}

void MainWindow::actionSet_Solid_triggered() { emit linesTypeChanged(solid); }
void MainWindow::actionSet_Dashed_triggered() { emit linesTypeChanged(dashed); }
void MainWindow::actionSet_color_lines_triggered() {
  QColor linesC = QColorDialog::getColor(ui->GLWidget->linesColor, this,
                                         "Choose Lines Color");
  if (linesC.isValid()) {
    emit linesColorChanged(linesC);
  }
}

void MainWindow::actionSet_background_color_triggered() {
  QColor backC = QColorDialog::getColor(ui->GLWidget->backgroundColor, this,
                                        "Choose Background Color");
  if (backC.isValid()) {
    emit backColorChanged(backC);
  }
}
void MainWindow::actionSet_color_vertices_triggered() {
  QColor vertC = QColorDialog::getColor(ui->GLWidget->verticesColor, this,
                                        "Choose Vertices Color");
  if (vertC.isValid()) {
    emit verticesColorChanged(vertC);
  }
}
void MainWindow::action_None_triggered() { emit verticeTypeChanged(none); }
void MainWindow::actionCircle_triggered() { emit verticeTypeChanged(circle); }
void MainWindow::actionSquere_triggered() { emit verticeTypeChanged(square); }
void MainWindow::saveSettings() {
  myGlSettings->setValue("backgroundcolor", ui->GLWidget->backgroundColor);
  myGlSettings->setValue("verticescolor", ui->GLWidget->verticesColor);
  myGlSettings->setValue("verticetype", ui->GLWidget->verticesType);
  myGlSettings->setValue("linescolor", ui->GLWidget->linesColor);
  myGlSettings->setValue("linestype", ui->GLWidget->linesType);
  myGlSettings->setValue("linewidth", ui->GLWidget->lineWidth);
  myGlSettings->setValue("verticeswidth", ui->GLWidget->verticesWidth);
  myGlSettings->setValue("scrinshotsettings", this->scrinshot_settings);
}
void MainWindow::loadSettings() {
  QVariant backgoundSettings =
      myGlSettings->value("backgroundcolor", QColor(Qt::black));
  ui->GLWidget->backgroundColor = backgoundSettings.value<QColor>();

  QVariant verticesColorSettings =
      myGlSettings->value("verticescolor", QColor(Qt::red));
  ui->GLWidget->verticesColor = verticesColorSettings.value<QColor>();

  QVariant verticeTypeSettings = myGlSettings->value("verticetype", circle);
  ui->GLWidget->verticesType = verticeTypeSettings.value<int>();

  QVariant linesColorSettings =
      myGlSettings->value("linescolor", QColor(Qt::green));
  ui->GLWidget->linesColor = linesColorSettings.value<QColor>();

  QVariant linesTypeSettings = myGlSettings->value("linestype", solid);
  ui->GLWidget->linesType = linesTypeSettings.value<int>();

  QVariant linesWidthSettings = myGlSettings->value("linewidth", 1.0);
  ui->GLWidget->lineWidth = linesWidthSettings.value<float>();
  ui->linesThiknessSlider->setValue(ui->GLWidget->lineWidth);

  QVariant verticesWidthSettings = myGlSettings->value("verticeswidth", 10.0);
  ui->GLWidget->verticesWidth = verticesWidthSettings.value<float>();
  ui->verticesThiknessSlider->setValue(ui->GLWidget->verticesWidth);

  QVariant scrinshotSettings = myGlSettings->value("scrinshotsettings", jpg);
  this->scrinshot_settings = scrinshotSettings.value<int>();

  ui->scaleSlider->setValue(100);
}

void MainWindow::open_file() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open object File"),
                                                  "", tr("OBJ Files (*.obj)"));
  if (!fileName.isEmpty()) {
    if (ui->GLWidget->exist) {
      clean_mem_obj(&data);
      clean_mem_obj(&ui->GLWidget->copy_data);
    }
    QFileInfo fileInfo(fileName);
    QString justFileName = fileInfo.fileName();
    ui->fileNameOutup->setText(justFileName);
    QString QSPath = fileInfo.filePath();
    data = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    parse_obj_file(QSPath.toStdString().c_str(), &data);
    parse_obj_file(QSPath.toStdString().c_str(), &ui->GLWidget->copy_data);
    ui->label_output_l->setText(QString::number(data.edges_count));
    ui->label_output_v->setText(QString::number(data.vertices_count));
    ui->GLWidget->data = data;
    emit transform_arrays();
  } else {
    QMessageBox::warning(this, "Error", "Не удалось прочитать файл");
  }
}
