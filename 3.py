import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score
from sklearn.preprocessing import StandardScaler
import seaborn as sns

# 1. Prepare Data
df = sns.load_dataset('iris')
X = df.drop('species', axis=1)
y = df['species']

# Scale features for distance-based algorithm
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

X_train, X_test, y_train, y_test = train_test_split(X_scaled, y, test_size=0.2, random_state=42)

# 2. Standard KNN (Uniform weights)
knn_std = KNeighborsClassifier(n_neighbors=5, weights='uniform')
knn_std.fit(X_train, y_train)
y_pred_std = knn_std.predict(X_test)

# 3. Distance-Weighted KNN
knn_weight = KNeighborsClassifier(n_neighbors=5, weights='distance')
knn_weight.fit(X_train, y_train)
y_pred_weight = knn_weight.predict(X_test)

print(f"Standard KNN Accuracy (k=5): {accuracy_score(y_test, y_pred_std):.2%}")
print(f"Weighted KNN Accuracy (k=5): {accuracy_score(y_test, y_pred_weight):.2%}")