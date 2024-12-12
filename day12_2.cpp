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

vector<string>mat;
int w,h;
vector<vector<bool>>vis;
set<pair<pair<int,int>,pair<int,int>>>fences;
int sz,per;
void dfs(int x,int y){
    if(vis[x][y])
        return;
    vis[x][y]=true;
    sz++;
    vector<pair<int,int>>nbrs={{x,y+1},{x,y-1},{x+1,y},{x-1,y}};
    for(auto[nx,ny]:nbrs){
        if(mat[nx][ny]!=mat[x][y]){
            per++;
            fences.insert({{x,y},{nx,ny}});
            continue;
        }
        dfs(nx,ny);
    }
}

void solve(){
    string s;
    while(getline(cin,s)){
        s.insert(s.begin(),'.');
        s.push_back('.');
        mat.push_back(s);
    }
    mat.push_back(string(mat[0].size(),'.'));
    mat.insert(mat.begin(),string(mat[0].size(),'.'));
    
    w=(int)mat.size();
    h=(int)mat[0].size();
    vis=vector(w,vector(h,false));
    ll res=0;
    for(int x=1;x<w-1;x++){
        for(int y=1;y<h-1;y++){
            sz=0;
            per=0;
            fences.clear();
            dfs(x,y);
            for(auto i:fences){
                int x=i.first.first;
                int y=i.first.second;
                int nx=i.second.first;
                int ny=i.second.second;
                if(x==nx){
                    per-=fences.count({{x-1,y},{nx-1,ny}});
                }else{
                    per-=fences.count({{x,y-1},{nx,ny-1}});
                }
            }
            res+=1LL*sz*per;
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
