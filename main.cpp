#include <iostream>
using namespace std;

double neville(double p, const double* x, const double* y, int wezly);
bool spradzanie(double * tab, int wezly, double p);

int main() {

    double p;
    int wezly;

    cout<<"Podaj ilość węzłów: ";
    cin>>wezly;
    double x[wezly];
    double y[wezly];
    cout<<"Podaj x:"<<endl;
    for(int i = 0; i< wezly; i++){
        cout<<"Podaj wartość x"<<i+1<<": ";
        cin>>x[i];
    }

    cout<<"Podaj y:"<<endl;
    for(int i = 0; i< wezly; i++){
        cout<<"Podaj wartość y"<<i+1<<": ";
        cin>>y[i];
    }
    cout<<"Podaj punkt: ";
    cin>>p;

    if(!spradzanie(x,wezly,p)){
        cout<<"Dane nie spełniają warunków"<<endl;
        return 100;
    }

    cout<<"Wynik to: "<<neville(p, x, y, wezly)<<endl;
    return 0;
}

/*
 * Funkcja sprawdzanie odpowiedzialna jest za sprawdzanie waruków niezbędnych dla poprawnego działania algorytmu Nevilla.
 *
 */


bool spradzanie(double * tab, int wezly, double p){
    double tab1[wezly];
    bool wartosc = true;
    for(int i = 0; i< wezly; i++) {
        tab1[i] = tab[i];
    }
    for( int i = 0; i < wezly; i++ )
    {
        for( int j = 0; j < wezly - 1; j++ )
        {
            if( tab1[ j ] > tab1[ j + 1 ] )
                swap( tab1[ j ], tab1[ j + 1 ] );

        }
    }

    for(int i = 0; i < wezly-1; i++){
        if(!(tab1[i] < tab1[i + 1])){
            wartosc = false;
        }
    }
    if(!(p>=tab1[0] && p<= tab1[wezly-1])){
        wartosc = false;
    }
    return wartosc;
}

/* Funkcja neville() stosująca algorytm Neville'a do oblicznia przybliżonej wartości wielomianu w punkcjie
 Wymagane jest aby tablica x-ów była posortowana rosnąco, oraz wartość p mieściła się między największym a najmniejszym x-em.

*/

double neville(double p, const double* x, const double* y, int wezly){
    double tab[wezly][wezly];
    for(int i = 0; i < wezly; i++){
        tab[i][0] = y[i];
    }
    for(int k = 1; k< wezly; k++){
        for(int j = 0; j< wezly-k; j++){
            tab[j][k] = ((p-x[j])*tab[j+1][k-1] - (p-x[j+k])*tab[j][k-1])/(x[j+k] - x[j]);
        }
    }
    return tab[0][wezly-1];
}