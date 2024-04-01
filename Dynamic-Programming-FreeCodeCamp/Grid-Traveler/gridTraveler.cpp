#include <iostream>
#include <unordered_map>
#include <string>
long long gridTraveler(int m, int n); // O(2^n) time , O(n) space 
// It actually is O(2^(n+m)) time, O(n+m) space

long long gridTravelerMemo(int m, int n, std::unordered_map<std::string, int>& memo);
// O(n) time, O(n) space
// It actually is O(m*n) time, O(n+m) space
// If we have already calculated that part of the tree, then we just reuse the values.
// So we have to execute each calculation only once, no duplicates.
// Unordered_map indexes at O(1) time, if the number is very large, then at worst case at O(n) time.
int main() {
	std::unordered_map<std::string, int> memo;

	std::cout << gridTravelerMemo(15, 15, memo) << std::endl; // 40116600
	// O(n), very fast

	// O(2^n), very slow
	std::cout << gridTraveler(1, 1) << std::endl; // 1
	std::cout << gridTraveler(2, 3) << std::endl; // 3
	std::cout << gridTraveler(3, 2) << std::endl; // 3
	std::cout << gridTraveler(3, 3) << std::endl; // 6
	std::cout << gridTraveler(18, 18) << std::endl; // 2333606220


	// gridTraveler(m,n) == gridTraveler(n,m)	
	return 0;
}
long long gridTravelerMemo(int m, int n, std::unordered_map<std::string, int>& memo) {
	const std::string key = (std::to_string(m) + ',' + std::to_string(n));
	if (memo.count(key) > 0 ) return memo[key];
	if (m == 1 && n == 1) return 1;
	if (m == 0 || n == 0) return 0;
	memo[key] = gridTravelerMemo(m - 1, n, memo) + gridTravelerMemo(m, n - 1, memo);
	return memo[key];
}
long long gridTraveler(int m, int n) {
	if (m == 1 && n == 1) return 1;
	if (m == 0 || n == 0) return 0;
	return gridTraveler(m - 1, n) + gridTraveler(m, n - 1);
}