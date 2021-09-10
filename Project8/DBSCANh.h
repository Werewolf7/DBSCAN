#pragma once

#include "Point.h"

/*!
	\brief ����� DBSCAN ��������� ������ ���������.
*/

class DBSCAN {
public:
	/*!
	�������� ����� ������ ��������� DBSCAN.
	*/
	void work();

	/*!
	����� ��������� ������� ������.
	\param _eps - ������ ������
	*/
	void setRaduis(double _eps);

	/*!
	����� ��������� ������������ ���-�� ����� � ��������.
	\param _minPoints - ����������� ���-�� ����� � ��������
	*/
	void setMinPoints(std::size_t _minPoints);
private:
	/*!
	����� ������������ �������� �� ����� ��������.
	\param _point1, _point2 - ����� ��� �������� �� ���������
	\return �������� �� �������� ��� ��� (true, false)
	*/
	bool isNeighbors(const Point& _point1, const Point& _point2) const;

	/*!
	����� ����������� ����� � �������(���������� ��������).
	\param _point, _id - ����� ��� ���������� � ����� ��������
	\return ���������� ������ ������� ��� ���
	*/
	int addToCluster(Point& _point, int _id);

	/*!
	����� ��������� ������� ����� � �������������� ������ � �� ���������.
	\param _point - ����� � ������� ���� �������
	\return ������ �������� �������
	*/
	std::vector<int> searchAndConstructForNeighborIndexes(const Point& _point) const;

private:
	/// ������ ������
	double m_eps = 40;

	/// ����������� ���-�� ����� � ��������
	std::size_t m_minPoints = 2;
};