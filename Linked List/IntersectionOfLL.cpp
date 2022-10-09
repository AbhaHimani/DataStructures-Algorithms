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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> data;
        ListNode* x=headA;
        ListNode* y=headB;
         while(x || y){
           if(x){
               data[x]++;
               if(data[x]==2) return x;
               x=x->next;
           }
            if(y){
                data[y]++;
                if(data[y]==2) return y;
                y=y->next;
            }
        }
        return NULL;
    }
};