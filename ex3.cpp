#include <iostream>
using namespace std;
void wczytaj_macierz(double (*macierz)[10], int m, int n);
double fun_m(double (*macierz)[10], int m, int n, int* ile);

int main(){
    //wspolna czesc
    const int m_max = 10, n_max = 10; //maksymalne wymiary
    double macierz[m_max][n_max]; //utworzenie tablicy wskaznikow do tablic czyli macierzy
    int m, n; 
    cout << "Podaj wymiary macierzy (max 10x10): ";
    cin >> m >> n; //wczytanie wymiarow roboczych
    wczytaj_macierz(macierz, m, n); //wczytanie macierzy: przekazanie adresu tablicy tablic (macierzy), wymiarow roboczych
    int ile;
    double suma = 0.0;
    suma = fun_m(macierz, m, n, &ile);
    cout << "Ile: " << ile << endl
    << "Suma: " << suma << endl;
    return 0;
}
void wczytaj_macierz(double (*macierz)[10], int m, int n){
    cout << "Uzupelnij macierz: " << endl; 
    for(int i = 0; i < m; ++i){ //i to numer aktualnego wiersza
        cout << "Wiersz: " << i + 1 << endl; //wypisanie w ktorym jestesmy w wierszu
        
        for(int j = 0; j < n; ++j){ //j to numer aktualnej kolumny w danym wierszu i
            cout << "Podaj element dla kolumny " << j + 1 << ": ";
            cin >> macierz[i][j]; //macierz to tablica dwuwymiarowa czyli w C++ 
            //jest to tablica przechowujaca wskazniki do tablic przechowujacych dane
            //macierz - adres calej macierzy
            //macierz[m] - adres tablicy (wiersza) n
            //macierz[m][n] - konkretny element -> macierz[m] zostawia tablice o indeksie m
            //tablica_o_indeksie_m[n] a to zostawia nam juz dane
        }
    }
}
double fun_m(double (*macierz)[10], int m, int n, int* ile){ 
    double suma_ujemnych = 0.0; 
    /* suma elementów ujemnych w pierwszym wierszu
    for(int i = 0; i < n; ++i){ //i to indeks kolumny
        if(macierz[0][i] < 0){ //jesli ujemne 
            suma_ujemnych += macierz[0][i]; //dodaj do sumy
            //suma_ujemnych = suma_ujemnych + macierz[0][i];
        }
    }
    */
    for(int i = 0; i < m; ++i){ //i to indeks wiersza, suma elementów ujemnych w ostatniej kolumnie
        if(macierz[i][n - 1] < 0){ //jesli ujemne 
            suma_ujemnych += macierz[i][n - 1]; //dodaj do sumy
        }
    }
    int ilosc = 0;//ilosc dodatnich elementow w macierzy
    for(int i = 0; i < m; ++i){ //i to indeks wiersza
        for(int j = 0; j < n; ++j){ //j to indeks kolumny
            if(macierz[i][j] > 0) ++ilosc; //jesli element jest wiekszy od zera czyli dodatni, zwieksz licznik
            //if(macierz[i][j] < 0) ++ilosc; //ujemne 
        }
    }

    *ile = ilosc; //do funkcji przekazujemy adres do zmiennej pod ktorym ma byc przechowywany wynik sprawdzania ile jest dodatnich elementow w macierzy
    //korzystamy z operatora wyluskania (dereferencji)
    return suma_ujemnych;
}