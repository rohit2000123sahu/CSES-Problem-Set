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
    
    ll n,i;
    cin>>n;

    ll profit=0,deadline;
    ll duration[n];

    for(i=0;i<n;i++){
        cin>>duration[i];
        cin>>deadline;
        profit+=deadline;
    }

    sort(duration,duration+n);

    ll loss=0;
    ll sum=0;

    for(i=0;i<n;i++){
        loss+=sum+duration[i];
        sum+=duration[i];
    }

    cout<<profit-loss<<endl;


    return 0;
}
