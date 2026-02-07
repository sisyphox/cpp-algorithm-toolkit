/**
 * @file NC_120563_B.cpp
 * @brief 测试算法：线性基
 * @source 牛客 contest/120563/B  
 * @see 题目链接：https://ac.nowcoder.com/acm/contest/120563/B
 */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD=998244353;
const int N=2e5+100;
class LinearBasis {
private:
    vector<int> mask,basis,rec;
    int cnt=0,MAX_BIT=62;
public:
    LinearBasis(){
        basis.resize(MAX_BIT+1);
        rec.resize(MAX_BIT+1); 
        mask.resize(MAX_BIT+1);
    }
    bool insert(int x,int idx){
        int cur_mask=1ll<<cnt;
        for(int i=MAX_BIT;i>=0;i--){
            if(x&(1ll<<i)){
                if(basis[i]){
                    x^=basis[i];
                    cur_mask^=mask[i];
                }else{
                    basis[i]=x;
                    mask[i]=cur_mask;
                    rec[cnt++]=idx;
                    return true;
                }   
            }
        }
        return false;
    }
    int can_achieve(int x){
        int cur_mask=0;
        for(int i=MAX_BIT;i>=0;i--){
            if(x&(1ll<<i)){
                if(basis[i]){
                    x^=basis[i];
                    cur_mask^=mask[i];
                }else{
                    return -1;
                }
            }
        }
        return cur_mask;
    }
    vector<int> convert(int mask){
        vector<int> ret;
        for(int i=MAX_BIT;i>=0;i--){
            if(mask&(1ll<<i)){
                ret.emplace_back(rec[i]);
            }
        }
        return ret;
    }
};
void solve(){
    int n;cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    int tar=0;
    for(int i=1;i<=n;i++)tar^=a[i];
    vector<int> c(n+1);
    for(int i=1;i<=n;i++)c[i]=a[i]^b[i];
    LinearBasis lb=LinearBasis();
    for(int i=1;i<=n;i++){
        lb.insert(c[i],i);
    }
    int ret=lb.can_achieve(tar);
    if(ret==-1){
        cout<<-1<<endl;
        return ;
    }
    vector<int> vis(n+1,0);
    vector<int> tmp=lb.convert(ret);
    for(auto x:tmp){
        vis[x]=1;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]){
            cout<<b[i]<<' ';
        }else{
            cout<<a[i]<<' ';
        }
    }
    cout<<endl;
}
signed main(){
    IOS;
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}