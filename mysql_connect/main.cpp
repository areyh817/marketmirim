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
#define MYSQLDB "study_db"	
MYSQL* mysql = mysql_init(NULL);
MYSQL_RES* res;
MYSQL_ROW row;


// 함수 프로토타입 선언
void foodApple();
void foodMarket();
void foodGrape();
void foodcheese();
void foodchoco();
void foodCoffee();
void foodCake();
void foodPie();
void foodMlik();
void basket();
void login();
void join();
void buy();

// 눌린 key값 이걸로 이동할 거임
int join_key = 0;


// 음식주문 번호 입력받는 변수
int foodNumberKey;

// 음식 주문
int foodCnt1 = 0;

int fields;
int id;
char* name = (char*)malloc(sizeof(char) * 50);
char* pw = (char*)malloc(sizeof(char) * 50);

// function prototype
void foodCount();

// gotoxy
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//색상
enum {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DAKR_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

// 콘솔 텍스트 색상 변경해주는 함수
void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}



// 메인로고
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
	gotoxy(55, 27);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

	join_key = _getch();
	if (join_key == '1') {
		system("cls");
		join();
	}
	else if (join_key == '2') {
		system("cls");
		login();
	}
	else if (join_key == '3') {
		system("cls");
		basket();
	}
	else if (join_key == '4') {
		exit(0);
	}
}

// 회원가입
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

	gotoxy(60, 23);
	cout << "♥ SPACE를 눌러 회원가입을 해주세요 ♥" << endl;

	// 쿼리:레코드삽입
	char query[255];
	sprintf(query, "INSERT INTO user VALUES(%d, '%s', '%s')", id, pw, name);
	int stat = mysql_query(mysql, query);

	join_key = _getch();
	if (join_key == 32) {
		system("cls");
		login();
	}



}

// login function
void login() {

	gotoxy(69, 9);
	cout << "♥ 로그인 ♥" << endl;
	gotoxy(65, 18);
	cout << "▶   학   번  \t";
	cin >> id;
	gotoxy(65, 19);
	cout << "▶   비밀번호 \t";
	cin >> pw;

	gotoxy(60, 23);
	cout << "♥ SPACE를 눌러 로그인해주세요 ♥" << endl;

	char query[255];
	join_key = _getch();	// 눌린 값 대입
	if (join_key == 32) {
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
			Sleep(1000);
			system("cls");
			login();

		}

		Sleep(1000);
		system("cls");
		foodMarket();
	}

}


