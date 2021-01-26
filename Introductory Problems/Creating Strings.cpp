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
#define INF 10000000000
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
typedef unordered_map< ll, ll > uml;
typedef vector< pl > vpl;

ll power(ll a, ll b){
    if(b==1){
        return a;
    }

    ll temp = power(a,b/2);

    if(b%2==0){
        return temp*temp;
    }else{
        return temp*temp*a;
    }
}

ll n;

void solve(ll i, string s, set< string > &uset){
    ll j;
    if(i>=n){
        uset.insert(s);
        return;
    }

    for(j=i;j<n;j++){
        swap(s[i],s[j]);
        solve(i+1,s,uset);
        swap(s[i],s[j]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;

    set< string > uset;
    n=s.size();

    solve(0,s,uset);

    cout<<uset.size()<<endl;

    for(auto c: uset){
        cout<<c<<endl;
    }




    return 0;
}
