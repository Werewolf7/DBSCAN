#include "Commander.h"

Commander* Commander::m_instance = nullptr;

Commander* Commander::getInstance() {

    if (m_instance == nullptr) {

        m_instance = new Commander();

    }

    return m_instance;

}

Commander::Commander() {

    m_dataForDBSCAN = new DataManager();

    m_dbscan = new DBSCAN();

}

DataManager* Commander::getDataManager() {

    return m_dataForDBSCAN;

}

DBSCAN* Commander::getDBSCAN() {

    return m_dbscan;

}

void Commander::resetInstance() {

    delete m_instance;

}

Commander::~Commander() {

    delete m_dataForDBSCAN;
    m_dataForDBSCAN = nullptr;

    delete m_dbscan;
    m_dbscan = nullptr;

}