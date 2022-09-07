#include<iostream>
#define MAX 20
void index(int arr[], int n, int k)
{
int elements [MAX], indices[MAX],temp;
int i,j=0,ind = 0,start,end;
for(int i=0;i<n;i+=3)
{
elements [ind] = arr[i];
indices [ind] = I;
ind++;
}
if(k<elements [0])
{
cout<<”Not Found”;
exit(0);
}
else
{
for(i=1;i<ind;i++)
{
if(k<elements [i])
{
start = indices [i-1];
end = indices [i];
break;
}
if(i==ind)
{
start = indices[i-1];
end = n-1;
}
}
for(i= start; i<=end;i++)
{
if(k==a[i])
{
j=1;
int p=i+1;
break;
}
}
if(j==1)
cout<<”Found at”<<p<<”Position”;
else
cout<<”Not Found”;
}

int main()
{
int n,k;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
cin>>arr[i];
cin>>k;
index(arr,n,k);
return 0;
}