# 📊 Linear Regression in C

This project implements a **simple linear regression model in C** that:

* Reads input data from a **CSV file** (`X`, `Y` values).
* Trains a regression model (slope `a` and intercept `b`).
* Generates predictions and error values.
* Writes results to an **output CSV file**.
* Can be compared with a Python linear regression model for validation.

---

## 🚀 Features

* CSV **read/write** modules (`fileReader.c`, `fileReader.h`).
* **Algorithm module** (`algoK.c`, `algoK.h`) to compute regression.
* **Main file** (`main.c`) to connect everything.
* Modular design for readability and reusability.
* Works with datasets of **any size** (e.g., 10K rows).

---

## 📂 Project Structure

```
.
├── main.c            # Entry point
├── algoK.c           # Linear regression implementation
├── algoK.h           # Header for regression functions
├── fileReader.c      # CSV input/output functions
├── fileReader.h      # Header for CSV I/O
├── input.csv         # Example dataset
├── output.csv        # Results after training
└── README.md         # Project documentation
```

---

## 🔧 Compilation & Run

Use **gcc** (or any C compiler) to build the project.

```bash
# Compile all files together
gcc main.c algoK.c fileReader.c -o linreg -lm

# Run with input/output files
./linreg input.csv output.csv
```

---

## 📄 Example Input (`input.csv`)

```csv
X,Y
1,2
2,4
3,6
4,8
5,10
```

---

## 📄 Example Output (`output.csv`)

```csv
X,Y,Prediction,Error
1,2,2.0,0.0
2,4,4.0,0.0
3,6,6.0,0.0
4,8,8.0,0.0
5,10,10.0,0.0
```

---

## 📊 Python Comparison

We also provide a **Python script** (`compare.py`) to validate results against `scikit-learn`’s `LinearRegression`.

```bash
python compare.py input.csv output.csv
```

This script:

* Trains a regression model in Python.
* Reads C output (`output.csv`).
* Plots graphs for comparison.
* Checks slope/intercept differences.

---

## 🛠 Dependencies

* C compiler (GCC / Clang / MSVC).
* `math.h`, `stdio.h`, `stdlib.h` (standard C libraries).
* (Optional) Python 3 with `numpy`, `matplotlib`, `pandas`, `scikit-learn` for validation.

---

## 📌 To Do

* [ ] Add support for multiple regression.
* [ ] Implement Mean Squared Error (MSE) reporting.
* [ ] Add unit tests.

---

## 📜 License

MIT License – free to use, modify, and distribute.
