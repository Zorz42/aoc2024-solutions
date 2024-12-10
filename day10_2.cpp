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

vector<vector<int>>mat;
vector<vector<int>>vis;
int cvis;
int res;
int w,h;

void dfs(int x,int y){
    //if(vis[x][y]==cvis)
        //return;
    vis[x][y]=cvis;
    if(mat[x][y]==9)
        res++;
    
    vector<pair<int,int>>nbrs;
    if(x>0)
        nbrs.emplace_back(x-1,y);
    if(y>0)
        nbrs.emplace_back(x,y-1);
    if(x<w-1)
        nbrs.emplace_back(x+1,y);
    if(y<h-1)
        nbrs.emplace_back(x,y+1);
    for(auto[nx,ny]:nbrs){
        if(mat[nx][ny]==mat[x][y]+1){
            dfs(nx,ny);
        }
    }
}

void solve(){
    string s;
    while(getline(cin,s)){
        mat.emplace_back();
        vis.emplace_back();
        for(char c:s){
            mat.back().push_back(c-'0');
            vis.back().push_back(0);
        }
    }
    w=(int)mat.size();
    h=(int)mat[0].size();
    for(int x=0;x<w;x++){
        for(int y=0;y<h;y++){
            if(mat[x][y]==0){
                cvis++;
                dfs(x,y);
            }
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

