#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <WinSock2.h>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")
using namespace std;
#define MYSQLIP "localhost"	
#define MYSQLUSER "root"
#define MYSQLPW "2118"	
#define MYSQLDB "study_db"	
MYSQL* mysql = mysql_init(NULL);
MYSQL_RES* res;
MYSQL_ROW row;

int main(int argc, char* argv[]) {


	if (!mysql_real_connect(mysql, MYSQLIP, MYSQLUSER, MYSQLPW, MYSQLDB, 3308, NULL, 0))
		cout << "error" << endl;
	else {
		cout << "success" << endl;
		mysql_set_character_set(mysql, "euckr");
	}


	
	int id;
	char* name = (char*)malloc(sizeof(char) * 50);
	char* pw = (char*)malloc(sizeof(char) * 50);
	int query_stat;

	/*cout << "�й� : ";
	cin >> id;
	cout << "��й�ȣ : ";
	cin >> pw;
	cout << "�̸� : ";
	cin >> name;

	// ����:���ڵ����
	char query[255];
	sprintf(query, "INSERT INTO user VALUES(%d, '%s', '%s')", id, pw, name);
	int stat = mysql_query(mysql, query);
	if (stat != 0) {
		printf("error : %s", mysql_error(mysql));
		return 1;
	}*/


	char query2[100];
	sprintf(query2, "select foodname, cnt, money from product where id = %d", 2118);
	int state2 = 0;

	state2 = mysql_query(mysql, query2);

	if (state2 == 0) {

		res = mysql_store_result(mysql);		// Result set�� ����

		while ((row = mysql_fetch_row(res)) != NULL) {		// Result set���� 1���� �迭�� ������

			cout << row[0] << " " << row[1] << " " << row[2] << endl;					// ����� �迭�� ���

		}

		// Result set ����
		mysql_free_result(res);
	}
	// DB���� ����
	mysql_close(mysql);

}