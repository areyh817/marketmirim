#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")
using namespace std;

#define MYSQLID "localhost"	
#define MYSQLUSER "root"
#define MYSQLPW "2118"	
#define MYSQLDB "marketmirim"	
MYSQL* mysql = mysql_init(NULL);
MYSQL_RES* res;
MYSQL_ROW row;

int id;
int fields;
int key;
int adminmoney;
int admincount;
int foodnum;
int foodisertnum;
char* name = (char*)malloc(sizeof(char) * 50);
char* pw = (char*)malloc(sizeof(char) * 50);
char* foodname = (char*)malloc(sizeof(char) * 50);


void login();
void join();
void basket();
void buy();
void product();
void adminlogin();
void adminadd();
void payment();


void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void borderLine() {

	for (int i = 1; i <= 113; i++) {
		gotoxy(1 + i, 1);
		cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	}
	for (int i = 1; i <= 36; i++) {
		gotoxy(1, 1 + i);
		cout << "┃";
	}
	for (int i = 1; i <= 113; i++) {
		gotoxy(1 + i, 38);
		cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	}
	for (int i = 1; i <= 36; i++) {
		gotoxy(156, 1 + i);
		cout << "┃";
	}
}

void mamilogo() {



	gotoxy(52, 5);
	cout << ".___    ___.        ___         .___  ___.     __  ";
	gotoxy(52, 6);
	cout << ".|   \\/   |        /   \\        |   \\/   |    |  |";
	gotoxy(52, 7);
	cout << " |  \\  /  |       /  ^  \\       |  \\  /  |    |  |";
	gotoxy(52, 8);
	cout << " |  |\\/|  |      /  /_\\  \\      |  |\\/|  |    |  | ";
	gotoxy(52, 9);
	cout << " |  |  |  |     /  _____  \\     |  |  |  |    |  | ";
	gotoxy(52, 10);
	cout << " |__|  |__|    /__/     \\__\\    |__|  |__|    |__|";

	gotoxy(56, 14);
	cout << "마켓미림에서 직접 물건을 구매해보세요 !";

	// 게임 설명 방법
	gotoxy(55, 16);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	gotoxy(61, 19);
	cout << "♥ 번호를 눌러 실행시켜주세요 ♥";
	gotoxy(67, 21);
	cout << "▶   1. 회원가입";
	gotoxy(67, 22);
	cout << "▶   2. 로그인";
	gotoxy(67, 23);
	cout << "▶   3. 장바구니보기";
	gotoxy(67, 24);
	cout << "▶   4. 종료하기";
	gotoxy(67, 25);
	cout << "▶   5. 관리자 로그인";
	gotoxy(55, 28);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

	key = _getch();
	if (key == '1') {
		system("cls");
		 join();
	} else if (key == '2') {
		system("cls");
		login();
	} else if (key == '3') {
		system("cls"); 
		basket();
	} else if (key == '4') {
		exit(0);
	} else if (key == '5') {
		system("cls"); 
		adminlogin();
	}
}

void login() {
	gotoxy(69, 9);
	cout << "♥ 로그인 ♥" << endl;
	gotoxy(65, 18);
	cout << "▶   학   번  \t";
	cin >> id;
	gotoxy(65, 19);
	cout << "▶   비밀번호 \t";
	cin >> pw;

	gotoxy(63, 23);
	cout << "♥ SPACE를 눌러 로그인해주세요 ♥" << endl;

	char query[255];
	key = _getch();	// 눌린 값 대입
	if (key == 32) {
		system("cls");
		sprintf(query, "select * from user where id = %d", id);
		mysql_query(mysql, query);
		res = mysql_store_result(mysql);
		fields = mysql_num_fields(res);

		int cnt = 0;
		if (row = mysql_fetch_row(res)) {
			cnt++;
			if (!strcmp(row[1], pw)) {
				cout << "로그인 되었습니다.";

			}
			else {
				cout << "아이디 또는 비밀번호가 일치하지 않습니다.";
				Sleep(1000);
				system("cls");
				login();
			}
		}
		else {
			cout << "아이디 또는 비밀번호가 일치하지 않습니다";

		}

		Sleep(1000);
		system("cls");
		product();
	}
}

void join() {
	gotoxy(69, 9);
	cout << "♥ 회원가입 ♥" << endl;
	gotoxy(65, 18);
	cout << "▶   학   번  \t";
	cin >> id;
	gotoxy(65, 19);
	cout << "▶   비밀번호 \t";
	cin >> pw;
	gotoxy(65, 20);
	cout << "▶   이    름 \t";
	cin >> name;

	gotoxy(63, 23);
	cout << "♥ SPACE를 눌러 회원가입을 해주세요 ♥" << endl;

	// 쿼리:레코드삽입
	char query[255];
	sprintf(query, "INSERT INTO user VALUES(%d, '%s', '%s')", id, pw, name);
	int stat = mysql_query(mysql, query);

	key = _getch();
	if (key == 32) {
		system("cls");
		login();
	}
}

