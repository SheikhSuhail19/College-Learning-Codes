#include<bits/stdc++.h>
using namespace std;
int main()
{
    int apple=0,orange=0;
    long int s,t,a,b,m,n;
    cin>>s>>t>>a>>b>>m>>n;
    long int da[m],d[n];
    for(int i=0;i<m;i++)
    {
        cin>>da[i];
        da[i] = a + da[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>d[i];
        d[i] = b + d[i];
    }
    for(int i=0;i<m;i++)
            if(((a+da[i]) >= s) && ((a+da[i]) <=t))
                apple++;
    for(int i=0;i<n;i++)
            if(((a+d[i]) >= s) && ((a+d[i]) <=t))
                orange++;
    cout<<apple<<'\n'<<orange;
}