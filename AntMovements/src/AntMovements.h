#pragma once

#include <vector>
namespace TestTask
{
	struct MatrixCell
	{
		int		coordX = 0;
		int		coordY = 0;
		int		sumValue = -1;
		bool	visited = false;

		MatrixCell() = default;

		MatrixCell(int sumValue, int coordX, int coordY) : 
			sumValue(sumValue), coordX(coordX), coordY(coordY) {}
	};

	typedef	std::vector<MatrixCell> MatrixRow;
	typedef	std::vector<MatrixRow> MatrixType;

	class	AntMovements
	{
	public:
		AntMovements() { FillInMatrix(); };

		AntMovements(int maxSumOfDigits) : maxSumOfDigits(maxSumOfDigits) { FillInMatrix(); };

		AntMovements(int originX, int originY, int maxSumOfDigits) :
			originX(originX), originY(originY), maxSumOfDigits(maxSumOfDigits) 	{FillInMatrix(); }

		int	CalculateAccessibleFieldSize();

		static int GetSumOfDigits(int number);

		int	GetOriginX() { return originX; }
		
		int	GetOriginY() { return originY; }

		int	GetMaxSumOfDigits() { return maxSumOfDigits; };

		const MatrixType& GetMatrix() { return fieldMatrix;  }

	protected:

		int	FillInMatrix();

		std::vector<std::pair<int, int>>GetNbrForCoord(int x, int y);

		int	GetSideLength(int startValue);

		int	originX = 1000;
		int	originY = 1000;

		int maxSumOfDigits = 12;
		
		MatrixType	fieldMatrix;
	};
}
