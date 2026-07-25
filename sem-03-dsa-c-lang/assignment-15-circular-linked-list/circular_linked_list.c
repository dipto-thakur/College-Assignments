#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// A circular linked list has no NULL terminator, the last node's
// 'next' always points back to the head instead. Keeping a 'tail'
// pointer around (rather than head alone) makes insertion at the end
// an O(1) operation instead of having to walk the whole list to find
// where to stop.
struct Node* insertEnd(struct Node* tail, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (tail == NULL) {
        newNode->next = newNode;   // points to itself, a circle of one
        return newNode;
    }

    newNode->next = tail->next;   // new node points to the current head
    tail->next = newNode;         // old tail points to the new node
    return newNode;                // new node is now the tail
}

struct Node* deleteValue(struct Node* tail, int value) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* current = tail->next;   // start at the head
    struct Node* prev = tail;

    do {
        if (current->data == value) {
            if (current == tail && current->next == tail) {
                // only one node in the list, and it's the one being removed
                free(current);
                printf("%d deleted.\n", value);
                return NULL;
            }

            prev->next = current->next;
            if (current == tail) {
                tail = prev;   // we deleted the tail, prev becomes the new tail
            }
            free(current);
            printf("%d deleted.\n", value);
            return tail;
        }
        prev = current;
        current = current->next;
    } while (current != tail->next);

    printf("%d not found in the list.\n", value);
    return tail;
}

int search(struct Node* tail, int value) {
    if (tail == NULL) return -1;

    struct Node* current = tail->next;   // start at the head
    int position = 1;

    do {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    } while (current != tail->next);

    return -1;
}

// Reverses a circular list by flipping every node's 'next' pointer,
// same core idea as reversing a singly linked list, just needing extra
// care around the wraparound point since there's no NULL to stop at.
struct Node* reverseList(struct Node* tail) {
    if (tail == NULL || tail->next == tail) {
        return tail;   // empty list or single node, nothing to reverse
    }

    struct Node* head = tail->next;
    struct Node* prev = tail;
    struct Node* current = head;
    struct Node* next;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    return head;   // the old head is now the tail
}

void display(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = tail->next;   // start at the head
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != tail->next);
    printf("(back to head)\n");
}

int main() {
    struct Node* tail = NULL;   // an empty circular list is represented by tail == NULL
    int choice, value, pos;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Reverse\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                tail = insertEnd(tail, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                tail = deleteValue(tail, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                pos = search(tail, value);
                if (pos == -1) {
                    printf("%d not found.\n", value);
                } else {
                    printf("%d found at position %d.\n", value, pos);
                }
                break;
            case 4:
                tail = reverseList(tail);
                printf("List reversed.\n");
                break;
            case 5:
                display(tail);
                break;
            case 6:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}
