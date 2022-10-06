/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {

        ListNode curr= node.next;
        node.val=curr.val;
        // 4 5 1 9
        // 4 1
        node.next=curr.next;

        //curr-> // 1 9
    }
}