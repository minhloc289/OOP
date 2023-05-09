#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;
class SinhVien {
private:
	string msv, ten, lop, ns;
	double gpa;
public:
	SinhVien() {
		msv = ten = lop = ns = "";
		gpa = 0;
	}

	friend ostream& operator << (ostream&, SinhVien);
	friend istream& operator >> (istream&, SinhVien&);
	/*bool operator < (SinhVien another) {
		return this->lop < another.lop;
	}*/
};

ostream& operator << (ostream& out, SinhVien a) {
	out << a.msv << " " << a.ten << " " << a.lop << " " << a.ns << " " << fixed << setprecision(2) << a.gpa << endl;
	return out;
}

istream& operator >> (istream& in, SinhVien& a) {
	a.msv = "B20DCCN001";
	getline(in, a.ten);
	in >> a.lop;
	in >> a.ns;
	in >> a.gpa;
	if (a.ns[2] != '/')
		a.ns = "0" + a.ns;
	if (a.ns[5] != '/')
		a.ns.insert(3, "0");
	return in;
}

#define a() a

int main() {
	SinhVien a();
	cin >> a;
	cout << a;
	return 0;
}
