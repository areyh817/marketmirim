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

	// 연결 에러 처리
	if (connection == NULL) {
		cout << mysql_errno(&conn) << " 에러 : " << mysql_error(&conn);			// 연결 실패했을 때 에러 구문 출력
		return 1;
	}

	else { cout << "연결 성공 ! \n"; }	// 연결에 성공했을 때


	const char* query = "select * from user";
	int state = 0;

	state = mysql_query(connection, query);

	if (state == 0) {

		sql_result = mysql_store_result(connection);		// Result set에 저장

		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {		// Result set에서 1개씩 배열을 가져옴

			cout << sql_row[0] << " " << sql_row[1] << " " << sql_row[2] << endl;					// 저장된 배열을 출력

		}

		// Result set 해제
		mysql_free_result(sql_result);
	}

	// DB서버 종료
	mysql_close(connection);

}