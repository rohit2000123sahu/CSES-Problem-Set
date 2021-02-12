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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    ll x,n;
    ll pos;
    cin >> x >> n;
    set<int> s;         // To store the positions of lamps
    s.insert(0);        // Storing the initial positions of  start and end
    s.insert(x);
    multiset<int> ms;   // For storing the lengths between the two lamps
    ms.insert(x);       // Storing the initial lenth
    while(n--)
    {
        cin >> pos;
        auto it = s.lower_bound(pos);   // Finding the upper lamp;
        auto it2 = it;
        --it2;                          // Finding the lower lamp;                   
        ms.erase(ms.find(*it - *it2));  // Erasing the original length in multiset
        ms.insert(pos - *it2);          // Inserting the new lenths in multiset
        ms.insert(*it - pos);
        cout << *ms.rbegin() << " ";
        s.insert(pos);
    }



    return 0;
}
