#include "Student.h"
enum ConsoleColor {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}


int main()
{
	Student* students = new Student[5];
	char menu{}; int size = 5, number{};
	students->input_mas_students(size);
	bool flag = false;
	SetColor(12, 0);
	while (flag == false)
	{
		system("cls");
		cout << "\t\t\t\tStudent manager\n" <<
			"\t\t\Enter P(p) to show your students list\n" <<
			"\t\tEnter N(n) to sort students by name\n" <<
			"\t\tEnter A(a) to sort students by grade point average\n" <<
			"\t\tEnter D(d) to add a new student\n" <<
			"\t\tEnter S(s) to print student`s grades sum\n" <<
			"\t\tEnter E(e) to exit the editor\n\n" <<
			"\t\t\tEnter a command to select an action : ";
		cin >> menu;
		switch (menu)
		{
		case 'P':
		case 'p':
			system("cls");
			cout << "\tThe list of your students is displayed below\n";
			cout << left << setw(8) << "Number" << left << setw(12) << "Name:" <<
				left << setw(12) << "Family:" <<
				left << setw(10) << "Age:" <<
				left << setw(15) << "Grades:" << right <<
				setw(10) << setprecision(3) << "Average grade:\n\n";
			for (int i = 0; i < size; ++i)
			{
				cout << left << setw(8) << i + 1 << students[i];
			}
			system("pause");
			break;
		case 'N':
		case 'n':
			system("cls");
			students->Sort_students_name(students, 5);
			cout << "\t\tStudents are successfully sorted by name\n";
			system("pause");
			break;
		case 'A':
		case 'a':
			system("cls");
			students->Sort_students_avg_mark(students, 5);
			cout << "\t\tStudents are successfully sorted by " <<
				"grade point average\n";
			system("pause");
			break;
		case 'D':
		case 'd':
			system("cls");
			students->Add_Student(students, size);
			cout << "New student successfully added\n";
			system("pause");
			break;
		case 'S':
		case 's':
			cout << "Select the student's number to show his sum grades\n" <<
				"Enter student`s number : "; cin >> number;
			while (number < 1 || number > size)
			{
				cout << "Error\n" <<
					"Enter student`s number again : ";
				cin >> number;
			}
			number--;
			cout << "Sum grades of student number " << number + 1 <<
				" = " << Sum_Students_Grades(students[number]) << endl;
			system("pause");
			break;
		case 'E':
		case 'e':
			system("cls");
			cout << "\t\tThe program exits\n";
			flag = true;
			break;
		default:
			cout << "\t\tMistake. Wrong command\n";
			system("pause");
			break;
		}
	}
	delete[] students;
	system("pause");
}
