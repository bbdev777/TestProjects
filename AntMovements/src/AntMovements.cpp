
#include "AntMovements.h"
#include <vector>
#include <list>

namespace TestTask
{
	using namespace std;

	int	AntMovements::CalculateAccessibleFieldSize()
	{	
		int	reachebleCellCount = 0;
		list<vector<std::pair<int, int>>> indecesToVisit;
		
		indecesToVisit.push_back(GetNbrForCoord(0, 0));

		while (indecesToVisit.begin() != indecesToVisit.end())
		{
			auto indeces = indecesToVisit.front();
			indecesToVisit.pop_front();

			for (auto& item : indeces)
			{
				auto& matrixItem = fieldMatrix[item.second][item.first];
				if (!matrixItem.visited && matrixItem.sumValue >= 0)
				{
					matrixItem.visited = true;
					indecesToVisit.push_back(GetNbrForCoord(item.first, item.second));
					reachebleCellCount++;
				}
			}
		}

		return reachebleCellCount;
	}

	std::vector<std::pair<int, int>> AntMovements::GetNbrForCoord(int baseX, int baseY)
	{
		std::vector<std::pair<int, int>>	nbrIndeces;

		if (baseX + 1 < fieldMatrix[baseY].size())
			nbrIndeces.emplace_back(baseX + 1, baseY);

		if (baseX - 1 >= 0)
			nbrIndeces.emplace_back(baseX - 1, baseY);

		if (baseY + 1 < fieldMatrix.size())
			nbrIndeces.emplace_back(baseX, baseY + 1);

		if (baseY - 1 >= 0)
			nbrIndeces.emplace_back(baseX, baseY - 1);

		return nbrIndeces;
	}

	int	AntMovements::GetSumOfDigits(int number)
	{
		int	sum = 0;

		while (number > 0)
		{
			int	digit = number % 10;
			sum += digit;

			number /= 10;
		}

		return sum;
	}

	int	AntMovements::GetSideLength(int startValue)
	{
		int sideLength = 0;
		int curValue = GetSumOfDigits(startValue);

		while (curValue <= maxSumOfDigits)
		{
			sideLength++;
			curValue = GetSumOfDigits(startValue + sideLength);
		}

		return sideLength;
	}

	int	AntMovements::FillInMatrix()
	{
		int	deltaX = GetSideLength(originX);
		int	deltaY = GetSideLength(originY);
		int cellCount = 0;

		fieldMatrix.clear();

		fieldMatrix.reserve(deltaY);
		int i = 0, j = 0, sumXY = 0;
		for (j = 0; j < deltaY; j++)
		{
			fieldMatrix.push_back(std::move(MatrixRow()));
			fieldMatrix.back().reserve(deltaX);

			int sumY = GetSumOfDigits(originY + j);
			for (i = 0; i < deltaX; i++)
			{
				int sumX = GetSumOfDigits(originX + i);
				sumXY = sumX + sumY;
				if (sumXY <= maxSumOfDigits)
					fieldMatrix.back().emplace_back(sumXY, originX + i, originY + j);
				else
					fieldMatrix.back().emplace_back(-1, 0, 0);
			}
		}

		return 0;
	}
}
