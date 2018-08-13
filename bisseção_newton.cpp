#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

double f(double x, double numero){
 return x*x - numero;
}

double der_f(double x){
    return 2.0f*x*x;
}

int bissecao(double tolerancia, double intervaloA, double intervaloB, double media_intervalo, double numero){
 
    cout << endl << "Método Bisseção\n" << "IntervaloA |" << "     Média    |" << "  IntervaloB  |" << "   Tolerância" << endl;
    while(fabs(f(media_intervalo, numero)) > tolerancia){
        
        if(f(intervaloA, numero)*f(media_intervalo, numero)<0.0f){
            intervaloB = media_intervalo;
        }
        else{
            intervaloA = media_intervalo;
        }
        
        media_intervalo = (intervaloA+intervaloB)/2.0f;
        printf("%f   |   %f   |   %f   |   %f", intervaloA, media_intervalo, intervaloB, f(media_intervalo, numero));
        cout << endl;
    }
    
    cout << endl << "Erro inferior a " << tolerancia << "\n" << "Raíz de "<< numero <<" pelo método de bisseção: "<< media_intervalo << endl;
    return 0;
}

int newton(double tolerancia, double x_new, double x_old, double numero){
    
    cout << endl << "Método Newton\n" << "Nº Antigo  |" << "   Nº Novo    |" << "  Tolerância  |" << "   Derivada" << endl;
    while(fabs(f(x_new, numero)) > tolerancia){
        x_new = x_old - f(x_old, numero)/der_f(x_old);
        printf("%f   |   %f   |   %f   |   %f\n", x_old, x_new, f(x_new, numero), der_f(x_new));
        x_old = x_new;
    }
    
    cout << endl << "Erro inferior a " << tolerancia << "\n" << "Raíz de "<< numero <<" pelo método de newton: "<< x_new << endl << endl;
    return 0;
}

int main(){
    double tolerancia=0.0005f, intervaloA=1.0f, intervaloB, media_intervalo, numero;
 
    cout << "Número: "; cin >> numero;
    intervaloB = numero/2;
    media_intervalo = (intervaloA + intervaloB)/2.0f;

    bissecao(tolerancia, intervaloA, intervaloB, media_intervalo, numero);
    cout << endl;
    newton(tolerancia, 1, 1, numero);
    
    system("PAUSE");
    return 0;
}
