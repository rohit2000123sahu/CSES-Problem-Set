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
#define INF 1e17
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
typedef unordered_map< ll, ll > uml;
typedef vector< pl > vpl;
typedef map< ll, ll > ml;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m,q;
    cin>>n>>m>>q;

    ll mat[n+1][n+1];

    ll i,j,k;

    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            if(i==j){
                mat[i][j]=0;
                continue;
            }
            mat[i][j]=INF;
        }
    }

    ll a,b,weight;

    while(m--){
        cin>>a>>b>>weight;
        mat[a][b]=min(mat[a][b],weight);    // There might be more than one edge between two nodes hence we need to take the minimum cost between these two edges
        mat[b][a]=min(mat[b][a],weight);
    }

    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }

    while(q--){
        cin>>a>>b;
        if(mat[a][b]==INF){
            cout<<-1<<endl;
        }else{
            cout<<mat[a][b]<<endl;
        }
    }



    return 0;
}
