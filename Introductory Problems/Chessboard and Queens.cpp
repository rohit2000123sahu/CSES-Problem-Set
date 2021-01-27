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

ll power(ll a, ll b){
    if(b==1){
        return a;
    }

    ll temp = power(a,b/2);

    if(b%2==0){
        return temp*temp;
    }else{
        return temp*temp*a;
    }
}

ll ans;
bool visited[8][8];
vector< string > vect;

bool isSafe(ll x , ll y){
    if(!visited[x][y] && vect[x][y]!='*'){
        ll k;
        for(k=0;k<8;k++){           // Checking the column
            if(visited[k][y]){
                return false;
            }
        }

        // Here we have not checked the row because we have solved it in this way only.

        // Checking all the four diagonal directions.

        ll i , j;
        i=x;
        j=y;

        while(i<8 && j<8){
            if(visited[i][j]){          
                return false;
            }
            i++;
            j++;
        }

        i=x;
        j=y;

        while(i>=0 && j<8){
            if(visited[i][j]){
                return false;
            }
            i--;
            j++;
        }

        i=x;
        j=y;

        while(i>=0 && j>=0){
            if(visited[i][j]){
                return false;
            }
            i--;
            j--;
        }

        i=x;
        j=y;

        while(i<8 && j>=0){
            if(visited[i][j]){
                return false;
            }
            i++;
            j--;
        }



        return true;        // If there is none clashing then return true; 
    }
    return false;
}

void solve(ll i){
    if(i==8){
        ans+=1;
        return;
    }
    ll k;
    for(k=0;k<8;k++){
        if(isSafe(i,k)){
            visited[i][k]=true;
            solve(i+1);
            visited[i][k]=false;
        }
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i;

    for(i=0;i<8;i++){
        string temp;
        cin>>temp;
        vect.pb(temp);
    }
    ans=0;

    memset(visited,false,sizeof(visited));

    solve(0);

    cout<<ans<<endl;

    return 0;
}
