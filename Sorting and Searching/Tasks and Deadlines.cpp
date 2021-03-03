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
        profit+=deadline;           // Calculatiing the maximum profit if all the task are done at time=0;
    }

    sort(duration,duration+n);      // Now to minimize the loss we should sort it in the increasing order

    ll loss=0;
    ll sum=0;                       // Total time that has been used

    for(i=0;i<n;i++){
        loss+=sum+duration[i];      // Now the loss would be total time used for previous works(i.e. sum ) and current work duration(i.e. duration[i])
        sum+=duration[i];           // Now incrementing the total time
    }

    cout<<profit-loss<<endl;        // Finally substracting the loss from the profit to get the ans


    return 0;
}
