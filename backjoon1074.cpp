//#include<cmath>
//#include<vector>
//#include<iostream>
//
//int Count = 0;
//std::vector<std::vector<int>> vec{};
//void w(int StartX, int EndX, int StartY, int EndY, int size)
//{
//	if (size <= 1)
//	{
//		if (vec[StartY][StartX] == 0)
//		{
//			vec[StartY][StartX] = Count;
//			Count++;
//		}
//		return;
//	}
//	int DivideSize = size / 2;
//	w(StartX, EndX / 2, StartY, EndY / 2, DivideSize);
//	w(StartX + (DivideSize), EndX, StartY, EndY / 2, DivideSize);
//	w(StartX, EndX / 2, StartY + (DivideSize), EndY, DivideSize);
//	w(StartX + (DivideSize), EndX, StartY + (DivideSize), EndY, DivideSize);
//
//}
//
//
//int main()
//{
//	int N = 0;
//	int r = 0;
//	int c = 0;
//	std::cin >> N >> r >> c;
//	int RowSize = std::pow(2, N);
//	vec.resize(RowSize);
//	for (int i = 0; i < RowSize; i++)
//	{
//		vec[i].resize(RowSize);
//	}
//	w(0, RowSize - 1, 0, RowSize - 1, RowSize);
//
//
//	std::cout << vec[r][c] << std::endl;
//
//	vec.clear();
//	return 0;
//}