#include<stdio.h>
int main() {
  char str[1000];
  int i;
  scanf("%s",str);
  for(i=0;str[i]!='\0';i++)
  {
    if(i==0)
    {
      if((str[i]>='a' && str[i]<='z'))
      str[i]-=32;
      continue;
    }
  }
  printf("%s",str);
  return 0;
}
  