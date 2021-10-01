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

	/*cout << "학번 : ";
	cin >> id;
	cout << "비밀번호 : ";
	cin >> pw;
	cout << "이름 : ";
	cin >> name;

	// 쿼리:레코드삽입
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

		res = mysql_store_result(mysql);		// Result set에 저장

		while ((row = mysql_fetch_row(res)) != NULL) {		// Result set에서 1개씩 배열을 가져옴

			cout << row[0] << " " << row[1] << " " << row[2] << endl;					// 저장된 배열을 출력

		}

		// Result set 해제
		mysql_free_result(res);
	}
	// DB서버 종료
	mysql_close(mysql);

}