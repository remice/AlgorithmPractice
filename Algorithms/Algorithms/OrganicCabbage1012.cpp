#include <iostream>

using namespace std;

int GroundArray[50][50] = { 0 };

#define NOTHING 0
#define CABBAGE 1

void ProtectCabbage(int FirstIndex, int SecondIndex)
{
	if (FirstIndex < 0 || FirstIndex >= 50 || SecondIndex < 0 || SecondIndex >= 50)
	{
		return;
	}
	
	if (GroundArray[FirstIndex][SecondIndex] == NOTHING)
	{
		return;
	}

	GroundArray[FirstIndex][SecondIndex] = NOTHING;

	ProtectCabbage(FirstIndex + 1, SecondIndex);
	ProtectCabbage(FirstIndex - 1, SecondIndex);
	ProtectCabbage(FirstIndex, SecondIndex + 1);
	ProtectCabbage(FirstIndex, SecondIndex - 1);
}

int main()
{
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int M, N, K;

		cin >> M >> N >> K;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				GroundArray[i][j] = 0;
			}
		}

		int Ix, Iy;

		for (int i = 0; i < K; i++)
		{
			cin >> Ix >> Iy;
			GroundArray[Iy][Ix] = CABBAGE;
		}

		int Count = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (GroundArray[i][j] == CABBAGE)
				{
					Count++;
					ProtectCabbage(i, j);
				}
			}
		}
		cout << Count << endl;
	}
}