#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>

using namespace std;

double fact(int x){
        
    double f=1.0;
    
	for (int i=1; i<=x; i++){
        f=f*i;
    }
    
    return f;
}

int main(){
    
//    double intervalo=10, x=-1, y=3, comprimento=0.1;
    
     double intervalo, x, y, comprimento;
     cout << "Intervalo: "; cin >> intervalo;
     cout << "X: "; cin >> x;
     cout << "Y: "; cin >> y;
     cout << "Comprimento: "; cin >> comprimento;
    
    cout << endl << "\tXn" << "\t\tYn"<<endl;
        
    for (int i=0; i<=intervalo; i++){
        
        cout << endl << "\t" << x <<"\t\t" << setprecision (16) << y;
        
        double y1 = cos(x) - sin(y) + pow(x,2);
        double y2 = -sin(x) - cos(y) * y1 + 2 * x;
        double y3 = -cos(x) + (sin(y))*(pow(y2,2)) - (cos(y))*y1 + 2;
        double y4 = sin(x) + (pow(y1,3)-y3) * cos(y);
        
        y += comprimento*(y1+(comprimento/2)*(y2+(comprimento/3)*(y3+(comprimento/4)*(y4))));
        x += comprimento;
        x = floor(x * 100.00 + 0.5) / 100.00;
    }
    
	cout << endl << endl;
    system("pause");
	return 0;
}
