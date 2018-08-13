#include <iostream>
#include <iomanip>
#include <cmath>
#include <locale.h>

using namespace std;

int main(){
    
    setlocale(LC_ALL, "Portuguese");
    
    int i,j,k,n=100;
    double x[n],y[n],a,b;
    double xsum=0,x2sum=0,ysum=0,xysum=0;
    double y_fit[n];
    
    // número de elementos que se quer trabalhar
    cout<<"\nDigite o número de pontos (x,y) a serem inseridos: ";
    cin>>n;
    
    // Loop para entrar com os valores de x e y
    for (i=0;i<n;i++){
    	cout << "\n";
    	
        cout << "Insira o valor de x" << i << ": ";
        cin>>x[i];
        
        cout << "Insira o valor de y" << i << ": ";
        cin>>y[i];
    }
    
    //cout << "\nx^2" << "\txy" << "\n";
    //cout<<"-----------------\n";
    
    // Loop de cálculos
    for (i=0;i<n;i++){
        xsum = xsum+x[i];             // calculando somatório de x 
        ysum = ysum+y[i];             // calculando somatório de y 
        x2sum = x2sum+pow(x[i],2);    // calculando somatório de xÂ²
        xysum = xysum+x[i]*y[i];      // calculando somatório de x * y
        //cout << pow(x[i],2) << "\t" << x[i]*y[i] << "\n";   // imprimindo resultados
    }
    
    a = (n*xysum-xsum*ysum)/(n*x2sum-xsum*xsum);            // calculando o declive
    b = (x2sum*ysum-xsum*xysum)/(x2sum*n-xsum*xsum);        // calculando intercepção
    
    for (i=0;i<n;i++){
        y_fit[i] = a*x[i]+b;                    // array para armazenar os novos valores ajustados de y
    }
    
    cout<<"\nN.   "<<setw(5)<<"x"<<setw(19)<<"y(observado)"<<setw(19)<<"y(ajustado)"<<endl;
    cout<<"-----------------------------------------------------------------\n";
    
	for (i=0;i<n;i++){
        cout<<i+1<<"."<<setw(8)<<x[i]<<setw(14)<<y[i]<<setw(19)<<y_fit[i]<<endl;        // imprimindo resultado em tabela
    }
    
    cout<<"\nReta linear: \ny = "<<a<<"x + "<<b<<"\n"<<endl;                // imprimindo equação da reta linear
    
    system("PAUSE");
    return 0;
}   
