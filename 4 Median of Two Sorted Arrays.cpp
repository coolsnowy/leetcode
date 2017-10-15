/*
*There are two sorted arrays nums1 and nums2 of size m and n respectively.
*
*Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*
*Example 1:
*nums1 = [1, 3]
*nums2 = [2]
*
*The median is 2.0
*Example 2:
*nums1 = [1, 2]
*nums2 = [3, 4]
*
*The median is (2 + 3)/2 = 2.5
look solution
https://leetcode.com/problems/median-of-two-sorted-arrays/solution/
*/


#include <iostream>
#include <vector>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	//solution must insure n >= m
	int m = nums1.size(), n = nums2.size();
	if (m > n) {
		vector<int> temp = nums1;
		nums1 = nums2;
		nums2 = temp;
		int tempi = m;
		m = n;
		n = tempi;
	}
	int imin = 0, imax = m;
	//0,1,2,3 or 0,1,2,3,4 so i = 2£¬because left part form 0 to i-1
	//A 0,i-1 | i,m-1  B 0,j-1 | j,n-1 so i+j = m-i + n-j -> 2j = m+n-2i -> j = (m+n+1)/2 - i;1/2 == 0 not impact the result
	//if size is odd ,let the mid in the left ,so plus 1,when the size is odd ,median = max(a[i-1],b[j-1]) instead of max(a[i],b[j])
	int i = (imin + imax) / 2, j = (m + n + 1) / 2 - i;
	while (1) {
		if (i > 0 && nums1[i - 1] > nums2[j] ) {
			i = i - 1;
			j = j + 1;
		}
		else if (i < m && nums2[j - 1] > nums1[i] ) {
			j = j - 1;
			i = i + 1;
		}
		else {
			int max_left = 0, min_right = 0;
			double median = 0;
			if (i == 0)
				max_left = nums2[j - 1];
			else if (j == 0)
				max_left = nums1[i - 1];
			else {
				max_left = (nums1[i - 1] > nums2[j - 1]) ? nums1[i - 1] : nums2[j - 1];
			}
			if (i == m)
				min_right = nums2[j];
			else if (j == n)
				min_right = nums1[i];
			else
				min_right = (nums1[i] < nums2[j]) ? nums1[i] : nums2[j];
			if ((m + n) % 2 == 1) {
				median = max_left;
				return median;
			}
			else {
				
				median = (max_left + min_right) / 2.0;
				return median;
			}
		}
	}
}
int main()
{
	vector<int> a = { 3,4};
	vector<int> b = { 1,2 };
	cout << findMedianSortedArrays(a, b) << endl;
}
