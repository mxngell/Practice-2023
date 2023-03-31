#include <iostream>
#include <string>
#include <locale>
#include <regex>

using namespace std;

#define DEBUGGING


class Student {
private:
	string Name;
	string Surname;
	int Age;
public:
	int setName(string curName) {
		int errorCode{ 0 };
		smatch n;
		if (regex_search(curName, n, regex("^[А-Я]{1}[а-я]{1,40}$"))) {
			Name = curName;
			errorCode = 0;
		}
		else {
			errorCode = -1;
		}
		return errorCode;
	}
	string getName() {
		return Name;
	}

	int setSurname(string curSurname) {
		int errorCode{ 0 };
		if (curSurname != "" && curSurname != " ") {
			smatch n;
			if (regex_search(curSurname, n, regex("^[А-Я]{1}[а-я]{1,40}$"))) {
				Surname = curSurname;
				errorCode = 0;
			}
			else {
				errorCode = -1;
			}
		}
		else {
			errorCode = -1;
		}

		return errorCode;
	}
	string getSurname() {
		return Surname;
	}

	int setAge(int curAge) {
		int errorCode{ 0 };
		if (isdigit(curAge)) {
			if (!(curAge < 16 || curAge > 35)) {
				Age = curAge;
				errorCode = 0;
			}
			else {
				errorCode = -1;
			}
		}

		return errorCode;
	}
	int getAge() {
		return Age;
	}
};


class Group {
private:
	int Number;
	int StartYear;
	string Duration; // МЕСЯЦЕВ:ЛЕТ
public:
	int setNumber(int curNumber) {
		int errorCode{ 0 };
		if (isdigit(curNumber)) {
			if (!(curNumber < 111 || curNumber > 431)) {
				Number = curNumber;
				errorCode = 0;
			}
			else {
				errorCode = -1;
			}
		}

		return errorCode;
	}
	int getNumber() {
		return Number;
	}

	int setStartYear(int curStartYear) {
		int errorCode{ 0 };
		if (isdigit(curStartYear)) {
			if (!(curStartYear < 2020 || curStartYear > 2023)) {
				StartYear = curStartYear;
				errorCode = 0;
			}
			else {
				errorCode = -1;
			}
		}

		return errorCode;
	}
	int getStartYear() {
		return StartYear;
	}

	int setDuration(string curDuration) {
		int errorCode{ 0 };
		smatch n;
		if (curDuration != "" && curDuration != " ") {
			if (regex_search(curDuration, n, regex("^[0-9]{2}:[0]{1}[0-5]{1}$"))) {
				// МЕСЯЦЕВ:ЛЕТ
				// MM:YY
				Duration = curDuration;
				errorCode = 0;
			}
			else {
				errorCode = -1;
			}
		}
		else {
			errorCode = -1;
		}

		return errorCode;
	}
	string getDuration() {
		return Duration;
	}
};

void testingSetSurnameMethod(Student object) {

	string curSurname = "Никаев";
	if (object.setName(curSurname) == 0) {
		cerr << "Test " << curSurname << " success!" << endl;
	}
	else {
		cerr << "Test " << curSurname << " failed!" << endl;
	}

	curSurname = "Малышенко";
	if (object.setName(curSurname) == 0) {
		cerr << "Test " << curSurname << " success!" << endl;
	}
	else {
		cerr << "Test " << curSurname << " failed!" << endl;
	}

	curSurname = "";
	if (object.setName(curSurname) != 0) {
		cerr << "Test " << curSurname << " success!" << endl;
	}
	else {
		cerr << "Test " << curSurname << " failed!" << endl;
	}

	curSurname = " ";
	if (object.setName(curSurname) != 0) {
		cerr << "Test " << curSurname << " success!" << endl;
	}
	else {
		cerr << "Test " << curSurname << " failed!" << endl;
	}

	curSurname = "НИКАЕВ";
	if (object.setName(curSurname) != 0) {
		cerr << "Test " << curSurname << " success!" << endl;
	}
	else {
		cerr << "Test " << curSurname << " failed!" << endl;
	}

	curSurname = "никаев";
	if (object.setName(curSurname) != 0) {
		cerr << "Test " << curSurname << " success!" << endl;
	}
	else {
		cerr << "Test " << curSurname << " failed!" << endl;
	}


	curSurname = "НИкаев";
	if (object.setName(curSurname) != 0) {
		cerr << "Test " << curSurname << " success!" << endl;
	}
	else {
		cerr << "Test " << curSurname << " failed!" << endl;
	}

	curSurname = "NIKAEV";
	if (object.setName(curSurname) != 0) {
		cerr << "Test " << curSurname << " success!" << endl;
	}
	else {
		cerr << "Test " << curSurname << " failed!" << endl;
	}

	curSurname = "nikaev";
	if (object.setName(curSurname) != 0) {
		cerr << "Test " << curSurname << " success!" << endl;
	}
	else {
		cerr << "Test " << curSurname << " failed!" << endl;
	}

	curSurname = "Nikaev";
	if (object.setName(curSurname) != 0) {
		cerr << "Test " << curSurname << " success!" << endl;
	}
	else {
		cerr << "Test " << curSurname << " failed!" << endl;
	}

	curSurname = "331";
	if (object.setName(curSurname) != 0) {
		cerr << "Test " << curSurname << " success!" << endl;
	}
	else {
		cerr << "Test " << curSurname << " failed!" << endl;
	}


	curSurname = "3.3";
	if (object.setName(curSurname) != 0) {
		cerr << "Test " << curSurname << " success!" << endl;
	}
	else {
		cerr << "Test " << curSurname << " failed!" << endl;
	}

	curSurname = "-2";
	if (object.setName(curSurname) != 0) {
		cerr << "Test " << curSurname << " success!" << endl;
	}
	else {
		cerr << "Test " << curSurname << " failed!" << endl;
	}

	curSurname = ".";
	if (object.setName(curSurname) != 0) {
		cerr << "Test " << curSurname << " success!" << endl;
	}
	else {
		cerr << "Test " << curSurname << " failed!" << endl;
	}
}

