class Solution {
public:
    int totalNQueens(int n) {
        bit_mask=(1<<n)-1;
        int sum=0;
        dfs(sum,0,0,0);
        return sum;
    }
    
private:    
    void dfs(int& sum,int col,int ld,int rd) {
        if(col==bit_mask) {
            ++sum;
        } else {
            int avail_pos=bit_mask&~(col|ld|rd);
            while(avail_pos!=0) {
                int p=avail_pos&-avail_pos;
                avail_pos-=p;
                dfs(sum,col|p,(ld|p)<<1,(rd|p)>>1);
            }
        }
    }
    
    int bit_mask;
};

