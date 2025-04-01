// Gestionare-locuri-de-parcare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Parcare {
protected: float oraintrarii;
         float minutulintrarii;
         float oraiesirii;
         float minutuliesirii;
         int nrlocuriparcare;
         float tarif;

public:
    Parcare(float oraintrarii, float minutulintrarii, float oraiesirii, float minutuliesirii, int nrlocuriparcare, float tarif)
    {
        this->oraintrarii = oraintrarii;
        this->minutulintrarii = minutulintrarii;
        this->oraiesirii = oraiesirii;
        this->minutuliesirii = minutuliesirii;
        this->nrlocuriparcare = nrlocuriparcare;
        this->tarif = tarif;
    }

    float calculeazatarif() const {

        float ora_totala, min_tot, min_total, tarif_final;
        ora_totala = oraiesirii - oraintrarii;
        min_tot = minutuliesirii - minutulintrarii;
        min_total = ora_totala * 60 + min_tot;
        tarif_final = min_total * (tarif / 60);

        return tarif_final;
    }
    void afisare_detalii() {
        cout << "Ora intarii: " << oraintrarii << ", Minutul intarii:" << minutulintrarii << ", Ora iesirii: " << oraiesirii << ", Minutul iesirii:" << minutuliesirii << endl;
        cout << "Numar locuri parcare:" << nrlocuriparcare << ", Tarif:" << calculeazatarif() << "lei";
    }
};
class Masina : public Parcare {
private:
    string numar;
public:
    Masina(float oraintrarii, float minutulintrarii, float oraiesirii, float minutuliesirii, int nrlocuriparcare, float tarif, string numar) : Parcare(oraintrarii, minutulintrarii, oraiesirii, minutuliesirii, nrlocuriparcare, tarif)
    {
        this->numar = numar;
    }
    void afisare_informatii()
    {
        cout << "Ora intarii: " << oraintrarii << ", Minutul intarii:" << minutulintrarii << ", Ora iesirii: " << oraiesirii << ", Minutul iesirii:" << minutuliesirii << endl;
        cout << "Numar locuri parcare:" << nrlocuriparcare << ", Tarif:" << calculeazatarif() << ", Numar:" << numar;
    }

};

int main()
{
    int i, n;
    cout << "Afiseaza numarul:";
    cin >> n;

    Masina** masini = new Masina * [n];

    for (i = 0; i < n; i++)
    {
        float oraintrarii;
        float minutulintrarii;
        float oraiesirii;
        float minutuliesirii;
        int nrlocuriparcare;
        float tarif;
        string numar;
        cout << "Masina " << i + 1 << " cu nr de inmatriculare: ";
        cin >> numar;
        cout << "Introduceti ora intrarii: ";
        cin >> oraintrarii;
        cout << "Introduceti minutul intrarii:";
        cin >> minutulintrarii;
        cout << "Introduceti ora iesirii:";
        cin >> oraiesirii;
        cout << "Introduceti minutul iesirii:";
        cin >> minutuliesirii;
        cout << "Introduceti numar locuri de parcare:";
        cin >> nrlocuriparcare;
        cout << "Tarif:";
        cin >> tarif;


        masini[i] = new Masina(oraintrarii, minutulintrarii, oraiesirii, minutuliesirii, nrlocuriparcare, tarif, numar);
        cout << "Tarif:" << masini[i]->calculeazatarif() << "lei" << endl;
    }

    for (i = 0; i < n; i++)
    {
        masini[i]->afisare_informatii();
    }

    for (i = 0; i < n; i++)
    {
        delete masini[i];
    }
    delete[] masini;

}

