#include"MatrixLib.hpp"

int main () {
        matrix X(4,4);
        matrix Y(4,4);
        X.matrixFill();
        Y.matrixFill();
        matrix Z = matrixSums(X,Y);
        Z.read();
}/*
Functions to manipulate multiple matrixes at once
dotProduct (matrix -> matrix0, matrix -> matrix1) -> matrix
matrixSums (matarix -> matrix0, matrix -> matrix1) -> matrix
*/