import java.util.Stack;

public class ReverseSinglyLinkedList {

    Node head;

    class Node {

        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    public void pushFront(int val) {
        Node newNode = new Node(val);
        newNode.next = head;
        head = newNode;
    }

    public void reverseListUsing3Pointer() {
        Node prev = null;
        Node curr = head;
        Node next = null;

        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    public void reverseListUsingStack() {
        Stack<Node> st = new Stack<Node>();

        Node temp = head;

        while (temp.next != null) {
            st.push(temp);
            // System.out.println(temp);
            temp = temp.next;
        }

        head = temp; // set the last node as head

        while (!st.empty()) {
            // System.out.println(st.peek().data + " " + st.peek().next);

            temp.next = st.peek();
            st.pop();
            temp = temp.next;
        }

        temp.next = null; // set the 1st node's next as null
    }

    public void printList() {
        Node i = head;

        while (i != null) {
            System.out.print(i.data + " ");
            i = i.next;
        }

        System.out.println();
    }

    public static void main(String[] args) {
        ReverseSinglyLinkedList ll = new ReverseSinglyLinkedList();

        // 5->4->3->2->1->null
        ll.pushFront(1);
        ll.pushFront(2);
        ll.pushFront(3);
        ll.pushFront(4);
        ll.pushFront(5);

        ll.printList();

        ll.reverseListUsing3Pointer();
        ll.printList();
        
        ll.reverseListUsingStack();
        ll.printList();
    }
}
