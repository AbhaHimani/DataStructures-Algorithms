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

    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq= new PriorityQueue<>((ListNode l1 ,ListNode l2)->l1.val-l2.val);
        for(ListNode list : lists){
            if(list!=null){
                pq.add(list);
            }
        }
        ListNode dummy = new ListNode(-1);
        ListNode tail = dummy;
        while(!pq.isEmpty()){
            tail.next=pq.poll();
            tail=tail.next;
            if(tail.next!=null){
                pq.add(tail.next);
            }
        }
        return dummy.next;
    }
}