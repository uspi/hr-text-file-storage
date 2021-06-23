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

    vector<Employee> employees;
    Employee oldest("", "", 3000, 0);

    // exists
    if (fileExist)
    {
        string fileBody = file.readText();

        window.print("Файл существует, содержание:", true, CPs::ru);
        window.print(fileBody, true, CPs::ru);

        employees = FileService::getEmployeesFromFile(fileBody, file.lineCount, 1, 2, 3, 4);

        // if no exists
    }
    else {
        window.print("Файл не существует", true, CPs::ru);
        window.print("Начало создания файла, сколько работников вы хотите создать?", true, CPs::ru);
        window.print("Введите количество(до 9): ", true, CPs::ru);

        int quantityOfEmployees = stoi(inp.getInputText(1, CPs::def));

        string lastName;
        string initials;
        int bornYear;
        float rate;

        // creating students and writitng in file
        for (int i = 1; i <= quantityOfEmployees; i++)
        {
            // last name
            window.print("Введите фамилию сотрудника номер ", true, CPs::ru);
            window.print(to_string(i) + ": ", false, CPs::ru);
            lastName = inp.getInputText(30, CPs::ru);

            // initials
            window.print("Введите инициалы сотрудника номер ", false, CPs::ru);
            window.print(to_string(i) + ": ", false, CPs::ru);
            initials = inp.getInputText(10, CPs::ru);

            // born year
            window.print("Введите год рождения сотрудника номер ", false, CPs::ru);
            window.print(to_string(i) + ": ", false, CPs::ru);
            bornYear = stoi(inp.getInputText(3, CPs::ru));

            // rate
            window.print("Введите зарплату сотрудника номер ", false, CPs::ru);
            window.print(to_string(i) + ": ", false, CPs::ru);
            rate = stof(inp.getInputText(3, CPs::ru));

            // create student add to array
            Employee stud(lastName, initials, bornYear, rate);
            employees.push_back(stud);

            window.print("Созданние сотрудников окончено", true, CPs::ru);
        }
    }

    // find oldest
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i].bornYear < oldest.bornYear)
        {
            oldest = employees[i];
        }
    }

    // show oldest
    window.print("Самый старый сотрудник: ", true, CPs::ru);
    window.print(oldest.toString(), false, CPs::ru);

    FileService::saveOutOne(employees);
    FileService::saveOutTwo(employees);

    window.print("Сохранение в двух представлениях окончено", true, CPs::ru);
}