// 마켓
void foodMarket() {

	gotoxy(66, 3);
	cout << "━━━━━━━━━━━━━━━━━━━";
	gotoxy(68, 4);
	cout << "♥ 음식 & 음료 ♥" << endl;
	gotoxy(66, 5);
	cout << "━━━━━━━━━━━━━━━━━━━";


	// 사과
	gotoxy(18, 8);
	cout << "1. 신선한 사과 ";
	gotoxy(18, 9);
	cout << "1000원";
	gotoxy(20, 11);
	setColor(RED);
	cout << "  ,--./,-.";
	gotoxy(20, 12);
	cout << " / #       ";
	gotoxy(20, 13);
	cout << "|         |";
	gotoxy(20, 14);
	cout << " \        / ";
	gotoxy(20, 15);
	cout << " `._,._,'";


	// 포도
	gotoxy(48, 8);
	setColor(WHITE);
	cout << "2. 옥천 포도";
	gotoxy(48, 9);
	cout << "2000원";
	gotoxy(50, 11);
	setColor(DARK_GREEN);
	cout << "   /";
	gotoxy(50, 12);
	setColor(VIOLET);
	cout << " ()()";
	gotoxy(50, 13);
	cout << "()()()";
	gotoxy(50, 14);
	cout << " ()()";
	gotoxy(50, 15);
	cout << " ()";


	// 치즈
	gotoxy(80, 8);
	setColor(WHITE);
	cout << "3. 목장에서 만든 치즈";
	gotoxy(80, 9);
	cout << "1500원";
	gotoxy(80, 10);
	setColor(DAKR_YELLOW);
	cout << "          ___ ";
	gotoxy(80, 11);
	cout << "        .'o O'-._";
	gotoxy(80, 12);
	cout << "       / O o_.-`|";
	gotoxy(80, 13);
	cout << "      /O_.-'  O |";
	gotoxy(80, 14);
	cout << "     | o   o .-`";
	gotoxy(80, 15);
	cout << "     |o O_.-'";
	gotoxy(80, 16);
	cout << "      '--`";

	// 초콜렛
	gotoxy(115, 8);
	setColor(WHITE);
	cout << "4. 피로를 깨워주는 초콜릿";
	gotoxy(115, 9);
	cout << "2000원";
	gotoxy(112, 11);
	setColor(DARK_GRAY);
	cout << "    __________________,.............,";
	gotoxy(112, 12);
	cout << "   /_/_/_/_/_/_/_/_/,-',  ,. -,-,--/|";
	gotoxy(112, 13);
	cout << "  /_/_/_/_/_/_/_/,-' //  /-| / /--/ /";
	gotoxy(112, 14);
	cout << " /_/_/_/_/_/_/,-' `-''--'  `' '--/ /";
	gotoxy(112, 15);
	cout << "/_/_/_/_/_/_,:................../ /";
	gotoxy(112, 16);
	cout << "|________,'                   hh|/";


	// 커피
	gotoxy(18, 22);
	setColor(WHITE);
	cout << "5. 따끈 따끈 커피";
	gotoxy(18, 23);
	cout << "3000원";
	gotoxy(20, 25);
	setColor(RED);
	cout << "     (   ) )";
	gotoxy(20, 26);
	cout << "      ) ( (";
	gotoxy(20, 27);
	cout << "    _______)_";
	gotoxy(20, 28);
	setColor(SKYBLUE);
	cout << " .-'---------|";
	gotoxy(20, 29);
	cout << "( C|/\\/\\/\\/\\/|";
	gotoxy(20, 30);
	cout << " '-./\\/\\/\\/\\/|";
	gotoxy(20, 31);
	cout << "   '_________'";
	gotoxy(20, 32);
	cout << "    '-------'";


	// 케이크
	gotoxy(48, 22);
	setColor(WHITE);
	cout << "6. 달콤한 케이크";
	gotoxy(48, 23);
	cout << "5000원";
	gotoxy(46, 25);
	setColor(RED);
	cout << "      $$  $$  $$";
	gotoxy(46, 26);
	setColor(WHITE);
	cout << "    __||__||__||__";
	gotoxy(46, 27);
	cout << "   | * * * * * * *|";
	gotoxy(46, 28);
	cout << "   |* * * * * * * |";
	gotoxy(46, 29);
	cout << "   | * * * * * * *|";
	gotoxy(46, 30);
	cout << "   |______________|";


	// 애플파이
	gotoxy(80, 22);
	setColor(WHITE);
	cout << "7. 애플파이";
	gotoxy(80, 23);
	cout << "6000원";
	setColor(RED);
	gotoxy(80, 25);
	cout << "         (";
	gotoxy(80, 26);
	cout << "          )";
	gotoxy(80, 27);
	setColor(DAKR_YELLOW);
	cout << "     __..---..__";
	gotoxy(80, 28);
	cout << " ,-='  /  |  \  `=-.";
	gotoxy(80, 29);
	cout << ":--..___________..--;";
	gotoxy(115, 22);
	setColor(WHITE);
	cout << "6. 해정우유";
	gotoxy(115, 23);
	cout << "1500원";
	gotoxy(119, 25);
	setColor(DARK_BLUE);
	cout << "   _________";
	gotoxy(119, 26);
	cout << "  | _______ |";
	gotoxy(119, 27);
	cout << " / \\         \\ ";
	gotoxy(119, 28);
	cout << "/___\\_________\\ ";
	gotoxy(119, 29);
	cout << "|   |         |";
	gotoxy(119, 30);
	cout << "|   |         |";
	gotoxy(119, 31);
	cout << "|   |         |";
	gotoxy(119, 32);
	cout << "|___|_________|";


	setColor(WHITE);
	gotoxy(66, 35);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	gotoxy(68, 36);
	cout << "♥ 장바구니 확인(ENTER) ♥" << endl;
	gotoxy(66, 37);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";


	foodNumberKey = _getch();		// 키보드로부터 눌린 값 대입

	if (foodNumberKey == '1') {
		system("cls");
		foodApple();
	}
	else if (foodNumberKey == '2') {
		system("cls");
		foodGrape();
	}
	else if (foodNumberKey == '3') {
		system("cls");
		foodcheese();
	}
	else if (foodNumberKey == '4') {
		system("cls");
		foodchoco();
	}
	else if (foodNumberKey == '5') {
		system("cls");
		foodCoffee();
	}
	else if (foodNumberKey == '6') {
		system("cls");
		foodCake();
	}
	else if (foodNumberKey == '7') {
		system("cls");
		foodPie();
	}
	else if (foodNumberKey == '8') {
		system("cls");
		foodMlik();
	}
	else if (foodNumberKey == 13) {
		system("cls");
		basket();
	}


}

