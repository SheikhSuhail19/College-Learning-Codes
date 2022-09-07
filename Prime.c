#include <stdio.h>  
int main()  
{  
    long int ct=0,j=1;
    long int n=0,i=1,p;  
    scanf("%ld",&p);
    while(n<p)  
    {  
        j=1;  
        ct=0;  
        while(j<=i)  
        {  
            if(i%j==0)  
            ct++;  
            j++;   
        }  
        if(ct==2)  
        {  
            printf("%ld ",i);  
            n++;  
        }  
        i++;  
}  
}  
