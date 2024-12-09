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
    if(s.size()%2)
        s.push_back('0');
    vector<pair<pair<int,int>,int>>vec;
    for(int i=0;i<(int)s.size();i+=2)
        vec.emplace_back(make_pair(s[i]-'0',i/2),s[i+1]-'0');
    ll res=0;
    while(vec.size()){
        auto last=vec.back().first;
        vec.pop_back();
        bool found=false;
        for(int i=0;i<(int)vec.size();i++){
            if(vec[i].second>=last.first){
                vec.insert(vec.begin()+i+1,make_pair(last,vec[i].second-last.first));
                vec[i].second=0;
                found=true;
                break;
            }
        }
        if(!found){
            int size=0;
            for(int i=0;i<(int)vec.size();i++)
                size+=vec[i].first.first+vec[i].second;
            for(int i=0;i<last.first;i++)
                res+=last.second*(size++);
            if(vec.size())
                vec.back().second=0;
        }
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

