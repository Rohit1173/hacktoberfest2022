// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function that generate all valid
// triplets and calculate the value
// of the valid triplets
void max_valid_triplet(int A[], int n)
{
	int ans = -1;

	// Generate all triplets
	for(int i = 0; i < n - 2; i++)
	{
		for(int j = i + 1; j < n - 1; j++)
		{
			for(int k = j + 1; k < n; k++)
			{
				
				// Check whether the triplet
				// is valid or not
				if (A[i] < A[j] && A[j] < A[k])
				{
					int value = A[i] + A[j] * A[k];

					// Update the value
					if (value > ans)
					{
						ans = value;
					}
				}
			}
		}
	}
	
	// Print the maximum value
	cout << (ans);
}

// Driver Code
int main()
{
	
	// Given array arr[]
	int arr[] = { 7, 9, 3, 8, 11, 10 };

	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	max_valid_triplet(arr, n);
	return 0;
}
