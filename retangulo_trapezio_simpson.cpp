#include <iostream>
#include <iomanip>
#include <cmath>
#include <locale.h>

using namespace std;

double f(double x){      // função f(x)
    double a = 1/(1+x*x);
    return a;
}

int main(){
    
    setlocale(LC_ALL, "Portuguese");
    
    int n;				// n é o número de subdivisões
    double a, b, h;		// a e b são os intervalos. h é o tamanho dos subintervalos
    
    double sum_retangulo=0, retangulo;
	double sum_trapezio=0, trapezio;
	double sum_simpson=0, simpson;
    
    cout<<"Digite o intervalo de integração,\na: ";
    cin>>a;											// pegando o limite inicial
    
	cout<<"b: ";
    cin>>b;							 				// pegando limite final
    
    cout<<"\nDigite o número de subdivisões: ";           
    cin>>n;											// pegando o número de subdivisões
    
    double x[n+1], y[n+1];
    h = (b-a)/n;                		// pegando o tamanho dos subintervalos
    
    for (int i=0; i<=n; i++){           // loop para pegar a área das subdivisões
        x[i] = a+i*h;           		 
        y[i] = f(x[i]);
    }
    
    for (int i=1; i<n; i++){			// loop para somatório das áreas (retângulo)
    	sum_retangulo += h*y[i];
    }
    
    for (int i=1; i<n; i++){            // loop para somatório das áreas (trapézio)
        sum_trapezio += h*y[i];
    }
    
    for (int i=1; i<n; i++){			// loop para somatório das áreas (simpson)
        if (i%3==0)
        	sum_simpson = sum_simpson + 2*y[i];
        else
        	sum_simpson = sum_simpson + 3*y[i];
    }
    
    retangulo = h * (y[0]+y[n]) + sum_retangulo;
    trapezio = h/2 * (y[0]+y[n]) + sum_trapezio;
    simpson = 3 * h/8 * (y[0] + y[n] + sum_simpson);
    
    cout << "\n\nIntegral Definitiva\n\n";
    
	cout << " --> Método dos Retângulos:\t" << retangulo << endl;
    cout << " --> Método dos Trapézios:\t" << trapezio << endl;
    cout << " --> Método de Simpson:\t\t" << simpson << endl;
    cout << "\n\n";
    
    system("PAUSE");
    return 0;
}   
