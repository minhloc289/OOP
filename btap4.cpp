#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;
class SinhVien {
private:
	string msv, ten, lop, email;
public:
	SinhVien() {
		msv = ten = lop = email = "";
	}
	friend ostream& operator <<  (ostream&, SinhVien);
	friend istream& operator >> (istream&, SinhVien&);
	bool operator < (SinhVien another) {
		return this->lop < another.lop;
	}
};

istream& operator >> (istream& in, SinhVien& a) {
	in >> a.msv;
	in.ignore();
	getline(in, a.ten);
	in >> a.lop >> a.email;
	return in;
}

ostream& operator << (ostream& out, SinhVien a) {
	out << a.msv << " " << a.ten << " " << a.lop << " " << a.email << endl;
	return out;
}

int main() {
	vector<SinhVien> v;
	SinhVien tmp;
	while (cin >> tmp) {
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (SinhVien x : v) {
		cout << x;
	}
}