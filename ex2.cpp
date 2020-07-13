#include <iostream>
#include <string>
using namespace std;

struct samochod{ //definicja naszego typu
    string nazwa; //wlasciwosci naszego typu
    double v_max;
    double masa;
};
void clear(){ //czyszczenie bufora wejsciowego
    char c; 
    while((c = getchar()) != '\n')  //dopoki nie zostanie odczytany znak nowej linii '\n'
        continue;
}
void wczytaj(samochod* wektor, int ilosc){ //funkcja do ktorej przekazujemy wskaznik 
    for(int i = 0; i < ilosc; ++i){
        cout << "Podaj dane samochodu " << i + 1 << "." << endl; ///komunikat
        cout << "Podaj marke: ";
        cin >> wektor[i].nazwa;
        clear();
        cout << "Podaj predkosc max: ";
        cin >> wektor[i].v_max;
        clear();
        cout << "Podaj mase samochodu: ";
        cin >> wektor[i].masa;
        clear();
    }
}
/* funkcje "struktura osoba"
struct osoba{ //definicja naszego typu
    string nazwisko;
    string imie;
    double wzrost;
};
void clear(){ //czyszczenie bufora wejsciowego
    char c; 
    while((c = getchar()) != '\n')  //dopoki nie zostanie odczytany znak nowej linii '\n'
        continue;
}
void wczytaj(osoba* wektor, int ilosc){ //funkcja do ktorej przekazujemy wskaznik 
    for(int i = 0; i < ilosc; ++i){
        cout << "Podaj dane osoby " << i + 1 << "." << endl; ///komunikat
        cout << "Nazwisko: ";
        cin >> wektor[i].nazwisko; //wczytanie nazwiska
        clear(); //czyszczenie bufora ze znaku '\n'
        cout << "Imie: ";
        cin >> wektor[i].imie; //wczytanie imienia
        clear();
        cout << "Podaj wzrost: ";
        cin >> wektor[i].wzrost; //wczytanie wzrostu
        clear();
    }
}
*/

int main(){
    const int max = 10;
    samochod x[max];
    int n; //wczytanie roboczej wielkosci
    cin >> n; //wczytanie wielkosci roboczej
    wczytaj(x, n); //wczytywanie danych
    int ile = 0, ktory = 0;
    double max_v_max;

    max_v_max = x[0].v_max; //warunki poczatkowe
    ktory = 0; //indeks pierwszego elementu
    if(x[0].masa > 1000) ++ile; //ile += 1; ile++; ++ile; ile = ile + 1;
    
    for(int i = 1; i < n; ++i){
        if(x[i].masa > 1000) ++ile; //jesli masa wieksza od 1000 to zwieksz licznik
        if(x[i].v_max > max_v_max){ //jesli ktorys samochod ma wieksza predkosc max 
            max_v_max = x[i].v_max; //max nowa predkosc max rowna v_max aktualnego elementu
            ktory = i; //zapisanie indeksu tego elementu w tablicy
        }
    }

    cout << "Ilosc samochodow z masa powyzej 1000kg: " << ile << endl
    << "Numer samochodu z v_max: " << ktory + 1 << endl 
    << "Dane samochodu z v_max: " << endl
    << "Nazwa: " << x[ktory].nazwa << endl
    << "Masa: " << x[ktory].masa << endl
    << "V_max: " << x[ktory].v_max << endl;
    
    //int tab[3]; - tab[0], tab[1], tab[2]

    /* struktura osoba
    const int max = 10; //maksymalna ilosc osob
    osoba grupa[max]; //utworzenie "wektora" grupa
    int temp; //wczytanie roboczej wielkosci
    double avg = 0; //srednia wzrostu
    cout << "Podaj wielkosc wektora (max 10): ";
    cin >> temp; //wczytanie wielkosci roboczej
    wczytaj(grupa, temp);
    for(int i = 0; i < temp; ++i){
        avg += grupa[i].wzrost; //suma wzrostow
    }
    avg /= temp; //avg = avg / temp;

    cout << "Srednia wzrostu: " << avg << endl; 
    */
    return 0;
}