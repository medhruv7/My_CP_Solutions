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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* head_per = head;
        int size = 1;
        while(head->next != NULL){
            ++size;
            head = head->next;
        }
        // cout << size;
        int cnt = 1;
        if(size - n == 0){
            return head_per->next;
        }
        ListNode* tmp = head_per;
        while(cnt < (size - n)){
            tmp = tmp->next;
            ++cnt;
        }
        if(tmp->next != NULL)
        tmp->next = tmp->next->next;
        return head_per;
    }
};
