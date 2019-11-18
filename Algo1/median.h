#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>
#include <time.h>

namespace median {

	// Additional private namespace for functions, which shouldn't be exposed
	namespace {

		// Partitions the given vector, so that:
		// Each element left of the pivot is smaller than the pivot
		// Each element right of the pivot is greater than the pivot
		int partition(std::vector<int>& arr, int left, int right, int pivot) {
			while (left <= right) {
				while (arr[left] < pivot) {
					left++;
				}
				while (arr[right] > pivot) {
					right--;
				}

				// left and right now point to elements which are in the wrong halves of the array
				if (left <= right) {
					std::swap(arr[left], arr[right]);
					left++;
					right--;
				}
			}

			return left;
		}

		// Standard quicksort algorithm, which partitions recursively. The pivot is chosen randomly.
		void quicksort(std::vector<int>& arr, int left, int right) {
			if (left >= right) return;

			int pivot = arr[left + (rand() % (right - left + 1))];
			int index = partition(arr, left, right, pivot);
			quicksort(arr, left, index - 1);
			quicksort(arr, index, right);
		}

		// Randomized select, implemented as shown in the lecture slides
		int quickselect(std::vector<int>& arr, int p, int r, int i) {
			if (p == r) return arr[p];

			int pivot = arr[p + (rand() % (r - p + 1))];
			int q = partition(arr, p, r, pivot);
			int k = q - p + 1;

			if (i == k) return arr[q];
			else if (i < k) return quickselect(arr, p, q - 1, i);
			else return quickselect(arr, q + 1, r, i - k);
		}

	}

	// Quicksort first then return i-th element
	int sortedMedian(std::vector<int> arr, int i) {
		quicksort(arr, 0, arr.size() - 1);
		return arr[i];
	}

	// Wrapper functino to avoid array duplication
	int randomizedSelect(std::vector<int> arr, int p, int r, int i) {
		return quickselect(arr, p, r, i);
	}

	// Torbens method
	// The code is inspired by 
	int torben(std::vector<int> arr, int n) {
		int i, less, greater, equal, min, max, guess, maxltguess, mingtguess;

		// Find min and max values
		min = max = arr[0];
		for (i = 1; i < n; i++) {
			if (arr[i] < min) min = arr[i];
			if (arr[i] > max) max = arr[i];
		}

		while (true) {
			// Make a guess for the median
			guess = (min + max) / 2;
			
			less = 0;
			greater = 0;
			equal = 0;
			maxltguess = min;
			mingtguess = max;
			
			// Count the number of values that are lesser than the guess, greater than the guess and equal to the guess
			// and adjust maxltguess and mingtguess
			for (int i = 0; i < n; i++) {
				if (arr[i] < guess) {
					less++;
					if (arr[i] > maxltguess) maxltguess = arr[i];
				}
				else if (arr[i] > guess) {
					greater++;
					if (arr[i] < mingtguess) mingtguess = arr[i];
				}
				else equal++;
			}

			if (less <= (n + 1) / 2 && greater <= (n + 1) / 2) break;
			else if (less > greater) max = maxltguess;
			else min = mingtguess;
		}

		if (less >= (n + 1) / 2) return maxltguess;
		else if (less + equal >= (n + 1) / 2) return guess;
		else return mingtguess;
	}

	// C++ nth-element
	int cppMedian(std::vector<int> arr , int i) {
		std::nth_element(arr.begin(), arr.begin() + i, arr.end());
		return arr[i];
	}

}