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


// �Լ� ������Ÿ�� ����
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

// ���� key�� �̰ɷ� �̵��� ����
int join_key = 0;


// �����ֹ� ��ȣ �Է¹޴� ����
int foodNumberKey;

// ���� �ֹ�
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

//����
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

// �ܼ� �ؽ�Ʈ ���� �������ִ� �Լ�
void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

// �׵θ� �׸���
void borderLine() {

	for (int i = 1; i <= 113; i++) {
		gotoxy(1 + i, 1);
		cout << "������������������������������������������������������������������������������������";
	}
	for (int i = 1; i <= 36; i++) {
		gotoxy(1, 1 + i);
		cout << "��";
	}
	for (int i = 1; i <= 113; i++) {
		gotoxy(1 + i, 38);
		cout << "������������������������������������������������������������������������������������";
	}
	for (int i = 1; i <= 36; i++) {
		gotoxy(156, 1 + i);
		cout << "��";
	}
}


// ���ηΰ�
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
	cout << "���Ϲ̸����� ���� ������ �����غ����� !";

	// ���� ���� ���
	gotoxy(55, 16);
	cout << "������������������������������������������������������������������������������������" << endl;
	gotoxy(61, 19);
	cout << "�� ��ȣ�� ���� ��������ּ��� ��";
	gotoxy(67, 21);
	cout << "��   1. ȸ������";
	gotoxy(67, 22);
	cout << "��   2. �α���";
	gotoxy(67, 23);
	cout << "��   3. �����ϱ�";
	gotoxy(55, 26);
	cout << "������������������������������������������������������������������������������������" << endl;
}

// ȸ������
void join() {

	borderLine();

	// ���� ����

	gotoxy(67, 13);
	cout << "�� ȸ �� �� �� ��" << endl;
	gotoxy(58, 15);
	cout << "�� �̸��л��鸸 �̿� �����մϴ� ��";
	gotoxy(65, 18);
	cout << "��   ��    �� \t";
	cin >> id;
	gotoxy(65, 19);
	cout << "��   ��й�ȣ \t";
	cin >> pw;
	gotoxy(65, 20);
	cout << "��   ��    �� \t";
	cin >> name;

	// ����:���ڵ����
	char query[255];
	sprintf(query, "INSERT INTO user VALUES(%d, '%s', '%s')", id, pw, name);
	int stat = mysql_query(mysql, query);


	while (1) {
		gotoxy(48, 24);
		cout << "����������������������������������������������������������������������������������������������������������������������";
		gotoxy(48, 25);
		cout << "��            �������� �Ѿ�÷��� j�� �����ּ���         ��";
		gotoxy(48, 26);
		cout << "����������������������������������������������������������������������������������������������������������������������";

		join_key = _getch();	// ���� �� ����
		if (join_key == 'j') {
			system("cls");
			break;
		}
	}



}

// login function
void login() {


	borderLine();

	// ���� ����


	gotoxy(65, 8);
	cout << "��������������������������������������";
	gotoxy(69, 9);
	cout << "�� �α��� ��" << endl;
	gotoxy(65, 10);
	cout << "��������������������������������������";

	/*gotoxy(58, 15);
	cout << "�� �̸��л��鸸 �̿� �����մϴ� ��";*/
	gotoxy(47, 16);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(65, 18);
	cout << "��   ��   ��  \t";
	cin >> id;
	gotoxy(65, 19);
	cout << "��   ��й�ȣ \t";
	cin >> pw;
	gotoxy(47, 21);
	cout << "����������������������������������������������������������������������������������������������������������������������";



	gotoxy(48, 24);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(48, 25);
	cout << "��                   �α��� ( L ) Ŭ�� !                   ��";
	gotoxy(48, 26);
	cout << "����������������������������������������������������������������������������������������������������������������������";


	char query[255];
	join_key = _getch();	// ���� �� ����
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
				cout << "�α��� �Ǿ����ϴ�.";

			}
			else cout << "���̵� �Ǵ� ��й�ȣ�� ��ġ���� �ʽ��ϴ�.";

		} else cout << "���̵� �Ǵ� ��й�ȣ�� ��ġ���� �ʽ��ϴ�";
		Sleep(1000);
		system("cls");
		foodMarket();
	}

}


