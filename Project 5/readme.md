# LRU Cache Implementation (C++)

This project implements a **Least Recently Used (LRU) Cache system** using C++.  
It demonstrates object-oriented programming concepts such as **classes**, **encapsulation**, **composition**, and efficient data structure usage with **hash maps** and **doubly linked lists**.  

---

## Features

- Supports **constant time** `get` and `put` operations.  
- Maintains a **fixed-size cache** with automatic eviction of the **least recently used** item when full.  
- Tracks **usage order** using a **doubly linked list**.  
- Uses a **hash map** to store key-node mappings for **O(1) access**.  
- Can handle any integer keys and values.  
- Ensures memory is managed properly when nodes are removed.  

---

## Classes Overview

### **Node**
- Represents a node in the doubly linked list.  
- Each node stores:
  - `key`  
  - `value`  
  - `prev` pointer to previous node  
  - `next` pointer to next node  

### **LRU_Cache**
- Represents the LRU cache that manages nodes and capacity.  
- Responsibilities:
  - Store key-node mappings in a **hash map**.  
  - Maintain **head** (most recently used) and **tail** (least recently used) pointers.  
  - On `get(key)`:
    - Return value if key exists.  
    - Move accessed node to the front (most recently used).  
  - On `put(key, value)`:
    - Update value if key exists and move to front.  
    - Insert new node if key doesn’t exist.  
    - Evict the **least recently used node** when capacity is reached.  

---

## Example Workflow

1. Create an `LRU_Cache` instance with a fixed capacity.  
2. Use `put(key, value)` to insert key-value pairs into the cache.  
3. Use `get(key)` to retrieve values; accessed keys are moved to the front.  
4. When capacity is exceeded, the **least recently used key** is automatically evicted.  
5. Repeat `put` and `get` operations as needed to simulate cache usage.  

---

## Future Improvements

- Use **smart pointers** instead of raw pointers for better memory safety.  
- Extend the cache to support **generic key-value types**.  
- Track **hit/miss statistics** for performance analysis.  
- Add **thread safety** for concurrent access in multithreaded environments.  
