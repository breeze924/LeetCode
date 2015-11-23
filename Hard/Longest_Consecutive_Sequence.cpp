class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> help;
        for(const int& val: nums) {
            help[val]=0;
        }
        int ans=1;
        for(const int& val: nums) {
            ans=max(ans,dfs(help,help.find(val)));
        }
        return ans;
    }

private:
    int dfs(unordered_map<int,int>& help,unordered_map<int,int>::iterator it) {
        if(it->second>0) {
            return it->second;
        }
        auto it2=help.find(it->first+1);
        if(it2==help.end()) {
            it->second=1;
            return 1;
        }
        dfs(help,it2);
        it->second=it2->second+1;
        return it->second;
    }
};

