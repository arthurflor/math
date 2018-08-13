#include <iostream>
#include <iomanip>
#include <cmath>
#include <locale.h>

using namespace std;

double f(double x){      // fun��o f(x)
    double a = 1/(1+x*x);
    return a;
}

int main(){
    
    setlocale(LC_ALL, "Portuguese");
    
    int n;				// n � o n�mero de subdivis�es
    double a, b, h;		// a e b s�o os intervalos. h � o tamanho dos subintervalos
    
    double sum_retangulo=0, retangulo;
	double sum_trapezio=0, trapezio;
	double sum_simpson=0, simpson;
    
    cout<<"Digite o intervalo de integra��o,\na: ";
    cin>>a;											// pegando o limite inicial
    
	cout<<"b: ";
    cin>>b;							 				// pegando limite final
    
    cout<<"\nDigite o n�mero de subdivis�es: ";           
    cin>>n;											// pegando o n�mero de subdivis�es
    
    double x[n+1], y[n+1];
    h = (b-a)/n;                		// pegando o tamanho dos subintervalos
    
    for (int i=0; i<=n; i++){           // loop para pegar a �rea das subdivis�es
        x[i] = a+i*h;           		 
        y[i] = f(x[i]);
    }
    
    for (int i=1; i<n; i++){			// loop para somat�rio das �reas (ret�ngulo)
    	sum_retangulo += h*y[i];
    }
    
    for (int i=1; i<n; i++){            // loop para somat�rio das �reas (trap�zio)
        sum_trapezio += h*y[i];
    }
    
    for (int i=1; i<n; i++){			// loop para somat�rio das �reas (simpson)
        if (i%3==0)
        	sum_simpson = sum_simpson + 2*y[i];
        else
        	sum_simpson = sum_simpson + 3*y[i];
    }
    
    retangulo = h * (y[0]+y[n]) + sum_retangulo;
    trapezio = h/2 * (y[0]+y[n]) + sum_trapezio;
    simpson = 3 * h/8 * (y[0] + y[n] + sum_simpson);
    
    cout << "\n\nIntegral Definitiva\n\n";
    
	cout << " --> M�todo dos Ret�ngulos:\t" << retangulo << endl;
    cout << " --> M�todo dos Trap�zios:\t" << trapezio << endl;
    cout << " --> M�todo de Simpson:\t\t" << simpson << endl;
    cout << "\n\n";
    
    system("PAUSE");
    return 0;
}   