void adminlogin() {
	gotoxy(69, 9);
	cout << "♥ 관리자 로그인 ♥" << endl;
	gotoxy(65, 18);
	cout << "▶   학   번  \t";
	cin >> id;
	gotoxy(65, 19);
	cout << "▶   비밀번호 \t";
	cin >> pw;

	gotoxy(63, 23);
	cout << "♥ SPACE를 눌러 로그인해주세요 ♥" << endl;

	char query[255];
	key = _getch();	
	if (key == 32) {
		system("cls");
		sprintf(query, "select * from adminuser where adminid = %d", id);
		mysql_query(mysql, query);
		res = mysql_store_result(mysql);
		fields = mysql_num_fields(res);

		int cnt = 0;
		if (row = mysql_fetch_row(res)) {
			cnt++;
			if (!strcmp(row[1], pw)) {
				cout << "로그인 되었습니다.";

			} else {
				cout << "아이디 또는 비밀번호가 일치하지 않습니다.";
				Sleep(1000);
				system("cls");
				adminlogin();
			}
		} else {
			cout << "아이디 또는 비밀번호가 일치하지 않습니다";
			Sleep(1000);
			system("cls");
			adminlogin();

		}

		Sleep(1000);
		system("cls");
		adminadd();
	}
	
}

void adminadd() {
	gotoxy(69, 9);
	cout << "♥ 상품추가 ♥" << endl;
	gotoxy(65, 18);
	cout << "▶   품   번  \t";
	cin >> foodnum;
	gotoxy(65, 19);
	cout << "▶   상   품  \t";
	cin >> foodname;
	gotoxy(65, 20);
	cout << "▶   가   격 \t";
	cin >> adminmoney;
	gotoxy(65, 21);
	cout << "▶   수   량 \t";
	cin >> admincount;

	gotoxy(63, 25);
	cout << "♥ SPACE를 눌러 상품추가를 해주세요 ♥" << endl;

	char query[255];
	sprintf(query, "INSERT INTO market VALUES(%d, '%s', %d, %d)", foodnum, foodname, adminmoney, admincount);
	int stat = mysql_query(mysql, query);

	key = _getch();
	if (key == 32) {
		system("cls");
		product();
	}
}

void basket() {

}

void product() {
	char query[255];
	char* foodkey;

	sprintf(query, "select * from market");
	int state = mysql_query(mysql, query);

	if (state == 0) {

		res = mysql_store_result(mysql);		// Result set에 저장

		gotoxy(55, 8);
		cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
		gotoxy(58, 9);
		cout << "품번\t\t상품명\t      금액      수량\n";
		gotoxy(55, 10);
		cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";


		cout << "\n\n\n";
		while ((row = mysql_fetch_row(res)) != NULL) {		// Result set에서 1개씩 배열을 가져옴


			cout << "                                                         " << row[0] << "\t\t" << row[1] << "\t" << row[2] << "\t" << row[3] << endl;	

		}
	}

	key = _getch();
	foodisertnum = key;
	if (key == '1') {
		system("cls");
		payment();
	}
	else if (key == '2') {
		system("cls");
		payment();
	}
}

void payment() {
	gotoxy(60, 18);
	cout << "♥ 장바구니에 담으시겠습니까 ? ( y / n ) ♥" << endl;

	key = _getch();
	if (key == 'y') {
		system("cls");

		gotoxy(69, 9);
		cout << "♥ 상품담기 ♥" << endl;
		gotoxy(65, 18);
		cout << "▶   학   번  \t";
		cin >> id;

		gotoxy(63, 23);
		cout << "♥ SPACE를 눌러 장바구니에 담아주세요 ♥" << endl;

		key = _getch();
		if (key == 32) {

		}
	}
}


int main() {
	if (!mysql_real_connect(mysql, MYSQLID, MYSQLUSER, MYSQLPW, MYSQLDB, 3308, NULL, 0)) cout << "error" << endl;
	else {
		cout << "success" << endl;
		mysql_set_character_set(mysql, "euckr");
	}

	// 한글로 입력받기 위함
	mysql_query(mysql, "set session character_set_connection=euckr;");
	mysql_query(mysql, "set session character_set_results=euckr;");
	mysql_query(mysql, "set session character_set_client=euckr;");

	// console 기본 설정
	system("mode con: cols=160 lines=40");
	SetConsoleTitle(TEXT("MaMi"));

	mamilogo();
}