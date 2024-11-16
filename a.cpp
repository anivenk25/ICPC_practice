#include<bits/stdc++.h>
using namespace std;
#define ll long long 
typedef vector<long long> vll;

ll binExp(ll x,ll y,ll m){
    ll res=1;
    while(y){
        if(y&1){
            res=(res*x)%m;
        }
        x=(x*x)%m;
        y>>=1;
    }
    return res;
}
ll f(vll& v,ll i,ll sum,ll y,vector<vll>&dp,ll m){
   if(sum==y){
    return 1;
   }
   if(sum>y){
    return 0;
   }
   if(i>v.size()){
    return 0;
   }
   if(dp[i][y-sum]!=-1){
     return dp[i][y-sum];
   }
   ll left=f(v,i,sum+v[i],y,dp,m) %m;
   ll right=f(v,i+1,sum,y,dp,m) %m;
   return dp[i][y-sum]=(left+right)%m;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
vector<vll>dp(40,vll(4*1e6+1,-1));
int t;cin>>t;
while(t--){
    ll y;
    cin>>y;
    vll v(31);
    ll m=998244353;
    v[2]=4;
    for(int i=3;i<=30;i++){
       v[i]=((v[i-1]*2)+binExp(2,i,m))%m;
    //    cout<<v[i]<<" ";
    }
    
    cout<<f(v,2,0,y,dp,m)<<endl;
}
return 0;
}
