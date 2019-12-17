// CARO3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
//x: chieu Ngang; y: chien doc
using namespace std;
char a[79][24], key;
short x, y, i, m, n, m1, n1, LuaChon; //m1,n1: phuc vu cho viec kiem tra Dieu Kien chien thang
									  //Cac thu tuc trang tri
void MoDau();
void Choi2Nguoi();
void ChoiVoiMay();
void ThongTin();
void Thoat();
void HuongDan(short);
void VeKhung();

void Goto(int x, int y) {
	COORD co = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);
}

void TextColor(int x)//Xac dinh mau cua chu
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
//Tro Choi
short Chan(short i) {// Kiem tra chan le de phuc vu cho chia luot
	if (i % 2 == 0) return 1;
	else return 0;
}

char OX(short i) {
	if (Chan(i) == 1) return 'O';
	else return 'X';
}

void VeOX() {//Ve O, X theo luot
	if (a[n][m] != 'X' && a[n][m] != 'O') {
		if (Chan(i) == 1) TextColor(11); else TextColor(12);
		a[n][m] = OX(i);
		cout << a[n][m];
		i += 1;
	}
	else a[n][m];
	TextColor(7);
}

void AnSangTrai() {
	x -= 1;
	if (x<13) x = 13;
}

void AnSangPhai() {
	x += 1;
	if (x >= 79) x = 79;
}

void AnLenTren() {
	y -= 1;
	if (y<3) y = 3;
}

void AnXuongDuoi() {
	y += 1;
	if (y >= 24) y = 24;
}

void ConTro(short x, short y) {  //Phuc vu cho di chuyen
	Goto(x, y);
	n = x; m = y;
}

void ThongTinTrauDau() {
	TextColor(7);
	//Thong tin
	Goto(0, 0); cout << "Toa Do: " << x << "-" << y << "    Q : Thoat tran dau." << endl << "Luot thu: " << i;
	//Trang tri
	cout << "     E: choi.";
	TextColor(12); cout << "         ";
	TextColor(14); cout << "p/s:" << endl << "Chan dau," << endl << "chan duoi " << endl << "van tinh=))";
	TextColor(7);
}

short DKOChienThang() {//Dieu kien de ben O chien thang
					   //Theo hang ngang
	m1 = m; n1 = n;
	while (a[n1][m] == 'O')
		n1++;
	n1--;
	//Doan tren nham muc dich chuen con tro den vi tri 'O' dau hang de tien cho viec xet vi neu 'O' duoc nhap o giau hang se khong xet
	if ((a[n1][m] == 'O') && (a[n1 + 1][m] == 'O') && (a[n1 + 2][m] == 'O') && (a[n1 + 3][m] == 'O') && (a[n1 + 4][m] == 'O')) return 1; else
		if ((a[n1][m] == 'O') && (a[n1 - 1][m] == 'O') && (a[n1 - 2][m] == 'O') && (a[n1 - 3][m] == 'O') && (a[n1 - 4][m] == 'O')) return 1;
	//Theo hang doc
	m1 = m; n1 = n;
	while (a[n][m1] == 'O')
		m1++;
	m1--;
	//Theo duong cheo chinh
	if ((a[n][m1] == 'O') && (a[n][m1 + 1] == 'O') && (a[n][m1 + 2] == 'O') && (a[n][m1 + 3] == 'O') && (a[n][m1 + 4] == 'O')) return 1; else
		if ((a[n][m1] == 'O') && (a[n][m1 - 1] == 'O') && (a[n][m1 - 2] == 'O') && (a[n][m1 - 3] == 'O') && (a[n][m1 - 4] == 'O')) return 1;
	//Theo duong cheo phu
	m1 = m; n1 = n;
	while (a[n1][m1] == 'O') {
		m1++; n1++;
	}
	m1--; n1--;
	if ((a[n1][m1] == 'O') && (a[n1 + 1][m1 + 1] == 'O') && (a[n1 + 2][m1 + 2] == 'O') && (a[n1 + 3][m1 + 3] == 'O') && (a[n1 + 4][m1 + 4] == 'O')) return 1; else
		if ((a[n1][m1] == 'O') && (a[n1 - 1][m1 - 1] == 'O') && (a[n1 - 2][m1 - 2] == 'O') && (a[n1 - 3][m1 - 3] == 'O') && (a[n1 - 4][m1 - 4] == 'O')) return 1;
	m1 = m; n1 = n;
	while (a[n1][m1] == 'O') {
		n1++; m1--;
	}
	n1--; m1++;
	if ((a[n1][m1]) == 'O' && (a[n1 + 1][m1 - 1]) == 'O' && (a[n1 + 2][m1 - 2]) == 'O' && (a[n1 + 3][m1 - 3]) == 'O' && (a[n1 + 4][m1 - 4] == 'O')) return 1; else
		if ((a[n1][m1]) == 'O' && (a[n1 - 1][m1 + 1]) == 'O' && (a[n1 - 2][m1 + 2]) == 'O' && (a[n1 - 3][m1 + 3]) == 'O' && (a[n1 - 4][m1 + 4] == 'O')) return 1;

	return 0;
}

