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


// л熱 Щ煎饜顫殮 摹樹
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

// 揚萼 key高 檜勘煎 檜翕й 剪歜
int join_key = 0;


// 擠衝輿僥 廓�� 殮溘嫡朝 滲熱
int foodNumberKey;

// 擠衝 輿僥
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

//儀鼻
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

// 夔樂 臢蝶お 儀鼻 滲唳п輿朝 л熱
void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}



// 詭檣煎堅
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
	cout << "葆鰍嘐葡縑憮 霜蕾 僭勒擊 掘衙п爾撮蹂 !";

	// 啪歜 撲貲 寞徹
	gotoxy(55, 16);
	cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
	gotoxy(61, 19);
	cout << "Ⅵ 廓�ㄧ� 揚楝 褒ч衛麵輿撮蹂 Ⅵ";
	gotoxy(67, 21);
	cout << "Ⅱ   1. �蛾灠㊣�";
	gotoxy(67, 22);
	cout << "Ⅱ   2. 煎斜檣";
	gotoxy(67, 23);
	cout << "Ⅱ   3. 濰夥掘棲爾晦";
	gotoxy(67, 24);
	cout << "Ⅱ   4. 謙猿ж晦";
	gotoxy(55, 27);
	cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;

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

// �蛾灠㊣�
void join() {
	gotoxy(69, 9);
	cout << "Ⅵ �蛾灠㊣� Ⅵ" << endl;
	gotoxy(65, 18);
	cout << "Ⅱ   з   廓  \t";
	cin >> id;
	gotoxy(65, 19);
	cout << "Ⅱ   綠塵廓�� \t";
	cin >> pw;
	gotoxy(65, 20);
	cout << "Ⅱ   檜    葷 \t";
	cin >> name;

	gotoxy(60, 23);
	cout << "Ⅵ SPACE蒂 揚楝 �蛾灠㊣埬� п輿撮蹂 Ⅵ" << endl;

	// 蘭葬:溯囀萄鳶殮
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
	cout << "Ⅵ 煎斜檣 Ⅵ" << endl;
	gotoxy(65, 18);
	cout << "Ⅱ   з   廓  \t";
	cin >> id;
	gotoxy(65, 19);
	cout << "Ⅱ   綠塵廓�� \t";
	cin >> pw;

	gotoxy(60, 23);
	cout << "Ⅵ SPACE蒂 揚楝 煎斜檣п輿撮蹂 Ⅵ" << endl;

	char query[255];
	join_key = _getch();	// 揚萼 高 渠殮
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
				cout << "煎斜檣 腎歷蝗棲棻.";

			}
			else {
				cout << "嬴檜蛤 傳朝 綠塵廓�ㄟ� 橾纂ж雖 彊蝗棲棻.";
				Sleep(1000);
				system("cls");
				login();
			}
		}
		else {
			cout << "嬴檜蛤 傳朝 綠塵廓�ㄟ� 橾纂ж雖 彊蝗棲棻";
			Sleep(1000);
			system("cls");
			login();

		}

		Sleep(1000);
		system("cls");
		foodMarket();
	}

}


