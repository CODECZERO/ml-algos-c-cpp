import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# ---------------- Python Linear Regression ----------------
py_df = pd.read_csv("./data/input_10000.csv")
# keep only numeric values (drop headers/non-numeric if present)
py_df = py_df.apply(pd.to_numeric, errors="coerce").dropna()

X = py_df.iloc[:, 0].values.reshape(-1, 1)  # first column = x
Y = py_df.iloc[:, 1].values  # second column = y

# Train Python regression model
py_model = LinearRegression().fit(X, Y)
py_pred = py_model.predict(X)

print("Python Linear Regression:")
print(f"  Intercept (a): {py_model.intercept_}")
print(f"  Slope (b): {py_model.coef_[0]}")

# ---------------- C Output ----------------
c_df = pd.read_csv("./data/output_c.csv")
c_df = c_df.apply(pd.to_numeric, errors="coerce").dropna()

c_x = c_df.iloc[:, 0].values
c_y = c_df.iloc[:, 1].values

# ---------------- Plotting ----------------
plt.figure(figsize=(15, 5))

# 1. Python regression
plt.subplot(1, 3, 1)
plt.scatter(X, Y, color="blue", alpha=0.6, label="Python Data")
plt.plot(X, py_pred, color="red", label="Python Fit")
plt.title("Python Linear Regression")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()

# 2. C regression output
plt.subplot(1, 3, 2)
plt.scatter(c_x, c_y, color="green", alpha=0.6, label="C Output")
plt.title("C Regression Output")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()

# 3. Combined
plt.subplot(1, 3, 3)
plt.scatter(X, Y, color="blue", alpha=0.5, label="Python Data")
plt.plot(X, py_pred, color="red", label="Python Fit")
plt.scatter(c_x, c_y, color="green", alpha=0.5, label="C Output")
plt.title("Python vs C Regression")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()

plt.tight_layout()
plt.show()
