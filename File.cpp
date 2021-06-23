#include "File.h"
#include <Ñonsole.h>

using namespace std;

File::File(string filePath) {
    path = filePath;
}

/// create or override text file
void File::createText(string text) {
    fs.open(path, fstream::out);
    if (!fs.is_open())
    {
        return;
    }

    fs.clear();
    fs << text;

    fs.close();
}

string File::readText() {
    string text;

    fs.open(path, fstream::in);
    if (!fs.is_open())
    {
        return "file stream are not opened";
    }

    string line;
    int lineCounter = 0;

    while (getline(fs, line))
    {
        lineCounter > 0 ?
            text += "\n" + line :
            text += line;

        lineCounter++;
    }

    lineCount = lineCounter;
    fs.close();
    
    return text;
}

void File::appendText(string text, bool onNextLine = true) {
    fs.open(path, fstream::app);
    if (!fs.is_open())
    {
        return;
    }

    if (onNextLine)
    {
        fs << "\n" << text;
    }
    else {
        fs << text;
    }

    fs.close();
}

bool File::isEmpty() {
    fs.open(path, fstream::in);

    return true;
}

/// WARN: does not guarantee the existence
bool File::isExists(string path) {
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0);
}