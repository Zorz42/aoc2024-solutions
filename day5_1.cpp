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
    vector<pair<int,int>>vec;
    map<pair<int,int>,int>mp;
    while(getline(cin,s)){
        if(s.empty())
            break;
        stringstream ss(s);
        int a,b;
        char c;
        ss>>a>>c>>b;
        vec.emplace_back(a,b);
        mp[{b,a}]=1;
        //cout<<b<<" "<<a<<"\n";
    }
    
    int res=0;
    while(getline(cin,s)){
        vector<int>arr;
        for(int i=0;i<s.size();i+=3){
            arr.push_back((s[i]-'0')*10+(s[i+1]-'0'));
            //cout<<arr.back()<<" ";
        }
        //cout<<"\n";
        int valid=1;
        for(int i=0;i<(int)arr.size();i++){
            for(int j=i+1;j<(int)arr.size();j++){
                if(mp[{arr[i],arr[j]}]==1){
                    //cout<<"found "<<arr[i]<<" "<<arr[j]<<"\n";
                    valid=0;
                }
            }
        }
        //cout<<valid<<"\n";
        res+=valid*arr[(int)arr.size()/2];
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

