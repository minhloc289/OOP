#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;

class SinhVien {
private:
	string ten, msv, ns, lop;
	double gpa;
public:
	SinhVien(string ten, string ns, double gpa) {
		this->ten = ten;
		this->ns = ns;
		this->gpa = 0;
	}
	SinhVien() {
		msv = ten = ns = "";
		gpa = 0;
	}
	friend void Nhap(SinhVien& a);
	friend void In(SinhVien a);
};

void Nhap(SinhVien& a) {
	a.msv = "B20DCCN001";
	getline(cin, a.ten);
	cin >> a.lop;
	cin >> a.ns;
	cin >> a.gpa;
	if (a.ns[2] != '/')
		a.ns = "0" + a.ns;
	if (a.ns[5] != '/')
		a.ns.insert(3, "0");
}

void In(SinhVien a) {
	cout << a.msv << " " << a.ten << " " << a.lop << " " << a.ns << " " << fixed << setprecision(2) << a.gpa << endl;
}
#define a() a;
int main() {
	SinhVien a(); //SinhVien a;
	Nhap(a);
	In(a);
	return 0;
}
