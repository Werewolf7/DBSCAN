#pragma once

#include "DataManager.h"
#include "DBSCANh.h"

/*!
	\brief ����� Commander ��������� �������������� ������� ���� � ������.
*/

class Commander {
public:

	/*!
	����� - ������ ��� ��������� �������� ������ Commander
	\return ��������� �� ������ ������ Commander
	*/
	static Commander* getInstance();

	/*!
	����� - ������ ��� ��������� ��������� �� ��������� DataManager'�
	\return ��������� �� ������ ������ DataManager
	*/
	DataManager* getDataManager();

	/*!
	����� - ������ ��� ��������� ��������� �� ��������� DBSCAN'�
	\return ��������� �� ������ ������ DBSCAN
	*/
	DBSCAN* getDBSCAN();

	/*!
	����� ��������� ���������, ��� ��������� memory-leak.
	*/
	static void resetInstance();
private:

	/*!
	����� - ����������� �� ���������
	*/
	Commander();

	/*!
	����� �����������-�����������
	*/
	Commander(const Commander& _commander) = delete;

	/*!
	����� �������� ������������
	*/
	Commander& operator=(Commander& _commadner) = delete;

	/*!
	����� - ����������.
	*/
	~Commander();
private:
	/// ������� ����������
	static Commander* m_instance;

	/// ������ ����-��������� ��� �������������� � ���(���������)
	DataManager* m_dataForDBSCAN;

	/// ������ dbscan ��� �������������� � ���������� �������������
	DBSCAN* m_dbscan;
};