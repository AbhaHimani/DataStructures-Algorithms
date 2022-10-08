/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head,ListNode nextHead) {
        ListNode curr=head;
        ListNode prev= null;
        while(curr!=nextHead){

            // 1 2 3 4 5
            //          1
            ListNode next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }
    public ListNode kthNode(ListNode curr, int k){

        while(k>1 && curr!=null){
            curr=curr.next;
            k--;
        }
        if(k==1){
            return curr;
        }
        return null;
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode curr=head;
        ListNode kh= head;
        ListNode kN= kthNode(kh,k);
        if(kN!=null){
            ListNode nextHead=kN.next;
            ListNode reverseHead=reverseList(head,nextHead);
            head.next= reverseKGroup(nextHead,k);
            return reverseHead;
        }




        return head;

    }
}