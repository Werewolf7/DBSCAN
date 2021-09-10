#include "Point.h"

#include <cmath>
#include <limits>


Point::Point() : m_idCluster{ static_cast<int>(InformationAboutPoint::UNCLASSIFIED) } {}

Point::Point(std::vector<double>& _coordinates) : m_coordinates{ _coordinates }, m_idCluster{ static_cast<int>(InformationAboutPoint::UNCLASSIFIED) } {}

double Point::distanceBetweenPoints(const Point& _point1, const Point& _point2) {

	double accumulate{ 0 };

	for (std::size_t i{ 0 }; i < _point1.m_coordinates.size(); ++i) {

		accumulate += std::powf(_point2.m_coordinates[i] - _point1.m_coordinates[i], 2);

	}

	return std::sqrt(accumulate);

}

bool operator != (const Point& _point1, const Point& _point2){

	for (std::size_t i{ 0 }; i < _point1.m_coordinates.size(); ++i) {

		// Так как сравниваем не целое число, для корректного сравнения ->
		if (!std::fabs(_point1.m_coordinates[i] - _point2.m_coordinates[i]) 
			< 
			std::numeric_limits<double>::epsilon()
			) {
			return true;
		}

	}

	return false;

}

int Point::getIdCluster() const {

	return m_idCluster;

}

void Point::setIdCluster(int _classification) {

	m_idCluster = _classification;

}

bool operator == (const Point& _point1, const Point& _point2) {

	return !(_point1 != _point2);

}

int Point::getDimensionSpace() const {

	return m_coordinates.size();

}