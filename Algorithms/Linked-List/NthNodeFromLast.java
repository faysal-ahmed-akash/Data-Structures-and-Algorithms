public class NthNodeFormLast {

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

    void getNodeFromLastInefficient(int n) {
        Node i = head;
        int size = 0;

        while (i != null) {
            size++;
            i = i.next;
        }

        if (n > size) {
            System.out.println("Invalid Node");
            return;
        }

        int nthNode = size - n + 1;

        i = head;
        int cnt = 0;

        while (i != null) {
            cnt++;

            if (cnt == nthNode) {
                System.out.println(i.data);
                break;
            }

            i = i.next;
        }
    }

    void getNodeFromLastEfficient(int n) {
        Node prev, curr;
        prev = head;
        curr = head;
        int cnt = 0;

        while (curr != null) {
            cnt++;
            if (cnt > n) {
                prev = prev.next;
            }
            curr = curr.next;
        }
        
        System.out.println(prev.data);
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
        NthNodeFormLast ll = new NthNodeFormLast();

        // 5->4->3->2->1->null
        ll.pushFront(1);
        ll.pushFront(2);
        ll.pushFront(3);
        ll.pushFront(4);
        ll.pushFront(5);

        ll.printList();

        ll.getNodeFromLastInefficient(5);
        ll.getNodeFromLastEfficient(5);
    }
}
