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
    public int size(ListNode head){
        int count=0;
        if(head==null){
            return 0;
        }
        else if(head.next==null){
            return 1;
        }
        else{
            while(head.next!=null ){
                count++;
                head=head.next;
            }
        }

        return count;

    }
    public int getDecimalValue(ListNode head) {
        int count=size(head);
        int ans=0;
        System.out.println(count);
        ListNode curr=head;
        if(count==0){
            return 0;
        }
        else if(count==1){
            return head.val;
        }
        else{
            while(curr!=null){
                // 0+ 1*
                ans= ans + curr.val*(int)Math.pow(2,count);
                curr=curr.next;
                count--;
            }

        }

        return ans;

    }
}