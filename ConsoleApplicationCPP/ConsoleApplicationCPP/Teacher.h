#pragma once

class Teacher : public Person {
    float _salary;
    Student** students; 
    int student_count=0;

    string splitString(string data) {
        int space = data.find(' ');
        string newData = data.substr(space, space - data.size());
        return newData;
    }
public:
    Teacher(){}
    Teacher(string name, string surname, int age, string email)
        : Person(name, surname, age, email) {
    }

    void Show() const override {
       cout << "Teacher Name: " << _name<<" "<<_surname << endl;
       cout << "Age: " << _age<< endl;
       cout << "Email: " << _email<< endl;
       cout << "Salary: " << _salary << endl;
    }

    void addStudent(Student* student) {
        Student** newArr = new Student * [student_count + 1];
        for (size_t i = 0; i < student_count; i++)
        {
            newArr[i] = students[i];
        }
        newArr[student_count] = student;
        student_count++;
        students = newArr;
    }

    float GetSalary() { return _salary; }
    void SetSalary(float salary) {
        if (salary < 0)
            throw exception("Salary CANNOT be lower than zero.");
        _salary = salary;
    }

    void viewAllStudents() {
        for (size_t i = 0; i < student_count; i++)
        {
            students[i]->Show();
            cout << endl;
        }
    }

    void writeStudentsToFile();
    void writeTeacherToFile();
    void readTeacherFromToFile(string name);
    void readStudentsFromFile();
    Teacher* LogIn();
    Student** GetAllStudents() { return students; }
    int GetStudentCount() { return student_count; }
    Teacher* Register();
    void deleteStudent(string name, string surname);


};

Teacher* Teacher::Register()
{
    Teacher* teacher = new Teacher();
    while (true) {
        try
        {
            string name;
            cout << "Enter Name: ";
            cin >> name;
            teacher->SetName(name);
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
            teacher->SetSurname(surname);
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
            teacher->SetAge(age);
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
            teacher->SetEmail(email);
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
            float salary;
            cout << "Enter Salary: ";
            cin >> salary;
            teacher->SetSalary(salary);
            break;
        }
        catch (const std::exception& e)
        {
            cout << e.what() << endl;
            system("pause");
        }
    }
    return teacher;
}

Teacher* Teacher::LogIn() {
    string name;
    cout << "Enter Name: ";
    cin >> name;
    Teacher* teacher = new Teacher();
    teacher->readTeacherFromToFile(name);
    return teacher;
}

void Teacher::readStudentsFromFile() {
    ifstream file(GetName() + ".txt");

    string line;
    while (file.eof()) {
        Student* student=new Student();
        getline(file, line);
        student->SetName(splitString(line));
        getline(file, line);
        student->SetSurname(splitString(line));
        getline(file, line);
        student->SetAge(stoi(splitString(line)));
        getline(file, line);
        student->SetEmail(splitString(line));
        getline(file, line);
        student->SetAvarage(stof(splitString(line)));
        getline(file, line);
        student->SetGroup(splitString(line));
        addStudent(student);
    }
}

void Teacher::readTeacherFromToFile(string name) {
    ifstream file("teacher.txt");
    if (!file) {
        cout << "File CANNOT be opened." << endl;
        return;
    }

    string line;
    while (file.eof())
    {
        getline(file, line);
        if (splitString(line) == name) {
            this->SetName(splitString(line));
            getline(file, line);
            this->SetSurname(splitString(line));
            getline(file, line);
            this->SetAge(stoi(splitString(line)));
            getline(file, line);
            this->SetEmail(splitString(line));
            getline(file, line);
            this->SetSalary(stof(splitString(line)));
        }

    }
}

void Teacher::writeStudentsToFile() {
    ofstream file(GetName() + ".txt");

    if (!file) {
        cout << "File CANNOT be opened." << endl;
        return;
    }

    for (size_t i = 0; i < student_count; i++)
    {
        file << "Name: " << students[i]->GetName() << endl;
        file << "Surname: " << students[i]->GetSurname() << endl;
        file << "Age: " << students[i]->GetAge() << endl;
        file << "Email: " << students[i]->GetEmail() << endl;
        file << "Avarage: " << students[i]->GetAvarage() << endl;
        file << "Group: " << students[i]->GetGroup() << endl;
    }
}

void Teacher::writeTeacherToFile() {
    ofstream file("teacher.txt");

    if (!file) {
        cout << "File CANNOT be opened." << endl;
        return;
    }

    file << "Name: " << GetName() << endl;
    file << "Surname: " << GetSurname() << endl;
    file << "Age: " << GetAge() << endl;
    file << "Email: " << GetEmail() << endl;
    file << "Salary: " << GetSalary() << endl;
}

void Teacher::deleteStudent(string name,string surname) {
    Student** newStudents = new Student * [student_count - 1];
    int index = 0;
    for (size_t i = 0; i < student_count; i++)
    {
        if (students[i]->GetName() == name && students[i]->GetSurname() == surname) {
            delete students[i];
            i++;
        }
        newStudents[index] = students[i];
        index++;
    }
    student_count--;
    students = newStudents;
}
