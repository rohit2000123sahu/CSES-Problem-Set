// This problem is based on the catlan number concept so please go through it once before going through this problem

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

ll fact[1000005];       // For factorial computation

ll power(ll a, ll b){   // Power function
    if(b==0){
        return 1;
    }
    ll temp = power(a,b/2);
    ll ans = temp*temp;
    ans=ans%MOD;
    if(b%2==0){
        return ans;
    }else{
        ans=ans*a;
        ans=ans%MOD;
        return ans;
    }
}

ll computeNCR(ll n, ll r){      // For computing the nCr
    ll num = fact[n];
    ll deno = fact[r]*fact[n-r];
    deno%=MOD;
    deno = power(deno,MOD-2);     // Computing the inverse modulo of the deno
    return (num*deno)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll x;
    cin>>x;

    if(x%2!=0){           // If total brackets are odd then no combinations is possible
        cout<<0<<endl;
        exit(0);
    }

    ll i;
    fact[0]=1;
    fact[1]=1;

    for(i=2;i<=1000000;i++){     // Precomputing the factorial modulus
        fact[i]=i*fact[i-1];
        fact[i]%=MOD;
    }

    // Here we need to find the valid bracket sequence
    // As we know it is the catlan number which is 2nCn-2nCn-1

    // Here n is the number of the bracket sequence

    ll n = x/2;     

    cout<<computeNCR(2*n,n)-computeNCR(2*n,n-1)<<endl;  // Formula for computing the catlan number as described above

    return 0;
}
