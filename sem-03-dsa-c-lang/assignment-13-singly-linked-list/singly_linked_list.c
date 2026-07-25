#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

struct Node* deleteValue(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->data == value) {
        struct Node* temp = head->next;
        free(head);
        printf("%d deleted.\n", value);
        return temp;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("%d not found in the list.\n", value);
        return head;
    }

    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
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

// Reverses the list in place by walking through it once and flipping
// each node's 'next' pointer to point backward instead of forward.
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;

    while (current != NULL) {
        struct Node* next = current->next;   // save it before we overwrite current->next
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;   // prev is now the new head
}

// Appends a copy of list2's nodes onto the end of list1, so the
// original list2 is left untouched.
struct Node* concatenate(struct Node* list1, struct Node* list2) {
    struct Node* copyOfList2 = NULL;
    struct Node* current = list2;
    while (current != NULL) {
        copyOfList2 = insertEnd(copyOfList2, current->data);
        current = current->next;
    }

    if (list1 == NULL) {
        return copyOfList2;
    }

    struct Node* tail = list1;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = copyOfList2;
    return list1;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice, value, pos;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert into List 1\n");
        printf("2. Delete from List 1\n");
        printf("3. Search in List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Display List 1\n");
        printf("6. Insert into List 2\n");
        printf("7. Display List 2\n");
        printf("8. Concatenate List 1 and List 2 (result stored in List 1)\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                list1 = insertEnd(list1, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                list1 = deleteValue(list1, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                pos = search(list1, value);
                if (pos == -1) {
                    printf("%d not found.\n", value);
                } else {
                    printf("%d found at position %d.\n", value, pos);
                }
                break;
            case 4:
                list1 = reverseList(list1);
                printf("List 1 reversed.\n");
                break;
            case 5:
                printf("List 1: ");
                display(list1);
                break;
            case 6:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                list2 = insertEnd(list2, value);
                break;
            case 7:
                printf("List 2: ");
                display(list2);
                break;
            case 8:
                list1 = concatenate(list1, list2);
                printf("Lists concatenated into List 1.\n");
                break;
            case 9:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}
