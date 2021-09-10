#pragma once

#include "DataManager.h"
#include "DBSCANh.h"

/*!
	\brief класс Commander реализует взаимодействие классов друг с другом.
*/

class Commander {
public:

	/*!
	Метод - геттер для получения инстанса класса Commander
	\return Указатель на объект класса Commander
	*/
	static Commander* getInstance();

	/*!
	Метод - геттер для получения указателя на экземпляр DataManager'а
	\return Указатель на объект класса DataManager
	*/
	DataManager* getDataManager();

	/*!
	Метод - геттер для получения указателя на экземпляр DBSCAN'а
	\return Указатель на объект класса DBSCAN
	*/
	DBSCAN* getDBSCAN();

	/*!
	Метод очищающий коммандер, для избежания memory-leak.
	*/
	static void resetInstance();
private:

	/*!
	Метод - конструктор по умолчанию
	*/
	Commander();

	/*!
	Удалён конструктор-копирования
	*/
	Commander(const Commander& _commander) = delete;

	/*!
	Удалён оператор присваивания
	*/
	Commander& operator=(Commander& _commadner) = delete;

	/*!
	Метод - деструктор.
	*/
	~Commander();
private:
	/// Инстанс коммандера
	static Commander* m_instance;

	/// Объект дата-менеджера для взаимодействия с ним(указатель)
	DataManager* m_dataForDBSCAN;

	/// Объект dbscan для взаимодействия с алгоритмом кластеризации
	DBSCAN* m_dbscan;
};