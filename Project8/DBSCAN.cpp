#include "Commander.h"

#include <fstream>

enum class InformationAboutAdding {
	INCORRECT = -3,
	CORRECT = -2
};

bool DBSCAN::isNeighbors(const Point& _point1, const Point& __point2) const {

	return Point::distanceBetweenPoints(_point1, __point2) <= m_eps ? true : false;

}

void DBSCAN::work() {

	//�������� �������� � ������ 1
	int currentClusterNumber = 1;

	DataManager* dataManager = Commander::getInstance()->getDataManager();

	std::vector<Point>& points = dataManager->getData();

	for (auto itPoints = points.begin(); itPoints != points.end(); ++itPoints) {
		//���� ������� ����� ��� �� ������������� � ����� ���� ��������� � �� ���
		if (itPoints->getIdCluster() == static_cast<int>(InformationAboutPoint::UNCLASSIFIED)) {
			//���� ���������� ������ �� ���������, ������ ����� �������� �����
			if (addToCluster(*itPoints, currentClusterNumber) != static_cast<int>(InformationAboutAdding::INCORRECT)) {

				++currentClusterNumber;

			}
		}
	}
}

int DBSCAN::addToCluster(Point& _point, int _id) {

	int index{ 0 };

	int indexCorePoint{ 0 };

	std::vector<int> neighboringPoints = std::move(searchAndConstructForNeighborIndexes(_point));

	//���� �� ��������� ������ �����, ��� ������ ���� � ������� -> ���
	if (neighboringPoints.size() < m_minPoints) {

		_point.setIdCluster(static_cast<int>(InformationAboutPoint::NOISE));

		return static_cast<int>(InformationAboutAdding::INCORRECT);

	}

	DataManager* dataManager = Commander::getInstance()->getDataManager();

	std::vector<Point>& points = dataManager->getData();

	for (auto itNeighboringPoints = neighboringPoints.begin(); 
		itNeighboringPoints != neighboringPoints.end(); 
		++itNeighboringPoints) {

		//��� ������������� ����� ������������� ����� ��������
		points[*itNeighboringPoints].setIdCluster(_id);

		//���� ����� �����, ������� ����������
		if (points[*itNeighboringPoints] == _point) {

			//���������� ������ ������� �����
			indexCorePoint = index;

		}

		++index;
	}

	neighboringPoints.erase(neighboringPoints.begin() + indexCorePoint);

	auto clusterSize = neighboringPoints.size();

	for (auto i{ 0 }; i < clusterSize; ++i) {

		//��� ������ ������������� �����, �������� �������
		std::vector<int> clusterNeighbors = std::move(searchAndConstructForNeighborIndexes(points[neighboringPoints[i]]));

		// ���� ������� ������ (�����) ��� ����������� ���-�� ����� � ��������
		if (clusterNeighbors.size() >= m_minPoints) {

			for (auto itNeighbors = clusterNeighbors.begin(); itNeighbors != clusterNeighbors.end(); ++itNeighbors) {

				//���� ����� �� �� ����������������
				if (points[*itNeighbors].getIdCluster() == static_cast<int>(InformationAboutPoint::UNCLASSIFIED)) {

					//��� �������� � ������������� �����(������)
					neighboringPoints.push_back(*itNeighbors);

					clusterSize = neighboringPoints.size();

					//����������� �� id ��������
					points[*itNeighbors].setIdCluster(_id);

				}

				// ���� ����� ���� �������� ��� ���, ����������� �� ����� ��������
				else if (points[*itNeighbors].getIdCluster() == static_cast<int>(InformationAboutPoint::NOISE)) {

					points[*itNeighbors].setIdCluster(_id);

				}

			}
		}
	}
	return static_cast<int>(InformationAboutAdding::CORRECT);
}

// ������ RangeQuery �� wiki
std::vector<int> DBSCAN::searchAndConstructForNeighborIndexes(const Point& _point) const {

	std::vector<int> indexesPoints;

	int index{ 0 };

	DataManager* dataManager = Commander::getInstance()->getDataManager();

	std::vector<Point>& points = dataManager->getData();

	for (auto it = points.begin(); it != points.end(); ++it, ++index) {

		if (isNeighbors(_point, *it)) {

			indexesPoints.push_back(index);

		}

	}

	return indexesPoints;
}

void DBSCAN::setRaduis(double _eps) {

	m_eps = _eps;

}

void DBSCAN::setMinPoints(std::size_t _minPoints) {

	m_minPoints = _minPoints;

}