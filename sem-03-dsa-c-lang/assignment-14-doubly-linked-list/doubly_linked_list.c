#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;   // the extra step a singly linked list doesn't need
    return head;
}

struct Node* deleteValue(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* current = head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        printf("%d not found in the list.\n", value);
        return head;
    }

    // relink the neighbors on both sides, this is where a doubly
    // linked list pays off, no need to track a separate "previous
    // node" pointer while walking, current->prev already has it
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;   // we're deleting the head
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("%d deleted.\n", value);
    return head;
}

int search(struct Node* head, int value) {
    int position = 1;
    while (head != NULL) {
        if (head->data == value) {
            return position;
        }
        head = head->next;
        position++;
    }
    return -1;
}

// Reversing a doubly linked list just means swapping 'prev' and 'next'
// on every node, then the old tail becomes the new head.
struct Node* reverseList(struct Node* head) {
    struct Node* current = head;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;   // this is the "next" node before the swap
    }

    // temp ends up holding the second-to-last node processed, whose
    // 'prev' (post-swap) points at the new head
    if (temp != NULL) {
        head = temp->prev;
    }
    return head;
}

void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("NULL <- ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    printf("NULL <- ");
    while (tail != NULL) {
        printf("%d <-> ", tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, pos;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Reverse\n");
        printf("5. Display Forward\n");
        printf("6. Display Backward\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertEnd(head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteValue(head, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                pos = search(head, value);
                if (pos == -1) {
                    printf("%d not found.\n", value);
                } else {
                    printf("%d found at position %d.\n", value, pos);
                }
                break;
            case 4:
                head = reverseList(head);
                printf("List reversed.\n");
                break;
            case 5:
                displayForward(head);
                break;
            case 6:
                displayBackward(head);
                break;
            case 7:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}
