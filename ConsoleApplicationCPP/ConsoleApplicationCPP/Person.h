#pragma once


class Person {
protected:
    string _name;
    string _surname;
    int _age;
    string _email;
public:
    Person(){}
    Person(string name, string surname, int age, string email){
        SetName(name);
        SetSurname(surname);
        SetAge(age);
        SetEmail(email);
    }
    string GetName() const { return _name; }
    string GetSurname() const { return _surname; }
    int GetAge() const { return _age; }
    string GetEmail() const { return _email; }
  
    void SetName(string name) {
        if (name == "") {
            throw exception("Name CANNOT be null.");
        }
        _name = name;
    }

    void SetSurname(string surname) {
        if (surname == "") {
            throw exception("Surname CANNOT be null.");
        }
        _surname = surname;
    }

    void SetEmail(string email) {
        if (email == "") {
            throw exception("Email CANNOT be null.");
        }
        _email = email;
    }

    void SetAge(int age) {
        if (age < 0)
            throw exception("Age CANNOT be lower than zero.");
        if (age < 9)
            throw exception("You need to be at least 9 years old.");
        _age = age;
    }

    virtual void Show() const = 0;
};


