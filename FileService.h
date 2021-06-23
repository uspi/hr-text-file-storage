#pragma once
#ifndef FILESERVICE_H
#define FILESERVICE_H
#endif
using namespace std;

#include <string>
#include <vector>

#include "File.h"
#include "Student.h"
#include <Employee.h>

class FileService {
public:
	static string removeZerosFromEnd(string str, int startBarrier);

	static void saveOutOne(vector<Employee> students);
	static void saveOutTwo(vector<Employee> students);

	/// <summary>
	/// Creates students from a text file in which their properties 
	/// are written line by line. They are supposed to have three 
	/// properties: name, group, rating.
	/// </summary>
	/// <param name="file">File text representation</param>
	/// <param name="lineQuantity">Number of lines in text</param>
	/// <param name="nameIndex">The order of the property in the text file (Number from 0 to 2)</param>
	/// <param name="groupIndex">The order of the property in the text file (Number from 0 to 2)</param>
	/// <param name="ratingIndex">The order of the property in the text file (Number from 0 to 2)</param>
	/// <returns></returns>
	static vector<Employee> getEmployeesFromFile(
		string file, int lineQuantity, int lastNameIndex,
		int initialsIndex, int bornYearIndex, int rateIndex);

	static string getLineSpaces(int quantity);

	static vector<string> getFileByLines(
		string fileText, vector<int> lineFeedIndices);

	static vector<int> getLineFeedIndices(string fileText);

	/// <summary>
	/// It is assumed that there is a set of objects written in a row into an array, 
	/// the properties of which are ordered relative to each other. In this case, 
	/// the method allows you to specify all indices of the desired property 
	/// in all objects of the selection.
	/// </summary>
	/// <param name="arraySize"></param>
	/// <param name="objectPropertyCount"></param>
	/// <param name="indexOfProperty"></param>
	/// <returns></returns>
	static vector<int> mapProperty(int arraySize, int objectPropertyCount, int indexOfProperty);

	static vector<string> getPropertiesByMap(vector<string> source, vector<int> map);
};