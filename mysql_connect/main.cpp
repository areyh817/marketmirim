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
#define MYSQLDB "study_db"	
MYSQL* mysql = mysql_init(NULL);
MYSQL_RES* res;
MYSQL_ROW row;


// ÇÔ¼ö ÇÁ·ÎÅäÅ¸ÀÔ ¼±¾ð
void foodMarket();

// ´­¸° key°ª ÀÌ°É·Î ÀÌµ¿ÇÒ °ÅÀÓ
int join_key = 0;


// À½½ÄÁÖ¹® ¹øÈ£ ÀÔ·Â¹Þ´Â º¯¼ö
int foodNumberKey;

// À½½Ä ÁÖ¹®
int foodCnt1 = 0;


// function prototype
void foodCount();

// gotoxy
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//»ö»ó
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

// ÄÜ¼Ö ÅØ½ºÆ® »ö»ó º¯°æÇØÁÖ´Â ÇÔ¼ö
void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

// Å×µÎ¸® ±×¸®±â
void borderLine() {

	for (int i = 1; i <= 113; i++) {
		gotoxy(1 + i, 1);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
	}
	for (int i = 1; i <= 36; i++) {
		gotoxy(1, 1 + i);
		cout << "¦­";
	}
	for (int i = 1; i <= 113; i++) {
		gotoxy(1 + i, 38);
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
	}
	for (int i = 1; i <= 36; i++) {
		gotoxy(156, 1 + i);
		cout << "¦­";
	}
}


// ¸ÞÀÎ·Î°í
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
	cout << "¸¶ÄÏ¹Ì¸²¿¡¼­ Á÷Á¢ ¹°°ÇÀ» ±¸¸ÅÇØº¸¼¼¿ä !";

	// °ÔÀÓ ¼³¸í ¹æ¹ý
	gotoxy(55, 16);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
	gotoxy(61, 19);
	cout << "¢¾ ¹øÈ£¸¦ ´­·¯ ½ÇÇà½ÃÄÑÁÖ¼¼¿ä ¢¾";
	gotoxy(67, 21);
	cout << "¢º   1. È¸¿ø°¡ÀÔ";
	gotoxy(67, 22);
	cout << "¢º   2. ·Î±×ÀÎ";
	gotoxy(67, 23);
	cout << "¢º   3. Á¾·áÇÏ±â";
	gotoxy(55, 26);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
}

// È¸¿ø°¡ÀÔ
void join() {

	borderLine();

	// º¯¼ö ¼±¾ð
	int id;
	char* name = (char*)malloc(sizeof(char) * 50);
	char* pw = (char*)malloc(sizeof(char) * 50);

	gotoxy(67, 13);
	cout << "¢¾ È¸ ¿ø °¡ ÀÔ ¢¾" << endl;
	gotoxy(58, 15);
	cout << "¢Ñ ¹Ì¸²ÇÐ»ýµé¸¸ ÀÌ¿ë °¡´ÉÇÕ´Ï´Ù ¢Ð";
	gotoxy(65, 18);
	cout << "¢º   ÇÐ    ¹ø \t";
	cin >> id;
	gotoxy(65, 19);
	cout << "¢º   ºñ¹Ð¹øÈ£ \t";
	cin >> pw;
	gotoxy(65, 20);
	cout << "¢º   ÀÌ    ¸§ \t";
	cin >> name;

	// Äõ¸®:·¹ÄÚµå»ðÀÔ
	char query[255];
	sprintf(query, "INSERT INTO user VALUES(%d, '%s', '%s')", id, pw, name);
	int stat = mysql_query(mysql, query);


	while (1) {
		gotoxy(48, 24);
		cout << "¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯";
		gotoxy(48, 25);
		cout << "¦­            ´ÙÀ½À¸·Î ³Ñ¾î°¡½Ã·Á¸é j¸¦ ´­·¯ÁÖ¼¼¿ä         ¦­";
		gotoxy(48, 26);
		cout << "¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°";

		join_key = _getch();	// ´­¸° °ª ´ëÀÔ
		if (join_key == 'j') {
			system("cls");
			break;
		}
	}



}

