#define ROWS 3
# define COLS 3

void print_matrix(int *matrix) {
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < Cols; col++) {
            printf("%d ", arr[row][col]);
        }
        printf("\n");
    }
}

void add_matrices(int *mA, int *mB, int *result) {
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < Cols; col++) {
            result[row][col] = mA[row][col] + mB[row][col];
        }
    }
}


int main(void) {
    
}

