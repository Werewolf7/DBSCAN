#pragma once

#include <string>

#include "Point.h"

/*!
    \brief ����� DataManager ��������� ����������� � �������.
*/

class DataManager {
public:
    /*!
    ����� - ����������� �� ���������.
    */
    DataManager();

    /*!
    ����� ���������� ������ � ������������ �� �����.
    \param _row ��������� ����� ��� ����������
    */
    void addRow(const Point&& _row);

    /*!
    ����� - ������ ��� ���-�� �����.
    \return ���-�� ����� � �������
    */
    std::size_t getSize() const;

    /*!
    ����� - ������ ��� ��������� ������� � �������.
    \return ������ �����
    */
    std::vector<Point>& getData();

    /*!
    ����� ����������� ������� ������ �� csv ����� �� �����������.
    \param str, separator ������ ������� ������ � �����������
    \return ������ ���������(� ���� std::string)
    */
    std::vector<std::string> customSplit(const std::string& _str, char _separator) const;

    /*!
    ����� ����������� ���� � ������ �� ���� ��� ������ ���������.
    \param _fileName ��� �����
    */
    void addFile(const std::string& _fileName);

    /*!
    ����� ��������� ������ � ����
    */
    void outputAnswer();
private:
	/// ������ ����� ���������� ��������� ������������� �� ����
	std::vector<Point> m_points;

    /// ��� ����� �� �������� ����� ������ � � ������� �������
    std::string m_fileName;

    /// ������ ����� �������� ������ ��� ������ � ����(��� �� �� ���������� �� ����� ���������� � std::string)
    std::vector<std::string> m_rowDataInFile;

    /// ����������� csv ����� - ';'
    char m_separator;
};