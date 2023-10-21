#include<bits/stdc++.h>
using namespace std;

int getMin(vector<int>& parcels, int k) {
    int n = parcels.size();
    if(n == k)  return 0;
    vector<int> count(k);
    for(auto i : parcels) {
        count[i] = 1;
    }
    int cost = 0;
    int i = 1;
    while(i <= k && n!= k) {
        if(!count[i]) {
            count[i] = 1;
            cost += i;
            n++;
        }
        i++;
    }
    return cost;
}

int main() {
    vector<int> parcels = {1,2,5,6,8};
    cout<<getMin(parcels,8);
}