#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Structure for a node in the linked list
 * @member data The integer data stored in the node
 * @member next Pointer to the next node
 */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/**
 * Structure for the linked list
 * @member head Pointer to the first node
 * @member size Current number of nodes in the list
 */
typedef struct {
    Node* head;
    size_t size;
} LinkedList;

/**
 * Initialize a new empty linked list
 * 
 * @return Pointer to the newly created linked list
 * @note Caller must free the list using destroyList when done
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
LinkedList* createList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

/**
 * Create a new node with the given data
 * 
 * @param data The integer data to store in the node
 * @return Pointer to the newly created node, or NULL if allocation fails
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/**
 * Insert a new node at the beginning of the list
 * 
 * @param list Pointer to the linked list
 * @param data The integer data to insert
 * @return true if insertion successful, false if memory allocation fails
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
bool insertAtBeginning(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        return false;
    }
    
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
    return true;
}

/**
 * Insert a new node at the end of the list
 * 
 * @param list Pointer to the linked list
 * @param data The integer data to insert
 * @return true if insertion successful, false if memory allocation fails
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool insertAtEnd(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        return false;
    }
    
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
    return true;
}

/**
 * Insert a new node at the specified position
 * 
 * @param list Pointer to the linked list
 * @param data The integer data to insert
 * @param position The position at which to insert (0-based)
 * @return true if insertion successful, false if invalid position or memory allocation fails
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool insertAtPosition(LinkedList* list, int data, size_t position) {
    if (position > list->size) {
        return false;
    }
    
    if (position == 0) {
        return insertAtBeginning(list, data);
    }
    
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        return false;
    }
    
    Node* current = list->head;
    for (size_t i = 0; i < position - 1; i++) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    list->size++;
    return true;
}

/**
 * Delete the first node in the list
 * 
 * @param list Pointer to the linked list
 * @return true if deletion successful, false if list is empty
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
bool deleteFromBeginning(LinkedList* list) {
    if (list->head == NULL) {
        return false;
    }
    
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
    return true;
}

/**
 * Delete the last node in the list
 * 
 * @param list Pointer to the linked list
 * @return true if deletion successful, false if list is empty
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool deleteFromEnd(LinkedList* list) {
    if (list->head == NULL) {
        return false;
    }
    
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        list->size--;
        return true;
    }
    
    Node* current = list->head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    free(current->next);
    current->next = NULL;
    list->size--;
    return true;
}

/**
 * Delete the node at the specified position
 * 
 * @param list Pointer to the linked list
 * @param position The position of the node to delete (0-based)
 * @return true if deletion successful, false if invalid position
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool deleteAtPosition(LinkedList* list, size_t position) {
    if (list->head == NULL || position >= list->size) {
        return false;
    }
    
    if (position == 0) {
        return deleteFromBeginning(list);
    }
    
    Node* current = list->head;
    for (size_t i = 0; i < position - 1; i++) {
        current = current->next;
    }
    
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    list->size--;
    return true;
}

/**
 * Search for a value in the list
 * 
 * @param list Pointer to the linked list
 * @param value The value to search for
 * @return The position of the first occurrence (0-based), or -1 if not found
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int search(LinkedList* list, int value) {
    Node* current = list->head;
    int position = 0;
    
    while (current != NULL) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }
    
    return -1;
}

/**
 * Reverse the linked list in-place
 * 
 * @param list Pointer to the linked list
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void reverse(LinkedList* list) {
    Node *prev = NULL, *current = list->head, *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    list->head = prev;
}

/**
 * Get the middle node's data
 * 
 * @param list Pointer to the linked list
 * @return The middle node's data, or -1 if list is empty
 * 
 * Time Complexity: O(n/2)
 * Space Complexity: O(1)
 */
int getMiddle(LinkedList* list) {
    if (list->head == NULL) {
        return -1;
    }
    
    Node *slow = list->head, *fast = list->head;
    
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow->data;
}

/**
 * Check if the list contains a cycle
 * 
 * @param list Pointer to the linked list
 * @return true if cycle exists, false otherwise
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool hasCycle(LinkedList* list) {
    if (list->head == NULL) {
        return false;
    }
    
    Node *slow = list->head, *fast = list->head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    
    return false;
}

/**
 * Display all elements in the list
 * 
 * @param list Pointer to the linked list
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void display(LinkedList* list) {
    Node* current = list->head;
    
    if (current == NULL) {
        printf("Empty List\n");
        return;
    }
    
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

/**
 * Free all memory used by the list
 * 
 * @param list Pointer to the linked list
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void destroyList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

/**
 * Example usage of the linked list implementation
 */
int main() {
    // Create a new list
    LinkedList* list = createList();
    
    // Insert some elements
    insertAtEnd(list, 1);
    insertAtEnd(list, 2);
    insertAtEnd(list, 3);
    insertAtBeginning(list, 0);
    insertAtPosition(list, 5, 2);
    
    // Display the list
    printf("Original list: ");
    display(list);  // Output: 0 -> 1 -> 5 -> 2 -> 3
    
    // Search for an element
    printf("Position of 5: %d\n", search(list, 5));  // Output: 2
    
    // Delete some elements
    deleteFromBeginning(list);
    deleteFromEnd(list);
    printf("After deletions: ");
    display(list);  // Output: 1 -> 5 -> 2
    
    // Reverse the list
    reverse(list);
    printf("After reverse: ");
    display(list);  // Output: 2 -> 5 -> 1
    
    // Get middle element
    printf("Middle element: %d\n", getMiddle(list));  // Output: 5
    
    // Check for cycle
    printf("Has cycle: %s\n", hasCycle(list) ? "true" : "false");  // Output: false
    
    // Clean up
    destroyList(list);
    
    return 0;
}