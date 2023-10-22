#include"matrixClass.cpp"
/*
Functions to manipulate multiple matrixes at once
dotProduct (matrix -> matrix0, matrix -> matrix1) -> matrix
matrixSums (matarix -> matrix0, matrix -> matrix1) -> matrix
*/

matrix dotProduct (matrix matrix0, matrix matrix1) {
        /* dotProduct (matrix -> matrix0, matrix -> matrix1) -> matrix
        Multipies two matrix together using dot-product
        Returns 0x0 matrix and stdout error if matrix0.columns != matrix1.rows*/
        if (matrix0.columns != matrix1.rows) {
                std::cout << "ERROR! These size matrix are not multiplyable";
                matrix e(0, 0);
                return e;
        }
        matrix1.transpose(); //This is increadably useful due to memory calls, trust me.
        matrix tmpMatrix(matrix0.rows-1, matrix0.columns-1);
        for (int row = 1; row < matrix0.rows; row++) {
                for (int column = 1; column < matrix0.columns; column++) {
                        int runningSum = 0;
                        for (int i = 1; i < matrix1.rows; i++) {
                                runningSum += matrix0.Matrix[row][i]*matrix1.Matrix[column][i];
                        }
                        tmpMatrix.Matrix[row][column] = runningSum;
                }
        }
        return tmpMatrix;
}

matrix matrixSums (matrix matrix0, matrix matrix1) {
        /* mattrixSums (matrix -> matrix0, matrix -> matrix1) -> matrix
        Adds matrix0 and matrix1 returning a matrix or the same size
        Returns 0x0 matrix and stdout error if matrix0.columns != matrix1.rows*/
        if (matrix0.rows != matrix1.rows or matrix0.columns != matrix1.columns) {
                std::cout << "ERROR! These size matrix are not multiplyable";
                matrix e(0, 0);
                return e;
        }
        matrix tmpMatrix(matrix0.rows-1, matrix0.columns-1);
        for (int row = 1; matrix0.rows > row; row++) {
                for (int column = 1; matrix0.columns > column; column++) {
                        tmpMatrix.Matrix[row][column] = matrix0.Matrix[row][column] + matrix1.Matrix[row][column];
                }
        }
}
