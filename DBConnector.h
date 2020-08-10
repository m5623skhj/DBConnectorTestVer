#pragma once

#include <mysql.h>
#include <unordered_map>
#include <string>

class DBConnector
{
public :
	struct ROW_ARRAY
	{
		char* operator[](std::string columnName)
		{
			auto findIter = itemMap->find(columnName);
			if (findIter == itemMap->end())
				return nullptr;

			//return &_row[findIter->second];
			return _row->data[findIter->second];
		}

		MYSQL_ROWS*		_row;
		std::unordered_map<std::string, int>* itemMap;
	};

	DBConnector();
	~DBConnector();

	void ConnectDB();
	void DBSendQuery(std::string query);
	void DBStoreResult();
	MYSQL_ROWS* DBGetResult();
	ROW_ARRAY* GetDBArr();

	void DBArray();

	void FreeResult();
	void FreeResult(ROW_ARRAY* deleteRow);
	void CloseDB();

private :
	MYSQL*									_con;
	MYSQL_RES*								_res;
	std::unordered_map<std::string, int>	_rowMap;
};