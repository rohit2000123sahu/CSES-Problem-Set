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


    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        ll n,i;
        cin>>n;

        ll temp = (n*(n+1))/2;
        if(temp%2==0){
            vl a,b;
            cout<<"YES"<<endl;
            if(n%2!=0){
                a.pb(n);      //Push the number and reduce n by 1
                n--;
                i=1;
                while(i<=n/2){
                    b.pb(i);
                    b.pb(n+1-i);
                    i++;
                    if(i>n/2){
                        break;
                    }
                    a.pb(i);
                    a.pb(n+1-i);
                    i++;
                }
            }else{
                i=1;
                while(i<=n/2){
                    a.pb(i);
                    a.pb(n+1-i);
                    i++;
                    b.pb(i);
                    b.pb(n+1-i);
                    i++;
                }
            }

            cout<<a.size()<<endl;
            for(auto c: a){
                cout<<c<<" ";
            }
            cout<<endl;
            cout<<b.size()<<endl;
            for(auto c: b){
                cout<<c<<" ";
            }
            cout<<endl;
        }else{
            cout<<"NO"<<endl;
        }


        return 0;
    }
