#include <stdio.h>

#define MAX 100

// Represents a sparse matrix as a list of (row, col, value) triplets,
// storing only the non-zero elements instead of the full grid. This is
// the classic "triplet" or "coordinate list" representation.
struct Triplet {
    int row, col, value;
};

int main() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter the matrix elements (%d x %d), use 0 for empty cells:\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    // build the sparse (triplet) representation by scanning row-major
    // and only recording cells that aren't zero
    struct Triplet sparse[MAX];
    int total = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[total].row = i;
                sparse[total].col = j;
                sparse[total].value = matrix[i][j];
                total++;
            }
        }
    }

    int totalCells = rows * cols;
    printf("\nOriginal matrix has %d cells, %d are non-zero (%.1f%% sparse).\n",
           totalCells, total, 100.0 * (totalCells - total) / totalCells);

    printf("\nSparse matrix representation (row, column, value):\n");
    printf("Rows: %d\tColumns: %d\tNon-zero terms: %d\n", rows, cols, total);
    for (int i = 0; i < total; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }

    // Fast transpose: build the transposed triplet list directly from
    // the sparse form, without ever rebuilding the full matrix. This
    // works by placing each triplet into its final sorted-by-column
    // position in one pass, using a per-column count and starting
    // position, instead of the slower approach of scanning the whole
    // sparse list once per column.
    struct Triplet transposed[MAX];
    int colCount[cols], colStart[cols];

    for (int i = 0; i < cols; i++) colCount[i] = 0;
    for (int i = 0; i < total; i++) colCount[sparse[i].col]++;

    colStart[0] = 0;
    for (int i = 1; i < cols; i++) {
        colStart[i] = colStart[i - 1] + colCount[i - 1];
    }

    for (int i = 0; i < total; i++) {
        int c = sparse[i].col;
        int pos = colStart[c];
        transposed[pos].row = sparse[i].col;   // rows and columns swap
        transposed[pos].col = sparse[i].row;
        transposed[pos].value = sparse[i].value;
        colStart[c]++;
    }

    printf("\nTransposed sparse matrix (row, column, value):\n");
    printf("Rows: %d\tColumns: %d\tNon-zero terms: %d\n", cols, rows, total);
    for (int i = 0; i < total; i++) {
        printf("%d\t%d\t%d\n", transposed[i].row, transposed[i].col, transposed[i].value);
    }

    return 0;
}
