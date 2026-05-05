#include <iostream>
#include <iomanip>
#include <windows.h> // Thư viện để điều khiển tọa độ màn hình và Sleep

using namespace std;

class CTime {
private:
    int gio, phut, giay;

    // Hàm chuẩn hóa để xử lý khi giây hoặc phút vượt quá 60 hoặc nhỏ hơn 0
    void chuanHoa() {
        long long tongGiay = (long long)gio * 3600 + phut * 60 + giay;
        if (tongGiay < 0) tongGiay = 0; // Đưa về mốc 0 nếu trừ quá đà

        tongGiay %= 86400; // Giới hạn trong 24 giờ (86400 giây)
        gio = tongGiay / 3600;
        phut = (tongGiay % 3600) / 60;
        giay = tongGiay % 60;
    }

public:
    CTime(int h = 0, int m = 0, int s = 0) : gio(h), phut(m), giay(s) {
        chuanHoa();
    }

    // Nạp chồng toán tử cộng/trừ số nguyên giây
    CTime operator+(int s) {
        return CTime(gio, phut, giay + s);
    }
    CTime operator-(int s) {
        return CTime(gio, phut, giay - s);
    }

    // Toán tử ++ (tiền tố và hậu tố)
    CTime& operator++() { // Tiền tố ++t
        giay++;
        chuanHoa();
        return *this;
    }
    CTime operator++(int) { // Hậu tố t++
        CTime temp = *this;
        ++(*this);
        return temp;
    }

    // Toán tử -- (tiền tố và hậu tố)
    CTime& operator--() {
        giay--;
        chuanHoa();
        return *this;
    }
    CTime operator--(int) {
        CTime temp = *this;
        --(*this);
        return temp;
    }

    // Nhập xuất dữ liệu
    friend istream& operator>>(istream& is, CTime& t) {
        cout << "Nhap Gio Phut Giay: ";
        is >> t.gio >> t.phut >> t.giay;
        t.chuanHoa();
        return is;
    }

    friend ostream& operator<<(ostream& os, const CTime& t) {
        os << setfill('0') << setw(2) << t.gio << ":"
            << setw(2) << t.phut << ":"
            << setw(2) << t.giay;
        return os;
    }

    // Hàm hỗ trợ vẽ đồng hồ ở góc màn hình
    void veDongHo(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << "Time: " << *this << flush;
    }
};

int main() {
    CTime t;
    cout << "--- Thiet lap thoi gian ban dau ---" << endl;
    cin >> t;

    cout << "\nBat dau chay dong ho o goc tren ben phai (Nhan Ctrl+C de dung)..." << endl;

    // Áp dụng: Tạo đồng hồ in ở góc trên bên phải màn hình
    while (true) {
        t.veDongHo(60, 0); // Tọa độ x=60, y=0 (góc trên bên phải)
        Sleep(1000);       // Tạm dừng 1 giây
        t++;               // Tăng thời gian lên 1 giây
    }

    return 0;
}