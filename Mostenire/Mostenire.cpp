// Mostenire.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//3 modificatori:


//1. Private : Datele sunt accesibile in acceasi clasa
//3.Protected:Datele sunt accesibile in aceeasi clasa si 
// in clasele derivate
//2.Public: Datele sunt accesibile in aceeasi clasa in clasele derivate(mostenire) si in exterior


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
    void afisare_detalii()
    {
        cout << "Nume: " << nume << ' ' << "Varsta:" << varsta << endl;
    }
};
class Student :public Persoana {
private:
    float medie;
public:
    Student(string nume, int varsta, float medie) :Persoana(nume, varsta)
    { 
        this-> medie = medie;
    }
    void afisare_informatii()
    {
        cout << "Nume:" << nume << ",Varsta:" << varsta << ",Medie:" << medie << endl;
    }
};
int main()
{
    Student s("Ion", 21, 10);
        s.afisare_informatii();
        int n;
        float mmediilor = 0;
        cout << "Numar studenti";
        cin >> n;
        Student** studenti = new Student * [n];
        for (int i = 0; i < n; i++)
        {
            string nume;
            int varsta;
            float medie;
            
           cout << "Nume";
            cin >> nume;
            cout << "Varsta";
            cin >> varsta;
            cout << "Medie";
            cin >> medie;
            studenti[i] = new Student(nume, varsta, medie);
            mmediilor = medie + 1;

    }
        for (int i = 0; i < n; i++)
        {
            studenti[i]->afisare_informatii();
        }
        cout << "Media mediilor a studentilor:" << mmediilor/n << endl;
        

        return 0;
}


