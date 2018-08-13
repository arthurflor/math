#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define e 0.0005

using namespace std;

int main() {
    
    float a[100][100], x[100], big, temp, relerror, sum;
    int n, i, j, maxit=20, itr;

    printf("\nDigite o número de equações: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        for(j=1;j<=n+1;j++){
            printf("Valor da posição [%d][%d]= ", i, j);
            scanf("%f",&a[i][j]);
        }
    }

    for(i=1; i<=n; i++){
        x[i]=0;
    }
    
    for(itr=1; itr<=maxit; itr++){
        big=0;
        
        for(i=1; i<=n; i++){
            sum=0;
            
            for(j=1; j<=n; j++){
                if(i!=j){
                    sum += a[i][j] * x[j];
                }
            }
    
            temp = (a[i][n+1] - sum)/a[i][i];            
            relerror = fabs((x[i]-temp)/temp);
            
            if(relerror>big){
                big=relerror;
            }
            
            x[i]=temp;
            printf("\nx[%d] = %f", i, x[i]);
            
        } printf("\n");
        
        if(big<=e){
            printf("\n\nResultado através do método de Jacobi:");
            
            for(i=1; i<=n; i++){
                printf("\n%.6f\t",x[i]);
            }
            
            printf("\n\n");
            system("PAUSE");
            return 0;
        }
     }
//   printf("does not converge in %d iteration \n",maxit);
 }
