// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2

#include <iostream>
#include <string>
using namespace std;

class cDate {
private:
	int  Ngay, Thang, Nam;
public:
	cDate() {
		Ngay = 1;
		Thang = 1;
		Nam = 2026;
	}
	bool KiemTraNamNhuam() {
		return (Nam % 400 == 0) || (Nam % 4 == 0 && Nam % 100 != 0);
	}
	int SoNgayTrongThang() {
		int ngay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (KiemTraNamNhuam())ngay[2] = 29;
		return ngay[Thang];
	}
	void Nhap() {
		do {
			cin >> Ngay >> Thang >> Nam;
		} while (Nam < 1 || Thang < 1 || Thang>12 || Ngay<1 || Ngay>SoNgayTrongThang());
	}
	void Xuat() {
		cout << Ngay << "/" << Thang << "/" << Nam << endl;
	}
	void SetNgay(int n) {
		if (n >= 1 && n <= SoNgayTrongThang())
			Ngay = n; 
	}
	void SetThang(int m) {
		if (m >= 1 && m <= 12) {
			Thang = m;
			if (Ngay > SoNgayTrongThang()) {
				Ngay = SoNgayTrongThang();
			}
		}
	}
	void SetNam(int y) {
		if (y > 0) {
		Nam = y;
			if (Ngay > SoNgayTrongThang()) {
				Ngay = SoNgayTrongThang();
			}
		}
	}
	int GetNgay() { return Ngay; }
	int GetThang() { return Thang; }
	int GetNam() { return Nam; }
	
	void TangNgay() {
		Ngay++;
		if (Ngay > SoNgayTrongThang()) {
			Ngay = 1;
			Thang++;
			if (Thang > 12) {
				Thang = 1;
				Nam++;
			}
		}
	}

	void GiamNgay() {
		Ngay--;
		if (Ngay < 1) {
			Thang--;
			if (Thang < 1) {
				Thang = 12;
				Nam--;
			}
			Ngay = SoNgayTrongThang(); 
		}
	}
	void TangThang() {
		Thang++;
		if (Thang > 12) {
			Thang = 1;
			Nam++;
		}
		if (Ngay > SoNgayTrongThang()) Ngay = SoNgayTrongThang();
	}

	void GiamThang() {
		Thang--;
		if (Thang < 1) {
			Thang = 12;
			Nam--;
		}
		if (Ngay > SoNgayTrongThang()) Ngay = SoNgayTrongThang();
	}

	void TangNam() {
		Nam++;
		if (Ngay > SoNgayTrongThang()) Ngay = SoNgayTrongThang(); // Xử lý 29/02 năm nhuận
	}

	void GiamNam() {
		if (Nam > 1) Nam--;
		if (Ngay > SoNgayTrongThang()) Ngay = SoNgayTrongThang();
	}
};
int main() {
	cDate n;
	n.SetNgay(22);
	n.SetThang(3);
	n.SetNam(2007);
	n.Xuat();
	n.TangNgay();
	n.Xuat();
}