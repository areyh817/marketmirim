#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <WinSock2.h>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")
using namespace std;

const char* host = "localhost";
const char* user = "root";
const char* pw = "2118";
const char* db = "study_db";
int query_stat;


int main(int argc, char* argv[]) {
	MYSQL* connection = NULL;
	MYSQL conn;
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	//�ѱۻ���������߰�.
	/*/mysql_query(connection, "set session character_set_connection=euckr;");
	mysql_query(connection, "set session character_set_results=euckr;");
	mysql_query(connection, "set session character_set_client=euckr;");*/

	connection = mysql_real_connect(&conn, host, user, pw, db, 3308, (const char*)NULL, 0);

	// ���� ���� ó��
	if (connection == NULL) {
		cout << mysql_errno(&conn) << " ���� : " << mysql_error(&conn);			// ���� �������� �� ���� ���� ���
		return 1;
	}


	/*int id;
	char* pw;
	char* name;

	cout << "�й� : ";
	cin >> id;
	cout << "��й�ȣ : ";
	cin >> pw;
	cout << "�̸� : ";
	cin >> name;

	// ����:���ڵ����
	char query[255];
	sprintf(query, "INSERT INTO user VALUES(%d, '%s', '%s')", id, pw, name);
	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		printf("error : %s", mysql_error(&conn));
		return 1;
	}*/





	

}