#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//     
#include <Windows.h>


using namespace std;

struct Data {
	bool isEmpty = true;
	string name="", dateOfBirth="", address="";

	string getField(int index) {
		if (index == 1) return name;
		else if (index == 2) return dateOfBirth;
		else if (index == 3) return address;
		else return "";
	}
};

class Database {
private:
	Data* dataArr;
	int dbsize;
	char* dbname;

public:
	Database(int size, string name) {
		dbsize = size;
		dataArr = new Data[dbsize];
		dbname = new char[name.length()+1];
		strcpy(dbname, name.c_str());

		for (int i = 0; i < dbsize; i++) {
			dataArr[i].isEmpty = true;
		}
	}

	void del(int i) { // 1 - 
		dataArr[i].isEmpty = true;
		dataArr[i].name = "";
		dataArr[i].dateOfBirth = "";
		dataArr[i].address = "";
	}

	int findEmpty() { // 2 -    
		for (int i = 0; i < dbsize; i++) {
			if (dataArr[i].isEmpty) return i;
		}
		return -1;
	}

	int add(int i, string name, string dateOfBirth, string address) { // 3 -   
		if (dataArr[i].isEmpty) {
			dataArr[i].isEmpty = false;
			dataArr[i].name = name;
			dataArr[i].dateOfBirth = dateOfBirth;
			dataArr[i].address = address;

			return 1;
		}
		return 0;
	}

	Data print(int i) { // 4 -    
		return dataArr[i];
	}

	Data* printAll() { // 5 -    
		Data* arrAll;
		int counter = 0;

		for (int i = 0; i < dbsize; i++) {
			if (!dataArr[i].isEmpty) counter++;
		}

		arrAll = new Data[counter];
		counter = 0;

		for (int i = 0; i < dbsize; i++) {
			if (!dataArr[i].isEmpty) {
				arrAll[counter] = dataArr[i]; //        (  ,   ),  
				counter++;
			}
		}
		return arrAll;
	}

	Data findElement(int intel = -1, string strel = "") { // 6 -     
		for (size_t i = 0; i < dbsize; i++)
			if (!dataArr[i].isEmpty && (dataArr[i].name.find(strel) != string::npos || dataArr[i].dateOfBirth == to_string(intel) || dataArr[i].dateOfBirth == to_string(intel + 1) || dataArr[i].dateOfBirth == to_string(intel - 1) || dataArr[i].address.find(strel) != string::npos)) return dataArr[i];
		return Data{};
	}

	Data findMin(int field) { // 7 -     
		int minIndex = 0;
		for (int i = 0; i < dbsize; i++) {
			if (!dataArr[i].isEmpty && dataArr[i].getField(field) < dataArr[minIndex].getField(field)) {
				minIndex = i;
			}
		}
		return dataArr[minIndex];
	}

	void sort(int type, int field) { // 8, 9 -       
		if (type == 1) { //  
			for (int i = 0; i < dbsize; i++) {
				for (int j = 0; j < dbsize-1; j++) {
					if (dataArr[j].getField(field) > dataArr[j + 1].getField(field)) {
						Data temp = dataArr[j];
						dataArr[j] = dataArr[j + 1];
						dataArr[j + 1] = temp;
					}
				}
			}
		}

		else { //  
			for (int i = 0; i < dbsize; i++) {
				for (int j = 0; j < dbsize - 1; j++) {
					if (dataArr[j].getField(field) < dataArr[j + 1].getField(field)) {
						Data temp = dataArr[j];
						dataArr[j] = dataArr[j + 1];
						dataArr[j + 1] = temp;
					}
				}
			}
		}
	}

	//    (  ,    ,        ... ,    Debug)
	// 10.        (  ).
	void Restore() {
		FILE* file = fopen(dbname, "rb");

		for (size_t i = 0; i < dbsize; i++)
			fread(&dataArr[i], sizeof(Data), 1, file);

		fclose(file);
	}

	// 11.        (  ).
	void Save() {
		FILE* file = fopen(dbname, "wb");

		for (size_t i = 0; i < dbsize; i++)
			fwrite(&dataArr[i], sizeof(Data), 1, file);

		fclose(file);
	}
};


