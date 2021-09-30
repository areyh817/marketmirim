#include <iostream>
#include <WinSock2.h>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")
using namespace std;

const char* host = "localhost";
const char* user = "root";
const char* pw = "2118";
const char* db = "study_db";


int main(int argc, char* argv[]) {
	MYSQL* connection = NULL;
	MYSQL conn;
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;


	if (mysql_init(&conn) == NULL) {
		printf("mysql_init() error!");
	}


	connection = mysql_real_connect(&conn, host, user, pw, db, 3308, (const char*)NULL, 0);

	// ���� ���� ó��
	if (connection == NULL) {
		cout << mysql_errno(&conn) << " ���� : " << mysql_error(&conn);			// ���� �������� �� ���� ���� ���
		return 1;
	}

	else { cout << "���� ���� ! \n"; }	// ���ῡ �������� ��


	const char* query = "select * from user";
	int state = 0;

	state = mysql_query(connection, query);

	if (state == 0) {

		sql_result = mysql_store_result(connection);		// Result set�� ����

		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {		// Result set���� 1���� �迭�� ������

			cout << sql_row[0] << " " << sql_row[1] << " " << sql_row[2] << endl;					// ����� �迭�� ���

		}

		// Result set ����
		mysql_free_result(sql_result);
	}

	// DB���� ����
	mysql_close(connection);

}