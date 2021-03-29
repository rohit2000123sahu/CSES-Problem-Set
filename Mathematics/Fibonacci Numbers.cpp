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

ml fib;

ll f(ll n){
    if(fib.find(n)!=fib.end()){
        return fib[n];
    }
    ll k=n/2;
    // This is the simple recursion formula for fibonacci series 
    if(n%2==0){
        return fib[n] = (f(k)*f(k)+f(k-1)*f(k-1))%MOD;
    }else{
        return fib[n] = (f(k)*f(k+1)+f(k-1)*f(k))%MOD; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin>>n;

    fib[0]=fib[1]=1;

    if(n==0){
        cout<<0<<endl;
        exit(0);
    }

    cout<<f(n-1)<<endl;



    return 0;
}
