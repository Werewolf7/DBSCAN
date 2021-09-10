#pragma once

#include <vector>

/*!
    \brief перечисление InformationAboutPoint, которое ассоциирует точку данных со значением (шум, не классифиццирована).
*/

enum class InformationAboutPoint {
    NOISE = -1,
    UNCLASSIFIED = 0
};

/*!
    \brief класс Point вспомогательный класс, для работы с одной точкой данных (в n мерном пространстве).
*/

class Point{
public:
    /*!
    Метод - конструктор по умолчанию.
    */
    Point();

    /*!
    Метод - конструктор с параметрами.
    \param _coordinates вектор координат для построения точки
    */
    Point(std::vector<double>& _coordinates);

    /*!
    Метод для расчета расстояния между двумя точками.
    \param _point1, _point2 точки для нахождения расстояния между ними
    \return Расстояние между точками
    */
    static double distanceBetweenPoints(const Point& _point1, const Point& _point2);

    /*!
    Метод-геттер предоставляющий id кластера у точки.
    \return id кластера
    */
    int getIdCluster() const;

    /*!
    Метод-геттер предоставляющий мерность пространства.
    \return Кол-во координат у точки
    */
    int getDimensionSpace() const;

    /*!
    Метод-сеттер для установки id кластера.
    */
    void setIdCluster(int _classification);
public:
    /*!
    Перегрузка оператора != для класса Point.
    \param _point1, _point2 точки
    \return Результат проверки на != двух точек (сравнение идет по каждой координате)
    */
    friend bool operator != (const Point& _point1, const Point& _point2);

    /*!
    Перегрузка оператора == для класса Point.
    \param _point1, _point2 точки
    \return Результат проверки на == двух точек (сравнение идет по каждой координате)
    */
    friend bool operator == (const Point& _point1, const Point& _point2);
private:
    /// вектор координат точки
    std::vector<double> m_coordinates;

    /// номер кластера к которому принадлежит точка
    int m_idCluster;
};