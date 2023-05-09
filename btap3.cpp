#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

class SinhVien {
private:
	string msv, ten, lop, email;
public:
	SinhVien() {
		msv = ten = lop = email = "";
	}
	string getLop() {
		return this->lop;
	}
	void Nhap();
	void In();
};

void SinhVien::Nhap() {
	cin >> msv;
	cin.ignore();
	getline(cin, ten);
	cin >> lop >> email;
}

void SinhVien::In() {
	cout << msv << " " << ten << " " << lop << " " << email << endl;
}
bool cmp(SinhVien a, SinhVien b) {
	return a.getLop() < b.getLop();
}
int main() {
	int n;
	cin >> n;
	SinhVien a[1000];
	for (int i = 0; i < n; i++) {
		 a[i].Nhap();
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++) {
		a[i].In();
	}
}