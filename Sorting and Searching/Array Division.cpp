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
    
    ll n,k;
    cin>>n>>k;

    ll sum[n];      // Here the answer is between the 0 and maximum sum hence we will use the binary search here
    ll a[n],i;

    for(i=0;i<n;i++){
        cin>>a[i];
    }

    sum[0]=a[0];


    for(i=1;i<n;i++){
        sum[i]=sum[i-1]+a[i];
    }

    ll low=0;
    ll high=sum[n-1];
    ll mid,temp;

    while(low<high){
        mid=(low+high)/2;
        ll count=0;
        ll subArray=0;
        bool possible=true;
        for(i=0;i<n;){       // Checking if mid is possible or not
            temp=a[i]+subArray;
            if(temp<=mid){
                subArray+=a[i];
                i++;
            }else{
                if(subArray==0 && a[i]>mid){
                    possible=false;
                    break;
                }else{
                    count++;
                    if(count>k){
                        possible=false;
                        break;
                    }
                    subArray=0;
                }
            }
        }
        count++;              // Adding the last subarray count
        if(count>k){          // Checking the condition
            possible=false;
        }

        if(possible){       // If it is possible then we will try the lower part
            high=mid;
        }else{              // Else try the higher part
            low=mid+1;
        }
    }

    cout<<high;             

    return 0;
}