// 葆鰍
void foodMarket() {

	gotoxy(66, 3);
	cout << "收收收收收收收收收收收收收收收收收收收";
	gotoxy(68, 4);
	cout << "Ⅵ 擠衝 & 擠猿 Ⅵ" << endl;
	gotoxy(66, 5);
	cout << "收收收收收收收收收收收收收收收收收收收";


	// 餌婁
	gotoxy(18, 8);
	cout << "1. 褐摹и 餌婁 ";
	gotoxy(18, 9);
	cout << "1000錳";
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


	// ん紫
	gotoxy(48, 8);
	setColor(WHITE);
	cout << "2. 螟繭 ん紫";
	gotoxy(48, 9);
	cout << "2000錳";
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


	// 纂鍔
	gotoxy(80, 8);
	setColor(WHITE);
	cout << "3. 跡濰縑憮 虜萇 纂鍔";
	gotoxy(80, 9);
	cout << "1500錳";
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

	// 蟾屬滇
	gotoxy(115, 8);
	setColor(WHITE);
	cout << "4. Я煎蒂 梟錶輿朝 蟾屬葩";
	gotoxy(115, 9);
	cout << "2000錳";
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


	// 醴Я
	gotoxy(18, 22);
	setColor(WHITE);
	cout << "5. 評莫 評莫 醴Я";
	gotoxy(18, 23);
	cout << "3000錳";
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


	// 馨檜觼
	gotoxy(48, 22);
	setColor(WHITE);
	cout << "6. 殖巍и 馨檜觼";
	gotoxy(48, 23);
	cout << "5000錳";
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


	// 擁Ыだ檜
	gotoxy(80, 22);
	setColor(WHITE);
	cout << "7. 擁Ыだ檜";
	gotoxy(80, 23);
	cout << "6000錳";
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
	cout << "6. п薑辦嶸";
	gotoxy(115, 23);
	cout << "1500錳";
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
	cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
	gotoxy(68, 36);
	cout << "Ⅵ 濰夥掘棲 �挫�(ENTER) Ⅵ" << endl;
	gotoxy(66, 37);
	cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";


	foodNumberKey = _getch();		// 酈爾萄煎睡攪 揚萼 高 渠殮

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

// 擠衝曖 輿僥 偎熱 л熱
void foodApple() {

	setColor(WHITE);


	gotoxy(58, 9);
	cout << "Ⅵ  餌婁蒂 賃 偃蒂 輿僥ж衛啊蝗棲梱 ? Ⅵ" << endl;

	gotoxy(47, 16);
	cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
	gotoxy(65, 18);
	cout << "Ⅱ   偃    熱  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";

	gotoxy(48, 22);
	cout << "輿僥ж衛溥賊 з廓擊 殮溘п輿撮蹂 : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
	gotoxy(48, 25);
	cout << "                     濰夥掘棲 氬晦                                                          ";
	gotoxy(48, 26);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";


	int money = foodCnt1 * 1000;

	join_key = _getch();	// 揚萼 高 渠殮
	if (join_key == 32) {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "餌婁", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "詭景陛 薯渠煎 氬晦雖 彊懊蝗棲棻. 詭景 摹鷗�飛橉虞� 棻衛 檜翕м棲棻.";
			Sleep(1000);
			system("cls");
			foodMarket();

		} else {
			system("cls");
			cout << "詭景陛 撩奢瞳戲煎 氬啣蝗棲棻 !";
			Sleep(1000);
			system("cls");
			foodMarket();
		}
	}



}

void foodGrape() {

	setColor(WHITE);



	gotoxy(58, 9);
	cout << "Ⅵ  ん紫蒂 賃 偃蒂 輿僥ж衛啊蝗棲梱 ? Ⅵ" << endl;

	gotoxy(47, 16);
	cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
	gotoxy(65, 18);
	cout << "Ⅱ   偃    熱  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";

	gotoxy(48, 22);
	cout << "輿僥ж衛溥賊 з廓擊 殮溘п輿撮蹂 : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
	gotoxy(48, 25);
	cout << "                     濰夥掘棲 氬晦                                                          ";
	gotoxy(48, 26);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";


	int money = foodCnt1 * 2000;

	join_key = _getch();	// 揚萼 高 渠殮
	if (join_key == 32) {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "ん紫", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "詭景陛 薯渠煎 氬晦雖 彊懊蝗棲棻. 詭景 摹鷗�飛橉虞� 棻衛 檜翕м棲棻.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "詭景陛 撩奢瞳戲煎 氬啣蝗棲棻 !";
			Sleep(1000);
			system("cls");
			foodMarket();
		}
	}



}

void foodcheese() {

	setColor(WHITE);



	gotoxy(58, 9);
	cout << "Ⅵ  纂鍔蒂 賃 偃蒂 輿僥ж衛啊蝗棲梱 ? Ⅵ" << endl;

	gotoxy(47, 16);
	cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
	gotoxy(65, 18);
	cout << "Ⅱ   偃    熱  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";

	gotoxy(48, 22);
	cout << "輿僥ж衛溥賊 з廓擊 殮溘п輿撮蹂 : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
	gotoxy(48, 25);
	cout << "                     濰夥掘棲 氬晦                                                          ";
	gotoxy(48, 26);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";


	int money = foodCnt1 * 1500;

	join_key = _getch();	// 揚萼 高 渠殮
	if (join_key == 32) {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "纂鍔", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "詭景陛 薯渠煎 氬晦雖 彊懊蝗棲棻. 詭景 摹鷗�飛橉虞� 棻衛 檜翕м棲棻.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "詭景陛 撩奢瞳戲煎 氬啣蝗棲棻 !";
			Sleep(1000);
			system("cls");
			foodMarket();
		}
	}



}


