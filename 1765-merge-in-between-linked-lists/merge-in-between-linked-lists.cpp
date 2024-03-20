/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* lower = list1;
        ListNode* upper = list1;
        int cnt = 0;
        while(temp1){
            if(a - 1 == cnt)lower = temp1;
            else if(b == cnt){
                upper = temp1->next;
                temp1->next = NULL;
            }
            temp1 = temp1->next;
            cnt++;
        }
        //del(lower->next);
        lower->next = list2;
        ListNode* temp2 = list2;
        while(temp2){
            if(!temp2->next){
                temp2->next = upper;
                break;
            }
            temp2 = temp2->next;
        }
        return list1;
    }
};