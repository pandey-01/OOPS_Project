import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from scipy import stats

# 1. Load Dataset
df = sns.load_dataset('iris')

# 2. Basic Statistics
print("Summary Statistics:\n", df.describe())

# 3. Normality Test (Shapiro-Wilk)
stat, p = stats.shapiro(df['sepal_length'])
print(f'\nSepal Length Normality Test: Statistics={stat:.3f}, p={p:.3f}')
if p > 0.05:
    print('Sample looks Gaussian (fail to reject H0)')
else:
    print('Sample does not look Gaussian (reject H0)')

# 4. Skewness and Kurtosis
print("\nSkewness:\n", df.skew(numeric_only=True))

# 5. Correlation Analysis
plt.figure(figsize=(8,6))
sns.heatmap(df.corr(numeric_only=True), annot=True, cmap='coolwarm')
plt.title("Correlation Matrix")
plt.show()

# 6. Visualization
df.hist(bins=20, figsize=(10,8))
plt.suptitle("Feature Distributions")
plt.show()