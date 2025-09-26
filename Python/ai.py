# AI/ML Study Example: Handwritten Digit Classification

from sklearn.datasets import load_digits
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, classification_report
import matplotlib.pyplot as plt

# Step 1: Load the dataset
digits = load_digits()

print("Dataset shape:", digits.data.shape)
print("Number of classes:", len(digits.target_names))

# Step 2: Visualize some sample digits
plt.gray()
for i in range(6):
    plt.subplot(2, 3, i + 1)
    plt.imshow(digits.images[i], cmap='gray')
    plt.title(f"Label: {digits.target[i]}")
plt.show()

# Step 3: Split dataset into training and testing
X_train, X_test, y_train, y_test = train_test_split(
    digits.data, digits.target, test_size=0.2, random_state=42
)

# Step 4: Train a simple Logistic Regression model
model = LogisticRegression(max_iter=2000)
model.fit(X_train, y_train)

# Step 5: Evaluate the model
y_pred = model.predict(X_test)

print("Accuracy:", accuracy_score(y_test, y_pred))
print("\nClassification Report:\n", classification_report(y_test, y_pred))