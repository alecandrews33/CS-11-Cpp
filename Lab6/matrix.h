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
     * @return the initialized Matrix object
     */
    Matrix(int rows, int cols);

    /** Initializes a 0x0 matrix. */
    Matrix();

    /** Destructor for the Matrix class. */
    ~Matrix();

    /**
     * Copy-constructor for Matrix class.
     */
    Matrix(const Matrix &m);

    /**
     * Copy-assignment operator for Matrix class.
     */
    Matrix & operator=(const Matrix &m);

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
     * @param r The row index of desired value
     * @param c The column index of desired value
     * @return The value stored at (r, c)
     */
    int get(int r, int c) const;

    /**
     * Sets the value at (r, c) to value in the Matrix.
     *
     * @param r The row index of the value to be set
     * @param c The column index of the value to be set
     * @param value The value to be set at (r,c)
     */
    void set(int r, int c, int value);

    /** Equality operator for Matrix class */
    bool operator==(const Matrix &m) const;

    /** Inequality operator for Matrix class */
    bool operator!=(const Matrix &m) const;
};
