#include<iostream>
#include<map>
#include<string>
#include<iomanip>
#include<vector>
#include<fstream>
#pragma warning(disable : 4996)
using namespace std;
#include"Person.h"
#include"Student.h"
#include"Teacher.h"


void main()
{
	Teacher* teacher = new Teacher();
	while (true)
	{
		system("cls");
		cout << "[0] Register." << endl;
		cout << "[1] Log In." << endl;
		int choice;
		cin >> choice;
		system("cls");
		if (choice == 0)
		{
			teacher = teacher->Register();
		}
		else if (choice == 1) {
			teacher = teacher->LogIn();
		}
		else cout << "Choice you've entered doesn't exist." << endl;

		if (teacher->GetName() != "")break;
		else if (choice == 1) cout << "User doesn't exist." << endl;
		system("pause");
	}

	while (true)
	{
		system("cls");
		int answer;
		cout << "[1]  => Show AllStudent\n[2] = > Show same Group Students\n[3] = > Create Student" <<
			"\n[4] = > Delete student\n[5] = > Save\n[0] = > Exit" << endl;
		cin >> answer;
		system("cls");
		if (answer == 1)
		{
			teacher->viewAllStudents();
			system("pause");
		}
		else if (answer == 2) {
			if (teacher->GetStudentCount() == 0) {//eyer Teacher-in telebeleri yoxdursa compiler asagidaki kodlarin icrasina vaxt itirmir
				cout << "No Student exist in class." << endl;
				system("pause");
				continue;
			}
			string group;
			cout << "Enter Group: ";
			cin >> group;
			Student** students = teacher->GetAllStudents();
			for (size_t i = 0; i < teacher->GetStudentCount(); i++)
			{
				if (students[i]->GetGroup() == group) {
					students[i]->Show();
					cout << endl;
				}
			}
		}
		else if (answer == 3) {
			Student* student = new Student();
			while (true) {
				try
				{
					string name;
					cout << "Enter Name: ";
					cin >> name;
					student->SetName(name);
					break;
				}
				catch (const std::exception& e)
				{
					cout << e.what() << endl;
					system("pause");
				}
			}
			while (true) {
				try
				{
					string surname;
					cout << "Enter Surname: ";
					cin >> surname;
					student->SetSurname(surname);
					break;
				}
				catch (const std::exception& e)
				{
					cout << e.what() << endl;
					system("pause");
				}
			}
			while (true) {
				try
				{
					int age;
					cout << "Enter Age: ";
					cin >> age;
					student->SetAge(age);
					break;
				}
				catch (const std::exception& e)
				{
					cout << e.what() << endl;
					system("pause");
				}
			}
			while (true) {
				try
				{
					string email;
					cout << "Enter Email: ";
					cin >> email;
					student->SetEmail(email);
					break;
				}
				catch (const std::exception& e)
				{
					cout << e.what() << endl;
					system("pause");
				}
			}
			string group;
			cout << "Enter Group: ";
			cin >> group;
			student->SetGroup(group);
			teacher->addStudent(student);
			cout << "Student Added Successfully!" << endl;
			system("cls");
		}
		else if (answer == 4) {
			string name;
			cout << "Enter Name: ";
			cin >> name;
			string surname;
			cout << "Enter surname: ";
			cin >> surname;
			teacher->deleteStudent(name, surname);
			cout << "Student is deleted." << endl;
			system("pause");
		}
		else if (answer == 5) {
			teacher->writeStudentsToFile();
			teacher->writeTeacherToFile();
		}
		else if (answer == 6)break;
	}



}