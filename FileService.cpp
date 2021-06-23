#include "FileService.h"

const int USER_NAME_LENGTH = 16;
const int USER_GROUP_LENGTH = 16;
const int USER_RATING_LENGTH = 16;

const int USER_PROPERTY_COUNT = 3;

string FileService::removeZerosFromEnd(string str) {
    int firstOfZero = str.find_first_of("0");
    int startBarrier = 3;

    if (firstOfZero < startBarrier)
    {
        return str.erase(startBarrier, str.size() - 1);
    }

	return str.erase(str.find_first_of("0"), str.size() - 1);
}

vector<Student> FileService::getStudentsFromFile(
    string file, int lineQuantity, int nameIndex, 
    int groupIndex, int ratingIndex) 
{
    vector<string> fileLines = getFileByLines(file, getLineFeedIndices(file));
    vector<Student> list;

    // map
    vector<int> nameIndexes = 
        mapProperty(fileLines.size(), USER_PROPERTY_COUNT, nameIndex);
    vector<int> groupIndexes =
        mapProperty(fileLines.size(), USER_PROPERTY_COUNT, groupIndex);
    vector<int> ratingIndexes =
        mapProperty(fileLines.size(), USER_PROPERTY_COUNT, ratingIndex);

    // get 
    vector<string> namesSortedByAscending = getPropertiesByMap(fileLines, nameIndexes);
    vector<string> groupsSortedByAscending = getPropertiesByMap(fileLines, groupIndexes);
    vector<string> ratingsSortedByAscending = getPropertiesByMap(fileLines, ratingIndexes);

    int quantityOfObjects = lineQuantity / USER_PROPERTY_COUNT;

    // create objects
    for (int i = 0; i < quantityOfObjects; i++)
    {
        Student stud(
            namesSortedByAscending[i], 
            groupsSortedByAscending[i], 
            stof(ratingsSortedByAscending[i])
        );

        list.push_back(stud);
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

void FileService::saveOutOne(vector<Student> students) {
    string filePath = "out1.txt";
    File file(filePath);

    string lines = "";

    // creating lines
    for (int i = 0; i < students.size(); i++)
    {
        string currentLine = "";

        // work with name
        int quantitySpaces = USER_NAME_LENGTH - students[i].name.length();
        currentLine = students[i].name;
        currentLine += getLineSpaces(quantitySpaces);
        
        // work with group
        quantitySpaces = USER_GROUP_LENGTH - students[i].group.length();
        currentLine += students[i].group;
        currentLine += getLineSpaces(quantitySpaces);
        
        // work with rating
        string currentStudentRating = removeZerosFromEnd(to_string(students[i].rating));
        quantitySpaces = USER_RATING_LENGTH - currentStudentRating.length();
        currentLine += currentStudentRating;
        currentLine += getLineSpaces(quantitySpaces);

        lines += currentLine + "\n";
    }

    file.createText(lines);
}

void FileService::saveOutTwo(vector<Student> students) {
    string filePath = "out2.txt";
    File file(filePath);

    string lines = "";

    string currentLine = "";
    
    // names line
    for (int i = 0; i < students.size(); i++) {
        // work with name
        int quantitySpaces = USER_NAME_LENGTH - students[i].name.length();
        currentLine += students[i].name;
        currentLine += getLineSpaces(quantitySpaces);
    }

    lines += currentLine + "\n";
    currentLine = "";

    // group line
    for (int i = 0; i < students.size(); i++) {
        // work with group
        int quantitySpaces = USER_GROUP_LENGTH - students[i].group.length();
        currentLine += students[i].group;
        currentLine += getLineSpaces(quantitySpaces);
    }

    lines += currentLine + "\n";
    currentLine = "";

    // rating line
    for (int i = 0; i < students.size(); i++) {
        // work with rating
        string currentStudentRating = removeZerosFromEnd(to_string(students[i].rating));
        int quantitySpaces = USER_RATING_LENGTH - currentStudentRating.length();
        currentLine += currentStudentRating;
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