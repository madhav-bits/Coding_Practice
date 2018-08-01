package CTCI.Linked_List;


/*
 * 
 * 2-3)Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
	EXAMPLE
	Input: the node ‘c’ from the linked list a->b->c->d->e
	Result: nothing is returned, but the new linked list looks like a->b->d->e
 * 
 * 
 * 
 * //Time Complexity: O(1).												
   //Space Complexity: O(1).
 *
 */
 


//Time Complexity: O(1).													
//Space Complexity: O(1).


// We copy the value of the next node of the target node, then make the next node's next as target node's next, thus instead of removing target
// node, we copy it's next node's val and remove the next node, return the root of the new LL.




public class LinkedList3 {

	static void printLL(ListNode root) {									// Prints the whole LL.
		while(root!=null) {
			System.out.println("The curr. node: "+root.val);
			root=root.next;
		}
		
	}
	
	static ListNode removeMidNode(ListNode root,ListNode mid) {
		if(root==null) return root;											// Two best cases.
		if(root==mid) return root.next;
		
//		System.out.println("The node val: "+ root.val);
		
		ListNode fol=mid.next;												// Removes the next node of the target node.
		mid.val=fol.val;													// Copy value of the next node.
		mid.next=fol.next;													// Removes the next node of the target node.
		return root;														// Return the root of the new LL.
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ListNode root= new ListNode(1);
		root.next=new ListNode(2);
		root.next.next=new ListNode(3);
		root.next.next.next= new ListNode(4);
		root.next.next.next.next= new ListNode(5);
		root.next.next.next.next.next= new ListNode(6);
		ListNode newRoot=removeMidNode(root,root.next.next);				// Calling fn. to remove a node.
		
		printLL(newRoot);													// Print the new LL.
//		System.out.println("The value: "+root.val);
	}

}
