#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>

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
	
	string getLop() {
		return this->lop;
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
	int n; cin >> n;
	/*SinhVien* a = new SinhVien[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		cout << "DANH SACH SINH VIEN LOP " << s << endl;
		for (int i = 0; i < n; i++) {
			if (a[i].getLop() == s) {
				cout << a[i];
			}
		}
	}*/
	map<string, vector<SinhVien>> mp;
	for (int i = 0; i < n; i++) {
		SinhVien tmp;
		cin >> tmp;
		mp[tmp.getLop()].push_back(tmp);
	}
	int q; cin >> q;
	while (q--) {
		string s; cin >> s;
		cout << "DANH SACH SINH VIEN LOP " << s << endl;
		for (SinhVien x : mp[s]) {
			cout << x;
		}
	}
}