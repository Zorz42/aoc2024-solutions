#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<limits.h>
#include<math.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<iomanip>
#include<cstring>
#include<random>
#include<cassert>
#include<sstream>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

void solve(){
    string line;
    ll res=0;
    while(getline(cin,line)){
        ll r;
        stringstream ss(line);
        ss>>r;
        vector<ll>vec;
        ll a;
        char c;
        ss>>c;
        while(ss>>a)
            vec.push_back(a);
        /*cout<<r<<": ";
        for(ll i:vec)
            cout<<i<<" ";
        cout<<"\n";*/
        
        unordered_set<ll>v={0};
        for(ll i:vec){
            unordered_set<ll>v2;
            for(ll i2:v){
                if(i2+i<=r)
                    v2.insert(i2+i);
                if(i2*i<=r)
                    v2.insert(i2*i);
            }
            v=v2;
        }
        res+=v.count(r)*r;
    }
    cout<<res<<"\n";
}
 
int main(){
    ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}
 
/*

 */

