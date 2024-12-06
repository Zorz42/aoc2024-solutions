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
    int x=0,y=0;
    while(getline(cin,line)){
        vector<bool>vec;
        for(int i=0;i<(int)line.size();i++){
            vec.push_back(line[i]=='#');
            if(line[i]=='^'){
                x=(int)mat.size();
                y=i;
            }
        }
        mat.push_back(vec);
    }
    int w=(int)mat.size(),h=(int)mat[0].size();
    set<pair<int,int>>vis;
    int dir=0; // 0 = up, 1 = right, 2 = down, 3 = left
    while(true){
        vis.insert({x,y});
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
    
    cout<<vis.size()<<"\n";
}
 
int main(){
    ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}
 
/*

 */