/*
                  (  ) .
      ,         .            (.. "").

         :
  1.    (     ).        .
  2.    .          .
  3.   ()   .          .
  4.   ()   .       .
  5.        .
  6.                 .         .
  7.         .      ,     .
  8.         (     ,   ++    );
  9.         (     ,   ++    );
  10.        (  ).
  11.        (  ).
*/

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size, ans=-1, index=0, field=0;
	string name, dateOfBirth, address;

	cout << "   : ";
	getline(cin, name);
	cout << "   : ";
	cin >> size;

	Database db(size, name);

	do {
		while (ans < 0 || ans > 10) {
			cout << "\n       ?"
				<< "\n1.  "
				<< "\n2.  "
				<< "\n3.     "
				<< "\n4.    "
				<< "\n5.   "
				<< "\n6.         "
				<< "\n7.     "
				<< "\n8.  "
				<< "\n9.    "
				<< "\n10.    "
				<< endl;
			cin >> ans;
			cin.ignore();
		}

		if (ans == 1) {
			cout << "\n   :";
			cin >> index;
			db.del(index);
			cout << "   " << index << " ." << endl;
		}

		else if (ans == 2) {
			cout << "\n   : ";
			cin >> index;
			cin.ignore();
			cout << " : ";
			getline(cin, name);
			cout << "  : ";
			getline(cin, dateOfBirth);
			cout << " : ";
			getline(cin, address);

			if (db.add(index, name, dateOfBirth, address) != 0) cout << "  "<<endl;
			else cout << "  "<<endl;
		}

		else if (ans == 3) {
			int i = db.findEmpty();
			if (i != -1) cout << "\n     " << i << endl;
			else cout << "\n  " << endl;
		}

		else if (ans == 4) {
			cout << "\n   : ";
			cin >> index;
			Data onestring = db.print(index);
			cout << "\n ..: " << onestring.name
				<< "\n : " << onestring.dateOfBirth
				<< "\n: " << onestring.address << endl;
		}

		else if (ans == 5) {
			Data* alldata = db.printAll();
			int i = 0;
			do {
				cout << "\n  " << i << ":"
					<< "\n ..: " << alldata[i].name
					<< "\n : " << alldata[i].dateOfBirth
					<< "\n: " << alldata[i].address << endl;
				i++;
			} while (!alldata[i].isEmpty);
		}

		else if (ans == 6) {
			cout << "\n 1      2    : ";
			cin >> index;
			string findstring="";
			int findint=-1;

			if (index == 1) {
				cout << "  : ";
				cin >> findstring;
			}

			else if (index == 2) {
				cout << "  : ";
				cin >> findint;
			}

			Data onestring = db.findElement(findint, findstring);
			if (!onestring.isEmpty) {
				cout << "\n ..: " << onestring.name
					<< "\n : " << onestring.dateOfBirth
					<< "\n: " << onestring.address << endl;
			}

			else cout << "\n   " << endl;
		}

		else if (ans == 7) {
			cout << "   (1 - name, 2 - dateOfBirth, 3 - address): ";
			cin >> field;
			Data minField = db.findMin(field);
			if (!minField.isEmpty) {
				cout << "\n ..: " << minField.name
					<< "\n : " << minField.dateOfBirth
					<< "\n: " << minField.address << endl;
			}
			else cout << "   :   " << endl;
		}

		else if (ans == 8) {
			do {
				cout << " 1      2    : ";
				cin >> index;
			} while (index < 1 || index > 2);

			cout << "   (1 - name, 2 - dateOfBirth, 3 - address),     : ";
			cin >> field;

			db.sort(index, field);

			cout << " " << endl;
		}

		else if (ans == 9) {
			db.Restore();
			cout << "   " << endl;
		}

		else if (ans == 10) {
			db.Save();
			cout << "   " << endl;
		}
		
		cout << " 99,  ,  ,      ,  0,   : ";
		cin >> ans;
	}

	while (ans != 0);

	return 0;
}