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
void reverse(ListNode* head,int size){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(size--){
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        int size=2;
        ListNode* left=head;
        ListNode* right;
        ListNode* res=NULL;
        ListNode* prevleft =NULL;
        while(true){
            right=left;
            for(int i=0;i<(size-1);i++){
                if(right ==NULL){
                    break;
                }
                right=right->next;
            }
            if(right){
                ListNode* nexleft=right->next;
                reverse(left,size);
                if(prevleft){
                    prevleft->next=right;
                }
                prevleft=left;
                if(res==NULL){
                    res=right;
                }
                left=nexleft;
            }
            else{
                if(prevleft){
                    prevleft->next=left;
                }
                 if(res==NULL){
                    res=left;
                }
                break;
            }
        }
        return res;
        
    }
};
