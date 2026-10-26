class LRUCache {
    Node head;
    Node tail;
    Map<Integer, Node> hm;
    int capacity;
    int size;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        hm = new HashMap<>();
    }

    public int get(int key) {
        if (!hm.containsKey(key))
            return -1;

        Node node = hm.get(key);
        remove(node);
        addLast(node);

        return node.val;
    }

    public void put(int key, int value) {

        if (hm.containsKey(key)) {
            Node node = hm.get(key);
            node.val = value;
            remove(node);
            addLast(node);
            return;
        }

        if (size == capacity) {
            hm.remove(head.key);
            remove(head);
        }

        Node node = new Node(key, value);
        addLast(node);
        hm.put(key, node);
    }

    private void remove(Node node) {

        if (node.prev != null)
            node.prev.next = node.next;
        else
            head = node.next;

        if (node.next != null)
            node.next.prev = node.prev;
        else
            tail = node.prev;

        size--;
    }

    private void addLast(Node node) {

        node.prev = tail;
        node.next = null;

        if (tail != null)
            tail.next = node;
        else
            head = node;

        tail = node;
        size++;
    }
}

class Node {
    int key;
    int val;
    Node prev;
    Node next;

    Node(int key, int val) {
        this.key = key;
        this.val = val;
    }
}