void foodchoco() {

	setColor(WHITE);



	gotoxy(58, 9);
	cout << "Ⅵ  蟾屬葩擊 賃 偃蒂 輿僥ж衛啊蝗棲梱 ? Ⅵ" << endl;

	gotoxy(47, 16);
	cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
	gotoxy(65, 18);
	cout << "Ⅱ   偃    熱  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";

	gotoxy(48, 22);
	cout << "輿僥ж衛溥賊 з廓擊 殮溘п輿撮蹂 : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
	gotoxy(48, 25);
	cout << "                     濰夥掘棲 氬晦                                                          ";
	gotoxy(48, 26);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";


	int money = foodCnt1 * 2000;

	join_key = _getch();	// 揚萼 高 渠殮
	if (join_key == 32) {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "蟾屬葩", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "詭景陛 薯渠煎 氬晦雖 彊懊蝗棲棻. 詭景 摹鷗�飛橉虞� 棻衛 檜翕м棲棻.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "詭景陛 撩奢瞳戲煎 氬啣蝗棲棻 !";
			Sleep(1000);
			system("cls");
			foodMarket();
		}
	}



}

void foodCoffee() {

	setColor(WHITE);



	gotoxy(58, 9);
	cout << "Ⅵ  醴Я蒂 賃 偃蒂 輿僥ж衛啊蝗棲梱 ? Ⅵ" << endl;

	gotoxy(47, 16);
	cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
	gotoxy(65, 18);
	cout << "Ⅱ   偃    熱  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";

	gotoxy(48, 22);
	cout << "輿僥ж衛溥賊 з廓擊 殮溘п輿撮蹂 : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
	gotoxy(48, 25);
	cout << "                     濰夥掘棲 氬晦                                                          ";
	gotoxy(48, 26);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";


	int money = foodCnt1 * 3000;

	join_key = _getch();	// 揚萼 高 渠殮
	if (join_key == 32) {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "醴Я", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "詭景陛 薯渠煎 氬晦雖 彊懊蝗棲棻. 詭景 摹鷗�飛橉虞� 棻衛 檜翕м棲棻.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "詭景陛 撩奢瞳戲煎 氬啣蝗棲棻 !";
			Sleep(1000);
			system("cls");
			foodMarket();
		}
	}



}

void foodCake() {

	setColor(WHITE);


	gotoxy(58, 9);
	cout << "Ⅵ  馨檜觼蒂 賃 偃蒂 輿僥ж衛啊蝗棲梱 ? Ⅵ" << endl;

	gotoxy(47, 16);
	cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
	gotoxy(65, 18);
	cout << "Ⅱ   偃    熱  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";

	gotoxy(48, 22);
	cout << "輿僥ж衛溥賊 з廓擊 殮溘п輿撮蹂 : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
	gotoxy(48, 25);
	cout << "                     濰夥掘棲 氬晦                                                          ";
	gotoxy(48, 26);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";


	int money = foodCnt1 * 5000;

	join_key = _getch();	// 揚萼 高 渠殮
	if (join_key == 32) {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "馨檜觼", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "詭景陛 薯渠煎 氬晦雖 彊懊蝗棲棻. 詭景 摹鷗�飛橉虞� 棻衛 檜翕м棲棻.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "詭景陛 撩奢瞳戲煎 氬啣蝗棲棻 !";
			Sleep(1000);
			system("cls");
			foodMarket();
		}
	}



}

void foodPie() {

	setColor(WHITE);


	gotoxy(58, 9);
	cout << "Ⅵ  擁Ыだ檜蒂 賃 偃蒂 輿僥ж衛啊蝗棲梱 ? Ⅵ" << endl;

	gotoxy(47, 16);
	cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
	gotoxy(65, 18);
	cout << "Ⅱ   偃    熱  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";

	gotoxy(48, 22);
	cout << "輿僥ж衛溥賊 з廓擊 殮溘п輿撮蹂 : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
	gotoxy(48, 25);
	cout << "                     濰夥掘棲 氬晦                                                          ";
	gotoxy(48, 26);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";


	int money = foodCnt1 * 6000;

	join_key = _getch();	// 揚萼 高 渠殮
	if (join_key == 32) {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "擁Ыだ檜", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "詭景陛 薯渠煎 氬晦雖 彊懊蝗棲棻. 詭景 摹鷗�飛橉虞� 棻衛 檜翕м棲棻.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "詭景陛 撩奢瞳戲煎 氬啣蝗棲棻 !";
			Sleep(1000);
			system("cls");
			foodMarket();
		}
	}



}

