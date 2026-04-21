//Mã số sinh viên: 25520518
//Họ và tên sinh viên: Nguyễn Lê Duy Hậu
//Ngày sinh: 22/03/2007
//Lớp: IT002.Q25.2
#include<iostream>
#include <cmath>
using namespace std;
class cSoPhuc {
private:
	float thuc, ao;
public:
	void DinhGiaTri(float t, float a) {
		thuc = t;
		ao = a;
	}
	void Nhap() {
		cin >> thuc;
		cin >> ao;
	}
	void Xuat() {
		if (ao >= 0) cout << thuc << "+" << ao << "i";
		else cout << thuc << "-" << abs(ao) << "i";
	}
	cSoPhuc Cong(cSoPhuc b) {
		cSoPhuc res;
		res.thuc = thuc + b.thuc;
		res.ao = ao + b.ao;
        return res;
	}
  
    cSoPhuc Tru(cSoPhuc b) {
        cSoPhuc res;
        res.thuc = thuc - b.thuc;
        res.ao = ao - b.ao;
        return res;
    }

    cSoPhuc Nhan(cSoPhuc b) {
        cSoPhuc res;
        res.thuc = thuc * b.thuc - ao * b.ao;
        res.ao = thuc * b.ao + ao * b.thuc;
        return res;
    }

    cSoPhuc Chia(cSoPhuc b) {
        cSoPhuc res;
        float mau = b.thuc * b.thuc + b.ao * b.ao;
        if (mau != 0) {
            res.thuc = (thuc * b.thuc + ao * b.ao) / mau;
            res.ao = (b.thuc * ao - thuc * b.ao) / mau;
        }
        else {
            res.thuc = 0; res.ao = 0; 
        }
        return res;
    }
};
int main() {
    cSoPhuc a, b;
    a.Nhap();
    b.Nhap();
    cout << "A + B = "; a.Cong(b).Xuat(); cout << endl;
    cout << "A - B = "; a.Tru(b).Xuat(); cout << endl;
    cout << "A * B = "; a.Nhan(b).Xuat(); cout << endl;
    cout << "A / B = "; a.Chia(b).Xuat(); cout << endl;

    return 0;
}