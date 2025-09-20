#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v){
        this->key = k;
        this->value = v;

        prev = nullptr;
        next = nullptr;
    }
};

class LRU_Cache{
    int capacity;
    unordered_map<int, Node*>mpp;
    Node* head;
    Node* tail;

    void remove(Node* node){
        if(!node) 
        return;

        if(node->prev) 
        node->prev->next = node->next;

        if(node->next) 
        node->next->prev = node->prev;

        if(node == head) 
        head = node->next;

        if(node == tail) 
        tail = node->prev;
    }

    void addToFront(Node* node){
        node->next = head;
        node->prev = nullptr;

        if(head)
        head->prev = node;

        if(!tail)
        tail = node;

        head = node;
    }

    public:

    LRU_Cache(int n){
        this->capacity = n;

        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;
        Node* node = mpp[key];
        remove(node);
        addToFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->value = value;
            remove(node);
            addToFront(node);
        } else {
            if (mpp.size() == capacity) {
                mpp.erase(tail->key);
                remove(tail);
            }
            Node* node = new Node(key, value);
            addToFront(node);
            mpp[key] = node;
        }
    }
};

int main() {
    LRU_Cache cache(2);

    cache.put(1, 100);
    cache.put(2, 200);
    cout << cache.get(1) << endl; // 100

    cache.put(3, 300); // evicts key 2
    cout << cache.get(2) << endl; // -1

    cache.put(4, 400); // evicts key 1
    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 300
    cout << cache.get(4) << endl; // 400

    return 0;
}