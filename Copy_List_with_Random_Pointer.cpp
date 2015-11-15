/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*,RandomListNode*> help;
        RandomListNode* h=nullptr;
        auto p1=head;
        auto p2=h;
        for(;p1!=nullptr;p1=p1->next) {
            auto p3=new RandomListNode(p1->label);
            if(p2==nullptr) {
                p2=p3;
                h=p3;
            } else {
                p2->next=p3;
                p2=p3;
            }
            help[p1]=p3;
        }
        for(p1=head,p2=h;p1!=nullptr;p1=p1->next,p2=p2->next) {
            if(p1->random!=nullptr) {
                p2->random=help[p1->random];
            } else {
                p2->random=nullptr;
            }
        }
        return h;
    }
};

