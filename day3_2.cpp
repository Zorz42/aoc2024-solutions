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
    bool enabled=true;
    while(getline(cin,s)){
        int n=(int)s.size();
        for(int i=0;i<n-4;i++){
            if(s.substr(i,4)=="do()"){
                enabled=true;
            }
            
            if(i<n-7&&s.substr(i,7)=="don't()"){
                enabled=false;
            }
            
            if(s.substr(i,4)=="mul("&&enabled){
                int it=i+4;
                int num1=0;
                for(int j=0;j<3;j++){
                    if(it<n&&s[it]>='0'&&s[it]<='9'){
                        num1*=10;
                        num1+=s[it]-'0';
                        it++;
                    }
                }
                if(it==n||s[it]!=',')
                    continue;
                it++;
                int num2=0;
                for(int j=0;j<3;j++){
                    if(it<n&&s[it]>='0'&&s[it]<='9'){
                        num2*=10;
                        num2+=s[it]-'0';
                        it++;
                    }
                }
                if(it==n||s[it]!=')')
                    continue;
                
                res+=num1*num2;
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

