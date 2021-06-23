#include "FileService.h"

const int LAST_NAME_LENGHT = 16;
const int INITIALS_LENGHT = 16;
const int BORN_YEAR_LENGHT = 16;
const int RATE_LENGHT = 16;

const int USER_PROPERTY_COUNT = 4;

string FileService::removeZerosFromEnd(string str, int startBarrier) {
    int firstOfZero = str.find_first_of("0");
    startBarrier = 3;

    if (firstOfZero < startBarrier)
    {
        return str.erase(startBarrier, str.size() - 1);
    }

	return str.erase(str.find_first_of("0"), str.size() - 1);
}

vector<Employee> FileService::getEmployeesFromFile(
    string file, int lineQuantity, int lastNameIndex,
    int initialsIndex, int bornYearIndex, int rateIndex)
{
    vector<string> fileLines = getFileByLines(file, getLineFeedIndices(file));
    vector<Employee> list;

    // map
    vector<int> lastNameIndexes = 
        mapProperty(fileLines.size(), USER_PROPERTY_COUNT, lastNameIndex);
    vector<int> inititalsIndexes =
        mapProperty(fileLines.size(), USER_PROPERTY_COUNT, initialsIndex);
    vector<int> bornYearIndexes =
        mapProperty(fileLines.size(), USER_PROPERTY_COUNT, bornYearIndex);
    vector<int> rateIndexes =
        mapProperty(fileLines.size(), USER_PROPERTY_COUNT, rateIndex);

    // get 
    vector<string> lastNamesSortedByAscending = getPropertiesByMap(fileLines, lastNameIndexes);
    vector<string> initialsSortedByAscending = getPropertiesByMap(fileLines, inititalsIndexes);
    vector<string> bornYearsSortedByAscending = getPropertiesByMap(fileLines, bornYearIndexes);
    vector<string> ratesSortedByAscending = getPropertiesByMap(fileLines, rateIndexes);

    int quantityOfObjects = lineQuantity / USER_PROPERTY_COUNT;

    // create objects
    for (int i = 0; i < quantityOfObjects; i++)
    {
        Employee empl(
            lastNamesSortedByAscending[i],
            initialsSortedByAscending[i],
            stoi(bornYearsSortedByAscending[i]),
            stof(ratesSortedByAscending[i])
        );

        list.push_back(empl);
    }

    return list;
}

vector<string> FileService::getPropertiesByMap(vector<string> source, vector<int> map) 
{
    vector<string> props;
    for (int i = 0; i < source.size(); i++)
    {
        for (int j = 0; j < map.size(); j++)
        {
            if (i == map[j])
            {
                props.push_back(source[i]);
            }
        }
    }

    return props;
}

vector<int> FileService::mapProperty(
    int arraySize, int objectPropertyCount, int indexOfProperty) 
{
    int objectQuantity = arraySize / objectPropertyCount;
    vector<int> indexesOfProperty;

    for (int i = indexOfProperty - 1; i <= arraySize; i += objectPropertyCount)
    {
        indexesOfProperty.push_back(i);
    }

    return indexesOfProperty;
}

void FileService::saveOutOne(vector<Employee> employees) {
    string filePath = "out1.txt";
    File file(filePath);

    string lines = "";

    // creating lines
    for (int i = 0; i < employees.size(); i++)
    {
        string currentLine = "";

        // work with last name
        int quantitySpaces = LAST_NAME_LENGHT - employees[i].lastName.length();
        currentLine = employees[i].lastName;
        currentLine += getLineSpaces(quantitySpaces);
        
        // work with initals
        quantitySpaces = INITIALS_LENGHT - employees[i].initials.length();
        currentLine += employees[i].initials;
        currentLine += getLineSpaces(quantitySpaces);
        
        // work with born year
        string currentEmployeeBornYear = removeZerosFromEnd(to_string(employees[i].bornYear), 6);
        quantitySpaces = BORN_YEAR_LENGHT - currentEmployeeBornYear.length();
        currentLine += currentEmployeeBornYear;
        currentLine += getLineSpaces(quantitySpaces);

        // work with rate
        string currentRate = removeZerosFromEnd(to_string(employees[i].rate), 6);
        quantitySpaces = RATE_LENGHT - currentRate.length();
        currentLine += currentRate;
        currentLine += getLineSpaces(quantitySpaces);

        lines += currentLine + "\n";
    }

    file.createText(lines);
}

void FileService::saveOutTwo(vector<Employee> employees) {
    string filePath = "out2.txt";
    File file(filePath);

    string lines = "";

    string currentLine = "";
    
    // last name line
    for (int i = 0; i < employees.size(); i++) {
        int quantitySpaces = LAST_NAME_LENGHT - employees[i].lastName.length();
        currentLine += employees[i].lastName;
        currentLine += getLineSpaces(quantitySpaces);
    }

    lines += currentLine + "\n";
    currentLine = "";

    // initials line
    for (int i = 0; i < employees.size(); i++) {
        int quantitySpaces = INITIALS_LENGHT - employees[i].initials.length();
        currentLine += employees[i].initials;
        currentLine += getLineSpaces(quantitySpaces);
    }

    lines += currentLine + "\n";
    currentLine = "";

    // born year line
    for (int i = 0; i < employees.size(); i++) {
        string currentBornYear = removeZerosFromEnd(to_string(employees[i].bornYear), 6);
        int quantitySpaces = BORN_YEAR_LENGHT - currentBornYear.length();
        currentLine += currentBornYear;
        currentLine += getLineSpaces(quantitySpaces);
    }

    lines += currentLine + "\n";
    currentLine = "";

    // rate line
    for (int i = 0; i < employees.size(); i++) {
        string currentRate = removeZerosFromEnd(to_string(employees[i].rate), 6);
        int quantitySpaces = RATE_LENGHT - currentRate.length();
        currentLine += currentRate;
        currentLine += getLineSpaces(quantitySpaces);
    }

    lines += currentLine + "\n";
    currentLine = "";

    file.createText(lines);
}

string FileService::getLineSpaces(int quantity) {
    string outLine = "";
    for (int i = quantity; i > 0; i--)
    {
        outLine += " ";
    }

    return outLine;
}

vector<string> FileService::getFileByLines(string fileText, vector<int> lineFeedIndices) {
    vector<string> fileLines;

    // get lines
    for (int i = 0; i < lineFeedIndices.size(); i++)
    {
        string line = fileText;

        // cut only after
        if (i == 0)
        {
            line.erase(lineFeedIndices[i], fileText.size() - 1);
            fileLines.push_back(line);
        }
        else {
            // cut after
            line.erase(lineFeedIndices[i], fileText.size() - 1);

            // cut before 
            line.erase(0, lineFeedIndices[i - 1] + 1);

            // add index to array
            fileLines.push_back(line);
        }
    }

    return fileLines;
}

vector<int> FileService::getLineFeedIndices(string fileText) {
    vector<int> lineFeedIndices;

    // get line indexes array
    for (int i = 0; i < fileText.size(); i++)
    {
        if (fileText[i] == '\n')
        {
            lineFeedIndices.push_back(i);
        }
    }

    // if there is no '\n' sign at the end of the file,
    // add the end-of-file index as if it were there.
    if (lineFeedIndices[lineFeedIndices.size() - 1] < fileText.size())
    {
        lineFeedIndices.push_back(fileText.size());
    }

    return lineFeedIndices;
}