// 음식의 주문 갯수 함수
void foodApple() {

	setColor(WHITE);


	gotoxy(58, 9);
	cout << "♥  사과를 몇 개를 주문하시겠습니까 ? ♥" << endl;

	gotoxy(47, 16);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(65, 18);
	cout << "▶   개    수  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

	gotoxy(48, 22);
	cout << "주문하시려면 학번을 입력해주세요 : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(48, 25);
	cout << "                     장바구니 담기                                                          ";
	gotoxy(48, 26);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";


	int money = foodCnt1 * 1000;

	join_key = _getch();	// 눌린 값 대입
	if (join_key == 32) {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "사과", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "메뉴가 제대로 담기지 않았습니다. 메뉴 선택화면으로 다시 이동합니다.";
			Sleep(1000);
			system("cls");
			foodMarket();

		} else {
			system("cls");
			cout << "메뉴가 성공적으로 담겼습니다 !";
			Sleep(1000);
			system("cls");
			foodMarket();
		}
	}



}

void foodGrape() {

	setColor(WHITE);



	gotoxy(58, 9);
	cout << "♥  포도를 몇 개를 주문하시겠습니까 ? ♥" << endl;

	gotoxy(47, 16);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(65, 18);
	cout << "▶   개    수  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

	gotoxy(48, 22);
	cout << "주문하시려면 학번을 입력해주세요 : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(48, 25);
	cout << "                     장바구니 담기                                                          ";
	gotoxy(48, 26);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";


	int money = foodCnt1 * 2000;

	join_key = _getch();	// 눌린 값 대입
	if (join_key == 32) {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "포도", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "메뉴가 제대로 담기지 않았습니다. 메뉴 선택화면으로 다시 이동합니다.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "메뉴가 성공적으로 담겼습니다 !";
			Sleep(1000);
			system("cls");
			foodMarket();
		}
	}



}

void foodcheese() {

	setColor(WHITE);



	gotoxy(58, 9);
	cout << "♥  치즈를 몇 개를 주문하시겠습니까 ? ♥" << endl;

	gotoxy(47, 16);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(65, 18);
	cout << "▶   개    수  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

	gotoxy(48, 22);
	cout << "주문하시려면 학번을 입력해주세요 : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(48, 25);
	cout << "                     장바구니 담기                                                          ";
	gotoxy(48, 26);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";


	int money = foodCnt1 * 1500;

	join_key = _getch();	// 눌린 값 대입
	if (join_key == 32) {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "치즈", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "메뉴가 제대로 담기지 않았습니다. 메뉴 선택화면으로 다시 이동합니다.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "메뉴가 성공적으로 담겼습니다 !";
			Sleep(1000);
			system("cls");
			foodMarket();
		}
	}



}


