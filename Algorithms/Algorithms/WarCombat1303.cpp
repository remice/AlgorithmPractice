//
//#include <iostream>
//
//using namespace std;
//
//#define ALLIY -1
//#define ENEMY -2
//
//int IntArray[100][100] = { 0 };
//
//int CalcAlliyPower(int FirstIndex, int SecondIndex)
//{
//	if (FirstIndex < 0 || FirstIndex >= 100 || SecondIndex < 0 || SecondIndex >= 100)
//	{
//		return 0;
//	}
//
//	if (IntArray[FirstIndex][SecondIndex] != ALLIY)
//	{
//		return 0;
//	}
//
//	int Sum = 1;
//
//	IntArray[FirstIndex][SecondIndex] = 0;
//
//	Sum += CalcAlliyPower(FirstIndex - 1, SecondIndex);
//	Sum += CalcAlliyPower(FirstIndex + 1, SecondIndex);
//	Sum += CalcAlliyPower(FirstIndex, SecondIndex - 1);
//	Sum += CalcAlliyPower(FirstIndex, SecondIndex + 1);
//
//	return Sum;
//}
//
//int CalcEnemyPower(int FirstIndex, int SecondIndex)
//{
//	if (FirstIndex < 0 || FirstIndex >= 100 || SecondIndex < 0 || SecondIndex >= 100)
//	{
//		return 0;
//	}
//
//	if (IntArray[FirstIndex][SecondIndex] != ENEMY)
//	{
//		return 0;
//	}
//
//	int Sum = 1;
//
//	IntArray[FirstIndex][SecondIndex] = 0;
//
//	Sum += CalcEnemyPower(FirstIndex - 1, SecondIndex);
//	Sum += CalcEnemyPower(FirstIndex + 1, SecondIndex);
//	Sum += CalcEnemyPower(FirstIndex, SecondIndex - 1);
//	Sum += CalcEnemyPower(FirstIndex, SecondIndex + 1);
//
//	return Sum;
//}
//
//int main()
//{
//	cin.tie(0);
//	cout.tie(0);
//
//	int N, M;
//	cin >> N >> M;
//
//
//	char TempCharArray[101];
//	for (int i = 0; i < M; i++)
//	{
//		cin >> TempCharArray;
//		
//		for (int j = 0; j < N; j++)
//		{
//			if (TempCharArray[j] == 'W')
//			{
//				IntArray[i][j] = ALLIY;
//			}
//			else 
//			{
//				IntArray[i][j] = ENEMY;
//			}
//		}
//	}
//
//
//	int AlliyPower = 0, EnemyPower = 0, TempValue = 0;
//
//	for (int i = 0; i < M; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if (IntArray[i][j] == ALLIY)
//			{
//				TempValue = CalcAlliyPower(i, j);
//				AlliyPower += TempValue * TempValue;
//			}
//			else if (IntArray[i][j] == ENEMY)
//			{
//				TempValue = CalcEnemyPower(i, j);
//				EnemyPower += TempValue * TempValue;
//			}
//		}
//	}
//	cout << AlliyPower << " " << EnemyPower;
//}