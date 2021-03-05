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

string s;
vl vect;
ll lps[1000005];

void solve(ll n){           // In this function we will find the lps of the string and then  recursively find the lps of the smaller sub string of size lps[n-1];
    if(n>0 && lps[n-1]!=0){
        vect.pb(lps[n-1]);
        solve(lps[n-1]);        
    }
}

void computeLPS(ll n){      // It is for computing the lps of the array(longest prefix which is suffix)
    ll i;
    ll j;

    i=0;
    j=1;
    lps[0]=0;
    while(j<n){
        if(s[i]==s[j]){
            i++;
            lps[j]=i;
            j++;
        }else{
            if(i!=0){
                i=lps[i-1];
            }else{
                lps[j]=0;
                j++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>s;
    ll n=s.size();
    
    computeLPS(n);

    solve(n);

    sort(all(vect));
    for(auto c: vect){
        cout<<c<<" ";
    }

    


    return 0;
}
