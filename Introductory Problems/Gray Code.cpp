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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;

    ll i,j;

    vector< string >vect;

    ll size = power(2,n);
    ll a,b,num;

    for(i=0;i<size;i++){
        string ans;
        num=i;
        for(j=0;j<n;j++){
            a=num&1;
            num=num>>1;
            b=num&1;
            ans+=(a^b)+'0';
        }
        reverse(ans.begin(),ans.end());
        vect.push_back(ans);
    }

    for(auto c: vect){
        cout<<c<<endl;
    }




    return 0;
}
