#pragma once

class Student : public Person {
    float _avarage=0;
    string _group;
public:
    Student(){}
    Student(string name, string surname, int age,string email)
        : Person(name, surname, age, email)
    {}
    string GetGroup() { return _group; }
    void SetGroup(string group) {
        if (group == "")
            throw exception("Group CANNOT be null.");
        _group = group;
    }
    float GetAvarage() { return _avarage; }
    void SetAvarage(float avarage) {
        if (avarage <= 0)
            throw exception("Avarage CANNOT be equal or lower than zero.");
        _avarage = avarage;
    }

    void Show() const override {
        cout << "Student Name: " << _name << " " << _surname << endl;
        cout << "Age: " << _age << endl;
        cout << "Email: " << _email << endl;
        cout << "Avarage: " << _avarage << endl;
        cout << "Group: " << _group << endl;
    }


};