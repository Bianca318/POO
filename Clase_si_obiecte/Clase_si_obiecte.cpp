// Clase_si_obiecte.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
 
class Student {
private:
	string nume;
	int varsta;
	float medie;

public:
	//constructor cu var aux
	Student(string nume_student, int varsta_student, float medie_student) {
		nume = nume_student;
		varsta = varsta_student;
		medie = medie_student;
		cout << "Constructorul a fost apelat pentru:" << nume << endl;
	}
	//Constructor folosind THIS
	/*Student(string nume, int varsta, float medie) {
		this->nume = nume;
		this->varsta = varsta;
		this->medie = medie;
		cout << "Constructoru a fost apelat pentru:" << nume << endl;
	}
	*/
	~Student()
	{
		cout << "Destructorul a fost apelat pentru:" << nume << endl;
	}
	void afisare_informatii()
	{
		cout << "NUME:" << nume << ",Varsta:"<<varsta << ",Medie:" << medie<<endl;
	}
	float mmedie()
	{
		return medie;
	}
	float returneaza_media() const {
		return medie;
		
	}
	
	

};
  void sortare_dupa_medie (Student **studenti,int n)
  {
	  for (int i = 0; i< n-1; i++)
		  for (int j = 0; j < n -i- 1; j++)
		  {
			  if(studenti[j]->returneaza_media()>studenti[j+1]->returneaza_media())
			  {
				  Student* aux = studenti[j];
				  studenti[j] = studenti[j + 1];
				  studenti[j + 1] = aux;
			  }
		  }
  }
int main()
{
	int i,k;
	 int n = 0;
	 int medies = -1,z;
	cout << "Introduceti numarul de studenti:";
	cin >> k;
	n = k;

	Student** studenti=new Student*[n];
	for (i = 0; i < n; i++)
	{
		string nume;
		int varsta;
		float medie;
		cout << "Introduceti numele studentului:" << i + 1 << ":"; cin >> nume;
		cout<< "Introduceti varsta studentului:" << i + 1 << ":"; cin >> varsta;
		cout<< "Introduceti media studentului:" << i + 1 << ":"; cin >> medie;
		if (medie > medies)
			medies = -1; z = i;
		studenti[i] = new Student(nume, varsta, medie);

	}

	//Afisarea studentilor folosind metoda afisare_informatii()
	for( int i=0;i<n;i++)
	{
		studenti[i]->afisare_informatii();

	}
	//Eliberam memoria alocata dinamic
	cout << "Studentul cu cea mai mare medie este:";
		studenti[z]->afisare_informatii();
	cout << endl;
	bool ok = 0;
	 do 
	 {
		 ok = 1;
		 for(int i=0;i<n;i++)
		  if(studenti[i]->mmedie()>studenti[i+1]->mmedie())
		  {
			  Student* aux = studenti[i];
			  studenti[i] = studenti[i + 1];
			  studenti[i + 1] = aux;
			  ok = 0;

		  }
	 } while (!ok);
	 for (int i = 0; i < n; i++) {
		 studenti[i]->afisare_informatii();
	 }
	for(int i=0;i<n;i++)
	{
		delete studenti[i];
	}
	return 0;
}