void testingSetDurationMethod(Group object) {

	string curDuration = "12:04";
	if (object.setDuration(curDuration) == 0) {
		cerr << "Test " << curDuration << " success!" << endl;
	}
	else {
		cerr << "Test " << curDuration << " failed!" << endl;
	}

	curDuration = "03:03";
	if (object.setDuration(curDuration) == 0) {
		cerr << "Test " << curDuration << " success!" << endl;
	}
	else {
		cerr << "Test " << curDuration << " failed!" << endl;
	}


	curDuration = "00:01";
	if (object.setDuration(curDuration) == 0) {
		cerr << "Test " << curDuration << " success!" << endl;
	}
	else {
		cerr << "Test " << curDuration << " failed!" << endl;
	}

	curDuration = "";
	if (object.setDuration(curDuration) != 0) {
		cerr << "Test " << curDuration << " success!" << endl;
	}
	else {
		cerr << "Test " << curDuration << " failed!" << endl;
	}

	curDuration = " ";
	if (object.setDuration(curDuration) != 0) {
		cerr << "Test " << curDuration << " success!" << endl;
	}
	else {
		cerr << "Test " << curDuration << " failed!" << endl;
	}

	curDuration = "99:99";
	if (object.setDuration(curDuration) != 0) {
		cerr << "Test " << curDuration << " success!" << endl;
	}
	else {
		cerr << "Test " << curDuration << " failed!" << endl;
	}

	curDuration = "12:12";
	if (object.setDuration(curDuration) != 0) {
		cerr << "Test " << curDuration << " success!" << endl;
	}
	else {
		cerr << "Test " << curDuration << " failed!" << endl;
	}

	curDuration = "-1:4";
	if (object.setDuration(curDuration) != 0) {
		cerr << "Test " << curDuration << " success!" << endl;
	}
	else {
		cerr << "Test " << curDuration << " failed!" << endl;
	}

	curDuration = "12:-4";
	if (object.setDuration(curDuration) != 0) {
		cerr << "Test " << curDuration << " success!" << endl;
	}
	else {
		cerr << "Test " << curDuration << " failed!" << endl;
	}

	curDuration = "1.2:4";
	if (object.setDuration(curDuration) != 0) {
		cerr << "Test " << curDuration << " success!" << endl;
	}
	else {
		cerr << "Test " << curDuration << " failed!" << endl;
	}

	curDuration = "22.3";
	if (object.setDuration(curDuration) != 0) {
		cerr << "Test " << curDuration << " success!" << endl;
	}
	else {
		cerr << "Test " << curDuration << " failed!" << endl;
	}

	curDuration = "02:3";
	if (object.setDuration(curDuration) != 0) {
		cerr << "Test " << curDuration << " success!" << endl;
	}
	else {
		cerr << "Test " << curDuration << " failed!" << endl;
	}

	curDuration = "2/2:3";
	if (object.setDuration(curDuration) != 0) {
		cerr << "Test " << curDuration << " success!" << endl;
	}
	else {
		cerr << "Test " << curDuration << " failed!" << endl;
	}

	curDuration = "2/3";
	if (object.setDuration(curDuration) != 0) {
		cerr << "Test " << curDuration << " success!" << endl;
	}
	else {
		cerr << "Test " << curDuration << " failed!" << endl;
	}

}
int main() {
	setlocale(LC_ALL, "Russian");

	Group testGroup;
	Student testStudent;

#ifdef DEBUGGING
	testingSetDurationMethod(testGroup);
	cerr << "\n";
	testingSetSurnameMethod(testStudent);
#endif

	return 0;
}
