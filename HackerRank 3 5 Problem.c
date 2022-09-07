#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin>>t;
    int n[t];
    for (int i=0; i<t; i++)
    cin>>n[i];
    for (int i=0; i<t; i++)
    {
        if(n[i]%3 == 0)
        {
            for (int j=0; j<n[i]; j++)
                cout<<'5';
            cout<<'\n';
        }
        else if (n[i]%5 == 0)
        {
            for (int j=0; j<n[i]; j++)
                cout<<'3';
            cout<<'\n';
        }
        else if (n[i] % 3 != 0 && n[i] % 5 != 0)
            {
                int t= (11%3)*3;
                int f=(11%5)*5;
                for (int i=0; i<f; i++)
                    cout<<'5';
                for (int j=0; j<t; j++)
                    cout<<'3';
                cout<<'\n';
            }
        else
        {
            cout<<'-1';
            cout<<'\n';
        }
            
    }
    
}