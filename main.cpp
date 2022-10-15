/*Stwórz klasę mrówka oraz 3 obiekty czarna, czerwona i żółta.
Klasa ma pola: rodzaj, wiek, imię. Program ma się nazywać mrowisko.
Następnie wprowadź dane do obiektów i wyświetl najstarszą mrówkę.*/

#include <iostream>
#include "ant.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int numberOfAnts = 0;
Ant mrowka[100];
string programVersion = "v. 0.3.7";

void readTitle()
{
    ifstream plik;
    plik.open("title");
    if (plik.good())
    {
        for(int i=0; i<8; i++)
        {
            string text;
            getline(plik, text);
            cout << text << endl;
        }
        cout<< programVersion << endl;
    }
    else
    {
        cout << "Mrowisko" << programVersion << endl;
    }
    plik.close();
}

void loadData()
{
    ifstream plik;
    plik.open("data");
    if (plik.good())
    {
        int nr;
        string antName;
        string antColor;
        string sAge;
        int antAge;

        plik >> nr;
        numberOfAnts = nr;

        for(int i=0; i<numberOfAnts; i++)
        {
            plik >> antName;
            plik >> antColor;
            plik >> sAge;
            antAge = stoi(sAge);

            mrowka[i].setData(antName, antColor, antAge);
        }
        system("cls");
        readTitle();
        cout << "Dane wczytano pomyslnie!\n";
        system("pause");
    }
    else
    {
        cout << "Nie udalo sie zaladowac pliku!";
    }
    plik.close();
}

void saveData()
{
    string const dataFile("data");
    ofstream save(dataFile.c_str());

    if(save)
    {
        save << numberOfAnts << endl;
        for(int i=0; i<numberOfAnts; i++)
        {
            save << mrowka[i].getName() << " " << mrowka[i].getColor() << " " << mrowka[i].getAge() << endl;
        }
        system("cls");
        readTitle();
        cout << "Dane zapisano pomyslnie!\n";
        system("pause");
    }
    else
    {
        cout<<"Nie mozna zapisac danych do pliku.\nJesli wyjdziesz bez zapisu stracisz postepy poczynione od ostatniego zapisu!!!";
    }
    save.close();
}

void addAnt()
{
    system("cls");
    readTitle();
    numberOfAnts += 1;

    int lp = numberOfAnts - 1;

    string antName;
    string antColor;
    int antAge;

    cout<<"\nDodawanie nowej mrowki (Pozostale miejsce w mrowisku:"<<101-numberOfAnts<<"):\n";
    cout<<"Podaj imie mrowki(text): ";
    cin>>antName;
    cout<<"Podaj kolor mrowki(text): ";
    cin>>antColor;
    cout<<"Podaj wiek mrowki(liczba): ";
    cin>>antAge;

    mrowka[lp].setData(antName, antColor, antAge);

    system("cls");
    readTitle();
    cout<<"\nDodano mrowke!\n\n";

    system("pause");
}


void showAnts()
{
    system("cls");
    readTitle();

    cout<<"\nMrowki w tym mrowisku["<<numberOfAnts<<"]:\n";
    cout<<"| I - Lp | II - Nazwa | III - Kolor | IV - Wiek |"<<endl;

    for(int i = 0; i<numberOfAnts; i++)
    {

        if(i+1 < 10)
        {
            cout<<"| I - 0"<<i+1;
        } 
        else if(i+1 >= 10)
        {
            cout<<"| I - "<<i+1;
        }
        cout<<" | II - "<<mrowka[i].getName()<<" | III - "<<mrowka[i].getColor()<<" | IV - "<<mrowka[i].getAge()<<" |"<<endl;
    }

    system("pause");
}

void sortByAge()
{
    system("cls");
    readTitle();

    for(int i = 0; i < numberOfAnts; i++)
    {
        int ageOne;
        int ageTwo;
        
        for(int i = 0; i < numberOfAnts; i++)
        {
            if(mrowka[i].getAge() > mrowka[i+1].getAge())
            {
                ageOne = mrowka[i].getAge();
                ageTwo = mrowka[i+1].getAge();
                mrowka[i].setAge(ageTwo);
                mrowka[i+1].setAge(ageOne);
            }
        }
    }

    cout<<"\nPosortowano!\n\n";

    system("pause");
}


int main()
{
    bool exitProgram = false;

    do
    {
        int choise;

        system("cls");
        readTitle();
        cout<<endl<<"Witaj w mrowisku!"<<endl;
        cout<<"1 - Dodaj mrowke\n2 - Wyswietl mrowki\n3 - Posortuj wg wieku\n4 - Zapisz stan mrowiska\n5 - Wczytaj stan mrowiska\n6 - Wyjdz z programu\n--> ";
        cin>>choise;

        switch (choise)
        {
            case 1:
                addAnt();
                break;
            case 2:
                showAnts();
                break;
            case 3:
                sortByAge();
                break;
            case 4:
                saveData();
                break;
            case 5:
                loadData();
                break;
            case 6:
                exitProgram = true;
                break;
            default:
                break;
        }

    } while (exitProgram != true);
}