#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  
  int tamanho,cont,i,j;
     
     // número de elementos que se quer trabalhar
     printf("\nInsira o numero de valores conhecidos da funcao que deseja interpolar:\t");
     scanf("%d",&tamanho);
     printf("\n"); 
     
  float vetfx[tamanho],vetx[tamanho],x,pdtparcial,pdtfinal,fx;
     
     printf("Valores de x pre existentes:\n");
     
     // Loop para entrar com os valores de x
     for(cont=0;cont<tamanho;cont++){
        printf("Insira o valor de x%d :\t",cont);
        scanf("%f",&vetx[cont]);
     }                                
     printf("\n");   
        
          
     printf("Valores de f(x) pre existentes:\n");    
     
     // Loop para entrar com os valores de y
     for(cont=0;cont<tamanho;cont++){
        printf("Insira o valor de y%d :\t",cont);
        scanf("%f",&vetfx[cont]);
     }                                
     printf("\n");   

     // valor de x para obter f(x)
     printf("Insira o valor de x para o qual deseja obter f(x): ");
     scanf("%f",&x);
     printf("\n");
     
     fx=0;        
     pdtfinal=1;
          
     // loop de cálculos
     for(i=0;i<tamanho;i++){
       for(j=0;j<=tamanho;j++){
          if(j==i){j++;}                               // evitando a diagonal da matriz
          pdtparcial=0;
          pdtparcial=(x-vetx[j])/(vetx[i]-vetx[j]);    // realização parcial do cálculo de lagrange
          if(j!=tamanho){ pdtfinal*=pdtparcial; }      // só torna o valor parcial em final (multiplicando), 
                                                       // caso o valor de j seja diferente do tamanho
       }
       
       fx=fx+vetfx[i]*pdtfinal;                        // cáculando resultado
       pdtfinal=0;                                            
     } 

     printf("Valor de f(%f): %.4f ",x,fx);             // imprimindo resultado na tela
     printf("\n\n");
     
  system("PAUSE");    
  return 0;
}
