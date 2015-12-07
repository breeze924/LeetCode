class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int sz=nums.size();
        if(sz<2) {
            return 0;
        }
        int max_num=nums[0];
        int min_num=nums[0];
        for(const int& num: nums) {
            if(num>max_num) {
                max_num=num;
            } else if(num<min_num) {
                min_num=num;
            }
        }
        int gap=(max_num-min_num+sz-2)/(sz-1);
        if(gap==0) {
            return 0;
        }
        vector<vector<int> > buckets(sz,vector<int>(2,-1));
        for(const int& num: nums) {
            int loc=(num-min_num)/gap;
            if(buckets[loc][0]==-1 || buckets[loc][0]>num) {
                buckets[loc][0]=num;
            }
            buckets[loc][1]=max(buckets[loc][1],num);
        }
        int ans=gap;
        int cur=buckets[0][1];
        for(int i=1;i<sz;++i) {
            if(buckets[i][0]!=-1) {
                ans=max(ans,buckets[i][0]-cur);
                cur=buckets[i][1];
            }
        }
        return ans;
    }
};

