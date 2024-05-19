
#include <iostream>
#include<fstream>
#include<string>
#define MAX 100
using namespace std;
void ghiFile(string a[], int n) {
	fstream demDong;
	demDong.open("data.txt", ios_base::out);
	cin.ignore(1);
	for (int i = 0; i < n; i++) {
		cout << "Chuoi thu " << i + 1 << " : ";
		getline(cin, a[i]);
		demDong << a[i] << endl;

	}
	demDong.close();
}
void docFile() {
	ifstream infile("data.txt");
	string str;
	int count = 0;
	int countDash = 0;
	cout << "Dong bat dau bang dau '-': " << endl;
	while (getline(infile, str)) {
		count++;
		if (str.compare(0, 1, "-") == 0) {
			countDash++;
			cout << str << endl;
		}
	}
	infile.close();
	cout << "So dong bat dau bang '-': " << countDash << endl;
	cout << "So dong trong file: " << count << endl;


}
void menu()
{
	cout << "052305005348- Huynh Ngo Yen Di" << endl;
	cout << endl;
	cout << "===========* MENU *===============" << endl;
	cout << "1. Them dong" << endl;
	cout << "2. Kiem tra so dong" << endl;
	cout << "Nhap so bat ki de thoat!!" << endl;
	cout << "==================================" << endl;
	cout << "Chon: ";
}
int main()
{
	int luaChon, a;
	string n[MAX];
	string dong;
	int nhap;
	do {
		menu();
		cin >> luaChon;
		switch (luaChon) {

		case 1:
		{
			cout << "Nhap so dong ban muon them: ";
			cin >> a;
			ghiFile(n, a);
			break;
		}

		case 2:
		{
			docFile();
			break;
		}
		default:
		{
			nhap = 0;
		}

		}
		if (luaChon == 1 || luaChon == 2)
		{
			cout << "-------------------------" << endl;
			cout << "1. tiep tuc ---  0. thoat" << endl;
			cout << "Chon: ";
			cin >> nhap;
		}
	} while (nhap != 0);
	return 0;
}
