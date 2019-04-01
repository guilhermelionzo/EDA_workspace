#include "stdio.h"
 #include <math.h>

int power(int base, int exp) {
    if (exp == 0)
        return 1;
    else if (exp % 2)
        return base * power(base, exp - 1);
    else {
        int temp = power(base, exp / 2);
        return temp * temp;
    }
}

int main ()
{   
    int i=0;

    while(1)
    {   
        int a; 
        
        scanf("%d",&a);
        
        if(a==0){break;}

        if(a>30){

        }else{

            printf("Teste %d\n%d\n\n",++i,power(2,a)-1);
        }

        
    }

    return 0;
}