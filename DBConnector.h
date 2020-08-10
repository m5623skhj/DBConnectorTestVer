#pragma once

#include <mysql.h>
#include <unordered_map>
#include <string>

class DBConnector
{
public :
	DBConnector();
	~DBConnector();

	void ConnectDB();
	void DBSendQuery(std::string query);
	MYSQL_ROW_OFFSET DBGetResult();
	void FreeResult();
	void CloseDB();

private :
	MYSQL* con;
	MYSQL_RES* res;
};