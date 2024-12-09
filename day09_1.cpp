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
    cin>>s;
    vector<int>vec;
    for(int i=0;i<(int)s.size();i++){
        for(int j=0;j<s[i]-'0';j++){
            if(i%2){
                vec.push_back(-1);
            }else{
                vec.push_back(i/2);
            }
        }
    }
    while(vec.back()==-1)
        vec.pop_back();
    for(int i=0;i<(int)vec.size();i++){
        if(vec[i]==-1){
            vec[i]=vec.back();
            vec.pop_back();
            while(vec.back()==-1)
                vec.pop_back();
        }
    }
    ll res=0;
    for(int i=0;i<(int)vec.size();i++)
        res+=i*vec[i];
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

