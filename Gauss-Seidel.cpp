#include <cstdlib>
#include <stdio.h>
#include <math.h>
#define e 0.0005

using namespace std;

int main(){
    
 int i, j, k, n;
 float a[100][100], x[100];
 float sum, temp, error, big; 
 
 printf("Digite o número de equações: ");
 scanf("%d",&n) ;
 
 for(i=1;i<=n;i++){
    for(j=1;j<=n+1;j++){
        printf("Valor da posição [%d][%d]= ", i, j);
        scanf("%f",&a[i][j]);
    }
 }
 
 for(i=1;i<=n;i++){
    x[i]=0;
 }
 
 do{
    big=0;
    for(i=1;i<=n;i++){
        sum=0;
        
        for(j=1;j<=n;j++){
            if(j!=i){
                sum=sum+a[i][j]*x[j];
            }
        }
        
        temp=(a[i][n+1]-sum)/a[i][i];
        error=fabs(x[i]-temp);
        
        if(error>big){
            big=error;
        }
 
        x[i]=temp;
        printf("\nx[%d] = %f",i,x[i]);
        
    }printf("\n");
    
 } while(big>=e);

 printf("\n\nResultado através do método de Gauss-Seidel:");
 
 for(i=1;i<=n;i++){
    printf("\nx[%d]=%f",i,x[i]);
 }
 
 printf("\n\n");
 system("PAUSE");
 return 0;
}
