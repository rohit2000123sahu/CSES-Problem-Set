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
 
ll solve(ll a[], ll n, map<ll, ll> &mapping)
{
    ll i;
    vpl vect;
    for (i = 1; i <= n; i++)
    {
        vect.pb(mp(a[i], i));
    }
 
    sort(vect.begin(), vect.end());
 
    for (i = 0; i < n; i++)
    {
        mapping[vect[i].first] = vect[i].second;
    }
 
    ll ans = 0;
 
    i = 0;
    while (i < n)
    {
        i++;
        while (i < n && vect[i].second > vect[i - 1].second)
        {
            i++;
        }
        ans++;
    }
 
    return ans;
}
 
ll check(ll new_i, ll old_i, ll pivot)
{
    if (old_i < pivot && new_i >= pivot)      // This will reduce our answer by 1
    {
        return -1;
    }
    else if (new_i <= pivot && old_i > pivot)   // This will increase our answer by 1
    {
        return 1;
    }
    return 0;           // Else answer will be constant
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n, i, q;
    cin >> n >> q;
 
    ll a[n + 1];
 
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<ll, ll> mapping;                    // For finding the index of any element
    ll initial_ans = solve(a, n, mapping);
 
    ll ans = initial_ans;
  
    // Here we took only (num1-1, num1) (num1, num1+1) (num2-1,num2) (num2,num2+1)
    // Because we num1 and num2 is changed then only its previous element and next element will only play the role
 
    while (q--)
    {
        ll i1, i2;
        cin >> i1 >> i2;
 
        ll num1 = a[i1];
        ll num2 = a[i2];
 
        if (num1 > num2)                // This step ensures that num1 is always smaller than num2
        {
            swap(num1, num2);
            swap(i1, i2);
        }
 
        set<pair<ll, ll>> s;           // Set to ensure two pair are not processed again. i.e. 1,2 we may get multiple set hence for this we used this
        if (num1 != 1)
        {
            // num1-1, num1
            ans += check(i2, i1, mapping[num1 - 1]);
            s.insert(mp(num1 - 1, num1));
        }
  
        // num1 ,num1+1
        if (s.find(mp(num1, num1 + 1)) == s.end())
        {
            ans -= check(i2, i1, mapping[num1 + 1]);      // Here we have minus because pivot is grater than the element. Hence the effect will reverse therefor minus
            s.insert(mp(num1, num1 + 1));
        }
 
        // num2-1, num2
        if (s.find(mp(num2 - 1, num2)) == s.end())      // Same for num2 as we did for num1
        {
            ans += check(i1, i2, mapping[num2 - 1]);
            s.insert(mp(num2 - 1, num2));
        }
 
        // num2, num2+1
        if (s.find(mp(num2, num2 + 1)) == s.end() && num2 + 1 <= n)
        {
            ans -= check(i1, i2, mapping[num2 + 1]);
            s.insert(mp(num2, num2 + 1));
        }
      
        // Finishing
        mapping[num1] = i2;
        mapping[num2] = i1;
 
        swap(a[i1], a[i2]);
 
        cout << ans << endl;
    }
 
    return 0;
}
