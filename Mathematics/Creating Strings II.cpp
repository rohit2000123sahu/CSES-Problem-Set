// In this we have used the little fermat theorem for calculating the inverser
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

ll fact[1000001];

ll power(ll a, ll b){
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll i;
    fact[0]=1;

    for(i=1;i<=1000000;i++){
        fact[i]=i*fact[i-1];
        fact[i]%=MOD;
    }
    
    string s;

    cin>>s;
    ll n=s.size();
    ll a[26]={0};

    for(i=0;i<n;i++){
        a[s[i]-'a']++;
    }

    ll num = fact[n];

    ll deno = 1;

    for(i=0;i<26;i++){
        deno=deno*fact[a[i]];
        deno%=MOD;
    }

    ll inv = power(deno,MOD-2);

    ll ans=num*inv;
    ans%=MOD;

    cout<<ans<<endl;



    return 0;
}
