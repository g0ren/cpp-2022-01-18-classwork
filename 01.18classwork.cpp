#include <iostream>
using namespace std;

// является ли n степенью p?
bool isPow(int n, int p) {
	if (n % p)
		return false;
	if (n == p)
		return true;
	return isPow(n / p, p);
}

// n-ное число Фибоначчи
int fib(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fib(n - 2) + fib(n - 1);
}

// являтся ли n числом Фибоначчи?
bool isFib(int n, int f = 0) {
	if (fib(f) == n)
		return true;
	if (fib(f) > n)
		return false;
	return isFib(n, f + 1);
}

// разбиваем сумму на $5, $2 и $1
void split(int total, int fives = 0, int twos = 0, int ones = 0) {
	if (!(fives || twos || ones))
		cout << "$"<<total<<" = ";
	if (total == 0) {
		cout << fives << "*$5, " << twos << "*$2, " << ones << "*$1" << endl;
		return;
	}
	if (total > 5) {
		fives += total / 5;
		total %= 5;
	} else if (total > 2) {
		twos += total / 2;
		total %= 2;
	} else {
		ones += total;
		total = 0;
	}
	split(total, fives, twos, ones);
}

// Вводим числа до тех пор, пока не введено 0, потом печатаем максимальное из них
void maxInt(int max = 0) {
	int n { 0 };
	cout << "Enter number" << endl;
	cin >> n;
	if (n == 0) {
		cout << max;
		return;
	}
	if (n > max)
		max = n;
	maxInt(max);
}

// Возведение в целочисленную степень с минимальным количеством умножений
int snmPow(int b, int p) {
	if (p == 1)
		return b;
	if (p % 2) {
		return b * snmPow(b * b, (p - 1) / 2);
	} else {
		return snmPow(b * b, p / 2);
	}
}

// печатаем цифры числа n в обратном порядке
void reverse(int n) {
	if (n == 0)
		return;
	cout << n % 10;
	reverse(n / 10);

}

// возвращаем перевёрнутое число n
int reverse2(int n, int r = 0) {
	if (n == 0)
		return r / 10;
	return reverse2(n / 10, (r + (n % 10)) * 10);
}

// проверяем простое ли число n
bool prime(int n, int d = 2) {
	if (d >= n / 2 && n % d)
		return true;
	if (!(n % d))
		return false;
	return prime(n, d + 1);
}

int main() {
	//...
	return 0;
}
