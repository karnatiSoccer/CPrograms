#include<stdio.h>
#include<math.h>

//Expected Output {{}, {1, }, {2, }, {1, 2, }, {3, }, {1, 3, }, {2, 3, }, {1, 2, 3, }, }
// Logic Total 2 power n sets can be formed. 
// Think the arrangements in terms of binary representation of numbers
// 000 001 010 011 100 101 110 111 , bit 1 represent which index to consider

void findPowerSet(int S[], int n)
{
	// N stores total number of subsets
	int N = pow(2, n);
	printf("{");
	// generate each subset one by one
	for (int i = 0; i < N; i++)
	{
		printf("{");
		// check every bit of i
		for (int j = 0; j < n; j++)
		{
			// if j'th bit of i is set, print S[j]
			if (i & (1 << j))
				printf("%d, ", S[j]);
		}
		printf("}, ");
	}
	printf("} ");
}

// main function
int main()
{
	int S[] = { 1, 2, 3 };
	int n = sizeof(S)/sizeof(S[0]);

	findPowerSet(S, n);

	return 0;
}