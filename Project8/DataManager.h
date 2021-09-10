#pragma once

#include <string>

#include "Point.h"

/*!
    \brief класс DataManager реализует манипуляцию с данными.
*/

class DataManager {
public:
    /*!
    Метод - конструктор по умолчанию.
    */
    DataManager();

    /*!
    Метод добавления строки с координатами из файла.
    \param _row Принимает точку для добавления
    */
    void addRow(const Point&& _row);

    /*!
    Метод - геттер для кол-ва точек.
    \return Кол-во точек в векторе
    */
    std::size_t getSize() const;

    /*!
    Метод - геттер для получения вектора с точками.
    \return Вектор точек
    */
    std::vector<Point>& getData();

    /*!
    Метод разибвающий входные данные из csv файла по разделителю.
    \param str, separator Строка входных данных и разделитель
    \return Вектор координат(в виде std::string)
    */
    std::vector<std::string> customSplit(const std::string& _str, char _separator) const;

    /*!
    Метод добавляющий файл и данные из него для работы алгоритма.
    \param _fileName Имя файла
    */
    void addFile(const std::string& _fileName);

    /*!
    Метод выводящий данные в файл
    */
    void outputAnswer();
private:
	/// Вектор точек подаваемых алгоритму кластеризации на вход
	std::vector<Point> m_points;

    /// Имя файла из которого берем данные и в который выводим
    std::string m_fileName;

    /// Вектор строк исходных данных для вывода в файл(что бы не переводить по новой координаты в std::string)
    std::vector<std::string> m_rowDataInFile;

    /// Разделитель csv файла - ';'
    char m_separator;
};