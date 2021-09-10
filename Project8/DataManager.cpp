#include "DataManager.h"

#include <fstream>
#include <iostream>
#include <sstream>

DataManager::DataManager() : m_separator{ ';' } {
}

void DataManager::addRow(const Point&& _row){

    m_points.push_back(_row);

}

std::size_t DataManager::getSize() const {

    return m_points.size();

}

std::vector<Point>& DataManager::getData() {

    return m_points;

}

std::vector<std::string> DataManager::customSplit(const std::string& _str, char _separator) const {

    std::vector<std::string> tokens;

    std::string token;

    std::istringstream tokenStream(_str);

    while (std::getline(tokenStream, token, _separator)){

        tokens.push_back(token);

    }

    return tokens;

}

void DataManager::addFile(const std::string& _fileName) {

    //Очистка на случай добавления нового файла
    m_rowDataInFile.clear();

    m_rowDataInFile.shrink_to_fit();

    m_points.clear();

    m_points.shrink_to_fit();

    std::ifstream file(_fileName);

    m_fileName = _fileName;

    if (!file.is_open()) {

        std::cout << "Error";

    }

    std::string readStrFromFile;

    std::vector<std::string> strDataInRow;

    std::vector<double> dataInRow;

    //Читаем каждую строку файла
    while (std::getline(file, readStrFromFile)) {

        //Сохраняем строку для формирования строки с ответом
        m_rowDataInFile.push_back(readStrFromFile);

        //Тут храним раздитую строку по разделителю
        strDataInRow = std::move(customSplit(readStrFromFile, m_separator));

        //Добавляем каждое число из строки в вектор double
        for (auto& el : strDataInRow) {

            dataInRow.push_back(std::stod(el));

        }
        
        //Из вектора формируем точку и запоминаем её
        m_points.push_back(Point(dataInRow));

        dataInRow.clear();
    }
}

void DataManager::outputAnswer() {

    std::ofstream answerFile(m_fileName);

    for (std::size_t i{ 0 }; i < m_points.size(); ++i) {

        m_rowDataInFile[i] += m_separator + std::to_string(m_points[i].getIdCluster());

    }

    for (auto it = m_rowDataInFile.begin(); it != m_rowDataInFile.end(); ++it) {

        answerFile << *it << "\n";

    }
}