// login function
void login() {


	borderLine();

	// º¯¼ö ¼±¾ð
	int fields;
	int id;
	char* name = (char*)malloc(sizeof(char) * 50);
	char* pw = (char*)malloc(sizeof(char) * 50);


	gotoxy(65, 8);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
	gotoxy(69, 9);
	cout << "¢¾ ·Î±×ÀÎ ¢¾" << endl;
	gotoxy(65, 10);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";

	/*gotoxy(58, 15);
	cout << "¢Ñ ¹Ì¸²ÇÐ»ýµé¸¸ ÀÌ¿ë °¡´ÉÇÕ´Ï´Ù ¢Ð";*/
	gotoxy(47, 16);
	cout << "¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯";
	gotoxy(65, 18);
	cout << "¢º   ÇÐ   ¹ø  \t";
	cin >> id;
	gotoxy(65, 19);
	cout << "¢º   ºñ¹Ð¹øÈ£ \t";
	cin >> pw;
	gotoxy(47, 21);
	cout << "¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°";



	gotoxy(48, 24);
	cout << "¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯";
	gotoxy(48, 25);
	cout << "¦­                   ·Î±×ÀÎ ( L ) Å¬¸¯ !                   ¦­";
	gotoxy(48, 26);
	cout << "¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°";


	char query[255];
	join_key = _getch();	// ´­¸° °ª ´ëÀÔ
	if (join_key == 'l') {
		system("cls");
		sprintf(query, "select * from user where id = %d", id);
		mysql_query(mysql, query);
		res = mysql_store_result(mysql);
		fields = mysql_num_fields(res);

		int cnt = 0;
		if (row = mysql_fetch_row(res)) {
			cnt++;
			if (!strcmp(row[1], pw)) {
				cout << "·Î±×ÀÎ µÇ¾ú½À´Ï´Ù.";

			}
			else cout << "¾ÆÀÌµð ¶Ç´Â ºñ¹Ð¹øÈ£°¡ ÀÏÄ¡ÇÏÁö ¾Ê½À´Ï´Ù.";

		} else cout << "¾ÆÀÌµð ¶Ç´Â ºñ¹Ð¹øÈ£°¡ ÀÏÄ¡ÇÏÁö ¾Ê½À´Ï´Ù";
		Sleep(1000);
		system("cls");
		foodMarket();
	}
	/*while (1) {
		
		

	}*/


	/*				
					break;
				}*/

}


// ¸¶ÄÏ
void foodMarket() {

	gotoxy(66, 3);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
	gotoxy(68, 4);
	cout << "¢¾ À½½Ä & À½·á ¢¾" << endl;
	gotoxy(66, 5);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";


	// »ç°ú
	gotoxy(18, 8);
	cout << "1. ½Å¼±ÇÑ »ç°ú ";
	gotoxy(18, 9);
	cout << "1000¿ø";
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


	// Æ÷µµ
	gotoxy(48, 8);
	setColor(WHITE);
	cout << "2. ¿ÁÃµ Æ÷µµ";
	gotoxy(48, 9);
	cout << "2000¿ø";
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


	// Ä¡Áî
	gotoxy(80, 8);
	setColor(WHITE);
	cout << "3. ¸ñÀå¿¡¼­ ¸¸µç Ä¡Áî";
	gotoxy(80, 9);
	cout << "1500¿ø";
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

	// ÃÊÄÝ·¿
	gotoxy(115, 8);
	setColor(WHITE);
	cout << "4. ÇÇ·Î¸¦ ±ú¿öÁÖ´Â ÃÊÄÝ¸´";
	gotoxy(115, 9);
	cout << "2000¿ø";
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


	// Ä¿ÇÇ
	gotoxy(18, 22);
	setColor(WHITE);
	cout << "5. µû²ö µû²ö Ä¿ÇÇ";
	gotoxy(18, 23);
	cout << "3000¿ø";
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


	// ÄÉÀÌÅ©
	gotoxy(48, 22);
	setColor(WHITE);
	cout << "6. ´ÞÄÞÇÑ ÄÉÀÌÅ©";
	gotoxy(48, 23);
	cout << "5000¿ø";
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


	// ¾ÖÇÃÆÄÀÌ
	gotoxy(80, 22);
	setColor(WHITE);
	cout << "7. ¾ÖÇÃÆÄÀÌ";
	gotoxy(80, 23);
	cout << "6000¿ø";
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
	gotoxy(80, 30);
	cout << " \.,_____________,./";


	// ¿ìÀ¯
	gotoxy(115, 22);
	setColor(WHITE);
	cout << "6. ¿ìÀ¯";
	gotoxy(115, 23);
	cout << "1500¿ø";
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







	while (1) {

		foodNumberKey = _getch();		// Å°º¸µå·ÎºÎÅÍ ´­¸° °ª ´ëÀÔ

		if (foodNumberKey == '1') {
			system("cls");
			foodCount();
		}
	}



}

