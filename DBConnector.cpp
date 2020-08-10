#include "DBConnector.h"
#pragma comment(lib, "libmySQL.lib")

DBConnector::DBConnector()
{

}

DBConnector::~DBConnector()
{

}

void DBConnector::ConnectDB()
{
	mysql_real_connect(con, "127.0.0.1",
		"root", "1234", "testschema", 3306, NULL, 0);
}

void DBConnector::DBSendQuery(std::string query)
{
	mysql_query(con, query.c_str());
}

MYSQL_ROW_OFFSET DBConnector::DBGetResult()
{
	res = mysql_store_result(con);
	return mysql_row_tell(res);
}

void DBConnector::FreeResult()
{

}

void DBConnector::CloseDB()
{

}