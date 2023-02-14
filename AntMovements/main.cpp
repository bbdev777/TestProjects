#include <stdio.h>
#include <stdlib.h>

#include "./src/AntMovements.h"

void	PrintMatrix(const TestTask::MatrixType& matrix);
void	RunDebugTest();
void	RunTaskTest();

int main(int argc, char* argv[])
{
	printf("AntMovements v1.0\n");
	
	RunDebugTest();

	RunTaskTest();

    //printf("\n\nPress Enter key to exit.\n\n");

    //int symbol = getchar();

	return 0; 
}

void	PrintMatrix(const TestTask::MatrixType& matrix)
{
	for (int y = 0, rowCount = matrix.size(); y < rowCount; y++)
	{
		for (int x = 0, cellCount = matrix[y].size(); x < cellCount; x++)
		{
			if (matrix[y][x].sumValue >= 0)
				printf("%c ", matrix[y][x].visited ? 'O' : 'X');
			else
				printf("  ");
		}

		printf("\n");
	}
}

void	RunDebugTest()
{
	printf("\nDebug test\n");

	TestTask::AntMovements	solver(12);

	//PrintMatrix(solver.GetMatrix());

	int fieldSize = solver.CalculateAccessibleFieldSize();

	printf("Debug matrix\n");
	PrintMatrix(solver.GetMatrix());

	printf("Max sum number is : %d\n", solver.GetMaxSumOfDigits());
	printf("Cell count: %d\n", fieldSize);
}

void	RunTaskTest()
{
	printf("\nTask test\n");

	TestTask::AntMovements	solver(25);

	int fieldSize = solver.CalculateAccessibleFieldSize();

	printf("Max sum number is : %d\n", solver.GetMaxSumOfDigits());
	printf("Cell count: %d\n", fieldSize);
}
