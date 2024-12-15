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

pair<int,int>parse(string line){
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
        int cr=1e9;
        for(int i=0;;i++){
            int dx=r3.first-i*r1.first;
            int dy=r3.second-i*r1.second;
            if(dx<0||dy<0)
                break;
            if(dx%r2.first!=0||dy%r2.second!=0)
                continue;
            if(dx/r2.first!=dy/r2.second)
                continue;
            cr=3*i+dx/r2.first;
        }
        if(cr!=1e9)
            res+=cr;
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

