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
    string s;
    vector<int>v1,v2;
    while(getline(cin,s)){
        stringstream ss(s);
        int a,b;
        ss>>a>>b;
        v1.push_back(a);
        v2.push_back(b);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    ll res=0;
    for(int i=0;i<(int)v1.size();i++)
        res+=abs(v1[i]-v2[i]);
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

