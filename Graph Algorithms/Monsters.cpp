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
vpl monsters;
 
bool isSafe(ll x, ll y){
    if(x>=0 && x<n && y>=0 && y<m && (mat[x][y]=='.' || mat[x][y]=='A') ){
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

void findMonsters(){
    ll i,j;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(mat[i][j]=='M'){
                monsters.pb(mp(i,j));
            }
        }
    }
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

    findMonsters();             // Finding all the postions of the monsters
 
    pl parent[n][m];            // For parent 
    char path[n][m];            // For printing the ans
    ll dist[n][m];              // For storing the dist while doing BFS for A

    ll time[n][m];              // It is for monster It stores the minimum time reaching the particular cell
    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            path[i][j]='X';
        }
    }

    
    memset(parent,-1,sizeof(parent));
    memset(dist,-1,sizeof(dist));
    memset(time,-1,sizeof(time));

    ll row[] = {-1,0,0,1};
    ll col[] = {0,-1,1,0};

    queue< pair< pl, ll > > q2;

    for(auto c: monsters){
        time[c.F][c.S]=0;
        q2.push(mp(c,0));
    }

    while(!q2.empty()){
        pair< pl, ll > temp = q2.front();;
        q2.pop();

        ll x1=temp.F.F;
        ll y1=temp.F.S;

        for(k=0;k<4;k++){
            if(isSafe(x1+row[k],y1+col[k]) && time[x1+row[k]][y1+col[k]]==-1){
                time[x1+row[k]][y1+col[k]]=1+temp.S;
                q2.push(mp(mp(x1+row[k],y1+col[k]),1+temp.S));
            }
        }
        
    }

    
 
    pl start=findStart();
    pl finish;
    finish.F=-1;
    finish.S=-1;
 
    dist[start.F][start.S]=0;
    path[start.F][start.S]='.';
    
    queue< pl > q;
    q.push(start);
    
    char move[] = {'U','L','R','D'};
 
    while(!q.empty()){
        pl temp = q.front();
        q.pop();
 
        if(temp.F==0 || temp.F==n-1 || temp.S==0 || temp.S==m-1){
            finish.F=temp.F;
            finish.S=temp.S;
            break;
        }
 
        for(k=0;k<4;k++){
            ll x=temp.F+row[k];
            ll y=temp.S+col[k];
            if(isSafe(x,y) && dist[x][y]==-1 && (time[x][y]==-1 || time[x][y]>1+dist[temp.F][temp.S]) ){
                q.push(mp(x,y));
                dist[x][y]=1+dist[temp.F][temp.S];
                parent[x][y] = mp(temp.F,temp.S);
                path[x][y]=move[k];
            }
        }
 
    }
 
    
 
    if(finish.F==-1 && finish.S==-1){
        cout<<"NO"<<endl;
        exit(0);
    }
 
    cout<<"YES"<<endl;
    cout<<dist[finish.F][finish.S]<<endl;

    if(dist[finish.F][finish.S]==0){
        exit(0);
    }
 
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
