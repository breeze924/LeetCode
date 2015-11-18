class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        for(int i=0;i<words.size();) {
            int sum_len=0;
            int cnt;
            int j;
            for(j=i,cnt=0;j<words.size();++j) {
                int tmp=sum_len+words[j].length()+cnt;
                if(tmp>maxWidth) {
                    break;
                }
                sum_len+=words[j].length();
                ++cnt;
            }
            --cnt;
            int num_spaces;
            int extra_spaces;
            int last_spaces;
            if(cnt==0 || j==words.size()) {
                num_spaces=1;
                extra_spaces=0;
                last_spaces=maxWidth-sum_len-cnt;
            } else {
                num_spaces=(maxWidth-sum_len)/cnt;
                extra_spaces=(maxWidth-sum_len)%cnt;
                last_spaces=0;
            }
            char tmp[maxWidth+1];
            auto p=tmp;
            for(int k=i;k<j-1;++k) {
                for(int s=0;s<words[k].length();++s) {
                    *p=words[k][s];
                    ++p;
                }
                for(int s=0;s<num_spaces;++s) {
                    *p=' ';
                    ++p;
                }
                if(k-i<extra_spaces) {
                    *p=' ';
                    ++p;
                }
            }
            for(int s=0;s<words[j-1].length();++s) {
                *p=words[j-1][s];
                ++p;
            }
            for(int s=0;s<last_spaces;++s) {
                *p=' ';
                ++p;
            }
            *p='\0';
            ans.push_back(tmp);
            i=j;
        }
        return ans;
    }
};

