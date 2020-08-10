#include "DBConnector.h"
#include <iostream>

DBConnector::DBConnector()
{

}

DBConnector::~DBConnector()
{

}

void DBConnector::ConnectDB()
{
	_con = mysql_init(nullptr);
	if (!mysql_real_connect(_con, "127.0.0.1",
		"root", "1234", "testschema", 3306, NULL, 0))
	{
		std::cout << mysql_error(_con);
	}
}

void DBConnector::DBSendQuery(std::string query)
{
	if(mysql_query(_con, query.c_str()) != 0)
	{
		std::cout << mysql_error(_con);
	}
}

void DBConnector::DBStoreResult()
{
	_res = mysql_store_result(_con);
}

MYSQL_ROWS* DBConnector::DBGetResult()
{
	return mysql_row_tell(_res);
}

DBConnector::ROW_ARRAY* DBConnector::GetDBArr()
{
	//res = mysql_store_result(con);
	ROW_ARRAY* row = new ROW_ARRAY();
	row->_row = mysql_row_tell(_res);
	row->itemMap = &_rowMap;

	return row;
}

void DBConnector::DBArray()
{
	MYSQL_FIELD* field = mysql_fetch_fields(_res);
	int numOfFields = mysql_num_fields(_res);
	for(int i=0; i<numOfFields; ++i)
	{
		_rowMap.insert({ field[i].name, i });
	}
}

void DBConnector::FreeResult()
{
	mysql_free_result(_res);
}

void DBConnector::FreeResult(ROW_ARRAY* deleteRow)
{
	if (deleteRow != nullptr)
	{
		delete deleteRow;
		deleteRow = nullptr;
	}

	mysql_free_result(_res);
}

void DBConnector::CloseDB()
{
	mysql_close(_con);
}