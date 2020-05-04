#include "lru_cache.h"

int main()
{
    int capacity, queries, key, value;
    char type;
    cout <<"Enter the capacity of the cache:"<<endl;
    cin >> capacity;
    LRUCache lru(capacity);
    cout <<"Enter the number of queries: \n";
    cin >> queries;
    while(queries--)
    {
        cout <<"Enter the type of query : g / p :\n";
        cin >> type;
        switch(type)
        {
            case 'g' :
            cout <<"Enter the key : \n";
            cin >> key;
            value = lru.get(key);
            cout << "The value is "<<value<<endl;
            break;

            case 'p' :
            cout <<"Enter the key and value :\n";
            cin >> key >> value;
            lru.put(key, value);
        }
    }
    return 0;
}