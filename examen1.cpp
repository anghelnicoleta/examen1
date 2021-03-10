#include <iostream>
#include <fstream>
using namespace std;
ifstream f("intrare.in");
ofstream g("iesire.out");
void ordonare_greedy(int v[], int n)
{
    int vecRezultat[10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[j] == i && v[j] % 2 == 1) //daca aveam cu > 5 atunci scriai i>4 v[j] % 2 == 1 => i>4
            {
                vecRezultat[i] = v[j];
                break;
            }
            else
                vecRezultat[i] = 0;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        g << vecRezultat[i] << " ";
    }
    g << endl;
}

void recursiv_suma(int v[], int pozVector, int sumaTotala, int nTotalNumere) //suma
{
    //conditie > 3
    if (pozVector == nTotalNumere) //daca am apelat recursiv de n ori atunci afisam rezultatul
    {
        g << "Suma totala: " << sumaTotala << endl;
    }
    else
    {
        if (v[pozVector] > 3)
        {
            sumaTotala += v[pozVector];
        }
        pozVector++;
        recursiv_suma(v, pozVector, sumaTotala, nTotalNumere);
    }
}

void recursiv_produs(int v[], int pozVector, int produsTotal, int nTotalNumere) //produs
{
    if (pozVector == nTotalNumere) //daca am apelat recursiv de n ori atunci afisam rezultatul
    {
        g << "Produs total: " << produsTotal << endl;
    }
    else
    {
        if (v[pozVector] % 2 == 1)
        {
            produsTotal *= v[pozVector];
        }
        pozVector++;
        recursiv_produs(v, pozVector, produsTotal, nTotalNumere);
    }
}

int nrPare = 0;
void div_imp_nrPar(int v[], int s, int d) 
{
    int mij, pare1, pare2;
    if (s == d)
    {
        if (v[s] % 2 == 0)
        {
            nrPare++;
        }
    }
    else
    {
        mij = (s + d) / 2;
        div_imp_nrPar(v, s, mij);
        div_imp_nrPar(v, mij + 1, d);
    }
}

void div_imp_pozitieCifra(int v[], int s, int d) {

    int mij, pare1, pare2;
    if (s == d)
    {
        if (v[s] == 8)
        {
            g << "Pozitie 8: " << s + 1; //plecam de la 0 facem +1
        }
    }
    else
    {
        mij = (s + d) / 2;
        div_imp_pozitieCifra(v, s, mij);
        div_imp_pozitieCifra(v, mij + 1, d);
    }
}
int main()
{
    int n = 10;
    int v[10];
    int sumaTotala = 0;
    int produsTotal = 1;
    for (int i = 0; i < n; i++)
        f >> v[i];
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    ordonare_greedy(v, n);
    recursiv_suma(v, 0, sumaTotala, n);
    recursiv_produs(v, 0, produsTotal, n);
    div_imp_nrPar(v, 0, n - 1);
    g << "Nr pare: " << nrPare << endl;
    div_imp_pozitieCifra(v, 0, n - 1);
    return 0;
    //update
}


