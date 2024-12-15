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

void chars(stringstream&ss,int cnt){
    for(int i=0;i<cnt;i++){
        char c;
        ss>>c;
    }
}

void solve(){
    int q1=0,q2=0,q3=0,q4=0;
    string l;
    while(getline(cin,l)){
        stringstream ss(l);
        chars(ss,2);
        int ix,iy;
        ss>>ix;
        chars(ss,1);
        ss>>iy;
        chars(ss,2);
        int vx,vy;
        ss>>vx;
        chars(ss,1);
        ss>>vy;
        
        int x=(ix+100*(vx+101))%101;
        int y=(iy+100*(vy+103))%103;
        if(x<101/2&&y<103/2)
            q1++;
        if(x<101/2&&y>103/2)
            q2++;
        if(x>101/2&&y<103/2)
            q3++;
        if(x>101/2&&y>103/2)
            q4++;
    }
    cout<<1LL*q1*q2*q3*q4<<"\n";
}
 
int main(){
    ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}
 
/*

 */

