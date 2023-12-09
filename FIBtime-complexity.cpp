#include <iostream>


void foo(const int n);
void bar(const int n);
void lib(const int n);
void dib(const int n);
int main() {

	// O(n) time complexity
	foo(5); // calls the function 5 times (5 4 3 2 1)
	
	// O(n) time complexity
	// Actually it is O(n/2) but according to big O notation, translates into O(n)
	bar(6); // calls the function 4 times ( 6 4 2 0)


	// O(2^n) time complexity
	dib(5);


	// O(2^n) time complexity
	// Actually it is O( 2^(n/2) ) but translates into O(2^n)
	lib(5);

	return 0;
}

void foo(const int n){
	//std::cout << "foo\n";
	if (n <= 1) return;

	foo(n - 1);
}
void bar(const int n) {
	//std::cout << "bar\n";
	if (n <= 1) return;
	bar(n - 2);
}
void dib(const int n) {
	std::cout << "dib\n";
	if (n <= 1) return;
	dib(n - 1);
	dib(n - 1);
}
void lib(const int n) {
	std::cout << "lib\n";
	if (n <= 1) return;
	lib(n - 2);
	lib(n - 2);
}