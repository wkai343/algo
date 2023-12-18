#include <cstring>
struct Matrix {
    int data[2][2];
    Matrix() {}
    Matrix(int x00, int x01, int x10, int x11) {
        data[0][0] = x00, data[0][1] = x01, data[1][0] = x10, data[1][1] = x11;
    }
};
Matrix multiply(Matrix A, Matrix B) {
    Matrix C;
    memset(&C, 0, sizeof(Matrix));
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            for(int k = 0; k < 2; ++k)
                C.data[i][j] += A.data[i][k] * B.data[k][j];
    return C;
}