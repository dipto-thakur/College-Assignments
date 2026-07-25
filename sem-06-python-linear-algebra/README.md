# Sem 6 — Python Lab Assignments

Eight lab exercises covering vector and matrix algebra, linear systems,
and basic data analysis in Python, using NumPy, SymPy, pandas, and
Matplotlib. Each folder is self contained: one `.py` file plus a README
explaining the problem and the approach.

## Assignments

| Folder | Topic |
|---|---|
| assignment-01-vector-operations | Vector addition, scalar multiplication, dot/cross product, orthogonality, parallelism |
| assignment-02-matrix-properties | Determinant, inverse, transpose, adjoint, rank, trace, eigenvalues/eigenvectors |
| assignment-03-matrix-operations | Matrix addition, subtraction, multiplication, and "division" (via inverse) |
| assignment-04-linear-independence | Linear independence, basis, and dimension of a spanned subspace |
| assignment-05-gauss-elimination | Solving a linear system by hand-rolled Gauss elimination, verified with NumPy |
| assignment-06-gauss-jordan | Gaussian elimination and Gauss-Jordan (RREF), plus a consistency check |
| assignment-07-descriptive-statistics | Data types, mean, median, std, and `describe()` on a small dataset |
| assignment-08-frequency-diagrams | Absolute (bar) and cumulative (line) frequency diagrams |

## Running these

Every folder works the same way:

```
cd assignment-01-vector-operations
python vector_operations.py
```

Just swap in the folder and filename for whichever assignment you're
running. Different assignments need different packages:

```
pip install numpy sympy pandas matplotlib
```

(assignments 1, 2, 3, 5 need NumPy; 4 and 6 need SymPy; 7 needs pandas;
8 needs Matplotlib and NumPy)

## Verified against real runs

Every script in this project was actually executed, not just
transcribed, and its README's sample output reflects what the code
really produces. In the course of that, a few issues turned up in the
original assignment sheets, all fixed here rather than reproduced:

- **Assignments 4 and 6** had lost their indentation somewhere in the
  original document (every `if`/`for`/`else` block was flush against
  the margin), which doesn't run in Python at all, indentation is how
  Python defines block structure, not just formatting. Both are
  restored with correct indentation.
- **Assignments 3, 5, 6, and 7** each had at least one printed value in
  their original "Output" section that didn't match what the code
  actually produces, confirmed independently by re-running the code,
  and in most cases by checking the arithmetic by hand too. Each of
  those READMEs has a short note explaining exactly what was off and
  what the verified correct value is.
- **Assignment 8** only called `plt.show()`, which needs a display to
  do anything visible. Added a `plt.savefig(...)` call alongside it so
  the script also produces two PNG files on disk, `show()` still works
  as before wherever a display is available.

None of these were logic bugs in the underlying approach, mostly
transcription slips (a swapped digit, a value copied from the wrong
variable) from whatever process turned the original working code into
the assignment document this was built from.
