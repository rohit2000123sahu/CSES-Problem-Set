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

ll findIndex(vl &last_element, ll l , ll r, ll value){
    ll mid;
    while(l<r){
        mid=l+(r-l)/2;
        if(last_element[mid]>=value){
            r=mid;
        }else{
            l=mid+1;
        }
    }

    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;

    vl vect(n+1);

    ll i;

    for(i=1;i<=n;i++){
        cin>>vect[i];
    }

    ll length=1;
    vl last_element(n+1,0);       // This vector is used to represent the last element at every possible length
    
    last_element[1]=vect[1];

    for(i=2;i<=n;i++){
        if(last_element[1]>vect[i]){
            last_element[1]=vect[i];
        }else if(vect[i]>last_element[length]){
            length++;
            last_element[length]=vect[i];
        }else{
            // In this case the element need to be added in the existing list.
            // So we will find the index using binary search because all the elements are sorted

            ll index = findIndex(last_element,1,length,vect[i]);
            last_element[index]=vect[i];
        }
    }

    cout<<length<<endl;


    return 0;
}
