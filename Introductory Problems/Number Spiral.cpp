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

ll power(ll num, ll expo){
    if(expo==1){
        return num;
    }

    ll temp = power(num,expo/2);

    if(expo%2==0){
        return temp*temp;
    }else{
        return temp*temp*num;
    }

}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
 
    while(t--){
        ll row,col;
        cin>>row>>col;
 
        ll ans;
 
        if(row>col){
            if(row%2!=0){
                ans=power(row-1,2)+col;     //Either use your own power function or 
            }else{                          // Multiply the numbers twice
                ans=power(row,2)-col+1;     // Do not use the C++ power function becaue
            }                               // For large numbers it will not work properly even with approximations also. 
        }else{
            if(col%2!=0){
                ans=power(col,2)-row+1;
            }else{
                ans=power(col-1,2)+row;
            }
        }
 
        cout<<ans<<endl;
 
 
        
    }

    return 0;
}