// ����
void foodMarket() {

	gotoxy(66, 3);
	cout << "��������������������������������������";
	gotoxy(68, 4);
	cout << "�� ���� & ���� ��" << endl;
	gotoxy(66, 5);
	cout << "��������������������������������������";


	// ���
	gotoxy(18, 8);
	cout << "1. �ż��� ��� ";
	gotoxy(18, 9);
	cout << "1000��";
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


	// ����
	gotoxy(48, 8);
	setColor(WHITE);
	cout << "2. ��õ ����";
	gotoxy(48, 9);
	cout << "2000��";
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


	// ġ��
	gotoxy(80, 8);
	setColor(WHITE);
	cout << "3. ���忡�� ���� ġ��";
	gotoxy(80, 9);
	cout << "1500��";
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

	// ���ݷ�
	gotoxy(115, 8);
	setColor(WHITE);
	cout << "4. �Ƿθ� �����ִ� ���ݸ�";
	gotoxy(115, 9);
	cout << "2000��";
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


	// Ŀ��
	gotoxy(18, 22);
	setColor(WHITE);
	cout << "5. ���� ���� Ŀ��";
	gotoxy(18, 23);
	cout << "3000��";
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


	// ����ũ
	gotoxy(48, 22);
	setColor(WHITE);
	cout << "6. ������ ����ũ";
	gotoxy(48, 23);
	cout << "5000��";
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


	// ��������
	gotoxy(80, 22);
	setColor(WHITE);
	cout << "7. ��������";
	gotoxy(80, 23);
	cout << "6000��";
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
	cout << "6. ��������";
	gotoxy(115, 23);
	cout << "1500��";
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


	foodNumberKey = _getch();		// Ű����κ��� ���� �� ����

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


}

// ������ �ֹ� ���� �Լ�
void foodApple() {

	setColor(WHITE);

	borderLine();


	gotoxy(62, 9);
	cout << "��  ����� �� ���� �ֹ��Ͻðڽ��ϱ� ? ��" << endl;

	gotoxy(47, 16);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(65, 18);
	cout << "��   ��    ��  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "����������������������������������������������������������������������������������������������������������������������";

	gotoxy(48, 22);
	cout << "�ֹ��Ͻ÷��� �й��� �Է����ּ��� : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(48, 25);
	cout << "��                  ��ٱ��� ( L ) ��� !                  ��";
	gotoxy(48, 26);
	cout << "����������������������������������������������������������������������������������������������������������������������";


	int money = foodCnt1 * 1000;

	join_key = _getch();	// ���� �� ����
	if (join_key == 'l') {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "���", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "�޴��� ����� ����� �ʾҽ��ϴ�. �޴� ����ȭ������ �ٽ� �̵��մϴ�.";
			Sleep(1000);
			system("cls");
			foodMarket();

		} else {
			system("cls");
			cout << "�޴��� ���������� �����ϴ� !";
			Sleep(1000);
			system("cls");
			basket();
		}
	}



}

void foodGrape() {

	setColor(WHITE);

	borderLine();


	gotoxy(62, 9);
	cout << "��  ������ �� ���� �ֹ��Ͻðڽ��ϱ� ? ��" << endl;

	gotoxy(47, 16);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(65, 18);
	cout << "��   ��    ��  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "����������������������������������������������������������������������������������������������������������������������";

	gotoxy(48, 22);
	cout << "�ֹ��Ͻ÷��� �й��� �Է����ּ��� : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(48, 25);
	cout << "��                  ��ٱ��� ( L ) ��� !                  ��";
	gotoxy(48, 26);
	cout << "����������������������������������������������������������������������������������������������������������������������";


	int money = foodCnt1 * 2000;

	join_key = _getch();	// ���� �� ����
	if (join_key == 'l') {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "����", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "�޴��� ����� ����� �ʾҽ��ϴ�. �޴� ����ȭ������ �ٽ� �̵��մϴ�.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "�޴��� ���������� �����ϴ� !";
			Sleep(1000);
			system("cls");
			basket();
		}
	}



}

