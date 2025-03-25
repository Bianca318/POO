// Clasa prietena.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
class Persoana {
protected:
    string nume;
    int varsta;

public:
    Persoana(string nume, int varsta)
    {
        this->nume = nume;
        this->varsta = varsta;

    }
    void afiseazaInformatii()
    {
        cout << "Nume:" << nume << "Varsta:" << varsta << endl;
    }
};
//clasa derivata 
class Student :public Persoana {
private:
    float medie;
    //clasa prietena
    friend class Admin;
public:
    Student(string nume, int varsta, float medie) : Persoana(nume, varsta)
    {
        this->medie = medie;

    }
    void afiseazaInformatii()
    { 
        cout << "Nume:" << nume << " ,Varsta:" << varsta << " ,Medie:"<<medie<<endl;
    }
};
class Admin {
public:
    //folosind "&" inseamna ca lucram cu o referinta, adica 
    void modificaMedie(Student& s, float nouaMedie)
    {
        cout << " Modific media pentru" << s.nume << " de la " << s.medie << "la" << nouaMedie << endl;
        s.medie = nouaMedie;
    }
    void afiseazaDetaliistudent(const Student& s) {
        cout << "ADMIN->STUDENT: " << s.nume << ",Varsta" << s.varsta << ",Medie:" << s.medie << endl;
    }
};

int main()
{
    Student s1("Mihai", 20, 7.5);
    Student s2("Victor", 21, 10);
    s1.afiseazaInformatii();
    s2.afiseazaInformatii();
    Admin admin;
    admin.modificaMedie(s2, 5);
    admin.afiseazaDetaliistudent(s2);

}

