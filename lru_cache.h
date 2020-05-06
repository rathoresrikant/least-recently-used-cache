#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
    public:
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};


class LRUCache
{
    private:
    int capacity;
    unordered_map <int, Node*> cache;
    Node *head;
    Node *tail;

    void moveToFront(Node*);

    void removeNode(Node*);

    void addFirst(Node*);

    public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->head = NULL;
        this->tail = NULL;
        cache.clear();
    }

    int get(int);

    void put(int, int);

};
