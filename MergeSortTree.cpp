#include "MergeSortTree.h"
#include <algorithm>
#include <iterator>

MergeSortTree::MergeSortTree(const std::vector<int>& A) {
	T.resize(4 * A.size());
	BuildTree(A, 0, A.size() - 1, 0);
}

void MergeSortTree::BuildTree(const std::vector<int>& A, int lo, int hi, int v) {
	// Base case: If the segment consists of a single element, we can directly store that element in the current node's vector.
	if (lo == hi) {
		T[v] = { A[lo] };
		return;
	}

	// Divide the segment into two subsegments.
	int mid = (lo + hi) / 2;

	// Recursively build the tree for the left subsegment.
	BuildTree(A, lo, mid, 2 * v + 1);

	// Recursively build the tree for the right subsegment.
	BuildTree(A, mid + 1, hi, 2 * v + 2);

	// Combine the sorted vectors from the left and right children to create the sorted vector for the current node.
	std::merge(T[2 * v + 1].begin(), T[2 * v + 1].end(), T[2 * v + 2].begin(), T[2 * v + 2].end(), std::back_inserter(T[v]));
}

int MergeSortTree::FindNumberOfGreaterElements(const int qlo, const int qhi, const int x, int lo, int hi, int v) const {
	// The current segment is completely outside the query segment. We can directly return 0.
	if (qlo > hi || qhi < lo) {
		return 0;
	}

	// The current segment is completely covered by the query segment. We can directly return the number of elements greater than x in the current node's vector.
	if (qlo <= lo && hi <= qhi) {
		return T[v].size() - (std::upper_bound(T[v].begin(), T[v].end(), x) - T[v].begin());
	}

	// Divide the segment into two subsegments.
	int mid = (lo + hi) / 2;

	// Recursively find the number of elements greater than x in the left subsegment.
	int numberOfGreaterElementsInTheLeftSubsegment = FindNumberOfGreaterElements(qlo, qhi, x, lo, mid, 2 * v + 1);

	// Recursively find the number of elements greater than x in the right subsegment.
	int numberOfGreaterElementsInTheRightSubsegment = FindNumberOfGreaterElements(qlo, qhi, x, mid + 1, hi, 2 * v + 2);

	// Return the total number of elements greater than x in the current segment by summing the results from the left and right subsegments.
	return numberOfGreaterElementsInTheLeftSubsegment + numberOfGreaterElementsInTheRightSubsegment;
}
