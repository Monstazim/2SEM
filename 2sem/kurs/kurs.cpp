#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip>
#include <windows.h>

using namespace std;

// Структура для хранения данных о студенте
struct Student {
    string fullName;        // ФИО (до 50 символов)
    string groupNumber;     // номер группы
    vector<int> grades;    // 5 оценок за последнюю сессию
    double scholarship;     // размер стипендии
    string additionalInfo;  // дополнительная информация
};

// Функция для ввода данных о студенте с консоли
Student inputStudent() {
    Student student;

    cout << "Введите ФИО студента (до 50 символов): ";
    getline(cin, student.fullName);
    if (student.fullName.length() > 50) {
        student.fullName = student.fullName.substr(0, 50);
    }

    cout << "Введите номер группы: ";
    getline(cin, student.groupNumber);

    cout << "Введите 5 оценок за последнюю сессию (через пробел): ";
    student.grades.resize(5);
    for (int i = 0; i < 5; ++i) {
        cin >> student.grades[i];
    }
    cin.ignore(); // очищаем буфер после ввода чисел

    cout << "Введите размер стипендии: ";
    cin >> student.scholarship;
    cin.ignore();

    cout << "Введите дополнительную информацию: ";
    getline(cin, student.additionalInfo);

    return student;
}

// Функция для вывода данных о студенте в консоль
void printStudent(const Student& student) {
    cout << "ФИО: " << student.fullName << endl;
    cout << "Группа: " << student.groupNumber << endl;
    cout << "Оценки: ";
    for (int grade : student.grades) {
        cout << grade << " ";
    }
    cout << endl;
    cout << "Стипендия: " << student.scholarship << endl;
    cout << "Доп. информация: " << student.additionalInfo << endl;
    cout << "-------------------------" << endl;
}

// Функция для сохранения данных о потоке в файл
void saveToFile(const vector<Student>& students, const string& filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return;
    }

    for (const auto& student : students) {
        outFile << student.fullName << endl;
        outFile << student.groupNumber << endl;
        for (int grade : student.grades) {
            outFile << grade << " ";
        }
        outFile << endl;
        outFile << student.scholarship << endl;
        outFile << student.additionalInfo << endl;
        outFile << "---" << endl; // разделитель между студентами
    }

    outFile.close();
    cout << "Данные успешно сохранены в файл " << filename << endl;
}

// Функция для загрузки данных о потоке из файла
vector<Student> loadFromFile(const string& filename) {
    vector<Student> students;
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Ошибка открытия файла для чтения!" << endl;
        return students;
    }

    string line;
    while (getline(inFile, line)) {
        Student student;
        student.fullName = line;

        getline(inFile, student.groupNumber);

        student.grades.resize(5);
        for (int i = 0; i < 5; ++i) {
            inFile >> student.grades[i];
        }
        inFile.ignore();

        inFile >> student.scholarship;
        inFile.ignore();

        getline(inFile, student.additionalInfo);

        // Пропускаем разделитель
        getline(inFile, line);

        students.push_back(student);
    }

    inFile.close();
    cout << "Данные успешно загружены из файла " << filename << endl;
    return students;
}

// Функция для подсчета двоечников в группе
int countPoorStudents(const vector<Student>& students, const string& groupNumber) {
    int count = 0;
    for (const auto& student : students) {
        if (student.groupNumber == groupNumber) {
            for (int grade : student.grades) {
                if (grade == 2) {
                    count++;
                    break; // считаем студента двоечником, если есть хотя бы одна 2
                }
            }
        }
    }
    return count;
}

// Функция для подсчета количества студентов в группе
int countStudentsInGroup(const vector<Student>& students, const string& groupNumber) {
    int count = 0;
    for (const auto& student : students) {
        if (student.groupNumber == groupNumber) {
            count++;
        }
    }
    return count;
}

// Функция для вывода списка групп, упорядоченного по показателю "двоечники/численность"
void printGroupsByPoorRatio(const vector<Student>& students) {
    map<string, pair<int, int>> groupStats; // группа -> (двоечники, численность)

    // Собираем статистику по группам
    for (const auto& student : students) {
        string group = student.groupNumber;
        bool isPoor = false;

        for (int grade : student.grades) {
            if (grade == 2) {
                isPoor = true;
                break;
            }
        }

        auto it = groupStats.find(group);
        if (it == groupStats.end()) {
            groupStats[group] = make_pair(0, 0);
        }

        groupStats[group].second++; // увеличиваем численность
        if (isPoor) {
            groupStats[group].first++; // увеличиваем количество двоечников
        }
    }

    // Создаем вектор для сортировки
    vector<pair<string, double>> groupsWithRatio;
    for (const auto& entry : groupStats) {
        const string& group = entry.first;
        const auto& stats = entry.second;
        double ratio = (stats.second == 0) ? 0 : static_cast<double>(stats.first) / stats.second;
        groupsWithRatio.emplace_back(group, ratio);
    }

    // Сортируем по убыванию соотношения
    sort(groupsWithRatio.begin(), groupsWithRatio.end(),
        [](const pair<string, double>& a, const pair<string, double>& b) {
            return a.second > b.second;
        });

    // Выводим результаты
    cout << "\nСписок групп по показателю 'двоечники/численность':" << endl;
    cout << "------------------------------------------------" << endl;
    cout << left << setw(10) << "Группа" << setw(20) << "Двоечники" << setw(20) << "Численность" << "Соотношение" << endl;
    cout << "------------------------------------------------" << endl;

    for (const auto& entry : groupsWithRatio) {
        const string& group = entry.first;
        double ratio = entry.second;
        auto stats = groupStats[group];
        cout << left << setw(10) << group
            << setw(20) << stats.first
            << setw(20) << stats.second
            << fixed << setprecision(4) << ratio << endl;
    }
}

int main() {
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Student> students;
    string filename = "students.txt";

    int choice;
    do {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить студента" << endl;
        cout << "2. Просмотреть всех студентов" << endl;
        cout << "3. Сохранить данные в файл" << endl;
        cout << "4. Загрузить данные из файла" << endl;
        cout << "5. Удалить студента" << endl;
        cout << "6. Вывести список групп по показателю 'двоечники/численность'" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            Student newStudent = inputStudent();
            students.push_back(newStudent);
            cout << "Студент добавлен успешно!" << endl;
            break;
        }
        case 2: {
            if (students.empty()) {
                cout << "Список студентов пуст." << endl;
            }
            else {
                cout << "\nСписок студентов:" << endl;
                cout << "========================" << endl;
                for (const auto& student : students) {
                    printStudent(student);
                }
            }
            break;
        }
        case 3: {
            saveToFile(students, filename);
            break;
        }
        case 4: {
            students = loadFromFile(filename);
            break;
        }
        case 5: {
            if (students.empty()) {
                cout << "Список студентов пуст." << endl;
                break;
            }

            cout << "Введите номер студента для удаления (1-" << students.size() << "): ";
            int index;
            cin >> index;
            cin.ignore();

            if (index < 1 || index > students.size()) {
                cout << "Неверный номер студента!" << endl;
            }
            else {
                students.erase(students.begin() + index - 1);
                cout << "Студент удален успешно!" << endl;
            }
            break;
        }
        case 6: {
            if (students.empty()) {
                cout << "Список студентов пуст." << endl;
            }
            else {
                printGroupsByPoorRatio(students);
            }
            break;
        }
        case 0: {
            cout << "Выход из программы." << endl;
            break;
        }
        default: {
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
        }
    } while (choice != 0);

    return 0;
}

