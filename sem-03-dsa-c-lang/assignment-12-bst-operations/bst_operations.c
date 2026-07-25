#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// (a) Insertion: smaller values go left, larger (or equal) go right,
// recursively, until an empty spot is found.
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Finds the smallest value in a subtree, used by delete() when removing
// a node with two children.
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// (b) Deletion: three cases depending on how many children the node
// being removed has.
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // found the node to delete
        if (root->left == NULL && root->right == NULL) {
            // no children, just remove it
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            // one child (right), replace this node with that child
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // one child (left)
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            // two children: replace this node's value with its
            // inorder successor (smallest value in the right subtree),
            // then delete that successor from the right subtree instead
            struct Node* successor = findMin(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }
    return root;
}

// (c) Search
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

// (d) Recursive traversals
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// (e) Level-by-level (BFS) display using a simple array-backed queue
void levelOrder(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++) {
            struct Node* current = queue[front++];
            printf("%d ", current->data);
            if (current->left != NULL) queue[rear++] = current->left;
            if (current->right != NULL) queue[rear++] = current->right;
        }
        printf("\n");
    }
}

// (e) Leaf nodes: nodes with no children at all
void printLeafNodes(struct Node* root) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
        return;
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

// (f) Height: the number of edges on the longest path from root to a
// leaf. An empty tree has height -1, a single node has height 0.
int height(struct Node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- BST Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display Preorder\n");
        printf("5. Display Inorder\n");
        printf("6. Display Postorder\n");
        printf("7. Display Level-by-Level\n");
        printf("8. Display Leaf Nodes\n");
        printf("9. Display Height of Tree\n");
        printf("10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                if (search(root, value) == NULL) {
                    printf("%d not found in the tree.\n", value);
                } else {
                    root = deleteNode(root, value);
                    printf("%d deleted.\n", value);
                }
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("%d found in the tree.\n", value);
                } else {
                    printf("%d not found in the tree.\n", value);
                }
                break;

            case 4:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                printf("Level-by-level:\n");
                levelOrder(root);
                break;

            case 8:
                printf("Leaf nodes: ");
                printLeafNodes(root);
                printf("\n");
                break;

            case 9:
                printf("Height of tree: %d\n", height(root));
                break;

            case 10:
                printf("Exiting.\n");
                return 0;

            default:
                printf("Invalid choice, try again.\n");
        }
    }
}
