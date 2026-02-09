#include<string>
using namespace std;
const int N=1e5+100;
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