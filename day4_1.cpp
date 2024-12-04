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
    vector<string>vec;
    int res=0;
    while(getline(cin,s))
        vec.push_back(s);
    int w=(int)vec.size();
    int h=(int)vec[0].size();
    for(int x=0;x<w-3;x++){
        for(int y=0;y<h;y++){
            string word;
            word.push_back(vec[x][y]);
            word.push_back(vec[x+1][y]);
            word.push_back(vec[x+2][y]);
            word.push_back(vec[x+3][y]);
            res+=word=="XMAS"||word=="SAMX";
        }
    }
    
    for(int x=0;x<w;x++){
        for(int y=0;y<h-3;y++){
            string word;
            word.push_back(vec[x][y]);
            word.push_back(vec[x][y+1]);
            word.push_back(vec[x][y+2]);
            word.push_back(vec[x][y+3]);
            res+=word=="XMAS"||word=="SAMX";
        }
    }
    
    for(int x=0;x<w-3;x++){
        for(int y=0;y<h-3;y++){
            string word;
            word.push_back(vec[x][y]);
            word.push_back(vec[x+1][y+1]);
            word.push_back(vec[x+2][y+2]);
            word.push_back(vec[x+3][y+3]);
            res+=word=="XMAS"||word=="SAMX";
        }
    }
    
    for(int x=0;x<w-3;x++){
        for(int y=0;y<h-3;y++){
            string word;
            word.push_back(vec[x+3][y]);
            word.push_back(vec[x+2][y+1]);
            word.push_back(vec[x+1][y+2]);
            word.push_back(vec[x][y+3]);
            res+=word=="XMAS"||word=="SAMX";
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

