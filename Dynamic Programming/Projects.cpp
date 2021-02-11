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

struct job{
    ll s,e,profit;
};

bool comp(job j1, job j2){
    return j1.e<j2.e;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;

    job a[n];

    ll i;

    for(i=0;i<n;i++){
        cin>>a[i].s;
        cin>>a[i].e;
        cin>>a[i].profit;
    }

    sort(a,a+n,comp);

    ll dp[n];
    dp[0]=a[0].profit;

    for(i=1;i<n;i++){
        ll low=0;
        ll high=i-1;
        ll index=-1;

        ll mid;
        while(low<=high){     // Here we are seaching for an index that we can include the current job and that index;
            mid=(low+high)/2;
            if(a[mid].e<a[i].s){
                index=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        } 

        ll include=a[i].profit;  

        if(index!=-1){
            include+=dp[index]; // If we found any previous index that could be done along with this job then we will add it;
        }    

        dp[i]=max(include,dp[i-1]);   // Here we will check whether we are having maximum profit on including the current job or by excluding it.
    }


    cout<<dp[n-1]<<endl;

    return 0;
}
