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
    vector frames(10000,vector(101,vector(103,false)));
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
        
        for(int i=0;i<10000;i++){
            int x=(ix+i*(vx+101))%101;
            int y=(iy+i*(vy+103))%103;
            frames[i][x][y]=true;
        }
    }
    for(int i=0;i<10000;i++){
        bool good=true;
        for(int y=0;y<103;y++){
            int ch=0;
            for(int x=0;x<100;x++){
                ch+=frames[i][x][y]!=frames[i][x+1][y];
            }
            if(ch>15)
                good=false;
        }
        
        if(good){
            cout<<"FRAME "<<i<<"\n";
            for(int y=0;y<103;y++){
                for(int x=0;x<101;x++){
                    cout<<(frames[i][x][y]?"#":" ");
                }
                cout<<"\n";
            }
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}
 
/*

 */

