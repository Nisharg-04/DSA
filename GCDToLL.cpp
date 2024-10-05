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
 int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // Base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* temp=head->next;
        ListNode* prev=head;
        while(temp!=nullptr){
            int g=gcd(prev->val,temp->val);
            ListNode * newNode=new ListNode(g);
            prev->next=newNode;
            newNode->next=temp;
            
            prev=temp;
            temp=temp->next;

        }
        return head;
        
    }
};