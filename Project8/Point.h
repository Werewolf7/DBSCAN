#pragma once

#include <vector>

/*!
    \brief ������������ InformationAboutPoint, ������� ����������� ����� ������ �� ��������� (���, �� �����������������).
*/

enum class InformationAboutPoint {
    NOISE = -1,
    UNCLASSIFIED = 0
};

/*!
    \brief ����� Point ��������������� �����, ��� ������ � ����� ������ ������ (� n ������ ������������).
*/

class Point{
public:
    /*!
    ����� - ����������� �� ���������.
    */
    Point();

    /*!
    ����� - ����������� � �����������.
    \param _coordinates ������ ��������� ��� ���������� �����
    */
    Point(std::vector<double>& _coordinates);

    /*!
    ����� ��� ������� ���������� ����� ����� �������.
    \param _point1, _point2 ����� ��� ���������� ���������� ����� ����
    \return ���������� ����� �������
    */
    static double distanceBetweenPoints(const Point& _point1, const Point& _point2);

    /*!
    �����-������ ��������������� id �������� � �����.
    \return id ��������
    */
    int getIdCluster() const;

    /*!
    �����-������ ��������������� �������� ������������.
    \return ���-�� ��������� � �����
    */
    int getDimensionSpace() const;

    /*!
    �����-������ ��� ��������� id ��������.
    */
    void setIdCluster(int _classification);
public:
    /*!
    ���������� ��������� != ��� ������ Point.
    \param _point1, _point2 �����
    \return ��������� �������� �� != ���� ����� (��������� ���� �� ������ ����������)
    */
    friend bool operator != (const Point& _point1, const Point& _point2);

    /*!
    ���������� ��������� == ��� ������ Point.
    \param _point1, _point2 �����
    \return ��������� �������� �� == ���� ����� (��������� ���� �� ������ ����������)
    */
    friend bool operator == (const Point& _point1, const Point& _point2);
private:
    /// ������ ��������� �����
    std::vector<double> m_coordinates;

    /// ����� �������� � �������� ����������� �����
    int m_idCluster;
};