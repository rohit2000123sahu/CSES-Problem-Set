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

ll n,m;
vector< string > vect;
bool visited[1000][1000];

bool isSafe(ll x, ll y){
    if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && vect[x][y]=='.'){
        return true;
    }
    return false;
}

void dfs(ll i ,ll j){
    visited[i][j]=true;
    ll row[] = {-1,0,0,1};
    ll col[] = {0,-1,1,0};
    ll k;

    for(k=0;k<4;k++){
        if(isSafe(i+row[k],j+col[k])){
            dfs(i+row[k],j+col[k]);
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    ll i,j;

    for(i=0;i<n;i++){
        string temp;
        cin>>temp;
        vect.pb(temp);
    }

    memset(visited,false,sizeof(visited));
    ll ans=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(!visited[i][j] && vect[i][j]=='.'){
                dfs(i,j);
                ans+=1;
            }
        }
    }

    cout<<ans<<endl;





    return 0;
}
