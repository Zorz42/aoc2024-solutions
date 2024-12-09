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
    vector<string>mat;
    while(getline(cin,s))
        mat.push_back(s);
    int w=(int)mat.size(),h=(int)mat[0].size();
    vector res(w,vector<bool>(h,false));
    for(int x1=0;x1<w;x1++){
        for(int y1=0;y1<h;y1++){
            if(mat[x1][y1]=='.')
                continue;
            for(int x2=0;x2<w;x2++){
                for(int y2=0;y2<h;y2++){
                    if(mat[x2][y2]!=mat[x1][y1]||(x1==x2&&y1==y2))
                        continue;
                    int dx=x1-x2;
                    int dy=y1-y2;
                    int nx1=x1+dx;
                    int ny1=y1+dy;
                    int nx2=x2-dx;
                    int ny2=y2-dy;
                    if(nx1>=0&&nx1<w&&ny1>=0&&ny1<h)
                        res[nx1][ny1]=true;
                    if(nx2>=0&&nx2<w&&ny2>=0&&ny2<h)
                        res[nx2][ny2]=true;
                }
            }
        }
    }
    
    int cnt=0;
    for(auto i:res)
        for(auto j:i)
            cnt+=j;
    cout<<cnt<<"\n";
}
 
int main(){
    ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}
 
/*

 */

