#include<iostream>

/*
Main class for matrix, future will call for multi-class
Trying to limit external librarys to minimize any dependincies
*/
class matrix   {
/*
matrix (int -> rows, int -> columns) -> matrix of rows*columns size
matrixFill () -> fills matrix going across columns then down rows incramentin by 1
matrixRead () -> std::cout's all values of the matrix
transpose () -> transposes matrix flipping rows with columns and returning that value
*/

public:
        matrix(int rows, int columns) { //defined for building the matrix
                rows++;
                columns++;
                matrix::rows = rows;
                matrix::columns = columns;
                Matrix = (int **) malloc (rows * sizeof(int *));
                Matrix[0] = (int *) malloc((rows*columns)*sizeof(int));
                for (int i = 1; rows > i; i++) {
                        Matrix[i] = Matrix[i-1]+columns;
                }
        };
        int **Matrix;
        int rows, columns;
        void matrixFill();
        void read();
        void transpose();
};

void matrix::transpose ()   {
        /*Writes over current matrix with Row->Column flipped matrix*/
        matrix tmpMatrix(columns-1, rows-1);
        for(int i = 1; i < rows; i++) {
                for(int j = 1; j < columns; j++)
                tmpMatrix.Matrix[j][i] = matrix::Matrix[i][j];
        }
        free(Matrix[0]);
        matrix::Matrix = tmpMatrix.Matrix; //Releasing memory
        rows = tmpMatrix.rows;
        columns = tmpMatrix.columns;

}

void matrix::matrixFill()   {
        /*Returns called self but every value is filled row by row incramenting
        This mainly exists for testing and has a non-zero possibility of being removed*/
        int count = 0;
        for (int i = 1; i < rows; i++) {
                for (int j = 1; j < columns; j++) {
                        Matrix[i][j] = count++;
                }
        }
};

void matrix::read ()   {
        /*stdout all values of self, seperated by commas*/
        std::cout << rows-1 << "x" << columns-1 << std::endl;
        for(int i = 1; i < rows; i++)   {
                for(int j = 1; j < columns; j++)   {
                        std::cout << matrix::Matrix[i][j] << ", ";
                }
                std::cout << std::endl;
        }
};

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