void foodcheese() {

	setColor(WHITE);

	borderLine();


	gotoxy(62, 9);
	cout << "��  ġ� �� ���� �ֹ��Ͻðڽ��ϱ� ? ��" << endl;

	gotoxy(47, 16);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(65, 18);
	cout << "��   ��    ��  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "����������������������������������������������������������������������������������������������������������������������";

	gotoxy(48, 22);
	cout << "�ֹ��Ͻ÷��� �й��� �Է����ּ��� : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(48, 25);
	cout << "��                  ��ٱ��� ( L ) ��� !                  ��";
	gotoxy(48, 26);
	cout << "����������������������������������������������������������������������������������������������������������������������";


	int money = foodCnt1 * 1500;

	join_key = _getch();	// ���� �� ����
	if (join_key == 'l') {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "ġ��", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "�޴��� ����� ����� �ʾҽ��ϴ�. �޴� ����ȭ������ �ٽ� �̵��մϴ�.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "�޴��� ���������� �����ϴ� !";
			Sleep(1000);
			system("cls");
			basket();
		}
	}



}


void foodchoco() {

	setColor(WHITE);

	borderLine();


	gotoxy(62, 9);
	cout << "��  ���ݸ��� �� ���� �ֹ��Ͻðڽ��ϱ� ? ��" << endl;

	gotoxy(47, 16);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(65, 18);
	cout << "��   ��    ��  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "����������������������������������������������������������������������������������������������������������������������";

	gotoxy(48, 22);
	cout << "�ֹ��Ͻ÷��� �й��� �Է����ּ��� : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(48, 25);
	cout << "��                  ��ٱ��� ( L ) ��� !                  ��";
	gotoxy(48, 26);
	cout << "����������������������������������������������������������������������������������������������������������������������";


	int money = foodCnt1 * 2000;

	join_key = _getch();	// ���� �� ����
	if (join_key == 'l') {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "���ݸ�", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "�޴��� ����� ����� �ʾҽ��ϴ�. �޴� ����ȭ������ �ٽ� �̵��մϴ�.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "�޴��� ���������� �����ϴ� !";
			Sleep(1000);
			system("cls");
			basket();
		}
	}



}

void foodCoffee() {

	setColor(WHITE);

	borderLine();


	gotoxy(62, 9);
	cout << "��  Ŀ�Ǹ� �� ���� �ֹ��Ͻðڽ��ϱ� ? ��" << endl;

	gotoxy(47, 16);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(65, 18);
	cout << "��   ��    ��  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "����������������������������������������������������������������������������������������������������������������������";

	gotoxy(48, 22);
	cout << "�ֹ��Ͻ÷��� �й��� �Է����ּ��� : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(48, 25);
	cout << "��                  ��ٱ��� ( L ) ��� !                  ��";
	gotoxy(48, 26);
	cout << "����������������������������������������������������������������������������������������������������������������������";


	int money = foodCnt1 * 3000;

	join_key = _getch();	// ���� �� ����
	if (join_key == 'l') {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "Ŀ��", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "�޴��� ����� ����� �ʾҽ��ϴ�. �޴� ����ȭ������ �ٽ� �̵��մϴ�.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "�޴��� ���������� �����ϴ� !";
			Sleep(1000);
			system("cls");
			basket();
		}
	}



}

void foodCake() {

	setColor(WHITE);

	borderLine();


	gotoxy(62, 9);
	cout << "��  ����ũ�� �� ���� �ֹ��Ͻðڽ��ϱ� ? ��" << endl;

	gotoxy(47, 16);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(65, 18);
	cout << "��   ��    ��  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "����������������������������������������������������������������������������������������������������������������������";

	gotoxy(48, 22);
	cout << "�ֹ��Ͻ÷��� �й��� �Է����ּ��� : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(48, 25);
	cout << "��                  ��ٱ��� ( L ) ��� !                  ��";
	gotoxy(48, 26);
	cout << "����������������������������������������������������������������������������������������������������������������������";


	int money = foodCnt1 * 5000;

	join_key = _getch();	// ���� �� ����
	if (join_key == 'l') {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "����ũ", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "�޴��� ����� ����� �ʾҽ��ϴ�. �޴� ����ȭ������ �ٽ� �̵��մϴ�.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "�޴��� ���������� �����ϴ� !";
			Sleep(1000);
			system("cls");
			basket();
		}
	}



}

void foodPie() {

	setColor(WHITE);

	borderLine();


	gotoxy(62, 9);
	cout << "��  �������̸� �� ���� �ֹ��Ͻðڽ��ϱ� ? ��" << endl;

	gotoxy(47, 16);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(65, 18);
	cout << "��   ��    ��  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "����������������������������������������������������������������������������������������������������������������������";

	gotoxy(48, 22);
	cout << "�ֹ��Ͻ÷��� �й��� �Է����ּ��� : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(48, 25);
	cout << "��                  ��ٱ��� ( L ) ��� !                  ��";
	gotoxy(48, 26);
	cout << "����������������������������������������������������������������������������������������������������������������������";


	int money = foodCnt1 * 6000;

	join_key = _getch();	// ���� �� ����
	if (join_key == 'l') {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "��������", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "�޴��� ����� ����� �ʾҽ��ϴ�. �޴� ����ȭ������ �ٽ� �̵��մϴ�.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "�޴��� ���������� �����ϴ� !";
			Sleep(1000);
			system("cls");
			basket();
		}
	}



}

