#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#endif

using namespace std;
#include <string>

class Student {
public:
	string name;
	string group;
	float rating;

	Student(string _name, string _group, float _rating) {
		name = _name;
		group = _group;
		rating = _rating;
	}

	string toString() {
		//string w = str(boost::format("%d") % blah);

		string ratingRow = to_string(rating);
		string rating = ratingRow.erase(ratingRow.find_first_of("0"), ratingRow.size() - 1);
		return name + " " + group + " " + rating;
	}
};