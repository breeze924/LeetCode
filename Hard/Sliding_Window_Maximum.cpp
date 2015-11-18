class Solution {
public:
    struct node {
        int val;
        int idx;
        node(int val_,int idx_): val(val_),idx(idx_) {
        }
    };
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<node> dq;
        for(int i=0;i<nums.size();++i) {
            while(!dq.empty() && dq.back().val<=nums[i]) {
                dq.pop_back();
            }
            dq.push_back(node(nums[i],i));
            while(dq.back().idx-dq.front().idx>=k) {
                dq.pop_front();
            }
            if(i>=k-1) {
                ans.push_back(dq.front().val);
            }
        }
        return ans;
    }
};

