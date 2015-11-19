/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || k==1) {
            return head;
        }
        auto p1=head;
        auto p2=head;
        ListNode *pre_p1=nullptr;
        for(;p2!=nullptr;) {
            int cnt=1;
            for(p2=p2->next;p2!=nullptr;p2=p2->next) {
                ++cnt;
                if(cnt==k) {
                    break;
                }
            }
            if(cnt==k) {
                auto p3=p1;
                auto p4=p1->next;
                auto p5=p4->next;
                auto ed=p2->next;
                p3->next=p2->next;
                p4->next=p3;
                for(;p5!=ed;) {
                    p3=p4;
                    p4=p5;
                    p5=p5->next;
                    p4->next=p3;
                }
                if(pre_p1!=nullptr) {
                    pre_p1->next=p2;
                } else {
                    head=p2;
                }
                pre_p1=p1;
                p1=p1->next;
                p2=p1;
            }
        }
        return head;
    }
};