void foodchoco() {

	setColor(WHITE);



	gotoxy(58, 9);
	cout << "♥  초콜릿을 몇 개를 주문하시겠습니까 ? ♥" << endl;

	gotoxy(47, 16);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(65, 18);
	cout << "▶   개    수  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

	gotoxy(48, 22);
	cout << "주문하시려면 학번을 입력해주세요 : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(48, 25);
	cout << "                     장바구니 담기                                                          ";
	gotoxy(48, 26);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";


	int money = foodCnt1 * 2000;

	join_key = _getch();	// 눌린 값 대입
	if (join_key == 32) {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "초콜릿", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "메뉴가 제대로 담기지 않았습니다. 메뉴 선택화면으로 다시 이동합니다.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "메뉴가 성공적으로 담겼습니다 !";
			Sleep(1000);
			system("cls");
			foodMarket();
		}
	}



}

void foodCoffee() {

	setColor(WHITE);



	gotoxy(58, 9);
	cout << "♥  커피를 몇 개를 주문하시겠습니까 ? ♥" << endl;

	gotoxy(47, 16);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(65, 18);
	cout << "▶   개    수  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

	gotoxy(48, 22);
	cout << "주문하시려면 학번을 입력해주세요 : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(48, 25);
	cout << "                     장바구니 담기                                                          ";
	gotoxy(48, 26);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";


	int money = foodCnt1 * 3000;

	join_key = _getch();	// 눌린 값 대입
	if (join_key == 32) {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "커피", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "메뉴가 제대로 담기지 않았습니다. 메뉴 선택화면으로 다시 이동합니다.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "메뉴가 성공적으로 담겼습니다 !";
			Sleep(1000);
			system("cls");
			foodMarket();
		}
	}



}

void foodCake() {

	setColor(WHITE);


	gotoxy(58, 9);
	cout << "♥  케이크를 몇 개를 주문하시겠습니까 ? ♥" << endl;

	gotoxy(47, 16);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(65, 18);
	cout << "▶   개    수  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

	gotoxy(48, 22);
	cout << "주문하시려면 학번을 입력해주세요 : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(48, 25);
	cout << "                     장바구니 담기                                                          ";
	gotoxy(48, 26);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";


	int money = foodCnt1 * 5000;

	join_key = _getch();	// 눌린 값 대입
	if (join_key == 32) {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "케이크", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "메뉴가 제대로 담기지 않았습니다. 메뉴 선택화면으로 다시 이동합니다.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "메뉴가 성공적으로 담겼습니다 !";
			Sleep(1000);
			system("cls");
			foodMarket();
		}
	}



}

void foodPie() {

	setColor(WHITE);


	gotoxy(58, 9);
	cout << "♥  애플파이를 몇 개를 주문하시겠습니까 ? ♥" << endl;

	gotoxy(47, 16);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(65, 18);
	cout << "▶   개    수  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

	gotoxy(48, 22);
	cout << "주문하시려면 학번을 입력해주세요 : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(48, 25);
	cout << "                     장바구니 담기                                                          ";
	gotoxy(48, 26);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";


	int money = foodCnt1 * 6000;

	join_key = _getch();	// 눌린 값 대입
	if (join_key == 32) {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "애플파이", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "메뉴가 제대로 담기지 않았습니다. 메뉴 선택화면으로 다시 이동합니다.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "메뉴가 성공적으로 담겼습니다 !";
			Sleep(1000);
			system("cls");
			foodMarket();
		}
	}



}

