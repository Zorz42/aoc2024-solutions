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

unordered_map<ll,ll>mp[76];
ll get(ll i,int num){
    if(num==0)
        return 1;
    if(mp[num].count(i))
        return mp[num][i];
    if(i==0){
        mp[num][i]=get(1,num-1);
        return mp[num][i];
    }
    ll pw10=1;
    int pw=0;
    while(pw10<=i){
        pw10*=10;
        pw++;
    }
    if(pw%2){
        mp[num][i]=get(i*2024,num-1);
        return mp[num][i];
    }
    ll p20=1;
    pw/=2;
    while(pw--){
        p20*=10;
    }
    mp[num][i]=get(i/p20,num-1)+get(i%p20,num-1);
    return mp[num][i];
}

void solve(){
    string line;
    getline(cin,line);
    stringstream ss(line);
    vector<ll>vec;
    int a;
    while(ss>>a){
        vec.push_back(a);
    }
    
    ll res=0;
    for(ll i:vec)
        res+=get(i,75);
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

