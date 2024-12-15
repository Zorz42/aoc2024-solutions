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

pair<ll,ll>parse(string line){
    vector<int>res;
    for(char c:line){
        if(c>='0'&&c<='9'){
            res.back()=10*res.back()+c-'0';
        }else{
            if(res.empty()||res.back()!=0)
                res.push_back(0);
        }
    }
    return{res[0],res[1]};
}

int gcd(int a,int b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

void solve(){
    ll res=0;
    while(true) {
        string l1,l2,l3,un;
        if(!getline(cin,l1))
            break;
        getline(cin,l2);
        getline(cin,l3);
        getline(cin,un);
        auto r1=parse(l1);
        auto r2=parse(l2);
        auto r3=parse(l3);
        r3.first+=10000000000000LL;
        r3.second+=10000000000000LL;
        
        // i*r1 + j*r2 = r3
        // i*r1.first + j*r2.first = r3.first
        // i=(r3.first-j*r2.first)/r1.first
        // (r3.first-j*r2.first)/r1.first*r1.second + j*r2.second = r3.second
        // r3.first/r1.first*r1.second - j*r2.first/r1.first*r1.second + j*r2.second = r3.second
        // j*(r2.second - r2.first/r1.first*r1.second) = r3.second - r3.first/r1.first*r1.second
        // j = (r3.second*r1.first - r3.first*r1.second)/(r2.second*r1.first - r2.first*r1.second)
        
        if((r3.second*r1.first - r3.first*r1.second)%(r2.second*r1.first - r2.first*r1.second))
            continue;
        ll j=(r3.second*r1.first - r3.first*r1.second)/(r2.second*r1.first - r2.first*r1.second);
        if((r3.first-j*r2.first)%r1.first)
            continue;
        ll i=(r3.first-j*r2.first)/r1.first;
        
        res+=j+3*i;
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

