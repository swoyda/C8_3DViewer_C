#ifndef C8_3DVIEWER_V1_0_1_AFFINE_TRANSFORMATIONS_H
#define C8_3DVIEWER_V1_0_1_AFFINE_TRANSFORMATIONS_H

#include "s21_3dviewer.h"
#include <math.h>

#define M_PI 3.14159265358979323846
/**
 * @brief Перемещает объект вдоль оси X.
 *
 * Функция смещает все вершины объекта вдоль оси X на заданное значение.
 *
 * @param data Указатель на структуру obj_data, содержащую данные объекта.
 * @param k Величина смещения вдоль оси X.
 */
void move_X(obj_data *data, const double k);

/**
 * @brief Перемещает объект вдоль оси Y.
 *
 * Функция смещает все вершины объекта вдоль оси Y на заданное значение.
 *
 * @param data Указатель на структуру obj_data, содержащую данные объекта.
 * @param k Величина смещения вдоль оси Y.
 */
void move_Y(obj_data *data, const double k);

/**
 * @brief Перемещает объект вдоль оси Z.
 *
 * Функция смещает все вершины объекта вдоль оси Z на заданное значение.
 *
 * @param data Указатель на структуру obj_data, содержащую данные объекта.
 * @param k Величина смещения вдоль оси Z.
 */
void move_Z(obj_data *data, const double k);

/**
 * @brief Поворачивает объект вокруг оси X.
 *
 * Функция вращает все вершины объекта вокруг оси X на заданный угол.
 *
 * @param data Указатель на структуру obj_data, содержащую данные объекта.
 * @param angle Угол поворота в радианах.
 */
void rotate_X(obj_data *data, double angle);

/**
 * @brief Поворачивает объект вокруг оси Y.
 *
 * Функция вращает все вершины объекта вокруг оси Y на заданный угол.
 *
 * @param data Указатель на структуру obj_data, содержащую данные объекта.
 * @param angle Угол поворота в радианах.
 */
void rotate_Y(obj_data *data, double angle);

/**
 * @brief Поворачивает объект вокруг оси Z.
 *
 * Функция вращает все вершины объекта вокруг оси Z на заданный угол.
 *
 * @param data Указатель на структуру obj_data, содержащую данные объекта.
 * @param angle Угол поворота в радианах.
 */
void rotate_Z(obj_data *data, double angle);

/**
 * @brief Масштабирует объект.
 *
 * Функция масштабирует объект, изменяя размеры всех его вершин относительно начала координат на заданный коэффициент.
 *
 * @param data Указатель на структуру obj_data, содержащую данные объекта.
 * @param k Коэффициент масштабирования (значение больше 1 увеличивает объект, меньше 1 — уменьшает).
 */
void scale(obj_data *data, const double k);


#endif  // C8_3DVIEWER_V1_0_1_AFFINE_TRANSFORMATIONS_H