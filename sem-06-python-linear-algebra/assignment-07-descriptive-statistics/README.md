# Assignment 07 — Descriptive Statistics on a Wheat Seeds Dataset

**Date:** 06/06/26

## Problem

Given a small dataset of wheat seed measurements (area, perimeter,
compactness, kernel length, kernel width), identify the data type of
each variable and compute appropriate measures of central tendency and
dispersion using pandas.

| area | perimeter | compactness | kernel length | kernel width |
|---|---|---|---|---|
| 15.26 | 14.84 | 0.8710 | 5.763 | 3.312 |
| 14.88 | 14.57 | 0.8811 | 5.554 | 3.333 |
| 14.29 | 14.09 | 0.9050 | 5.291 | 3.337 |
| 13.84 | 13.94 | 0.8955 | 5.324 | 3.379 |
| 16.14 | 14.99 | 0.9034 | 5.658 | 3.562 |

## How it works

The dataset is built as a dictionary and converted straight into a
pandas DataFrame, `pd.DataFrame(data)`, which gives access to all of
pandas's built-in statistical methods without writing any of the math by
hand.

- **`df.dtypes`** shows the data type pandas inferred for each column,
  all five come out as `float64` here since every value has a decimal
  point, all five variables (area, perimeter, compactness, kernel
  length, kernel width) are continuous numerical measurements, not
  categories or counts.
- **`df.describe()`** gives a full summary in one call: count, mean,
  standard deviation, min, the three quartiles (25%/50%/75%), and max,
  for every numeric column at once.
- **`df.mean()`**, **`df.median()`**, and **`df.std()`** pull out those
  individual statistics on their own, useful when you want just one
  number per column rather than the full `describe()` table. Note that
  pandas's `.std()` computes the **sample** standard deviation by
  default (dividing by `n - 1`, not `n`), which is why it lines up with
  the `std` row in `describe()`.

## Run it

```
pip install pandas
python descriptive_statistics.py
```

## Sample run

```
Dataset:
    area  perimeter  compactness  kernel_length  kernel_width
0  15.26      14.84       0.8710          5.763         3.312
1  14.88      14.57       0.8811          5.554         3.333
2  14.29      14.09       0.9050          5.291         3.337
3  13.84      13.94       0.8955          5.324         3.379
4  16.14      14.99       0.9034          5.658         3.562

Data Types:
area             float64
perimeter        float64
compactness      float64
kernel_length    float64
kernel_width     float64
dtype: object

Summary Statistics:
            area  perimeter  compactness  kernel_length  kernel_width
count   5.000000   5.000000     5.000000       5.000000      5.000000
mean   14.882000  14.486000     0.891200       5.518000      3.384600
std     0.889056   0.458617     0.014729       0.206207      0.102104
min    13.840000  13.940000     0.871000       5.291000      3.312000
25%    14.290000  14.090000     0.881100       5.324000      3.333000
50%    14.880000  14.570000     0.895500       5.554000      3.337000
75%    15.260000  14.840000     0.903400       5.658000      3.379000
max    16.140000  14.990000     0.905000       5.763000      3.562000

Mean:
area             14.8820
perimeter        14.4860
compactness       0.8912
kernel_length     5.5180
kernel_width      3.3846
dtype: float64

Median:
area             14.8800
perimeter        14.5700
compactness       0.8955
kernel_length     5.5540
kernel_width      3.3370
dtype: float64

Standard Deviation:
area             0.889056
perimeter        0.458617
compactness      0.014729
kernel_length    0.206207
kernel_width     0.102104
dtype: float64
```

### A note on the standard deviation values

The original assignment sheet listed a different set of standard
deviation values (`0.853194` for area, etc). Running this exact code
gives `0.889056` for area instead, and that number checks out by hand:
the five area values have a mean of 14.882, and summing their squared
deviations from that mean and dividing by `n - 1 = 4` (pandas's default)
gives `0.889056` after the square root. The original sheet's numbers
don't match `n-1`, `n`, or any other obvious variant, so they look like
a transcription error rather than genuine output, corrected here.
