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
    getline(cin,line);
    stringstream ss(line);
    vector<ll>vec;
    int a;
    while(ss>>a){
        vec.push_back(a);
    }
    
    int num=25;
    while(num--){
        vector<ll>nvec;
        for(ll i:vec){
            if(i==0){
                nvec.push_back(1);
                continue;
            }
            ll pw10=1;
            int pw=0;
            while(pw10<=i){
                pw10*=10;
                pw++;
            }
            if(pw%2){
                nvec.push_back(i*2024);
            }else{
                ll p20=1;
                pw/=2;
                while(pw--){
                    p20*=10;
                }
                nvec.push_back(i/p20);
                nvec.push_back(i%p20);
            }
        }
        vec=nvec;
    }
    cout<<vec.size()<<"\n";
}
 
int main(){
    ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}
 
/*

 */

