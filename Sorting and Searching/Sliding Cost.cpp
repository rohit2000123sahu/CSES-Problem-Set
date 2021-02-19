// This problem is the little variation of the above problem Sliding Median.
// And the code would also be similar with little bit of modification

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
    
    ll n,k;
    cin>>n>>k;
 
    multiset< ll > small, large;
 
    ll a[n],i;
    ll sum_large=0;
    ll sum_small=0;
 
    for(i=0;i<n;i++){
        cin>>a[i];
    }
 
    ll num = ceil(k/2.0);
 
    for(i=0;i<k;i++){
        large.insert(a[i]);
    }
 
    i=0;
 
    for(auto c: large){
        if(i>=num){
            break;
        }
        small.insert(c);
        i++;
    }
 
    for(auto c: small){
        large.erase(large.find(c));
    }

    for(auto c: small){
        sum_small+=c;
    }

    for(auto c: large){
        sum_large+=c;
    }

    vl median;
    median.pb(*small.rbegin());

    vl ans;
    ans.pb(*small.rbegin()*(small.size())-sum_small+sum_large-(*small.rbegin()*large.size()));
 
    for(i=k;i<n;i++){
        if(a[i]>median.back()){
            large.insert(a[i]);         // Inserting the new element in large
            sum_large+=a[i];

            if(small.find(a[i-k])!=small.end()){
                sum_small-=a[i-k];
                small.erase(small.find(a[i-k]));

                sum_small+=*large.begin();
                small.insert(*large.begin());

                sum_large-=*large.begin();
                large.erase(large.begin());
            }else{
                sum_large-=a[i-k];
                large.erase(large.find(a[i-k]));
            }
        }else{
            small.insert(a[i]);
            sum_small+=a[i];

            if(small.find(a[i-k])!=small.end()){
                sum_small-=a[i-k];
                small.erase(small.find(a[i-k]));
            }else{
                sum_large-=a[i-k];
                large.erase(large.find(a[i-k]));

                sum_large+=*small.rbegin();
                large.insert(*small.rbegin());

                sum_small-=*(--small.end());
                small.erase(--small.end());
            }
        }
        median.pb(*small.rbegin());
        ans.pb(*small.rbegin()*(small.size())-sum_small+sum_large-(*small.rbegin()*large.size()));
    }
 
    for(auto c: ans){
        cout<<c<<" ";
    }
    cout<<endl;
 
 
    return 0;
}
