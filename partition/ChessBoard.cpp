#include <iostream>
void chessBoard(int** board, int tr, int tc, int dr, int dc, int k) {
    if(k == 0) return;
    int size = 1 << (k - 1);
    if(dr < tr + size && dc < tc + size) {
        chessBoard(board, tr, tc, dr, dc, k - 1);
    } else {
        board[tr + size - 1][tc + size - 1] = 1;
        chessBoard(board, tr, tc, tr + size - 1, tc + size - 1, k - 1);
    }
    if(dr < tr + size && dc >= tc + size) {
        chessBoard(board, tr, tc + size, dr, dc, k - 1);
    } else {
        board[tr + size - 1][tc + size] = 1;
        chessBoard(board, tr, tc + size, tr + size - 1, tc + size, k - 1);
    }
    if(dc < tc + size && dr >= tr + size) {
        chessBoard(board, tr + size, tc, dr, dc, k - 1);
    } else {
        board[tr + size][tc + size - 1] = 1;
        chessBoard(board, tr + size, tc, tr + size, tc + size - 1, k - 1);
    }
    if(dr >= tr + size && dc >= tc + size) {
        chessBoard(board, tr + size, tc + size, dr, dc, k - 1);
    } else {
        board[tr + size][tc + size] = 1;
        chessBoard(board, tr + size, tc + size, tr + size, tc + size, k - 1);
    }
}
int main() {
    int n, size, dr, dc;
    std::cin >> n;
    size = 1 << n;
    int** board = new int*[size];
    for(int i = 0; i < size; ++i) {
        board[i] = new int[size]{};
    }
    std::cin >> dr >> dc;
    board[dr][dc] = 1;
    chessBoard(board, 0, 0, dr, dc, n);
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    for(int i = 0; i < size; ++i) {
        delete[] board[i];
    }
    delete[] board;
}