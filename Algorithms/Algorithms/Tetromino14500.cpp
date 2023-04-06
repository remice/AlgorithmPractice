#include <iostream>

using namespace std;

short Paper[500][500] = {};

int UpDFS(const short index1, const short index2, const short depth);
int DownDFS(const short index1, const short index2, const short depth);
int LeftDFS(const short index1, const short index2, const short depth);
int RightDFS(const short index1, const short index2, const short depth);

int DFS(const short index1, const short index2, const short depth)
{
	int Temp = 0;
	int Max = UpDFS(index1, index2 + 1, depth - 1);
	Temp = DownDFS(index1, index2 - 1, depth - 1);
	Max = Temp > Max ? Temp : Max;
	Temp = LeftDFS(index1 - 1, index2, depth - 1);
	Max = Temp > Max ? Temp : Max;
	Temp = RightDFS(index1 + 1, index2, depth - 1);
	Max = Temp > Max ? Temp : Max;

	Max += Paper[index1][index2];

	return Max;
}

int UpDFS(const short index1, const short index2, const short depth)
{
	if (index1 < 0 || index1 >= 500 || index2 < 0 || index2 >= 500)
	{
		return -4000;
	}

	if (depth == 1)
	{
		return Paper[index1][index2];
	}

	int Temp = 0;
	int Max = UpDFS(index1, index2 + 1, depth - 1);
	Temp = LeftDFS(index1 - 1, index2, depth - 1);
	Max = Temp > Max ? Temp : Max;
	Temp = RightDFS(index1 + 1, index2, depth - 1);
	Max = Temp > Max ? Temp : Max;

	Max += Paper[index1][index2];

	return Max;
}

int DownDFS(const short index1, const short index2, const short depth)
{
	if (index1 < 0 || index1 >= 500 || index2 < 0 || index2 >= 500)
	{
		return -4000;
	}

	if (depth == 1)
	{
		return Paper[index1][index2];
	}

	int Temp = 0;
	int Max = DownDFS(index1, index2 - 1, depth - 1);
	Temp = LeftDFS(index1 - 1, index2, depth - 1);
	Max = Temp > Max ? Temp : Max;
	Temp = RightDFS(index1 + 1, index2, depth - 1);
	Max = Temp > Max ? Temp : Max;

	Max += Paper[index1][index2];

	return Max;
}

int LeftDFS(const short index1, const short index2, const short depth)
{
	if (index1 < 0 || index1 >= 500 || index2 < 0 || index2 >= 500)
	{
		return -4000;
	}

	if (depth == 1)
	{
		return Paper[index1][index2];
	}

	int Temp = 0;
	int Max = UpDFS(index1, index2 + 1, depth - 1);
	Temp = LeftDFS(index1 - 1, index2, depth - 1);
	Max = Temp > Max ? Temp : Max;
	Temp = DownDFS(index1, index2 - 1, depth - 1);
	Max = Temp > Max ? Temp : Max;

	Max += Paper[index1][index2];

	return Max;
}

int RightDFS(const short index1, const short index2, const short depth)
{
	if (index1 < 0 || index1 >= 500 || index2 < 0 || index2 >= 500)
	{
		return -4000;
	}

	if (depth == 1)
	{
		return Paper[index1][index2];
	}

	int Temp = 0;
	int Max = UpDFS(index1, index2 + 1, depth - 1);
	Temp = DownDFS(index1, index2 - 1, depth - 1);
	Max = Temp > Max ? Temp : Max;
	Temp = RightDFS(index1 + 1, index2, depth - 1);
	Max = Temp > Max ? Temp : Max;

	Max += Paper[index1][index2];

	return Max;
}

int CheckTBlock(const short index1, const short index2)
{
	int Min = 1500;
	int Sum = 0;
	int Temp = 0;

	Min = UpDFS(index1, index2 + 1, 1);
	Sum += Min;

	Temp = DownDFS(index1, index2 - 1, 1);
	Sum += Temp;
	Min = Temp < Min ? Temp : Min;

	Temp = LeftDFS(index1 - 1, index2, 1);
	Sum += Temp;
	Min = Temp < Min ? Temp : Min;

	Temp = RightDFS(index1 + 1, index2, 1);
	Sum += Temp;
	Min = Temp < Min ? Temp : Min;

	Sum -= Min;
	Sum += Paper[index1][index2];

	return Sum;
}

int main()
{
	cin.tie(0);
	cout.tie(0);

	short N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Paper[i][j];
		}
	}

	int Max = 0;
	int Temp = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			Temp = DFS(i, j, 4);
			Max = Temp > Max ? Temp : Max;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			Temp = CheckTBlock(i, j);
			Max = Temp > Max ? Temp : Max;
		}
	}

	cout << Max;
}