#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <mysql.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#pragma comment(lib, "libmysql.lib")
using namespace std;

#define MYSQLID "localhost"	
#define MYSQLUSER "root"
#define MYSQLPW "2118"	
#define MYSQLDB "test_db"	
MYSQL* mysql = mysql_init(NULL);
MYSQL_RES* res;
MYSQL_ROW row;


// main
int main() {


	if (!mysql_real_connect(mysql, MYSQLID, MYSQLUSER, MYSQLPW, MYSQLDB, 3308, NULL, 0)) cout << "error" << endl;
	else {
		cout << "success" << endl;
		mysql_set_character_set(mysql, "euckr");
	}

	// �ѱ۷� �Է¹ޱ� ����
	mysql_query(mysql, "set session character_set_connection=euckr;");
	mysql_query(mysql, "set session character_set_results=euckr;");
	mysql_query(mysql, "set session character_set_client=euckr;");

	char* name = (char*)malloc(sizeof(char) * 100);
	int num = 0;

	cout << "�̸��� �Է����ּ��� : ";
	cin >> name;
	cout << "�й��� �Է����ּ��� : ";
	cin >> num;

	// insert
	int query_stat;
	char query[1024];
	sprintf(query, "insert into user(hakbun, name) values('%d','%s')", num, name);

	query_stat = mysql_query(mysql, query);


	// ��� ���α׷��� ���� ���� ��
	system("pause");
}