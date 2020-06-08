#include "matrix.h"

Matrix::Matrix(int rows, int cols) {
    if (rows < 0 || cols < 0) {
        throw invalid_argument("Rows and columns of matrix must be positive");
    }
    this->rows = rows;
    this->cols = cols;
    int numValues = rows * cols;
    this->arr = new int[numValues];
    for (int i = 0; i < numValues; i++)
        arr[i] = 0;
}

Matrix::Matrix() {
    this->rows = 0;
    this->cols = 0;
    this->arr = new int[0];
}

Matrix::Matrix(Matrix &&m) {
    rows = m.rows;
    cols = m.cols;
    arr = m.arr;
    m.arr = nullptr;
}

Matrix::~Matrix() {
    delete[] arr;
}

Matrix::Matrix(const Matrix &m) {
    rows = m.rows;
    cols = m.cols;
    int numValues = rows * cols;
    arr = new int[numValues];
    for (int i = 0; i < numValues; i++) {
        arr[i] = m.arr[i];
    }
}

Matrix & Matrix::operator=(const Matrix &m) {
    if (this == &m)
        return *this;

    delete[] arr;
    rows = m.rows;
    cols = m.cols;
    int numValues = rows * cols;
    arr = new int[numValues];
    for (int i = 0; i < numValues; i++) {
        arr[i] = m.arr[i];
    }

    return *this;
}

Matrix & Matrix::operator=(Matrix &&m) {
    if (this == &m)
        return *this;

    rows = m.rows;
    cols = m.cols;
    delete[] arr;
    arr = m.arr;
    m.arr = nullptr;
    return *this;
}

int Matrix::get(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols || rows * cols == 0) {
        throw invalid_argument("Out of bounds exception!");
    }
    return this->arr[r * this->cols + c];
}

void Matrix::set(int r, int c, int value) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || rows * cols == 0) {
        throw invalid_argument("Out of bounds exception!");
    }
    this->arr[r * this->cols + c] = value;
}

bool Matrix::operator==(const Matrix &m) const {
    if (rows == m.rows && cols == m.cols) {
        int numValues = rows * cols;
        for (int i = 0; i < numValues; i++) {
            if (arr[i] != m.arr[i])
                return false;
        }
        return true;
    }
    return false;
}

bool Matrix::operator!=(const Matrix &m) const {
    return !(*this == m);
}

Matrix & Matrix::operator+=(const Matrix &rhs) {
    if (cols != rhs.cols || rows != rhs.rows) {
        throw invalid_argument("Matrices must be same size!");
    }
    int numValues = rows * cols;
    for (int i = 0; i < numValues; i++) {
        arr[i] += rhs.arr[i];
    }
    return *this;
}

Matrix & Matrix::operator-=(const Matrix &rhs) {
    if (cols != rhs.cols || rows != rhs.rows) {
        throw invalid_argument("Matrices must be same size!");
    }
    int numValues = rows * cols;
    for (int i = 0; i < numValues; i++) {
        arr[i] -= rhs.arr[i];
    }
    return *this;
}

Matrix & Matrix::operator*=(const Matrix &rhs) {
    Matrix result = Matrix(this->rows, rhs.cols);
    result = *this * rhs;
    *this = result;
    return *this;
}
