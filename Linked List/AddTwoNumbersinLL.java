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

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode small=new ListNode(-1);
        ListNode curr=small;

        int carry=0;
        while(l1!=null || l2!=null ||carry!=0 ){
            int x=0;
            if(l1!=null){
                x=l1.val;
            }else{
                x=0;
            }
            int y=0;
            if(l2!=null){
                y=l2.val;
            }
            else{
                y=0;
            }

            int sum=x+y+carry; //


            carry=sum/10;

            curr.next= new ListNode(sum%10);
            curr=curr.next;
            if(l1!=null){
                l1=l1.next;
            }else{
                l1=null;
            }
            if(l2!=null){
                l2=l2.next;
            }
            else{
                l2=null;
            }

        }
        return small.next;
    }
}