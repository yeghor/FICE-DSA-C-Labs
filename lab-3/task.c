# include <stdio.h>
# include <math.h>

// For sleep()
#include <unistd.h>

// Ordered matrix traversal

int main() {

	// Note that rows amount must be even to display all the matrix elements according to task variant
    int rows = 6;
    int cols = 8;

	if (!((rows % 2) == 0)) {
//		printf("%s\n", "Rows amount must be even!");
		return 0;
	};

//	printf("%s\n", "Starting creating matrix...");

    // Create matrix
    int matrix[rows][cols];
    int matrixVal = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = matrixVal;
            matrixVal++;
        };
    };

//	printf("%s\n", "Matrix created");

	// Start position according to variant №14
	int i = ceil((rows-1) / 2);
	int j = (rows-1) - i;

	int normalization = (rows-1) - i;

//	printf("%s\n", "Starting displaying matrix spiral traversal...");

	while (i < rows && j < cols &&  (!(matrix[j][j] == matrix[rows-1][cols-1]))) {
		// While loop iteration: left -> up -> right -> down

		// Left
		for (j; j > normalization; i--) {
			usleep(100000);
			printf("\033[%d;%dH%d", i, j, matrix[i][j]);
		};

		// Up
		for (i; i > normalization; i--) {
			usleep(100000);
			printf("\033[%d;%dH%d", i, j, matrix[i][j]);
		};

		normalization -= 1;

		// Right
		for (j; j < (cols - 1) - normalization; j++) {
			usleep(100000);
			printf("\033[%d;%dH%d", i, j, matrix[i][j]);
		};

		// Down
		for (i; i > (rows-1) - normalization; i--) {
			usleep(100000);
			printf("\033[%d;%dH%d", i, j, matrix[i][j]);
		};
	};

//	printf("%s\n", "Matrix traversal displayed.");

    return 0;
};