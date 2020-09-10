https://leetcode.com/problems/reorder-list/
I/P : 1-2-3-4-5-6
O/P  :1-6-2-5-3-4

I/P : 1-2-3-4-5
O/P  :1-5-2-4-3

class Solution {
public:

    ListNode * reverse(ListNode *head){
        ListNode *prev=NULL, *cur=head, *nxt= NULL;
        while(cur!=NULL){
            nxt = cur->next;
            cur->next = prev;
            prev= cur;
            cur= nxt;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slowPtr= head, *fastPtr=head;
        if(head==NULL)
            return;
        while(fastPtr !=NULL && fastPtr->next !=NULL && fastPtr->next->next!=NULL){
            slowPtr=slowPtr->next;
            fastPtr=fastPtr->next->next;
        }
        ListNode* l2 = slowPtr->next;
        slowPtr->next=NULL;
        ListNode* l1 = head;
        l2=reverse(l2);

        ListNode*res = new ListNode(0);
        ListNode*temp = res;
        while(l1 != NULL || l2 !=NULL){
            if(l1!=NULL){
                temp->next= l1;
                l1=l1->next;
                temp=temp->next;
            }
            if(l2!=NULL){
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
            }

        }
        temp->next=NULL;
        res=res->next;
        head=res;
    }
};
