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
    cout.tie(NULL);
    
    ll n;
    cin>>n;

    ll i;

    ll a[n];
    ll count[1000007]={0};

    for(i=0;i<n;i++){
        cin>>a[i];
        count[a[i]]++;
    }
    
    ll j;

    for(i=1000000;i>=1;i--){
        ll div=0;       // Consider i as max gcd then valve of div >= 2
        for(j=i;j<=1000000;j+=i){
            div+=count[j];      // Here we are adding the count of all numbers greater than i and divisible by i
        }
        if(div>1){
            cout<<i<<endl;
            break;
        }
    }


    return 0;
}
