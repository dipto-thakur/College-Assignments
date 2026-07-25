import matplotlib.pyplot as plt
import numpy as np

# Given data
family_size = [2, 3, 4, 5, 6, 7, 8, 9, 10]
frequencies = [26, 21, 17, 12, 9, 3, 2, 2, 1]

# -----------------------------
# Absolute Frequency Diagram
# -----------------------------
plt.figure(figsize=(8, 5))
plt.bar(family_size, frequencies, color="skyblue", edgecolor="black")
plt.title("Absolute Frequency Distribution")
plt.xlabel("Family Size")
plt.ylabel("Frequency")
plt.grid(axis='y', linestyle='--', alpha=0.5)
plt.savefig("absolute_frequency.png", dpi=150, bbox_inches="tight")
plt.show()

# -----------------------------
# Cumulative Frequency Diagram
# -----------------------------
# np.cumsum runs a running total across the frequency list, so each
# point represents "how many families have this size or smaller",
# which is what a cumulative frequency distribution actually shows
cumulative_frequency = np.cumsum(frequencies)

plt.figure(figsize=(8, 5))
plt.plot(
    family_size,
    cumulative_frequency,
    marker='o',
    linewidth=2,
    color='red'
)
plt.title("Cumulative Frequency Distribution")
plt.xlabel("Family Size")
plt.ylabel("Cumulative Frequency")
plt.grid(True)
plt.savefig("cumulative_frequency.png", dpi=150, bbox_inches="tight")
plt.show()
