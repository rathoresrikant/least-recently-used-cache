#include "lru_cache.h"

int LRUCache::get(int key)
{
    if(cache.find(key) != cache.end())
    {
        Node *node = cache[key];
        moveToFront(node);
        return node->value;
    }
    return -1;
}

void LRUCache::put(int key, int value)
{
    if(cache.find(key) != cache.end())
    {
        Node *node = cache[key];
        node->value = value;
        moveToFront(node);
        return;
    }
    Node *node = new Node(key, value);
    if(cache.size() == capacity)
    {
        cache.erase(tail->key);
        removeNode(tail);
    }
    cache[key] = node;
    addFirst(node);
}

void LRUCache::moveToFront(Node *node)
{
    removeNode(node);
    addFirst(node);
}

void LRUCache::removeNode(Node *node)
{
    Node *prevNode = node->prev;
    Node *nextNode = node->next;

    if(prevNode != NULL)
    {
        prevNode->next = nextNode;
    }
    else
    {
        head = nextNode;
    }

    if(nextNode != NULL)
    {
        nextNode->prev = prevNode;
    }
    else
    {
        tail = prevNode;
    }
}

void LRUCache::addFirst(Node *node)
{
    node->next = head;
    node->prev = NULL;

    if(head != NULL)
    {
        head->prev = node;
    }
    head = node;
    if(tail == NULL)
    {
        tail = node;
    }
}