short DKXChienThang() { //Dieu kien de ben X chien thang
						//THeo hang ngang
	m1 = m; n1 = n;
	while (a[n1][m] == 'X') {
		n1++;
	}
	n1--;
	//Doan tren nham muc dich chuen con tro den vi tri 'O' dau hang de tien cho viec xet vi neu 'O' duoc nhap o giau hang se khong xet duoc
	if ((a[n1][m] == 'X') && (a[n1 + 1][m] == 'X') && (a[n1 + 2][m] == 'X') && (a[n1 + 3][m] == 'X') && (a[n1 + 4][m] == 'X')) return 1; else //Theo Hang ngang
		if ((a[n1][m] == 'X') && (a[n1 - 1][m] == 'X') && (a[n1 - 2][m] == 'X') && (a[n1 - 3][m] == 'X') && (a[n1 - 4][m] == 'X')) return 1;
	//Theo hang doc
	m1 = m; n1 = n;
	while (a[n][m1] == 'X') {
		m1++;
	}
	m1--;
	if ((a[n][m1] == 'X') && (a[n][m1 + 1] == 'X') && (a[n][m1 + 2] == 'X') && (a[n][m1 + 3] == 'X') && (a[n][m1 + 4] == 'X')) return 1; else //Theo Hang doc
		if ((a[n][m1] == 'X') && (a[n][m1 - 1] == 'X') && (a[n][m1 - 2] == 'X') && (a[n][m1 - 3] == 'X') && (a[n][m1 - 4] == 'X')) return 1;
	//Theo duong cheo chinh
	m1 = m; n1 = n;
	while (a[n1][m1] == 'X') {
		m1++; n1++;
	}
	m1--; n1--;
	if ((a[n1][m1] == 'X') && (a[n1 + 1][m1 + 1] == 'X') && (a[n1 + 2][m1 + 2] == 'X') && (a[n1 + 3][m1 + 3] == 'X') && (a[n1 + 4][m1 + 4] == 'X')) return 1; else //Theo Duong cheo chinh
		if ((a[n1][m1] == 'X') && (a[n1 - 1][m1 - 1] == 'X') && (a[n1 - 2][m1 - 2] == 'X') && (a[n1 - 3][m1 - 3] == 'X') && (a[n1 - 4][m1 - 4] == 'X')) return 1;
	//Theo duong cheo phu
	m1 = m; n1 = n;
	while (a[n1][m1] == 'X') {
		n1++; m1--;
	}
	n1--; m1++;
	if ((a[n1][m1]) == 'X' && (a[n1 + 1][m1 - 1]) == 'X' && (a[n1 + 2][m1 - 2]) == 'X' && (a[n1 + 3][m1 - 3]) == 'X' && (a[n1 + 4][m1 - 4] == 'X')) return 1; else //Theo Duong cheo phu
		if ((a[n1][m1]) == 'X' && (a[n1 - 1][m1 + 1]) == 'X' && (a[n1 - 2][m1 + 2]) == 'X' && (a[n1 - 3][m1 + 3]) == 'X' && (a[n1 - 4][m1 + 4] == 'X')) return 1;
	//Khong chien thang
	return 0;
}
// Ai do chien thang
void ChienThang() {
	TextColor(12);
	if ((DKOChienThang() == 1)) {
		Goto(33, 7);
		cout << "O chien thang";
	}
	else
		if ((DKXChienThang() == 1)) {
			Goto(33, 7);
			cout << "X Chien Thang";
		}
	TextColor(7);
}

