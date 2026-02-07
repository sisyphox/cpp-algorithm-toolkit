#include<vector>
using namespace std;
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