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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode ans= new ListNode(-1);
        ListNode list3=ans;
        // 1 2 4
        // 1 3 4
        // 1 1 2 3 4 4
        if(list1==null && list2==null){
            return null;
        }
        else if(list1==null && list2!=null){
            return list2;
        }
        else if(list2==null && list1!=null){
            return list1;
        }
        else{
            while(list1!=null &&list2!=null){


                // 1 2 3
                // 1 3 4
                //1

                if(list1.val<=list2.val){
                    list3.next=list1; //
                    list1=list1.next;
                    list3=list3.next;
                }

                else{
                    list3.next=list2;
                    // list3.next.next=list2;
                    // list1=list1.next;
                    list2=list2.next;
                    list3=list3.next;
                }
                if(list1==null){
                    list3.next=list2;
                }
                if(list2==null){
                    list3.next=list1;
                }
            }


        }

        return ans.next;
    }
}