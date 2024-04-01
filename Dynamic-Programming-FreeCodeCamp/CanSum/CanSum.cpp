#include <iostream>
#include <vector>
#include <unordered_map>
// m = target sum , n = array length

// O(n^m) time, O(m) space
bool canSum(int TargetSum, std::vector<int> numbers);

// O(m*n) time, O(m) space
bool canSumMemo(int TargetSum, std::vector<int> numbers, std::unordered_map<int, int>& memo);
int main() {
	// Passing vector by value, due to convenience, inneficient. 
	std::unordered_map<int, int> memo;
	std::cout << canSumMemo(300, { 7, 14 }, memo) << std::endl; // false
	std::cout << canSum(300, { 7, 14 }) << std::endl; // false

	/*
	std::cout << canSum(7, { 2, 3 }) << std::endl; // true
	std::cout << canSum(7, { 5, 3, 4, 7 }) << std::endl; // true
	std::cout << canSum(7, { 2, 4 }) << std::endl; // false
	std::cout << canSum(8, { 2, 3, 5 }) << std::endl;// true
	*/
	return 0;
}
bool canSum(int TargetSum, std::vector<int> numbers) {
	//if (numbers.size() == 1 && numbers[0] == TargetSum) return true;
	if (TargetSum == 0) return true;
	if (TargetSum < 0) return false;
	for (const auto& number : numbers) {
		int remainder = TargetSum - number;
		if (canSum(remainder, numbers) == true) return true;
	}
	return false;
}
bool canSumMemo(int TargetSum, std::vector<int> numbers, std::unordered_map<int, int>& memo) {
	if (memo.find(TargetSum) != memo.end()) {
		return memo[TargetSum];
	}
	if (TargetSum == 0) return true;
	if (TargetSum < 0) return false;
	for (const auto& number : numbers) {
		int remainder = TargetSum - number;
		if (canSumMemo(remainder, numbers, memo) == true) {
			memo[TargetSum] = true;
			return true;
		}
	}
	memo[TargetSum] = false;
	return false;
}