#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define all(x) x.begin(),x.end()
#define endl '\n'
#define MOD 1000000007
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
typedef unordered_map< ll, ll > uml;
typedef vector< pl > vpl;
typedef map< ll, ll > ml;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,k;
    cin>>n>>k;

    multiset< ll > small, large;

    ll a[n],i;

    for(i=0;i<n;i++){
        cin>>a[i];
    }

    ll num = ceil(k/2.0);

    for(i=0;i<k;i++){
        large.insert(a[i]);
    }

    i=0;

    for(auto c: large){
        if(i>=num){
            break;
        }
        small.insert(c);
        i++;
    }

    for(auto c: small){
        large.erase(large.find(c));
    }

    vl median;
    median.pb(*small.rbegin());

    for(i=k;i<n;i++){
        if(a[i]>median.back()){
            large.insert(a[i]);         // Inserting the new element in large
            if(small.find(a[i-k])!=small.end()){    // Removing the element which should no longer present in window
                small.erase(small.find(a[i-k]));
                small.insert(*large.begin());
                large.erase(large.begin());
            }else{
                large.erase(large.find(a[i-k]));
            }
            median.pb(*small.rbegin());
        }else{
            small.insert(a[i]);
            if(small.find(a[i-k])!=small.end()){
                small.erase(small.find(a[i-k]));
            }else{
                large.erase(large.find(a[i-k]));
                large.insert(*small.rbegin());
                small.erase(--small.end());// Note here we can not use small.erase(small.rbegin()); it will give error or seg fault
            }
            median.pb(*small.rbegin());
        }
    }

    for(auto c: median){
        cout<<c<<" ";
    }


    return 0;
}
