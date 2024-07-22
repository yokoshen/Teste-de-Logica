#include <iostream>
#include "Windows.h"

#define MAX_ARRAY 14
#define NULLO 999 
using namespace std;

int OriginalArray[MAX_ARRAY] = { 2, 1, 5, 2, 5, 2, 1, 1, 1, 7, 9, 13, 127, 21 };

int main()
{
	int ArrayFinal[MAX_ARRAY] = { NULL };
	int Count = 0;

	for (int loop1 = 0; loop1 < MAX_ARRAY; loop1++)
	{
		if (OriginalArray[loop1] == 1)
		{
			for (int loop2 = 0; loop2 < MAX_ARRAY; loop2++)
			{
				if (ArrayFinal[loop2] == 0)
				{
					ArrayFinal[loop2] = 1;
					Count++;
					break;
				}
			}

			OriginalArray[loop1] = NULLO;
		}
	}

	for (int loop1 = 0; loop1 < MAX_ARRAY; loop1++)
	{
		if (OriginalArray[loop1] != NULLO)
		{
			for (int loop2 = Count; loop2 < MAX_ARRAY; loop2++)
			{
				ArrayFinal[loop2] = OriginalArray[loop1];
				Count++;
				break;
			}
		}
	}

	for (int loop = 0; loop < MAX_ARRAY; loop++)
	{
		if (loop < MAX_ARRAY - 1)
			cout << ArrayFinal[loop] << ",";
		else
			cout << ArrayFinal[loop];
	}


	cout << "\n";
	system("pause");
	return 0;
}
