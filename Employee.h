#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#endif

using namespace std;
#include <string>

class Employee {
public:
	string lastName;
	string initials;
	int bornYear;
	float rate;

	Employee(string _lastName, string _initials, int _bornYear, float _rate) {
		lastName = _lastName;
		initials = _initials;
		bornYear = _bornYear;
		rate = _rate;
	}

	string toString() {
		// born
		string bornStr = to_string(bornYear);

		// rate
		string rateRow = to_string(rate);
		string rateStr = rateRow.erase(rateRow.find_first_of("0"), rateRow.size() - 1);

		return lastName + " " + initials + " " + bornStr + " " + rateStr;
	}
};
