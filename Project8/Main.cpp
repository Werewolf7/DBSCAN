#include "Commander.h"

#include <iostream>

int main() {

	Commander* c = Commander::getInstance();

	DataManager* dM = c->getDataManager();
	DBSCAN* DBSCAN = c->getDBSCAN();

	std::size_t minPts;
	double radius;
	std::string filePath{ "" };

	std::cout << "Input File path";
	std::cin >> filePath;

	std::cout << "Input Min Points: ";
	std::cin >> minPts;

	std::cout << "\nInput Radius: ";
	std::cin >> radius;

	DBSCAN->setMinPoints(minPts);
	DBSCAN->setRaduis(radius);
	dM->addFile(filePath);

	//dM->addFile("test.csv");

	c->getDBSCAN()->work();

	dM->outputAnswer();

	Commander::resetInstance();

	return 0;
}