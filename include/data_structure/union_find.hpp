#include<vector>
using namespace std;
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