#include <iostream>

int main(){
    using namespace std;
    
    int i = 0; //zmienna przechowujaca ilosc powtorzen
    double sum = 0, zad_s; //sum - suma calkowita, zad_s - zadana suma do przekroczenia
    cout << "Podaj liczbe, ktora ma byc przekroczona: ";
    cin >> zad_s;
    while(sum < zad_s){ //dopoki nie przekroczono zadanej sumy
        ++i; //zwiekszanie zmiennej przechowujacej ilosc powtorzen
        sum += (i*i) + 2*i + 1; //obliczenie wartosci funkcji dla i
        //alternatywnie sum = sum + ((i*i) + 2*i + 1);
    } 
    cout << "Suma zadana: " << zad_s << endl //wypisanie wyników
    << "Suma calkowita: " << sum << endl 
    << "Ilosc powtorzen: " << i << endl;


    /* zadanie z wczytywaniem
    
    double temp, while_sum = 0.0, sum_nd = 0.0, mul = 1.0; //while_sum - warunek, sum_nd - suma liczb pomiedzy -10 a 15, temp - zmienna do przechowywania wczytanej liczby
    int n = 0; //zmienna do przechowywania ilosci wczytanych liczb
    cout << "Podaj liczbe: "; //komunikat
    //alternatywnie #1
    //cin >> temp;
    //koniec
    //float y = 14.4f; 
    //double x = 500.0;
    while(while_sum < 500.0 && n++ < 100 && cin >> temp){ //dopóki calkowita suma jest mniejsza od 500 I n czyli ilosc wczytanych liczb jest mniejsze od 100
        while_sum += temp; //zwiekszenie calkowitej sumy o wczytana liczbe
        if(temp >= -10 && temp <= 15){ //jesli wczytana liczba jest z przedzialu <-10, 15>, dodaj ja do drugorzednej sumy 
            sum_nd += temp;
        }
        if(temp < 0){
            mul *= temp; //jesli wczytana liczba jest ujemna przemnoz zmienna przechowujaca wynik mnozenia liczb ujemnych
        }
        cout << "Podaj liczbe: ";  //komunikat
        //cin >> temp; druga czesc alternatywy
    }
    cout << "Suma calkowita: " << while_sum << endl //wyswietlanie danych koncowych
    << "Suma -10 a 15: " << sum_nd << endl
    << "Iloczyn liczb ujemnych: " << mul << endl;

    //alternatywnie 
    //cout << "Suma calkowita: " << while_sum << endl << "Suma -10 a 15: " << sum_nd << endl << "Iloczyn liczb ujemnych: " << mul << endl;
    */
    
    return 0;
}