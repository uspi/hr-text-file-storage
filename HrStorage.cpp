#include <vector>

#include "File.h"
#include "Input.h"
#include "Window.h"
#include "Student.h"
#include "FileService.h"


int main()
{
    FileService flservice;
    setlocale(LC_ALL, "Russian");

    string filePath = "in.txt";

    File file(filePath);
    Window window;
    Input inp;

    window.print("Проверка существания файла ", false, CPs::ru);
    window.print(filePath, false, CPs::ru);

    bool fileExist = file.isExists(filePath);

    vector<Student> students;

    // exists
    if (fileExist)
    {
        string fileBody = file.readText();

        window.print("Файл существует, содержание:", true, CPs::ru);
        window.print(fileBody, true, CPs::ru);

        students = FileService::getStudentsFromFile(fileBody, file.lineCount, 1, 2, 3);

        // if no exists
    }
    else {
        window.print("Файл не существует", true, CPs::ru);
        window.print("Начало создания файла, сколько студентов вы хотите создать?", true, CPs::ru);
        window.print("Введите количество(до 9): ", true, CPs::ru);

        int quantityOfSutdents = stoi(inp.getInputText(1, CPs::def));

        string name;
        string group;
        float rating;

        // creating students and writitng in file
        for (int i = 1; i <= quantityOfSutdents; i++)
        {
            // name
            window.print("Введите имя студента номер ", true, CPs::ru);
            window.print(to_string(i) + ": ", false, CPs::ru);
            name = inp.getInputText(30, CPs::ru);

            // group
            window.print("Введите группу студента номер ", false, CPs::ru);
            window.print(to_string(i) + ": ", false, CPs::ru);
            group = inp.getInputText(10, CPs::ru);

            // rating
            window.print("Введите рейтинг студента номер ", false, CPs::ru);
            window.print(to_string(i) + ": ", false, CPs::ru);
            rating = stof(inp.getInputText(3, CPs::ru));

            // create student add to array
            Student stud(name, group, rating);
            students.push_back(stud);

            window.print("Созданние студентов окончено", true, CPs::ru);
        }
    }

    FileService::saveOutOne(students);
    FileService::saveOutTwo(students);

    window.print("Сохранение в двух представлениях окончено", true, CPs::ru);
}