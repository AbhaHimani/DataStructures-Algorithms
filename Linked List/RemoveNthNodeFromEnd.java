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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // 1 2 3 4 5
        // 1 2 3 5
        if(head.next==null && n==1) return null;

        ListNode fast=head;
        for(int i=0;i<n;i++){
            fast=fast.next;
        }
        ListNode slow=head;
        if (fast == null) {
            return head.next;
        }
        while(fast.next!=null){
            fast=fast.next;
            slow=slow.next;
        }
        slow.next=slow.next.next;
        return head;

    }
}