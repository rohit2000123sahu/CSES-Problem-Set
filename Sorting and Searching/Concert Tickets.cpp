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
    
    ll n,m,i,temp;
    cin>>n>>m;

    multiset< ll, greater< ll > > concert_tickets;

    for(i=0;i<n;i++){
        cin>>temp;
        concert_tickets.insert(temp);
    }

    for(i=0;i<m;i++){
        cin>>temp;
        auto itr = concert_tickets.lower_bound(temp);

        if(itr==concert_tickets.end()){
            cout<<"-1"<<endl;
        }else{
            cout<<*itr<<endl;
            concert_tickets.erase(itr);
        }
    }



    return 0;
}
