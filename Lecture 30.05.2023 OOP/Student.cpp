#include "Student.h"

Student::Student()
{
	int len_name = strlen("Ivan");
	int len_family = strlen("Petrov");
	name = new char[len_name + 1];
	family = new char[len_family + 1];
	strcpy(name, "Ivan");
	strcpy(family, "Petrov");
	age = 18 + rand() % (40 - 18);
	for (int i = 0; i < 3; ++i)
	{
		mark[i] = 1 + rand() % (12 - 1);
	}
	CalculateAVG();
}

Student::Student(char* _name, char* _family, int _age)
{
	int len_name = strlen(_name);
	int len_family = strlen(_family);
	name = new char[len_name + 1];
	family = new char[len_family + 1];
	strcpy(name, _name);
	strcpy(family, _family);
	age = _age;
	for (int i = 0; i < 3; ++i)
	{
		mark[i] = 1 + rand() % (12 - 1);
	}
	CalculateAVG();
}

Student::Student(const Student& obj)
{
	int len_name = strlen(obj.name);
	int len_family = strlen(obj.family);
	name = new char[len_name + 1];
	family = new char[len_family + 1];
	strcpy(name, obj.name);
	strcpy(family, obj.family);
	age = obj.age;
	for (int i = 0; i < 3; ++i)
	{
		mark[i] = obj.mark[i];
	}
	avg_mark = obj.avg_mark;
}

Student::~Student()
{
	//cout << "Destructor activated\n";
	//cout << "Delete object : " << this->name << ' ' << &this->name << endl <<
	//	this->family << ' ' << & this->family << endl;
	delete[] name;
	delete[] family;
}

//void Student::Print()
//{
//	cout << left << setw(12) << name <<
//		left << setw(12) << family <<
//		left << setw(10) << age;
//	for (int i = 0; i < 3; ++i)
//	{
//		cout << left << setw(3) << mark[i];
//	}
//	cout << right << setw(10) << setprecision(3)  << avg_mark << endl;
//
//}

void Student::CalculateAVG()
{
	float sum = 0;
	for (int i = 0; i < 3; ++i)
	{
		sum += mark[i];
	}
	avg_mark = sum / 3;
}

void Student::SetStudent(char* _name, char* _family, int _age)
{
	int len_name = strlen(_name);
	int len_family = strlen(_family);
	name = new char[len_name + 1];
	family = new char[len_family + 1];
	strcpy(name, _name);
	strcpy(family, _family);
	age = _age;
	for (int i = 0; i < 3; ++i)
	{
		mark[i] = 1 + rand() % (12 - 1);
	}
	CalculateAVG();
}

void Student::Sort_students_avg_mark(Student* mas, int size)
{
	Student tmp;
	for (int i = 0; i < size; ++i) {
		bool flag = false;
		for (int j = 0; j < size - i - 1; ++j) {
			if (mas[j].avg_mark > mas[j + 1].avg_mark) {
				tmp.copy_tmp(mas[j]);
				mas[j].copy_tmp(mas[j+1]);
				mas[j+1].copy_tmp(tmp);
				flag = true;
			}
		}
		if (flag == false) break;
	}
}

void Student::copy_tmp(Student student)
{
	int len_name = strlen(student.name);
	int len_family = strlen(student.family);
	name = new char[len_name + 1];
	family = new char[len_family + 1];
	strcpy(name, student.name);
	strcpy(family,student.family);
	age = student.age;
	for (int i = 0; i < 3; ++i)
	{
		mark[i] = student.mark[i];
	}
	avg_mark = student.avg_mark;
}

Student* Student::input_mas_students(int size)
{
	if (size != 5)
	{
		cout << " Error\n Fuction work with size array = 5\n";
	}
	else
	{
		this[0].SetStudent((char*)"Roman", (char*)"Dalin", 23);
		this[1].SetStudent((char*)"Nikita", (char*)"Losev", 47);
		this[2].SetStudent((char*)"Stanislav", (char*)"Gerasimov", 30); // оставил для наглядности this - указатель
		this[3].SetStudent((char*)"Vitaliy", (char*)"Malov", 25);
		this[4].SetStudent((char*)"Pavel", (char*)"Lobanov", 32);
		return this;
	}
}

Student* Student::Add_Student(Student* &students, int &size)
{
	Student* copy = new Student[size+1];
	for (int i = 0; i < size; ++i) {
		copy[i].copy_tmp(students[i]);
	}
	cin >> copy[size];
	delete[]  students;
	size++;
	students = copy;
	for (int i = 0; i < size; ++i) {
		students[i].copy_tmp(copy[i]);
	}
	return students;
}

void Student::Sort_students_name(Student* mas, int size)
{
	Student tmp;
	for (int i = 0; i < size; i++) {
		for (int j = size-1; j > i; j--) {
			if (strcmp(mas[j - 1].name, mas[j].name) > 0) {
				tmp.copy_tmp(mas[j - 1]);
				mas[j - 1].copy_tmp(mas[j]);
				mas[j].copy_tmp(tmp);
			}
		}
	}
}

ostream& operator <<(ostream& os, Student& student)
{
	cout << left << setw(12) << student.name <<
		left << setw(12) << student.family <<
		left << setw(10) << student.age;
	for (int i = 0; i < 3; ++i)
	{
		cout << left << setw(3) << student.mark[i];
	}
	cout << right << setw(10) << setprecision(3) << student.avg_mark << endl;
	return os;
}

istream& operator>>(istream& is, Student& student)
{
	student.name = new char[BUFFER_SIZE];
	student.family = new char[BUFFER_SIZE];
	cout << "Enter the student's name : ";
	cin >> student.name;
	cout << "Enter the student's family : ";
	cin >> student.family;
	cout << "Enter student`s age :";
	cin >> student.age;
	while (student.age < 18 || student.age > 80)
	{
		cout << "Error\n" <<
			"Enter student`s age again : ";
		cin >> student.age;
	}
	for (int i = 0; i < 3; ++i)
	{
		cout << "Enter grade number (1-12) " << i + 1 << " : ";
		cin >> student.mark[i];
		while (student.mark[i] < 1 || student.mark[i] > 12)
		{
			cout << "Error\n" <<
				"Enter grade number again : ";
			cin >> student.mark[i];
		}
	}
	student.CalculateAVG();
	return is;
}

int Sum_Students_Grades(Student student)
{
	return student.mark[0] + student.mark[1] + student.mark[2];
}