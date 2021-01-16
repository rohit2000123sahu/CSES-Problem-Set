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
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
typedef unordered_map< ll, ll > uml;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;
 
    ll ans=1;
    ll n=s.size();
    ll i,temp=1;
 
 
    for(i=1;i<n;i++){
        if(s[i]==s[i-1]){
            temp++;
        }else{
            ans=max(ans,temp);
            temp=1;
        }
    }
 
    ans=max(ans,temp);
 
    cout<<ans<<endl;
 
    return 0;
}
