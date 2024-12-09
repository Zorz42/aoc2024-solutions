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
    vector<vector<bool>>mat;
    int sx=0,sy=0;
    while(getline(cin,line)){
        vector<bool>vec;
        for(int i=0;i<(int)line.size();i++){
            vec.push_back(line[i]=='#');
            if(line[i]=='^'){
                sx=(int)mat.size();
                sy=i;
            }
        }
        mat.push_back(vec);
    }
    
    int w=(int)mat.size(),h=(int)mat[0].size();
    // i know there is a linear algorithm with graphs, but brute force works fine for small cases
    int res=0;
    
    for(int xi=0;xi<w;xi++){
        for(int yi=0;yi<h;yi++){
            if(yi==sy&&xi==sx)
                continue;
            if(mat[xi][yi])
                continue;
            
            mat[xi][yi]=true;
            
            int x=sx,y=sy;
            vector vis(w,vector<vector<bool>>(h,vector<bool>(4)));
            int dir=0; // 0 = up, 1 = right, 2 = down, 3 = left
            while(true){
                if(vis[x][y][dir]){
                    res++;
                    break;
                }
                vis[x][y][dir]=true;
                int dx=0,dy=0;
                if(dir==0)
                    dx=-1;
                if(dir==1)
                    dy=1;
                if(dir==2)
                    dx=1;
                if(dir==3)
                    dy=-1;
                
                int nx=x+dx,ny=y+dy;
                if(nx<0||nx>=w||ny<0||ny>=h)
                    break;
                
                if(mat[nx][ny]){
                    dir++;
                    dir%=4;
                }else{
                    x=nx;
                    y=ny;
                }
            }
            
            mat[xi][yi]=false;
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

