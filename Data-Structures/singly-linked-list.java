class LinkedList {

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

    public void pushAfter(Node prevNode, int val) {
        if (prevNode == null) {
            System.out.println("The given previous node cannot be null");
            return;
        }

        Node newNode = new Node(val);
        newNode.next = prevNode.next;
        prevNode.next = newNode;
    }

    public void pushBefore(Node nextNode, int val) {
        if (nextNode == null) {
            System.out.println("The given next node cannot be null");
            return;
        }

        Node newNode = new Node(val);
        newNode.next = nextNode;

        if (nextNode == head) {
            head = newNode; //we need to change head directly, if we do Node a = head; a = an address; it won't change the head
        } else {
            Node prev = head;
            while (prev.next != nextNode) {
                prev = prev.next;
            }

            prev.next = newNode;
        }
    }

    // Pushing at the end can be done at O(1) cost if we maintain a tail pointer
    public void pushBack(int val) {
        Node newNode = new Node(val);

        if (head == null) {
            head = new Node(val);
            return;
        }

        newNode.next = null;

        Node last = head;
        while (last.next != null) {
            last = last.next;
        }

        last.next = newNode;
    }

    void deleteKey(int key) {
        // If linked list is empty
        if (head == null) {
            return;
        }

        Node temp = head;
        Node prev = null;

        // If head node itself holds the key to be deleted
        if (temp != null && temp.data == key) {
            head = temp.next; // Changed head
            return;
        }

        // Search for the key to be deleted, keep track of
        // the previous node as we need to change temp.next
        while (temp != null && temp.data != key) {
            prev = temp;
            temp = temp.next;
        }

        // If key was not present in linked list
        if (temp == null) {
            return;
        }

        // Unlink the node from linked list
        prev.next = temp.next;
    }

    void deletePosition(int position) {
        // If linked list is empty
        if (head == null) {
            return;
        }

        // Store head node
        Node temp = head;

        // If head needs to be removed
        if (position == 0) {
            head = temp.next;   // Change head
            return;
        }

        // Find previous node of the node to be deleted
        for (int i = 0; temp != null && i < position - 1; i++) {
            temp = temp.next;
        }

        // If position is more than number of nodes
        if (temp == null || temp.next == null) {
            return;
        }

        // Node temp->next is the node to be deleted
        // Store pointer to the next of node to be deleted
        Node next = temp.next.next;

        temp.next = next;  // Unlink the deleted node from list
    }

    // Java has automatic garbage collection feature, hence setting the head to null frees all the other nodes
    void deleteList() {
        head = null;
    }

    // In c++ we need to traverse the whole list and release every node one by one
    // Hence delete the whole list has complexity of O(n)
    /*void deleteList() {
        Node *current = *head;
        Node *next = null;
        while (current != null) {
            next = current.next;
            free(current);
            current = next;
        }
        *head=null;
    }*/
    public boolean search(Node head, int x) {
        Node current = head;    //Initialize current
        while (current != null) {
            if (current.data == x) {
                return true;    //data found
            }
            current = current.next;
        }
        return false;    //data not found
    }

    public void size() {
        Node i = head;
        int cnt = 0;

        while (i != null) {
            cnt++;
            i = i.next;
        }

        System.out.println("\nList size: " + cnt);
    }

    public void printList() {
        Node i = head;

        while (i != null) {
            System.out.print(i.data + " ");
            i = i.next;
        }
    }

    public static void main(String[] args) {
        LinkedList ll = new LinkedList();

        // 6->null
        ll.pushBack(6);

        // 7->6->null
        ll.pushFront(7);

        // 1->7->6->null
        ll.pushFront(1);

        // 1->7->6->4->null
        ll.pushBack(4);

        // 1->7->8->6->4->null
        ll.pushAfter(ll.head.next, 8);

        // 1->7->8->6->5->4->null
        ll.pushBefore(ll.head.next.next.next.next, 5);

        // 7->8->6->5->4->null
        ll.deleteKey(1);

        // 7->8->6->5->null
        ll.deleteKey(4);

        // 7->6->5->null
        ll.deleteKey(8);

        // 4->7->6->5->null
        ll.pushFront(4);

        // 7->6->5->null
        ll.deletePosition(0);

        // 7->5->null
        ll.deletePosition(1);

        // 7->null
        ll.deletePosition(1);

        // null
        ll.deleteList();

        ll.printList();
        ll.size();
    }
}
