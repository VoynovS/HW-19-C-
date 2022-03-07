#include <iostream>
#include <stdlib.h> 
#include <time.h> 
using namespace std; 

int divider(int num, int num1);
int resurveNumber(int num);
int random(int array[], int length);
template <typename T> int arrN(T array[], int length, int N);
void showArr(int array[], int length);
int mass(int array[], int length, int a, int b);
int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n, m, num;

   //Задача 1 Общий делитель.
	cout << "Task 1.\nEnter 2 numbers: ";
	cin >> n >> m;
	cout << "Maximum common divisor for numbers " << n << " и " << m << " = " << divider(n, m) << endl;

	//Задача 2. Зеркало
	
	cout << "Task 2.\nEnter the number you want to mirror: ";
	n = 0;
	cin >> num;
	for (int i = 0; i < num;) {
		n *= 10;
		n += num % 10;
		num /= 10;
	}
	cout << "Reflected number: " << n << endl;
	
	//Задача 3
	cout << "Task 3.\n";
	int arr[10];
	random(arr, 10);
	cout << "The original array: ";
	showArr(arr, 10);
	cout << "Enter the number ";
	cin >> n;
	arrN(arr, 10, n);
	cout << "Sorted array: ";
	showArr(arr, 10);

	//Задача 4
	int arr2[10];
	int a, b;
	cout << "Enter a range of numbers from 0 to 10: ";
	cin >> a >> b;
	mass(arr2, 10, a, b);
	showArr(arr2, 10);


	return 0;

}

//Задача 4
int mass(int array[], int length, int a, int b) {
	for (int i = 0; i <= length; i++) {
		if (array[i] < a || array[i] > b)
			array[i] = 0;
		for (int i = a; i <= b; i++) {
			array[i] = rand() % 100 + 1;
		}
	}
	return array[length];
}

//Задача 3
template <typename T> int arrN(T array[], int length, int N) {
	int n = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] == N) {
			n = i;
			break;
		}
	}
	cout << "The first position of the number " << N << " located under the index " << n << endl;
	for (int i = length - 1; i > 0; i--)
		for (int j = n; j < i; j++)
			if (array[j] > array[j + 1])
				swap(array[j], array[j + 1]);
	
	return n;
}

int random(int array[], int length) {
	
	for (int i = 0; i < length; i++) 
		array[i] = rand() % 100 + 1;
	return array[length];
	
}
void showArr(int array[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << array[i] << ", ";
	cout << "\b\b]\n";
}

//Задача 2
int resurveNumber(int num) {
	int n = 0;
	while (num > 0) {
		n *= 10;
		n += num % 10;
		num /= 10;
	}
	return n;
}
//Задача 1
int divider(int num, int num1) {
	int max = 0;
	for (int i = 1; i <= num;i++)
		if (num % i == 0 && num1 % i == 0)
			max = i;
	return max;
}

