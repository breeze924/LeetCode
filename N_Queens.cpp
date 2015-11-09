class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        pre(n);
        vector<vector<string>> ans;
        vector<int> pos(n);
        dfs(ans,pos,n,0,0,0,0);
        return ans;
    }
    
private:
    void pre(int n) {
        bit_mask=(1<<n)-1;
        hash.resize((1<<(n-1))+1);
        for(int i=0;i<n;++i) {
            hash[1<<i]=i;
        }
    }
    
    void dfs(vector<vector<string>>& ans,vector<int>& pos,const int& n,int row,int ld,int rd,int col) {
        if(row==n) {
            ans.push_back(vector<string>());
            record_ans(pos,n).swap(ans[ans.size()-1]);
            return;
        }
        if(col!=bit_mask) {
            int avail_pos=bit_mask&~(ld|rd|col);
            while(avail_pos!=0) {
                int p=avail_pos&-avail_pos;
                avail_pos-=p;
                pos[row]=hash[p];
                dfs(ans,pos,n,row+1,(ld|p)<<1,(rd|p)>>1,col|p);
            }
        }
    }
    
    vector<string> record_ans(const vector<int>& pos,const int& n) {
        vector<string> ret(n,string(n,'.'));
        for(int i=0;i<n;++i) {
            ret[i][pos[i]]='Q';
        }
        return ret;
    }
    
    int bit_mask;
    vector<int> hash;
};