void foodMlik() {

	setColor(WHITE);

	borderLine();


	gotoxy(62, 9);
	cout << "��  ������ �� ���� �ֹ��Ͻðڽ��ϱ� ? ��" << endl;

	gotoxy(47, 16);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(65, 18);
	cout << "��   ��    ��  \t";
	cin >> foodCnt1;
	gotoxy(47, 20);
	cout << "����������������������������������������������������������������������������������������������������������������������";

	gotoxy(48, 22);
	cout << "�ֹ��Ͻ÷��� �й��� �Է����ּ��� : ";
	cin >> id;

	gotoxy(48, 24);
	cout << "����������������������������������������������������������������������������������������������������������������������";
	gotoxy(48, 25);
	cout << "��                  ��ٱ��� ( L ) ��� !                  ��";
	gotoxy(48, 26);
	cout << "����������������������������������������������������������������������������������������������������������������������";


	int money = foodCnt1 * 1500;

	join_key = _getch();	// ���� �� ����
	if (join_key == 'l') {
		system("cls");
		char query[255];
		sprintf(query, "INSERT INTO product VALUES(%d, '%s', %d, %d)", id, "����", foodCnt1, money);
		int stat = mysql_query(mysql, query);

		if (stat != 0) {
			system("cls");
			cout << "�޴��� ����� ����� �ʾҽ��ϴ�. �޴� ����ȭ������ �ٽ� �̵��մϴ�.";
			Sleep(1000);
			system("cls");
			foodMarket();

		}
		else {
			system("cls");
			cout << "�޴��� ���������� �����ϴ� !";
			Sleep(1000);
			system("cls");
			basket();
		}
	}



}


void basket() {
	borderLine();

	gotoxy(55, 8);
	cout << "����������������������������������������������������������������������������������������";
	gotoxy(65, 9);
	cout << "��ٱ��� ���" << endl;
	gotoxy(55, 10);
	cout << "����������������������������������������������������������������������������������������";

	gotoxy(56, 22);
	cout << "���Ÿ���� Ȯ���Ͻ÷��� �й��� �Է����ּ��� : ";
	cin >> id;

	char query[255];
	join_key = _getch();	// ���� �� ����
	if (join_key == 'l') {
		system("cls");
		sprintf(query, "select foodname, cnt, money from product where id = '%s'", id);
		int state = mysql_query(mysql, query);

		if (state == 0) {

			res = mysql_store_result(mysql);		// Result set�� ����

			while ((row = mysql_fetch_row(res)) != NULL) {		// Result set���� 1���� �迭�� ������

				cout << row[0] << " " << row[1] << " " << row[2] << endl;					// ����� �迭�� ���

			}

			// Result set ����
			mysql_free_result(res);
		}

		Sleep(1000);
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

	mysql_query(mysql, "set session character_set_connection=euckr;");
	mysql_query(mysql, "set session character_set_results=euckr;");
	mysql_query(mysql, "set session character_set_client=euckr;");

	// console �⺻ ����
	system("mode con: cols=160 lines=40");
	SetConsoleTitle(TEXT("MaMi"));

	int key;	// Ű����� �Է¹��� ��


	while (1) {

		// ���ηΰ� ȣ��
		mamilogo();

		key = _getch(); // ���� �� ����

		if (key == '1') {					// ȸ������â ȣ�� -> �α��� -> Ǫ�帶��
			system("cls");
			join();
			if (join_key == 'j') {
				system("cls");
				login();  break;
			}

		}
		else if (key == '2') {				// �α��� -> Ǫ�帶��
			system("cls");
			login();
			if (join_key == 'l') {
				system("cls");
				break;
			}
		}
		else if (key == '3') {				/// ���α׷� ����
			exit(0);
		}

	}

	// ���� �޴� ��� ȭ�� ���
	foodMarket();




	// ��� ���α׷��� ���� ���� ��
	system("pause");
}