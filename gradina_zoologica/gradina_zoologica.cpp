// gradina_zoologica.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
	string nume;
	int varsta;
public:
	Animal(string nume, int varsta)
	{
		this->nume = nume;
		this->varsta = varsta;
	}
	void afisare_detalii()
	{
		cout << "Nume:" << nume << "Varsta:" << varsta << endl;
	}
};
class Caine : public  Animal {
private:
	string rasa;
public:
	Caine(string nume, int varsta, string rasa) :Animal(nume, varsta)
	{
		this->rasa = rasa;
	}
	void afisare_informatii()
	{
		cout << "Nume:" << nume << ",Varsta:" << varsta << ",Rasa" << rasa << endl;
	}
};
class Girafa : public  Animal {
private:
	float inaltime;
public:
	Girafa(string nume, int varsta, float inaltime) :Animal(nume, varsta)
	{
		this->inaltime = inaltime;
	}
	void afisare_informatii()
	{
		cout << "Nume:" << nume << ",Varsta:" << varsta << ",Inaltime:" << inaltime <<"m" << endl;
	}
};
class Papagal : public  Animal {
private:
	string culoare;
public:
	Papagal(string nume, int varsta, string culoare) :Animal(nume, varsta)
	{
		this->culoare = culoare;
	}
	void afisare_informatii()
	{
		cout << "Nume:" << nume << ",Varsta:" << varsta << ",Culoare:" << culoare << endl;
	}
};
	int main()
	{
	
	Caine c("Max", 2, "Dalmatian");
	Girafa g(" ", 4, 2);
	Papagal p("Roco", 1, "Albastru");
	c.afisare_informatii();
	g.afisare_informatii();
	p.afisare_informatii();

	return 0;
}

	