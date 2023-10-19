#include<iostream>

/*
Main class for matrix, future will call for multi-class
Trying to limit external librarys to minimize any dependincies
*/
class mxTool   {
/*
mxTool (int -> rows, int -> columns) -> matrix of rows*columns size
matrixFill () -> fills matrix going across columns then down rows incramentin by 1
matrixRead () -> std::cout's all values of the matrix
transpose () -> transposes matrix flipping rows with columns and returning that value
*/

public:
        mxTool(int rows, int columns) { //defined for building the matrix
                rows++;
                columns++;
                mxTool::rows = rows;
                mxTool::columns = columns;
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

void mxTool::transpose ()   {
        mxTool tmpMatrix(columns-1, rows-1);
        for(int i = 1; i < rows; i++) {
                for(int j = 1; j < columns; j++)
                tmpMatrix.Matrix[j][i] = mxTool::Matrix[i][j];
        }
        free(Matrix[0]);
        mxTool::Matrix = tmpMatrix.Matrix;
        rows = tmpMatrix.rows;
        columns = tmpMatrix.columns;

}

void mxTool::matrixFill()   {
        int count = 0;
        for (int i = 1; i < rows; i++) {
                for (int j = 1; j < columns; j++) {
                        Matrix[i][j] = count++;
                }
        }
};

void mxTool::read ()   {
        std::cout << rows-1 << "x" << columns-1 << std::endl;
        for(int i = 1; i < rows; i++)   {
                for(int j = 1; j < columns; j++)   {
                        std::cout << mxTool::Matrix[i][j] << ", ";
                }
                std::cout << std::endl;
        }
};


