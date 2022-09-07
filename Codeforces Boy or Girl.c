#include<stdio.h>
#include<string.h>
int main()
{
  char str[100];
  int i,j,s,c=1,temp;
  scanf("%s",&str);
  s=strlen(str);
  
  for (i = 0; i < s-1; i++) {
      for (j = i+1; j < s; j++)
      {  
        if (str[i] > str[j]) 
        {   
           temp = str[i];
            str[i] = str[j];
            str[j] = temp;
         }
      }
   }
  
  
  
  for(i=0;i<s-1;i++)
  {
     if(str[i]!=str[i+1])
      c++;
  }
   if(c%2==1)
        printf("IGNORE HIM!\n");
    else
        printf("CHAT WITH HER!\n");
    return 0;
}