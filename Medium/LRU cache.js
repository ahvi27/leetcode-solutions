var LRUCache = function(capacity) {
    this.capacity = capacity;
    this.cache = new Map();

    // Dummy head and tail nodes
    this.head = new Node(0, 0);
    this.tail = new Node(0, 0);

    this.head.next = this.tail;
    this.tail.prev = this.head;
};


// Node structure
function Node(key, value) {
    this.key = key;
    this.value = value;
    this.prev = null;
    this.next = null;
}


// Remove node from linked list
LRUCache.prototype.remove = function(node) {
    node.prev.next = node.next;
    node.next.prev = node.prev;
};


// Add node right after head (most recent)
LRUCache.prototype.add = function(node) {
    node.next = this.head.next;
    node.prev = this.head;

    this.head.next.prev = node;
    this.head.next = node;
};


// Get value
LRUCache.prototype.get = function(key) {
    if (!this.cache.has(key)) {
        return -1;
    }

    let node = this.cache.get(key);

    // Move accessed node to front
    this.remove(node);
    this.add(node);

    return node.value;
};


// Put key-value
LRUCache.prototype.put = function(key, value) {

    // If key exists, update it
    if (this.cache.has(key)) {
        let node = this.cache.get(key);
        node.value = value;

        this.remove(node);
        this.add(node);

        return;
    }

    // Create new node
    let node = new Node(key, value);
    this.cache.set(key, node);
    this.add(node);


    // Remove least recently used
    if (this.cache.size > this.capacity) {
        let lru = this.tail.prev;

        this.remove(lru);
        this.cache.delete(lru.key);
    }
};