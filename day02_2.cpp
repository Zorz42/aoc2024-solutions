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
    int res=0;
    while(getline(cin,s)){
        stringstream ss(s);
        vector<int>vec1;
        int a;
        while(ss>>a)
            vec1.push_back(a);
        // just brute force, it's a small enough dataset (i know there is a O(n) solution, I am just too lazy to do it)
        
        bool r=false;
        for(int j=0;j<(int)vec1.size();j++){
            vector<int>vec=vec1;
            vec.erase(vec.begin()+j);
            bool g1=true,g2=true;
            for(int i=0;i<(int)vec.size()-1;i++){
                int diff=vec[i]-vec[i+1];
                if(diff<1||diff>3)
                    g1=false;
                if(-diff<1||-diff>3)
                    g2=false;
            }
            r=r||(g1||g2);
        }
        res+=r;
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

