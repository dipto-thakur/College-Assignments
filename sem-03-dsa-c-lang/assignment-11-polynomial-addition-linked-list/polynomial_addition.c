#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Inserts a term into a polynomial's linked list, keeping the list
// sorted by exponent in descending order, that ordering is what makes
// the later addition step possible as a simple merge.
struct Node* insertTerm(struct Node* head, int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if (head == NULL || exp > head->exp) {
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->exp >= exp) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

struct Node* readPolynomial() {
    struct Node* head = NULL;
    int n, coeff, exp;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        head = insertTerm(head, coeff, exp);
    }
    return head;
}

void printPolynomial(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    struct Node* current = head;
    int first = 1;
    while (current != NULL) {
        if (!first && current->coeff >= 0) printf("+");
        if (current->exp == 0) {
            printf("%d", current->coeff);
        } else if (current->exp == 1) {
            printf("%dx", current->coeff);
        } else {
            printf("%dx^%d", current->coeff, current->exp);
        }
        first = 0;
        current = current->next;
    }
    printf("\n");
}

// Merges two polynomials that are each already sorted by descending
// exponent, term by term, the same way merging two sorted lists works
// in merge sort. Matching exponents get their coefficients added
// together (and dropped entirely if the sum is zero); non-matching
// terms just get copied over as-is.
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* p1 = poly1;
    struct Node* p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0) {
                result = insertTerm(result, sum, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            result = insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            result = insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    // append whichever polynomial still has terms left
    while (p1 != NULL) {
        result = insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main() {
    printf("=== First Polynomial ===\n");
    struct Node* poly1 = readPolynomial();

    printf("\n=== Second Polynomial ===\n");
    struct Node* poly2 = readPolynomial();

    printf("\nFirst polynomial:  ");
    printPolynomial(poly1);

    printf("Second polynomial: ");
    printPolynomial(poly2);

    struct Node* sum = addPolynomials(poly1, poly2);

    printf("Sum:               ");
    printPolynomial(sum);

    return 0;
}
