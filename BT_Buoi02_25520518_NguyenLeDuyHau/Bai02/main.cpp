//Mã số sinh viên: 25520518
//Họ và tên sinh viên: Nguyễn Lê Duy Hậu
//Ngày sinh: 22/03/2007
//Lớp: IT002.Q25.2
#include<iostream>
using namespace std;
class cDiem {
private:
	float hoanhdo, tungdo;
public:
	cDiem() {
		hoanhdo = 0;
		tungdo = 0;
	}
	cDiem(float hoanh, float tung) {
		hoanhdo = hoanh;
		tungdo = tung;

	} 
	void Nhap() {
		cin >> hoanhdo;
		cin >> tungdo;
	}
	void Xuat() {
		cout << "(" << hoanhdo << "," << tungdo << ")";
	}
	float GetHoanhDo() {
		return hoanhdo;
	}
	float GetTungDo() {
		return tungdo;
	}
	void SetHoanhDo(float hoanh) {
		hoanhdo = hoanh;
	}
	void SetTungDo(float tung) {
		tungdo = tung;
	}
	void SetDiem(float hoanh, float tung) {
		hoanhdo = hoanh;
		tungdo = tung;
	}
	void TinhTien(float dx, float dy) {
		hoanhdo += dx;
		tungdo += dy;
	}
};
int main() {
	cDiem d1;
	d1.Nhap();
	d1.Xuat();
	float a, b;
	cin >> a >> b;
	d1.SetHoanhDo(a);
	d1.SetTungDo(b);
	d1.Xuat();
	float c, d;
	cin >> c >> d;
	d1.SetDiem(c, d);
	d1.Xuat();
	float x, y;
	cin >> x >> y;
	d1.TinhTien(x,y);
	d1.Xuat();

	return 0;
}