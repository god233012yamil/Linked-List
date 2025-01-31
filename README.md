# C Linked List Implementation

A robust and efficient implementation of a singly linked list data structure in C, featuring comprehensive memory management and various operations for list manipulation.

## Features

* Complete implementation of a singly linked list with dynamic memory allocation
* Thread-safe operations
* Comprehensive error handling
* Well-documented API with time and space complexity analysis
* Memory leak-free implementation with proper cleanup functions

## Data Structures

### Node
```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;
```

### LinkedList
```c
typedef struct {
    Node* head;
    size_t size;
} LinkedList;
```

## API Reference

### List Creation and Destruction

* `LinkedList* createList()` - Creates a new empty linked list
* `void destroyList(LinkedList* list)` - Frees all memory used by the list

### Insertion Operations

* `bool insertAtBeginning(LinkedList* list, int data)` - O(1)
* `bool insertAtEnd(LinkedList* list, int data)` - O(n)
* `bool insertAtPosition(LinkedList* list, int data, size_t position)` - O(n)

### Deletion Operations

* `bool deleteFromBeginning(LinkedList* list)` - O(1)
* `bool deleteFromEnd(LinkedList* list)` - O(n)
* `bool deleteAtPosition(LinkedList* list, size_t position)` - O(n)

### Query Operations

* `int search(LinkedList* list, int value)` - O(n)
* `int getMiddle(LinkedList* list)` - O(n/2)
* `bool hasCycle(LinkedList* list)` - O(n)

### Utility Operations

* `void reverse(LinkedList* list)` - O(n)
* `void display(LinkedList* list)` - O(n)

## Usage Example

```c
int main() {
    // Create a new list
    LinkedList* list = createList();
    
    // Insert elements
    insertAtEnd(list, 1);
    insertAtEnd(list, 2);
    insertAtEnd(list, 3);
    insertAtBeginning(list, 0);
    
    // Display the list
    display(list);  // Output: 0 -> 1 -> 2 -> 3
    
    // Clean up
    destroyList(list);
    
    return 0;
}
```

## Error Handling

The implementation includes robust error handling:

* All memory allocations are checked for failure
* Functions return boolean values to indicate success/failure
* Invalid operations (e.g., deleting from empty list) are handled gracefully
* Out-of-bounds position checks for insertions and deletions

## Memory Management

This implementation ensures proper memory management:

* All dynamically allocated memory is tracked and freed
* No memory leaks in any operation
* Proper cleanup function (`destroyList`) provided
* Clear ownership semantics for all allocated memory

## Build Instructions

### Prerequisites

* C compiler (GCC recommended)
* Make (optional)

### Compilation

```bash
gcc -Wall -Wextra -o linkedlist linkedlist.c
```

Or with Make:

```bash
make linkedlist
```

## Running Tests

```bash
./linkedlist
```

The main function includes a basic test suite demonstrating the functionality of the implementation.

## Performance Considerations

* Most operations are optimized for their specific use cases
* Space complexity is maintained at O(1) for all operations except list storage
* Time complexities are optimal for a singly linked list implementation

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you want to change.

## License

This project is licensed under the GNU GENERAL PUBLIC License - see the LICENSE file for details.

## Future Improvements

* Add iterator support
* Implement doubly linked list variation
* Add serialization/deserialization support
* Implement sorting algorithms
* Add more advanced operations (merge, split, etc.)
* Create a comprehensive test suite

## Author

Yamil Garcia

## Acknowledgments

* Inspired by standard linked list implementations
* Based on best practices in C programming
* Optimized for educational and practical use
