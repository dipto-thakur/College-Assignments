import pandas as pd

# Creating Dataset
data = {
    "area": [15.26, 14.88, 14.29, 13.84, 16.14],
    "perimeter": [14.84, 14.57, 14.09, 13.94, 14.99],
    "compactness": [0.8710, 0.8811, 0.9050, 0.8955, 0.9034],
    "kernel_length": [5.763, 5.554, 5.291, 5.324, 5.658],
    "kernel_width": [3.312, 3.333, 3.337, 3.379, 3.562]
}

# Convert Dictionary into DataFrame
df = pd.DataFrame(data)

# Display Dataset
print("Dataset:")
print(df)

# Data Types
print("\nData Types:")
print(df.dtypes)

# Summary Statistics
print("\nSummary Statistics:")
print(df.describe())

# Mean
print("\nMean:")
print(df.mean())

# Median
print("\nMedian:")
print(df.median())

# Standard Deviation
print("\nStandard Deviation:")
print(df.std())