void foodMlik() {

	setColor(WHITE);


	gotoxy(58, 9);
	cout << "♥  우유를 몇 개를 주문하시겠습니까 ? ♥" << endl;

	gotoxy(47, 16);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(65, 18);
	cout << "▶   개    수  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

	gotoxy(48, 22);
	cout << "주문하시려면 학번을 입력해주세요 : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(48, 25);
	cout << "                     장바구니 담기                                                          ";
	gotoxy(48, 26);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";


	int money = foodCnt1 * 1500;

	join_key = _getch();	// 눌린 값 대입
	if (join_key == 32) {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "우유", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "메뉴가 제대로 담기지 않았습니다. 메뉴 선택화면으로 다시 이동합니다.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "메뉴가 성공적으로 담겼습니다 !";
			Sleep(1000);
			system("cls");
			foodMarket();
		}
	}



}


void basket() {

	gotoxy(72, 9);
	cout << "장바구니 목록" << endl;

	gotoxy(56, 22);
	cout << "장바구니를 확인하시려면 학번을 입력해주세요 : ";
	cin >> id;

	gotoxy(60, 25);
	cout << "♥ SPACE를 눌러 장바구니를 확인 해주세요 ♥" << endl;

	char query[255];
	join_key = _getch();	// 눌린 값 대입
	if (join_key == 32) {
		system("cls");
		sprintf(query, "select foodname, cnt, money from product where id = %d", id);
		int state = mysql_query(mysql, query);

		if (state == 0) {

			res = mysql_store_result(mysql);		// Result set에 저장

			gotoxy(55, 8);	
			cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
			gotoxy(58, 9);
			cout << "상품명\t      수량      \t금액\n";
			gotoxy(55, 10);
			cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
			

			cout << "\n\n\n";
			while ((row = mysql_fetch_row(res)) != NULL) {		// Result set에서 1개씩 배열을 가져옴

				
				cout << "                                                            " << row[0] << "\t\t" << row[1] << "\t\t" << row[2] << endl;					// 저장된 배열을 출력

			}
				
			gotoxy(63, 33);
			cout << "♥ SPACE를 눌러 상품을 담아주세요 ♥" << endl;

			setColor(WHITE);
			gotoxy(63, 36);
			cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
			gotoxy(68, 37);
			cout << "♥ 상품 확인(ENTER) ♥" << endl;
			gotoxy(63, 38);
			cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

			join_key = _getch();
			if (join_key == 32) {
				system("cls");
				Sleep(1000);
				buy();
			}
			else if (join_key == 13) {
				system("cls");
				Sleep(1000);
				foodMarket();
			}

			// Result set 해제
			mysql_free_result(res);
		}
	}

}

void buy() {
	setColor(WHITE);

	gotoxy(62, 9);
	cout << "♥ 메뉴를 주문하시겠습니까 ? ♥" << endl;


	gotoxy(56, 12);
	cout << "구매하시려면 학번을 입력해주세요 : ";
	cin >> id;
	

	gotoxy(59, 15);
	cout << "♥ SPACE를 눌러 상품을 구매해주세요 ♥" << endl;

	join_key = _getch();
	if (join_key == 32) {
		char query[255];
		sprintf(query, "delete from product where id = %d", id);
		int state = mysql_query(mysql, query);

		system("cls");
		foodMarket();
	}
}


// main
int main() {

	 
	if (!mysql_real_connect(mysql, MYSQLID, MYSQLUSER, MYSQLPW, MYSQLDB, 3308, NULL, 0)) cout << "error" << endl;
	else {
		cout << "success" << endl;
		mysql_set_character_set(mysql, "euckr");
	}

	PlaySound(TEXT("emart.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);  

	// 한글로 입력받기 위함
	mysql_query(mysql, "set session character_set_connection=euckr;");
	mysql_query(mysql, "set session character_set_results=euckr;");
	mysql_query(mysql, "set session character_set_client=euckr;");

	// console 기본 설정
	system("mode con: cols=160 lines=40");
	SetConsoleTitle(TEXT("MaMi"));

	mamilogo();

	// 모든 프로그램이 종료 제일 끝
	system("pause");
}