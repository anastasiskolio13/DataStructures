#pragma once
#include <vector>

class MergeSortTree
{
private:
	/// <summary>
	/// The vector of vectors that represents the Merge Sort Tree. Each node of the tree contains a sorted vector of the elements in the corresponding segment of the input vector.
	/// </summary>
	std::vector<std::vector<int>> T;

public:
	/// <summary>
	/// Initializes the Merge Sort Tree and calls BuildTree.
	/// </summary>
	/// <param name="A">The input vector.</param>
	MergeSortTree(const std::vector<int>& A);

	/// <summary>
	/// Creates the Merge Sort Tree.
	/// <para>Time Complexity. O(n lg^2 n).</para>
	/// <para>Space Complexity. O(n lg n).</para>
	/// </summary>
	/// <param name="A">The input vector.</param>
	/// <param name="lo">The first element of the segment.</param>
	/// <param name="hi">Τhe last element of the segment.</param>
	/// <param name="v">The node of the tree correspoding to segment [lo, hi].</param>
	void BuildTree(const std::vector<int>& A, int lo, int hi, int v);

	/// <summary>
	/// Recursively finds the number of elements greater than x in the segment [qlo, qhi] of the input vector.
	/// <para>Time Complexity. O(lg^2 n).</para>
	/// <para>Space Complexity. O(lg n).</para>
	/// </summary>
	/// <param name="qlo">The first element of the query segment.</param>
	/// <param name="qhi">The last element of the query segment.</param>
	/// <param name="x">The value to compare against.</param>
	/// <param name="lo">The first element of the segment.</param>
	/// <param name="hi">Τhe last element of the segment.</param>
	/// <param name="v">The node of the tree correspoding to segment [lo, hi].</param>
	/// <returns>The number of elements greater than x in the segment [qlo, qhi] of the input vector.</returns>
	int FindNumberOfGreaterElements(const int qlo, const int qhi, const int x, int lo, int hi, int v) const;
};

