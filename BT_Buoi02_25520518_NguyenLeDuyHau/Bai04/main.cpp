//Mã số sinh viên: 25520518
//Họ và tên sinh viên: Nguyễn Lê Duy Hậu
//Ngày sinh: 22/03/2007
//Lớp: IT002.Q25.2
#include<iostream>
#include<iomanip>
using namespace std;
class cTime {
private:
	int Gio, Phut, Giay;
public:
	void SetTime(int h, int m, int s) {
		Gio = h;
		Phut = m;
		Giay = s;
	}
	void SetGio(int h) {
		if (h >= 0 && h < 24) Gio = h;
	}

	void SetPhut(int m) {
		if (m >= 0 && m < 60) Phut = m;
	}

	void SetGiay(int s) {
		if (s >= 0 && s < 60) Giay = s;
	}
	int GetGio() {
		return Gio;
	}
	int GetPhut() {
		return Phut;
	}
	int GetGiay() {
		return Giay;
	}
	void Nhap() {
		do {
			cin >> Gio;
			cin >> Phut;
			cin >> Giay;
			
		} while (Gio < 0 || Gio>23 || Phut < 0 || Phut>59 || Giay < 0 || Giay>59);
	}

	void Xuat() {
		cout << setfill('0') << setw(2) << Gio << ":"
			<< setfill('0') << setw(2) << Phut << ":"
			<< setfill('0') << setw(2) << Giay << endl;
	}
	void TangGiay() {
		Giay++;
		if (Giay >= 60) {
			Giay = 0;
			Phut++;
			if (Phut >= 60) {
				Phut = 0;
				Gio++;
				Gio %= 24;
			}
		}
	}
	void GiamGiay() {
		Giay--;
		if (Giay < 0) {
			Giay = 59;
			Phut--;
			if (Phut < 0) {
				Phut = 59;
				Gio = (Gio - 1 + 24) % 24;
			}
		}
	}
	void TangPhut() {
		Phut++;
		if (Phut >= 60) {
			Phut = 0;
			Gio++;
			Gio %= 24;
		}
	}
	void GiamPhut() {
		Phut--;
		if (Phut < 0) {
			Phut = 59;
			Gio = (Gio - 1 + 24) % 24;
		}
	}
	void TangGio() {
		Gio++;
		Gio %= 24;
	}
	void GiamGio() {
		Gio = (Gio - 1 + 24) % 24;
	}
};
int main() {
	cTime t;
	t.Nhap();
	t.Xuat();
	t.SetGiay(36);
	t.SetPhut(36);
	t.SetGio(18);
	t.Xuat();
	t.TangGiay();
	t.Xuat();
	t.GiamGiay();
	t.Xuat();
	t.TangPhut();
	t.Xuat();
	t.GiamPhut();
	t.Xuat();
	t.TangGio();
	t.Xuat();
	t.GiamGio();
	t.Xuat();

	return 0;
}