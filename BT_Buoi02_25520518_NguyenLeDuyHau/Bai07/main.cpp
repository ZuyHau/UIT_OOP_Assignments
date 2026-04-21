// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2

#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

class Vehicle {
private:
    string chuXe;
    string loaiXe;
    float triGia;
    int dungTich;

public:
    Vehicle(string chu = "", string loai = "", float gia = 0, int cc = 0) {
        chuXe = chu;
        loaiXe = loai;
        triGia = (gia >= 0) ? gia : 0;
        dungTich = (cc >= 0) ? cc : 0;
    }

    void Nhap() {
        cout << "Nhap ten chu xe: ";
        getline(cin >> ws, chuXe);
        cout << "Nhap loai xe: ";
        getline(cin, loaiXe);

        do {
            cout << "Nhap tri gia xe (>=0): "; cin >> triGia;
        } while (triGia < 0);

        do {
            cout << "Nhap dung tich xylanh (>=0): "; cin >> dungTich;
        } while (dungTich < 0);
    }

    float TinhThue() {
        if (dungTich < 100) return triGia * 0.01f;
        if (dungTich <= 200) return triGia * 0.03f;
        return triGia * 0.05f;
    }

    void Xuat(int stt) {
        cout << left << setw(5) << stt
            << setw(20) << chuXe
            << setw(15) << loaiXe
            << setw(15) << (long long)triGia
            << setw(10) << dungTich
            << setw(15) << (long long)TinhThue() << endl;
    }
};

int main() {
    Vehicle xe1("Nguyen Van A", "Honda SH", 80000000, 150);
    Vehicle xe2("Le Thi B", "Yamaha R1", 500000000, 1000);

    Vehicle xe3;
    xe3.Nhap();

    cout << "\n" << string(80, '=') << endl;
    cout << left << setw(5) << "STT"
        << setw(20) << "Ten chu xe"
        << setw(15) << "Loai xe"
        << setw(15) << "Tri gia"
        << setw(10) << "Dung tich"
        << setw(15) << "Thue truoc ba" << endl;
    cout << string(80, '-') << endl;

    xe1.Xuat(1);
    xe2.Xuat(2);
    xe3.Xuat(3);
    cout << string(80, '=') << endl;

    system("pause");
    return 0;
}