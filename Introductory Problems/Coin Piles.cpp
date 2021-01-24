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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;

    while(t--){
        ll a,b;
        cin>>a>>b;

        ll temp = a+b;

        if(temp%3==0 && a>=temp/3 && b>=temp/3){            //If total sum is divisible by 3 then we could only do it. Also in both there should be atleast total/3 coins.
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;                               // Else No
        }



        
    }




    return 0;
}
