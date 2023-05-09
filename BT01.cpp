#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class SinhVienCaoDang {
private:
	string msv, name, address, tenluanvan;
	int tinchi;
	float dtb, dtn, dlv;
public:
	SinhVienCaoDang() {
		msv = name = address = tenluanvan = "";
		tinchi = dtb = dlv = 0;
	}
	SinhVienCaoDang(string msv, string name, string address, string tenluanvan, int tc, float dtb, float dtn, float dlv) {
		this->msv = msv;
		this->name = name;
		this->address = address;
		this->tenluanvan = tenluanvan;
		this->tinchi = tc;
		this->dtb = dtb;
		this->dlv = dlv;
	}

	void Xuat() {
		cout << msv << "\t" << name << "\t" << address << "\t" << tinchi << "\t" << dtb << "\t" << tenluanvan << "\t" << dlv << endl;
	}

	int getTinChiCaoDang() {
		return tinchi;
	}

	float getDtbCaoDang() {
		return dtb;
	}

	float getDtnCaoDang() {
		return dtn;
	}
};

class SinhVienDaiHoc {
private:
	string msv, name, address, tenluanvan;
	int tinchi;
	float dtb, dtn, dlv = 0;
public:
	SinhVienDaiHoc() {
		msv = name = address = tenluanvan = "";
		tinchi = dtb = dtn = dlv;
	}
	SinhVienDaiHoc(string msv, string name, string address, string tenluanvan, int tc, float dtb, float dtn, float dlv) {
		this->msv = msv;
		this->name = name;
		this->address = address;
		this->tenluanvan = tenluanvan;
		this->tinchi = tc;
		this->dtb = dtb;
		this->dlv = dlv;
	}

	void Xuat() {
		cout << msv << "\t" << name << "\t" << address << "\t" << tinchi << "\t" << dtb << "\t" << tenluanvan << "\t" << dlv << endl;
	}

	int getTinChiDaiHoc() {
		return tinchi;
	}

	float getDtbDaiHoc() {
		return dtb;
	}

	float getDlvDaiHoc() {
		return dlv;
	}
};

class QuanLiSinhVien {
private:
	SinhVienCaoDang* danhsachCaoDang;
	SinhVienDaiHoc* danhsachDaiHoc;
	int n;
	int m;
public:
	QuanLiSinhVien() {
		danhsachCaoDang = NULL;
		danhsachDaiHoc = NULL;
		n = 0;
		m = 0;
	}

	~QuanLiSinhVien() {
		delete []danhsachCaoDang;
		delete []danhsachDaiHoc;
	}

	void NhapSVCaoDang() {
		cout << "Nhap so luong Sinh Vien Cao Dang: ";
		cin >> n;
		danhsachCaoDang = new SinhVienCaoDang[n];
		for (int i = 0; i < n; i++) {
			string msv, name, address, tenluanvan;
			int tinchi;
			float dtb, dtn, dlv;
			
			cout << "Nhap msv: ";
			cin >> msv;

			cout << "Nhap ho ten: ";
			cin.ignore();
			getline(cin, name);

			cout << "Nhap dia chi: ";
			getline(cin, address);

			cout << "So tin chi: ";
			cin >> tinchi;

			cout << "Diem trung binh: ";
			cin >> dtb;

			cout << "Diem tot nghiep: ";
			cin >> dtn;

			cout << "Ten luan van: ";
			cin.ignore();
			getline(cin, tenluanvan);

			cout << "Diem luan van: ";
			cin >> dlv;

			danhsachCaoDang[i] = SinhVienCaoDang(msv, name, address, tenluanvan, tinchi, dtb, dtn, dlv);
		}
	}

	void NhapSVDaiHoc() {
		cout << "Nhap so luong sinh vien Dai Hoc: ";
		cin >> m;
		danhsachDaiHoc = new SinhVienDaiHoc[m];
		for (int i = 0; i < m; i++) {
			string msv, name, address, tenluanvan;
			int tinchi;
			float dtb, dtn, dlv;

			cout << "Nhap msv: ";
			cin >> msv;

			cout << "Nhap ho ten: ";
			cin.ignore();
			getline(cin, name);

			cout << "Nhap dia chi: ";
			getline(cin, address);

			cout << "So tin chi: ";
			cin >> tinchi;

			cout << "Diem trung binh: ";
			cin >> dtb;

			cout << "Diem tot nghiep: ";
			cin >> dtn;

			cout << "Ten luan van: ";
			cin.ignore();
			getline(cin, tenluanvan);

			cout << "Diem luan van: ";
			cin >> dlv;

			danhsachDaiHoc[i] = SinhVienDaiHoc(msv, name, address, tenluanvan, tinchi, dtb, dtn, dlv);
		}
	}

	void XuatDanhSachCaoDang() {
		for (int i = 0; i < n; i++) {
			danhsachCaoDang[i].Xuat();
			cout << endl;
		}
	}

	void XuatDanhSachDaiHoc() {
		for (int i = 0; i < m; i++) {
			danhsachDaiHoc[i].Xuat();
			cout << endl;
		}
	}

	int TotNghiepCaoDang() {
		int dem = 0;
		for (int i = 0; i < n; i++) {
			if (danhsachCaoDang[i].getTinChiCaoDang() >= 120 && danhsachCaoDang[i].getDtbCaoDang() >= 5 && danhsachCaoDang[i].getDtnCaoDang() >= 5) {
				dem++;
			}
		}
		return dem;
	}

	int TotNghiepDaiHoc() {
		int dem = 0;
		for (int i = 0; i < m; i++) {
			if (danhsachDaiHoc[i].getTinChiDaiHoc() >= 150 && danhsachDaiHoc[i].getDtbDaiHoc() >= 5 && danhsachDaiHoc[i].getDlvDaiHoc() >= 5) {
				dem++;
			}
		}
		return dem;
	}

	void BestOfDaiHoc() {
		SinhVienDaiHoc sv = danhsachDaiHoc[0];
		for (int i = 1; i < n; i++) {
			if (danhsachDaiHoc[i].getDtbDaiHoc() > sv.getDtbDaiHoc()) {
				sv = danhsachDaiHoc[i];
			}
		}
		cout << "Sinh vien Dai Hoc co diem cao nhat: ";
		sv.Xuat();
		cout << endl;
	}
};

int main() {
	QuanLiSinhVien qlsv;
	qlsv.NhapSVCaoDang();
	qlsv.NhapSVDaiHoc();

	cout << "Danh sach Sinh vien Cao Dang: " << endl;
	qlsv.XuatDanhSachCaoDang();
	cout << endl;

	
	cout << "Danh sach Sinh vien Dai Hoc: " << endl;
	qlsv.XuatDanhSachDaiHoc();
	cout << endl;

	cout << "So Sinh vien Cao Dang tot nghiep: " << endl;
	cout << qlsv.TotNghiepCaoDang();
	cout << endl;

	cout << "So Sinh vien Dai Hoc tot nghiep: " << endl;
	cout << qlsv.TotNghiepDaiHoc();
	cout << endl;

	qlsv.BestOfDaiHoc();
	cout << endl;

	return 0;
}