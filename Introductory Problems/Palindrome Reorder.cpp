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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vl vect(26,0);

    string s;
    cin>>s;

    ll i,n=s.size();

    for(i=0;i<n;i++){
        vect[s[i]-'A']++;
    }

    ll count=0,index=0;

    for(i=0;i<26;i++){
        if(vect[i]%2!=0){
            count++;
            index=i;
        }
    }

    if(count>1){
        cout<<"NO SOLUTION";
    }else{
        vector< char > ans(n);
        ll start=0,end=n-1;
        if(vect[index]%2!=0){
            ans[n/2]=index+'A';
            vect[index]--;
        }
        for(i=0;i<26;){
            if(vect[i]>0){
                ans[start]=i+'A';
                ans[end]=i+'A';
                start++;
                end--;
                vect[i]=vect[i]-2;
            }else{
                i++;
            }
        }

        for(auto c: ans){
            cout<<c;
        }
    }




    return 0;
}
