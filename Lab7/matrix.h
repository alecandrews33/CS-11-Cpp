#include <stdexcept>

using namespace std;

/**
 * This class represents a 2D matrix using a 1D matrix in memory;
 */
class Matrix {
    /** The number of rows in the matrix */
    int rows;

    /** The number of cols in the matrix */
    int cols;

    /**
     * The 1D array that stores the values of the 2D matrix. Indexed by
     * row-major order.
     */
    int *arr;

public:
    /**
     * Initializes a rows x cols matrix where all elements are set to 0.
     * The rows and cols values must be positive, or an invalid_argument
     * exception should be thrown.
     *
     * @param rows The number of rows
     * @param cols The number of cols
     * @return The rows x cols Matrix object
     */
    Matrix(int rows, int cols);

    /**
     * Initializes a 0x0 matrix.
     *
     * @return The 0x0 Matrix object
     */
    Matrix();

    /** Move constructor */
    Matrix(Matrix &&m);

    /** Destructor for the Matrix class. */
    ~Matrix();

    /** Copy-constructor for Matrix class. */
    Matrix(const Matrix &m);

    /** Copy-assignment operator for Matrix class. */
    Matrix & operator=(const Matrix &m);

    /** Move assignment operator for Matrix class. */
    Matrix & operator=(Matrix &&m);

    /**
     * Returns the number of rows in this particular Matrix.
     *
     * @return The number of rows
     */
    int numRows() const {
        return rows;
    }

    /**
     * Returns the number of columns in this particular Matrix.
     *
     * @return The number of columns
     */
    int numCols() const {
        return cols;
    }

    /**
     * Retrieves the value stored at (r, c) in the Matrix.
     *
     * @param r The number of rows
     * @param c The number of columns
     * @return The int at (r,c)
     */
    int get(int r, int c) const;

    /**
     * Sets the value at (r, c) to value in the Matrix.
     *
     * @param r The number of rows
     * @param c The number of cols
     * @param value The value to set (r, c) to
     */
    void set(int r, int c, int value);

    /** Equality operator for Matrix class */
    bool operator==(const Matrix &m) const;

    /** Inequality operator for Matrix class */
    bool operator!=(const Matrix &m) const;

    /** Addition assignment operator for Matrix class */
    Matrix & operator+=(const Matrix &rhs);

    /** Subtraction assignment operator for Matrix class */
    Matrix & operator-=(const Matrix &rhs);

    /** Multiplication assignment operator for Matrix class */
    Matrix & operator*=(const Matrix &rhs);
};

/** Operator overload for matrix addition */
inline const Matrix operator+(const Matrix &m1, const Matrix &m2) {
    Matrix result = Matrix(m1);
    result += m2;
    return result;
}

/** Operator overload for matrix subtraction */
inline const Matrix operator-(const Matrix &m1, const Matrix &m2) {
    Matrix result = Matrix(m1);
    result -= m2;
    return result;
}

/** Operator overload for matrix multiplication */
inline const Matrix operator*(const Matrix &m1, const Matrix &m2) {
    if (m1.numCols() != m2.numRows()) {
        throw invalid_argument("Dimensions not aligned. Can't multiply!");
    }
    Matrix result = Matrix(m1.numRows(), m2.numCols());
    for (int k = 0; k < m2.numCols(); k++) {
      for (int i = 0; i < m1.numRows(); i++) {
          int entry = 0;
          for (int j = 0; j < m1.numCols(); j++) {
               entry += m1.get(i, j) * m2.get(j, k);
          }
          result.set(i, k, entry);
      }
    }
    return result;
}