// À½½ÄÀÇ ÁÖ¹® °¹¼ö ÇÔ¼ö
void foodCount() {

	setColor(WHITE);

	borderLine();


	gotoxy(55, 8);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
	gotoxy(62, 9);
	cout << "¢¾  ¸î °³¸¦ ÁÖ¹®ÇÏ½Ã°Ú½À´Ï±î ? ¢¾" << endl;
	gotoxy(55, 10);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";

	gotoxy(47, 16);
	cout << "¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯";
	gotoxy(65, 18);
	cout << "¢º   °³    ¼ö  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°";



	while (1) {
		gotoxy(48, 24);
		cout << "¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯";
		gotoxy(48, 25);
		cout << "¦­                  Àå¹Ù±¸´Ï ( L ) ´ã±â !                  ¦­";
		gotoxy(48, 26);
		cout << "¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°";


		join_key = _getch();	// ´­¸° °ª ´ëÀÔ
		if (join_key == 'l') {
			system("cls");
			break;
		}
	}



}


void basket() {
	borderLine();

	gotoxy(55, 8);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";
	gotoxy(62, 9);
	cout << "¢¾  ³ªÀÇ Àå¹Ù±¸´Ï ¸ñ·Ï ¢¾" << endl;
	gotoxy(55, 10);
	cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬";


}




// main
int main() {


	if (!mysql_real_connect(mysql, MYSQLID, MYSQLUSER, MYSQLPW, MYSQLDB, 3308, NULL, 0)) cout << "error" << endl;
	else {
		cout << "success" << endl;
		mysql_set_character_set(mysql, "euckr");
	}

	// console ±âº» ¼³Á¤
	system("mode con: cols=160 lines=40");
	SetConsoleTitle(TEXT("MaMi"));

	int key;	// Å°º¸µå·Î ÀÔ·Â¹ÞÀ» °ª


	while (1) {

		// ¸ÞÀÎ·Î°í È£Ãâ
		mamilogo();

		key = _getch(); // ´­¸° °ª ´ëÀÔ

		if (key == '1') {					// È¸¿ø°¡ÀÔÃ¢ È£Ãâ -> ·Î±×ÀÎ -> Çªµå¸¶ÄÏ
			system("cls");
			join();
			if (join_key == 'j') {
				system("cls");
				login();  break;
			}

		}
		else if (key == '2') {				// ·Î±×ÀÎ -> Çªµå¸¶ÄÏ
			system("cls");
			login();
			if (join_key == 'l') {
				system("cls");
				break;
			}
		}
		else if (key == '3') {				/// ÇÁ·Î±×·¥ Á¾·á
			exit(0);
		}

	}

	// À½½Ä ¸Þ´º ¸ñ·Ï È­¸é Ãâ·Â
	foodMarket();




	// ¸ðµç ÇÁ·Î±×·¥ÀÌ Á¾·á Á¦ÀÏ ³¡
	system("pause");
}