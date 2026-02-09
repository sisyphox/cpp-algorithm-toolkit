/**
 * @file p2580.cpp
 * @brief 测试算法：字典树测试
 * @source 洛谷 p2580
 * @see 题目链接：https://www.luogu.com.cn/problem/p2580
 */
#include<iostream>
#include<string>
#include<set>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'

const int N=1e6;
class Trie{
private:
    static int nxt[N][26];
    static int cnt[N];
    static int top;
    int root;
    int get_node(){
        return ++top;
    }
public:
    Trie(){
        root=get_node();
    }
    void insert(const string&x){
        int u=root;
        for(auto c:x){
            if(!nxt[u][c-'a']){
                nxt[u][c-'a']=get_node();
            }
            u=nxt[u][c-'a'];
        }
        cnt[u]++;
    }
    int query(const string&x){
        int u=root;
        for(auto c:x){
            if(nxt[u][c-'a']){
                u=nxt[u][c-'a'];
            }else{
                return 0;
            }
        }
        return cnt[u];
    }
};
int Trie::nxt[N][26]={0};
int Trie::cnt[N]={0};
int Trie::top=0;


void solve(){
    int n;cin>>n;
    Trie trie=Trie();
    for(int i=1;i<=n;i++){
        string x;cin>>x;
        trie.insert(x);
    }
    int m;cin>>m;
    set<string> rec;
    for(int i=1;i<=m;i++){
        string x;cin>>x;
        if(rec.count(x)){
            cout<<"REPEAT"<<endl;
        }else if(trie.query(x)){
            cout<<"OK"<<endl;
            rec.insert(x);
        }else{
            cout<<"WRONG"<<endl;
        }
    }
}

int main(){
    IOS;
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}