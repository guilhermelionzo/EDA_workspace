#include "stdio.h"
 
int f91(unsigned int p)
{
    if(p <= 100) 
        printf("f91(%d) = 91\n", p);
    
    if(p >= 101) 
        printf("f91(%d) = %d\n", p, p-10);
}
 
int main ()
{
    unsigned int a; 

    while(1)
    {
        scanf("%d",&a);
        
        if(a==0){break;}

        f91(a);
        
    }

    return 0;
}