void TuongTacPhim() {
	key = _getch();
	if (key == 'a' || key == 'A' || int(key == 75)) AnSangTrai(); else
		if (key == 'd' || key == 'D' || int(key == 77)) AnSangPhai(); else
			if (key == 'w' || key == 'W' || int(key == 72)) AnLenTren(); else
				if (key == 's' || key == 'S' || int(key == 80)) AnXuongDuoi(); else
					if ( key == 'e' || key == 'E' ) VeOX();
}

int main() {
	MoDau();
}

void MoDau() {
	system("cls");
	TextColor(7);
	cout << "1. Choi 2 nguoi." << endl;
	cout << "2. Choi voi may." << endl;
	cout << "3. Huong Dan." << endl;
	cout << "4. Gioi thieu chuong trinh." << endl;
	cout << "5. Thoat" << endl;
	cout << "Menu: ";
	LuaChon = _getch();
	cout << char(LuaChon);
	Sleep(200);
	if (LuaChon == '1') Choi2Nguoi(); else
		if (LuaChon == '2') ChoiVoiMay(); else
			if (LuaChon == '3') HuongDan(1); else
				if (LuaChon == '4') ThongTin(); else Thoat();

}

void VeKhung() {
	short i, n = 5;
	Goto(12, 2);
	for (i = 0; i <= 65; i++) {
		cout << "*"; Sleep(n);
	}
	for (i = 0; i <= 22; i++) {
		Goto(12, i + 2);
		Sleep(n);
		cout << "*";
	}
	Goto(12, 24);
	for (i = 0; i <= 65; i++) {
		cout << "*"; Sleep(n);
	}

	for (i = 0; i <= 22; i++) {
		Goto(78, i + 2);
		Sleep(n);
		cout << "*";
	}
}

void Choi2Nguoi() {
	system("cls");
	HuongDan(2);
	system("cls");
	VeKhung();
	x = n = 13; y = m = 3;
	i = 0;
	do {
		ThongTinTrauDau();
		ConTro(x, y);
		ChienThang();
		TuongTacPhim();
	} while (key != 'q' && key != 'Q');
	Thoat();
}

void ChoiVoiMay() {
	TextColor(9);
	cout << endl << endl << "Em chua lam duoc :((\n";
	TextColor(12);
	system("pause");
	MoDau();
}

void HuongDan(short k) {
	cout << "                             HUONG DAN" << endl << endl;
	cout << "Dung";
	TextColor(12);
	cout << " phim di chuyen";
	TextColor(7);
	
	cout << " de di chuyen. Dung phim";
	TextColor(12);
	cout << " E";
	TextColor(7);
	cout << " de choi.\n";

	system("pause");
	if (k == 1) MoDau();
}

void ThongTin() {
	TextColor(11);
	cout << endl;
	cout << "Name:Demo Caro" << endl;
	cout << "Ver: 0.2" << endl;
	cout << "MSSV:17110061 HXP" << endl;
	system("pause");
	TextColor(7);
	MoDau();
}

void Thoat() {
	TextColor(10);
	Goto(31, 11);
	cout << "Xin Chao! Hen Gap lai!";
	Goto(31, 12);
	
	_getch();
	ExitProcess(0);
}


