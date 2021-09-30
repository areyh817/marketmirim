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

	//한글사용을위해추가.
	/*/mysql_query(connection, "set session character_set_connection=euckr;");
	mysql_query(connection, "set session character_set_results=euckr;");
	mysql_query(connection, "set session character_set_client=euckr;");*/

	connection = mysql_real_connect(&conn, host, user, pw, db, 3308, (const char*)NULL, 0);

	// 연결 에러 처리
	if (connection == NULL) {
		cout << mysql_errno(&conn) << " 에러 : " << mysql_error(&conn);			// 연결 실패했을 때 에러 구문 출력
		return 1;
	}


	/*int id;
	char* pw;
	char* name;

	cout << "학번 : ";
	cin >> id;
	cout << "비밀번호 : ";
	cin >> pw;
	cout << "이름 : ";
	cin >> name;

	// 쿼리:레코드삽입
	char query[255];
	sprintf(query, "INSERT INTO user VALUES(%d, '%s', '%s')", id, pw, name);
	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		printf("error : %s", mysql_error(&conn));
		return 1;
	}*/





	

}