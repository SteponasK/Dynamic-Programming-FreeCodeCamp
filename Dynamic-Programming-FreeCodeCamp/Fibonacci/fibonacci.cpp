#include <iostream>
#include <unordered_map>
// fibonacci number
  // O(2^n) time complexity
  // O(n) space complexity 
  // O(dib) <= O(fib) <= O(lib)  (returns (n-1)+(n-2), others return (n-1)+(n-1) and (n-2)+(n-2)

  //O(2^n) <= O(???) <= O(2^n)
  //O(fib) == O(2^n)
  //Further info in fib-memoisation.cpp
int fib(const int n);
int fibMemoisation(int n, std::unordered_map<int,  long long>& memo);

int main() {
	std::unordered_map<int, long long> memo;
	std::cout << fibMemoisation(45, memo) << std::endl;
	// fibMemoisation(45) is O(n) time complexity

	std::cout << fib(50) << std::endl; // Slow
	// fib(50) is ~ 2^50 steps == 1.12e+15 (1,1 quadrillion)
	return 0;
}
int fibMemoisation(int n, std::unordered_map<int,  long long>& memo) {
	if (memo.find(n) != memo.end()) {
		return memo[n];
	}
	if (n <= 2) return 1;
	
	memo[n] = fibMemoisation(n - 1, memo) + fibMemoisation(n - 2, memo);
	return memo[n];
}
int fib(const int n) {
	if (n <= 2) return 1;

	return fib(n - 1) + fib(n - 2);
}