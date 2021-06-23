#pragma once
#ifndef FILE_H
#define FILE_H
#endif
#include <string>
#include <iostream>
#include <fstream>
#include <sys/stat.h>

using namespace std;

class File {
public:
    string path;
    fstream fs;
    int lineCount = -1;

    File(string filePath);

    /// create or override text file
    void createText(string text);

    string readText();

    void appendText(string text, bool onNextLine);

    bool isEmpty();

    bool isExists(string path);
};
