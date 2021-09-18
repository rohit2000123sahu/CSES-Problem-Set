#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define all(x) x.begin(), x.end()
#define endl '\n'
#define MOD 1000000007
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef unordered_map<ll, ll> uml;
typedef vector<pl> vpl;
typedef map<ll, ll> ml;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll n, money;
    cin >> n >> money;
 
    vl coins;
    ll i;
 
    for (i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        coins.pb(temp);
    }
 
    ll dp[money + 1];
    memset(dp, 0, sizeof(dp));
 
    dp[0] = 1;
 
    for (ll j = 0; j < n; j++)
    {
        for (i = 1; i <= money; i++)
        {
            if (i - coins[j] >= 0)
                dp[i] += dp[i - coins[j]];
            dp[i] %= MOD;
        }
    }
 
    cout << dp[money] << endl;
 
    return 0;
}
