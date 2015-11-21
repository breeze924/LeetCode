class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) {
            return 0;
        }
        vector<int> hi_idx;
        int n=height.size();
        hi_idx.resize(n);
        hi_idx[n-1]=n-1;
        for(int i=n-2;i>=0;--i) {
            if(height[i]>=height[hi_idx[i+1]]) {
                hi_idx[i]=i;
            } else {
                hi_idx[i]=hi_idx[i+1];
            }
        }
        int sum=0;
        for(int i=0;i<n-1;) {
            int p=hi_idx[i+1];
            int maxh=height[p];
            if(maxh<height[i]) {
                sum+=calc(height,i,p,maxh);
                i=p;
            } else {
                int j;
                for(j=i+1;height[j]<height[i];++j) {
                }
                sum+=calc(height,i,j,height[i]);
                i=j;
            }
        }
        return sum;
    }

private:
    int calc(vector<int>& height,int l,int r,int curh) {
        int sum=0;
        for(int i=l+1;i<r;++i) {
            sum+=curh-height[i];
        }
        return sum;
    }
};

