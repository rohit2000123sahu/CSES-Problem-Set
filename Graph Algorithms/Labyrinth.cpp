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
vector< string > mat;
bool visited[1000][1000];

bool isSafe(ll x, ll y){
    if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && (mat[x][y]=='.' || mat[x][y]=='B')){
        return true;
    }
    return false;
}


pl findStart(){
    pl start;
    ll i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(mat[i][j]=='A'){
                start.F=i;
                start.S=j;
                break;
            }
        }
    }
    return start;
}

pl findFinish(){
    pl finish;
    ll i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(mat[i][j]=='B'){
                finish.F=i;
                finish.S=j;
                break;
            }
        }
    }
    return finish;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    ll i,k,j;

    for(i=0;i<n;i++){
        string temp;
        cin>>temp;
        mat.pb(temp);
    }

    memset(visited,false,sizeof(visited));

    pl parent[n][m];
    char path[n][m];
    ll dist[n][m];
    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            path[i][j]='X';
        }
    }
    
    memset(parent,-1,sizeof(parent));
    memset(dist,-1,sizeof(dist));

    pl start=findStart();

    dist[start.F][start.S]=0;
    visited[start.F][start.S]=true;
    path[start.F][start.S]='.';
    
    queue< pl > q;
    q.push(start);

    ll row[] = {-1,0,0,1};
    ll col[] = {0,-1,1,0};
    char move[] = {'U','L','R','D'};

    while(!q.empty()){
        pl temp = q.front();
        q.pop();

        if(mat[temp.F][temp.S]=='B'){
            break;
        }

        for(k=0;k<4;k++){
            ll x=temp.F+row[k];
            ll y=temp.S+col[k];
            if(isSafe(x,y)){
                visited[x][y]=true;
                q.push(mp(x,y));
                dist[x][y]=1+dist[temp.F][temp.S];
                parent[x][y] = mp(temp.F,temp.S);
                path[x][y]=move[k];
            }
        }

    }

    pl finish = findFinish();

    if(dist[finish.F][finish.S]==-1){
        cout<<"NO"<<endl;
        exit(0);
    }

    cout<<"YES"<<endl;
    cout<<dist[finish.F][finish.S]<<endl;

    stack< char > ans;

    pl temp=finish;

    while(1){
        ans.push(path[temp.F][temp.S]);
        temp=parent[temp.F][temp.S];
        if(path[temp.F][temp.S]=='.'){
            break;
        }
    }

    while(!ans.empty()){
        cout<<ans.top();
        ans.pop();
    }

    return 0;
}
