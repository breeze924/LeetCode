class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        tag=false;
        bit_mask=(1<<9)-1;
        hash.resize((1<<8)+1);
        for(int i=0;i<9;++i) {
            hash[1<<i]=i;
        }
        emp_row.clear();
        emp_col.clear();
        vector<int> row(9,0);
        vector<int> col(9,0);
        vector<int> reg(9,0);
        for(int i=0;i<board.size();++i) {
            for(int j=0;j<board[i].size();++j) {
                if(board[i][j]=='.') {
                    emp_row.push_back(i);
                    emp_col.push_back(j);
                } else {
                    row[i]|=1<<(board[i][j]-'1');
                    col[j]|=1<<(board[i][j]-'1');
                    reg[i/3*3+j/3]|=1<<(board[i][j]-'1');
                }
            }
        }
        dfs(row,col,reg,0,board);
    }
    
private:
    void dfs(vector<int>& row,vector<int>& col,vector<int>& reg,int d,vector<vector<char>>& board) {
        if(d==emp_row.size()) {
            tag=true;
            return;
        }
        int r=emp_row[d];
        int c=emp_col[d];
        int g=r/3*3+c/3;
        int ap=bit_mask&~(row[r]|col[c]|reg[g]);
        while(ap>0) {
            int p=ap&-ap;
            ap-=p;
            board[r][c]='1'+hash[p];
            row[r]|=p;
            col[c]|=p;
            reg[g]|=p;
            dfs(row,col,reg,d+1,board);
            if(tag) {
                return;
            }
            row[r]&=~p;
            col[c]&=~p;
            reg[g]&=~p;
            board[r][c]='.';
        }
    }
    
    bool tag;
    int bit_mask;
    vector<int> hash;
    vector<int> emp_row;
    vector<int> emp_col;
};

