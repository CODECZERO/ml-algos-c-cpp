# this file is ai generated
# it aims to test linear regression c code vs pre build model sklearn code
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# 1. Load input data (used for training Python model)
input_df = pd.read_csv("./data/input_10000.csv")
X = input_df["X"].values.reshape(-1, 1)
Y = input_df["Y"].values

# 2. Train linear regression model
model = LinearRegression()
model.fit(X, Y)

a_py = model.intercept_
b_py = model.coef_[0]

print("Python Linear Regression:")
print(f"  Intercept (a): {a_py:.6f}")
print(f"  Slope (b): {b_py:.6f}")

# 3. Load C program output file
c_df = pd.read_csv("./data/output_c.csv")
X_c = c_df["X"].values
Y_c = c_df["Y"].values
Pred_c = c_df["PredictedY"].values

# Extract slope/intercept from C model by simple regression fit
model_c = LinearRegression()
model_c.fit(X_c.reshape(-1, 1), Pred_c)
a_c = model_c.intercept_
b_c = model_c.coef_[0]

print("\nC Program Linear Regression:")
print(f"  Intercept (a): {a_c:.6f}")
print(f"  Slope (b): {b_c:.6f}")

# 4. Compare values
print("\nDifference (Python - C):")
print(f"  Intercept Δa: {a_py - a_c:.6f}")
print(f"  Slope Δb: {b_py - b_c:.6f}")

# 5. Plot graphs
plt.figure(figsize=(10, 6))

# Plot original data
plt.scatter(X, Y, color="gray", alpha=0.3, label="Original Data")

# Python regression line
plt.plot(
    X,
    model.predict(X),
    color="blue",
    linewidth=2,
    label=f"Python Model (a={a_py:.2f}, b={b_py:.2f})",
)

# C regression line
plt.plot(
    X_c,
    Pred_c,
    color="red",
    linewidth=2,
    linestyle="--",
    label=f"C Model (a={a_c:.2f}, b={b_c:.2f})",
)

plt.xlabel("X")
plt.ylabel("Y")
plt.title("Linear Regression: Python vs C Output")
plt.legend()
plt.grid(True)
plt.show()
