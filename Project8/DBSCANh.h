#pragma once

#include "Point.h"

/*!
	\brief класс DBSCAN реализует работу алгоритма.
*/

class DBSCAN {
public:
	/*!
	ќсновной метод работы алгоритма DBSCAN.
	*/
	void work();

	/*!
	ћетод установки радиуса поиска.
	\param _eps - радиус поиска
	*/
	void setRaduis(double _eps);

	/*!
	ћетод установки минимального кол-ва точек в кластере.
	\param _minPoints - минимальное кол-во точек в кластере
	*/
	void setMinPoints(std::size_t _minPoints);
private:
	/*!
	ћетод определ€ющий €вл€ютс€ ли точки сосед€ми.
	\param _point1, _point2 - точки дл€ проверки их соседства
	\return явл€ютс€ ли сосед€ми или нет (true, false)
	*/
	bool isNeighbors(const Point& _point1, const Point& _point2) const;

	/*!
	ћетод добавл€ющий точку в кластер(расширение кластера).
	\param _point, _id - точка дл€ добавлени€ и номер кластера
	\return ƒобавление прошло успешно или нет
	*/
	int addToCluster(Point& _point, int _id);

	/*!
	ћетод наход€щий соседей точки и конструирующий вектор с их индексами.
	\param _point - точка у которой ищем соседей
	\return ¬ектор индексов соседей
	*/
	std::vector<int> searchAndConstructForNeighborIndexes(const Point& _point) const;

private:
	/// радиус поиска
	double m_eps = 40;

	/// минимальное кол-во точек в кластере
	std::size_t m_minPoints = 2;
};