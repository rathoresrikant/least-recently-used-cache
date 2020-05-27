# LRU Cache
A Least Recently Used (LRU) cache as the same suggests, removes the item which was used least recently to make room for new items.
It is implemented using a doubly-linked list and a hash map. Each key-value pair is stores in a doubly-linked list node. The map stores the node pointer for each key present in the cache. If an item is accessed, we look for its node pointer using its key in the map. We then move it to the front of the list. If the cache is full, we remove the last element in the linked list. 


It supports the following operations : <br/>
**(i) get(key) :** It returns the value stored at the key. The key is now the most recent one and hence is moved front of the cache. If the key is not present in the cache it returns -1. <br/>
**(ii) put(key, val) :** If the key is already present in the cache, its value is updated. If not present we create an entry in the cache. After this operation, the current key is the most recently accessed. <br/>

Click [here](https://LRU-Cache.srikant95.repl.run) for a demo of the implementation.
