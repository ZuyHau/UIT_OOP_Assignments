// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
#include<string.h>
using namespace std;

class cString {
private:
    char* content; 
    int length;    

public:
    cString() {
        length = 0;
        content = new char[1];
        content[0] = '\0';
    }

    cString(const char* s) {
        length = strlen(s);
        content = new char[length + 1];
        strcpy(content, s);
    }

    cString(const cString& other) {
        length = other.length;
        content = new char[length + 1];
        strcpy(content, other.content);
    }

    ~cString() {
        delete[] content;
    }

    int Length() {
        return length;
    }

    cString NoiChuoi(const cString& s) {
        cString res;
        delete[] res.content; 
        res.length = length + s.length;
        res.content = new char[res.length + 1];
        strcpy(res.content, content);
        strcat(res.content, s.content);
        return res;
    }
    void DaoChuoi() {
        for (int i = 0; i < length / 2; i++) {
            char temp = content[i];
            content[i] = content[length - 1 - i];
            content[length - 1 - i] = temp;
        }
    }

    void ToUpper() {
        for (int i = 0; i < length; i++) {
            if (content[i] >= 'a' && content[i] <= 'z')
                content[i] -= 32;
        }
    }

    void ToLower() {
        for (int i = 0; i < length; i++) {
            if (content[i] >= 'A' && content[i] <= 'Z')
                content[i] += 32;
        }
    }

    void Nhap() {
        char temp[1000]; 
        cin.getline(temp, 1000);
        length = strlen(temp);
        delete[] content; 
        content = new char[length + 1];
        strcpy(content, temp);
    }

    void Xuat() {
        cout << content;
    }
};

int main() {
    cString s1, s2;

    s1.Nhap();
    s2.Nhap();
    cout << s1.Length() << endl;

    cString s3 = s1.NoiChuoi(s2);
    s3.Xuat(); cout << endl;

    s1.DaoChuoi();
    s1.Xuat(); cout << endl;

    s1.ToUpper();
    s1.Xuat(); cout << endl;

    s1.ToLower();
    s1.Xuat(); cout << endl;

    return 0;
}