void foodMlik() {

	setColor(WHITE);


	gotoxy(58, 9);
	cout << "Ⅵ  辦嶸蒂 賃 偃蒂 輿僥ж衛啊蝗棲梱 ? Ⅵ" << endl;

	gotoxy(47, 16);
	cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
	gotoxy(65, 18);
	cout << "Ⅱ   偃    熱  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";

	gotoxy(48, 22);
	cout << "輿僥ж衛溥賊 з廓擊 殮溘п輿撮蹂 : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
	gotoxy(48, 25);
	cout << "                     濰夥掘棲 氬晦                                                          ";
	gotoxy(48, 26);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";


	int money = foodCnt1 * 1500;

	join_key = _getch();	// 揚萼 高 渠殮
	if (join_key == 32) {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "辦嶸", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "詭景陛 薯渠煎 氬晦雖 彊懊蝗棲棻. 詭景 摹鷗�飛橉虞� 棻衛 檜翕м棲棻.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "詭景陛 撩奢瞳戲煎 氬啣蝗棲棻 !";
			Sleep(1000);
			system("cls");
			foodMarket();
		}
	}



}


void basket() {

	gotoxy(72, 9);
	cout << "濰夥掘棲 跡煙" << endl;

	gotoxy(56, 22);
	cout << "濰夥掘棲蒂 �挫恉牮繩襄� з廓擊 殮溘п輿撮蹂 : ";
	cin >> id;

	gotoxy(60, 25);
	cout << "Ⅵ SPACE蒂 揚楝 濰夥掘棲蒂 �挫� п輿撮蹂 Ⅵ" << endl;

	char query[255];
	join_key = _getch();	// 揚萼 高 渠殮
	if (join_key == 32) {
		system("cls");
		sprintf(query, "select foodname, cnt, money from product where id = %d", id);
		int state = mysql_query(mysql, query);

		if (state == 0) {

			res = mysql_store_result(mysql);		// Result set縑 盪濰

			gotoxy(55, 8);
			cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
			gotoxy(58, 9);
			cout << "鼻ヶ貲\t      熱榆      \t旎擋\n";
			gotoxy(55, 10);
			cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收";
			

			cout << "\n\n\n";
			while ((row = mysql_fetch_row(res)) != NULL) {		// Result set縑憮 1偃噶 寡翮擊 陛螳褥

				
				cout << "                                                            " << row[0] << "\t\t" << row[1] << "\t\t" << row[2] << endl;					// 盪濰脹 寡翮擊 轎溘

			}
				
			gotoxy(63, 35);
			cout << "Ⅵ SPACE蒂 揚楝 鼻ヶ擊 氬嬴輿撮蹂 Ⅵ" << endl;

			join_key = _getch();
			if (join_key == 32) {
				system("cls");
				buy();
			} 

			// Result set п薯
			mysql_free_result(res);
		}
	}

}

void buy() {
	setColor(WHITE);

	gotoxy(62, 9);
	cout << "Ⅵ 詭景蒂 輿僥ж衛啊蝗棲梱 ? Ⅵ" << endl;


	gotoxy(56, 12);
	cout << "掘衙ж衛溥賊 з廓擊 殮溘п輿撮蹂 : ";
	cin >> id;
	

	gotoxy(59, 15);
	cout << "Ⅵ SPACE蒂 揚楝 鼻ヶ擊 掘衙п輿撮蹂 Ⅵ" << endl;

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

	PlaySound(TEXT("emart.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //瑞Щ 營儅

	// и旋煎 殮溘嫡晦 嬪л
	mysql_query(mysql, "set session character_set_connection=euckr;");
	mysql_query(mysql, "set session character_set_results=euckr;");
	mysql_query(mysql, "set session character_set_client=euckr;");

	// console 晦獄 撲薑
	system("mode con: cols=160 lines=40");
	SetConsoleTitle(TEXT("MaMi"));

	mamilogo();

	// 賅萇 Щ煎斜極檜 謙猿 薯橾 部
	system("pause");
}