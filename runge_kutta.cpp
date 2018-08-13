#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>

using namespace std;

double fe(int op, double x, double y){
    
    if (op==1) 
        return (3 + x - y);
    
    else if (op==2) 
        return (1 - x + 4 * y);
    
    return 0;
}

int main(){
    
//    double intervalo=1, x=0, y=1, comprimento=0.1;
    double intervalo, x, y, comprimento;
    int op;
   
    while (true){
            cout << "Equacoes: " << endl;
            cout << "(1) y' = 3 + t - y" << endl;
            cout << "(2) y' = 1 - t + 4y" << endl << endl;
            cout << "Digite o numero da opcao: ";
            cin >> op;
            if (op!=1 && op!=2){
                cout << "Opcao incorreta! Escolha novamente.." << endl << endl;
            } else break;
    }
     
    cout << endl << "t: "; cin >> x;
    cout << "y: "; cin >> y; 
    cout << "Intervalo (n): "; cin >> intervalo;
    cout << "Comprimento (h): "; cin >> comprimento;
   
    if (intervalo==0) intervalo=1;
    cout << endl << "######################################" << endl;
    cout << endl << "\tXn" << "\t\tYn (Runge-kutta)"<<endl;
        
    for (int i=0; i<=intervalo; i++){
        
        cout << endl << "\t" << x <<"\t\t" << setprecision (16) << y;
        
        double y1 = comprimento * fe(op, x, y);
        double y2 = comprimento * fe(op, x + (0.5 * comprimento), y + (0.5 * y1));
        double y3 = comprimento * fe(op, x + 0.5 * comprimento, y + 0.5 * y2);
        double y4 = comprimento * fe(op, x + comprimento, y + y3);
        
        y += ((1.0/6.0) * (y1 + 2 * y2 + 2 * y3 + y4));
        x += comprimento;
        x = floor(x * 100.00 + 0.5) / 100.00;
    }
    
    cout << endl << endl;
    system("pause");
    return 0;
}
