/**
 * @file P3367.cpp
 * @brief 测试算法：并查集基础实现
 * @source 洛谷 P3367 【模板】并查集
 * @see 题目链接：https://www.luogu.com.cn/problem/P3367
 */
#include<iostream>
#include<vector>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
class DSU{
private:
    vector<int> pa;
public:
    DSU(int sz){
        pa.resize(sz);
        for(int i=1;i<sz;i++)pa[i]=i;
    }
    int get(int x){
        if(x!=pa[x])pa[x]=get(pa[x]);
        return pa[x];
    }
    void merge(int a,int b){
        pa[get(a)]=get(b);
    }
    bool is_same(int a,int b){
        return get(a)==get(b);
    }
};

void solve(){
    int n,m;cin>>n>>m;
    DSU dsu(n+1);
    for(int i=1;i<=m;i++){
        int op,u,v;cin>>op>>u>>v;
        if(op==1){
            dsu.merge(u,v);
        }else{
            if(dsu.is_same(u,v))cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
}
signed main(){
    IOS;
    int t=1;
//    cin>>t;
    while(t--)solve();
    return 0;
}