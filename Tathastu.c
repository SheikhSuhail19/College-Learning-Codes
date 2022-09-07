
#include <stdio.h>

int fun(int s1,int e1) {
    if(s1 == e1)
        return s1;
    else
        return s1 + fun(s1 + 1, e1);
}

int main() {
    int e1, s1;
    e1 = 6;
    s1 = 3;
    int a = fun(s1, e1);
    printf("%d",a);
}