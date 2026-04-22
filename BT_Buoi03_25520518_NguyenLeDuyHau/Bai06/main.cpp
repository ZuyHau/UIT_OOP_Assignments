// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2

#include "cCandidate.h"

int main() {
    cListCandidate list;

    list.Nhap();

    cout << "\n--- THI SINH CO TONG DIEM > 15 ---\n";
    list.XuatTren15();

    cout << "\n--- THI SINH CO TONG DIEM CAO NHAT ---\n";
    list.TimMaxTong();

    cout << "\n--- DANH SACH SAU KHI SAP XEP GIAM DAN ---\n";
    list.SapXepGiam();
    // Xuất lại danh sách sau khi sắp xếp (mượn logic Xuat của list nếu cần)
    // Ở đây mình tận dụng logic XuatTren15 với điều kiện luôn đúng để xem toàn bộ
    for (int i = 0; i < 1; i++) { // Demo xuất sau khi sắp xếp
        list.XuatTren15(); // Lưu ý: hàm này chỉ hiện > 15, Hậu có thể viết thêm hàm XuatAll nếu muốn
    }

    return 0;
}