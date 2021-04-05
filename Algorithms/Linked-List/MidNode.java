public class MidNode {

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

    void getMidNodeInefficient() {
        Node i = head;
        int size = 0;

        while (i != null) {
            size++;
            i = i.next;
        }

        int midNode = size / 2;

        i = head;
        int cnt = 0;

        while (i != null) {

            if (cnt == midNode) {
                System.out.println(i.data);
                break;
            }
            cnt++;
            i = i.next;
        }
    }

    void getMidNodeEfficient() {
        Node prev, curr;
        prev = head;
        curr = head;
        int cnt = 0;

        while (curr != null) {
            if (cnt > 0 && cnt % 2 == 0) {
                prev = prev.next;
            }

            cnt++;
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
        MidNode ll = new MidNode();

        // 5->4->3->2->1->null
        ll.pushFront(1);
        ll.pushFront(2);
        ll.pushFront(3);
        ll.pushFront(4);
        ll.pushFront(5);

        ll.printList();

        ll.getMidNodeInefficient();
        ll.getMidNodeEfficient();
    }
}
