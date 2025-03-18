#include <iostream>
#include <windows.h>
#include<iomanip>
#include <fstream>
using namespace std;
struct Student
{
	string fam;
	string im;
	string otch;
	int nogroup;
	int grad[5]{ 0,0,0,0,0 };
	float midgrad{ 0 };
	int count2{ 0 };
};
struct task3
{
	int nogroup;
	int count{ 0 };
	int badcount{ 0 };
};
void tableout(int N, Student* students, int maxlenfam, int maxlenim, int maxlenotch)
{
	ofstream out;
	out.open("output.txt");
	for (int i{ 0 }; i < 32 + maxlenfam + maxlenim + maxlenotch; i++)
		out << "=";
	out << endl;
	out << "|" << setw(2) << "ГРУППА" << setw(2) << "|" << setw(maxlenfam + 1) << "ФАМИЛИЯ" << setw(2) << "|" << setw(maxlenim - 1) << "ИМЯ" << setw(4) << "|" << setw(maxlenotch - 1) << "ОТЧЕСТВО" << setw(4) << "|" << setw(9) << "ОЦЕНКИ" << setw(5) << "|" << endl;
	for (int i{ 0 }; i < 32 + maxlenfam + maxlenim + maxlenotch; i++)
		out << "=";
	out << endl;
	for (int i{ 0 }; i < N; i++)
	{
		out << "|" << setw(5) << students[i].nogroup << setw(3) << "|";
		out << setw(maxlenfam + 1) << students[i].fam << setw(2) << "|";
		out << setw(maxlenim + 1) << students[i].im << setw(2) << "|";
		out << setw(maxlenotch + 1) << students[i].otch << setw(2) << "|";
		for (int k{ 0 }; k < 5; k++)
		{
			if (k == 4)
				out << students[i].grad[k] << "|";
			else
				out << students[i].grad[k] << ", ";

		}
		out << endl;
		for (int i{ 0 }; i < 32 + maxlenfam + maxlenim + maxlenotch; i++)
			out << "=";
		out << endl;
	}
	out.close();
}
void output(int N, Student* students)
{
	for (int i{ 0 }; i < N; i++)
	{
		cout << students[i].nogroup << " - ";
		cout << students[i].fam << " ";
		cout << students[i].im << " ";
		cout << students[i].otch << ": ";
		for (int k{ 0 }; k < 5; k++)
		{
			if (k == 4)
				cout << students[i].grad[k];
			else
				cout << students[i].grad[k] << ", ";

		}
		cout << endl;
	}
}
void listcreate(int N, Student* students, bool h)
{
	for (int i{ 0 }; i < N; i++)
	{
		if (h)
			cout << "Введите фамилию: ";
		cin >> students[i].fam;
		if (h)
			cout << "Введите имя: ";
		cin >> students[i].im;
		if (h)
			cout << "Введите отчество:";
		cin >> students[i].otch;
		if (h)
			cout << "Введите номер группы: ";
		cin >> students[i].nogroup;
		if (h)
			cout << "Введите оценки студента:";
		for (int k{ 0 }; k < 5; k++)
		{
			cin >> students[i].grad[k];
			if (students[i].grad[k] == 2)
				students[i].count2++;
			students[i].midgrad += students[i].grad[k];
		}
		students[i].midgrad = students[i].midgrad / 5;
	}
}
int maxlen(Student* students, int N, int& maxlenfam, int& maxlenim, int& maxlenotch)
{
	for (int i{ 0 }; i < N; i++)
	{
		if (students[i].fam.length() > maxlenfam)
			maxlenfam = students[i].fam.length();
		if (students[i].im.length() > maxlenim)
			maxlenim = students[i].im.length();
		if (students[i].otch.length() > maxlenotch)
			maxlenotch = students[i].otch.length();
	}
	return maxlenfam;
	return maxlenim;
	return maxlenotch;
}
void sortstudents_midgrad(int n, Student* a)
{
	int i, j, max;
	for (i = 0; i < n - 1; i++)
	{
		max = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j].midgrad > a[max].midgrad)
			{
				max = j;
			}
		}
		swap(a[max], a[i]);
	}
}
void sortstudents_badcount(int k, task3* a)
{
	int i, jp, min;
	for (i = 0; i < k - 1; i++)
	{
		min = i;
		for (jp = i + 1; jp < k; jp++)
		{
			if (a[jp].badcount > a[min].badcount)
			{
				min = jp;
			}
		}
		swap(a[min], a[i]);
	}
}
void sortstudentsnogroup(int n, Student* a)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j].nogroup < a[min].nogroup)
			{
				min = j;
			}
		}
		swap(a[min], a[i]);
	}
}
void studentsfilter(int N, Student* students, bool h, int maxlenfam, int maxlenim, int maxlenotch)
{
	int countstud{ 0 };
	if (h)
	{
		for (int i{ 0 }; i < 32 + maxlenfam + maxlenim + maxlenotch; i++)
			cout << "=";
		cout << endl;
		cout << "|" << setw(2) << "ГРУППА" << setw(2) << "|" << setw(maxlenfam + 1) << "ФАМИЛИЯ" << setw(2) << "|" << setw(maxlenim - 1) << "ИМЯ" << setw(4) << "|" << setw(maxlenotch - 1) << "ОТЧЕСТВО" << setw(4) << "|" << setw(9) << "БАЛЛ" << setw(5) << "|" << endl;
		for (int i{ 0 }; i < 32 + maxlenfam + maxlenim + maxlenotch; i++)
			cout << "=";
		cout << endl;
	}
	for (int i{ 0 }; i < N; i++)
		if (students[i].midgrad > 4)
		{
			if (h)
			{
				cout << "|" << setw(5) << students[i].nogroup << setw(3) << "|";
				cout << setw(maxlenfam + 1) << students[i].fam << setw(2) << "|";
				cout << setw(maxlenim + 1) << students[i].im << setw(2) << "|";
				cout << setw(maxlenotch + 1) << students[i].otch << setw(2) << "|";
				cout << setw(8) << students[i].midgrad << setw(6) << "|" << endl;
				for (int i{ 0 }; i < 32 + maxlenfam + maxlenim + maxlenotch; i++)
					cout << "=";
				cout << endl;
			}
			else
				cout << students[i].nogroup << ", " << students[i].fam << " " << students[i].im << " " << students[i].otch << " - " << students[i].midgrad << endl;
			countstud++;
		}
	if (countstud == 0)
	{
		if (h)
			cout << "Студентов, имеющих средний балл выше 4.0 нет." << endl;
		else
			cout << "NO" << endl;
	}
}
void agregatpotoka(int N, Student* students, task3* a, bool h)
{
	int j;
	int k{ 0 };
	for (int i{ 0 }; i < N; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (students[i].nogroup == students[j].nogroup)
				break;
		}
		if (i == j)
		{
			a[k].nogroup = students[i].nogroup;
			k++;
		}
	}
	for (int i{ 0 }; i < N; i++)
		for (int k{ 0 }; k < N; k++)
		{
			if (a[i].nogroup == students[k].nogroup)
			{
				a[i].count++;
				if (students[k].count2 > 0)
					a[i].badcount++;
			}
		}
	sortstudents_badcount(k, a);
	if (h)
	{
		cout << "================" << endl;
		for (int i{ 0 }; i < k; i++)
			cout << "|" << setw(5) << a[i].nogroup << setw(2) << "|" << setw(2) << a[i].count << setw(2) << "|" << setw(2) << a[i].badcount << setw(2) << "|" << endl << "================" << endl;
	}
	else
		for (int i{ 0 }; i < k; i++)
			cout << a[i].nogroup << " - " << a[i].count << " - " << a[i].badcount << endl;
}

int main(int argc, char* argv[])
{
	setlocale(LC_CTYPE, "rus");
	bool h = false;
	if (argc <= 1 || strcmp(argv[1], "false") != 0)
	{
		h = true;
	}
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N, m, maxlenfam{ 0 }, maxlenim{ 0 }, maxlenotch{ 0 }, len{ 0 };
	if (h)
		cout << "Введите количество студентов: ";
	cin >> N;
	struct Student* students = new struct Student[N];
	listcreate(N, students, h);
	sortstudentsnogroup(N, students);
	maxlen(students, N, maxlenfam, maxlenim, maxlenotch);
	if (h)
	{
		tableout(N, students, maxlenfam, maxlenim, maxlenotch);
		cout << endl;
	}
	else
		output(N, students);
	sortstudents_midgrad(N, students);
	studentsfilter(N, students, h, maxlenfam, maxlenim, maxlenotch);
	if (h)
		cout << endl << endl;
	struct task3* a = new struct task3[N];
	agregatpotoka(N, students, a, h);
}