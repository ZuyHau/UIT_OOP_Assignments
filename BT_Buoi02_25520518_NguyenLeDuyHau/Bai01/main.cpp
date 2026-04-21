//Mã số sinh viên: 25520518
//Họ và tên sinh viên: Nguyễn Lê Duy Hậu
//Ngày sinh: 22/03/2007
//Lớp: IT002.Q25.2
#include<iostream>
#include<numeric>
using namespace std; 


class cPhanso {
private :
	int tuso, mauso;
public:
	void Nhap()
	{
		cin >> tuso;
		do {
			cin >> mauso;
		} while (mauso == 0);
	}
	void Xuat()
	{
		if (mauso == 1) cout << tuso;
		else if (tuso == 0) cout << 0;
		else cout << tuso << "/" << mauso;
	}
	void RutGon()
	{
		int temp = gcd(tuso, mauso);
		tuso /= temp;
		mauso /= temp;
		if (mauso < 0)
		{
			tuso = -tuso;
			mauso = -mauso;
		}
	}
	cPhanso Cong(cPhanso b)
	{
		cPhanso res;
		res.tuso = tuso * b.mauso + b.tuso * mauso;
		res.mauso = mauso * b.mauso;
		res.RutGon();
		return res;
	}
	cPhanso Tru(cPhanso b)
	{
		cPhanso res;
		res.tuso = tuso * b.mauso - b.tuso * mauso;
		res.mauso = mauso * b.mauso;
		res.RutGon();
		return res;
	}
	cPhanso Nhan(cPhanso b)
	{
		cPhanso res;
		res.tuso = tuso * b.tuso;
		res.mauso = mauso * b.mauso;
		res.RutGon();
		return res;
	}
	cPhanso Chia(cPhanso b)
	{
		cPhanso res;
		res.tuso = tuso * b.mauso;
		res.mauso = mauso * b.tuso;
		res.RutGon();
		return res;
	}
	
};

int main()
{
	cPhanso ps1, ps2;
	ps1.Nhap();
	ps2.Nhap();
	cout << "Tong: ";ps1.Cong(ps2).Xuat();cout << endl;
	cout << "Hieu: ";ps1.Tru(ps2).Xuat();cout << endl;
	cout << "Tich: ";ps1.Nhan(ps2).Xuat();cout << endl;
	cout << "Thuong: ";ps1.Chia(ps2).Xuat();cout << endl;

	return 0;
}