#include<iostream>
#include"matrixFunctions.cpp"

/*
Main class for matrix, future will call for multi-class
Trying to limit external librarys to minimize any dependincies
matrix (int -> rows, int -> columns) -> matrix of rows*columns size
matrixFill () -> fills matrix going across columns then down rows incramentin by 1
matrixRead () -> std::cout's all values of the matrix
transpose () -> transposes matrix flipping rows with columns and returning that value
Functions to manipulate multiple matrixes at once
dotProduct (matrix -> matrix0, matrix -> matrix1) -> matrix
matrixSums (matarix -> matrix0, matrix -> matrix1) -> matrix
*/
class matrix;
matrix dotProduct (matrix matrix0, matrix matrix1); //See matrixFunctions.hpp
matrix matrixSums (matrix matrix0, matrix matrix1);