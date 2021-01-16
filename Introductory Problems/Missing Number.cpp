#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,i;
    cin>>n;
 
    ll temp=0,var;
 
    for(i=0;i<n;i++){
        temp=temp^(i+1);
    }
 
    for(i=0;i<n-1;i++){
        cin>>var;
        temp=temp^var;
    }
 
    cout<<temp<<"\n";
    return 0;
}
