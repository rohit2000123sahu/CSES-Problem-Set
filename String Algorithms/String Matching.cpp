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
    
    string text;
    string pat;

    cin>>text>>pat;
    
    ll n=pat.size();

    ll lps[n];

    ll i,j;
    i=0;
    j=1;

    lps[0]=0;

    while(j<n){     // Compute LPS
        if(pat[i]==pat[j]){
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

    ll ans=0;
    ll m=text.size();
    
    i=0;
    j=0;

    while(i<m){

        if(text[i]==pat[j]){
            j++;
            i++;
        }else{
            if(j!=0){
                j=lps[j-1];
            }else{
                i++;
            }
        }

        if(j==n){
            ans++;
            j=lps[j-1];
        }
    }
   

    cout<<ans<<endl;

    return 0;
}
