#include<stdio.h>
#include<locale.h>
#include<iostream>
#include<stdint.h>
#include<time.h>
#include<vector>

using namespace std;
#define k 20

int main()

{
	setlocale(LC_ALL, "Russian");
	int n;
	srand(time(NULL));
	do
	{
		cout << "введите номер задания:";
		cin >> n;
		switch (n) {
		case 1: {
			int count = 0, key;
			int m[k] = { 0 };
			cout << "Массив до сортировки: " << endl;

			for (int i = 0; i <= k - 1; i++)
			{
				m[i] = 1 + rand() % 99;
				cout << m[i] << endl;
			}

			for (int i = 0; i < k - 1; i++)
			{
				for (int j = k - 1; j > i; j--)
				{
					if (m[j - 1] > m[j])
					{
						int l = m[j - 1];
						m[j - 1] = m[j];
						m[j] = l;
					}
				}
			}

			cout << "массив после сортировки: " << endl;
			for (int i = 0; i <= k - 1; i++)
			{

				cout << m[i] << endl;
			}

			cout << "Введите число";
			cin >> key;

			//определить левую и правую границу
			int left = 0;
			int right = 19;

			//найденный индекс элемента равен -1 (элемент не найден)
			int isserch = -1;

			//пока левая граница не перескочит правую
			while (left <= right)
			{
				count++;
				//ищем середину отрезка

				int mid = (left + right) / 2;

				//если ключевое поле равно искомому, мы нашли требуемый элемент, выходим из цикла
				if (key == m[mid])
				{
					isserch = mid;
					break;
				}
				//если искомое ключевое поле меньше найденной середины
				if (key < m[mid])
				{
					//смещаем правую границу, продолжим поиск в левой части
					left = mid - 1;
				}
				//смещаем левую границу, продолжим поиск в правой части
				else
					left = mid + 1;
			}

			// если индекс элемента по прежнему -1, элемент не найден
			if (isserch == -1)
				cout << "Элемент не найден!" << endl;
			else //иначе выводим элемент, его ключ и значение
				cout << "m[" << isserch << "]=" << m[isserch] << "(за " << count << " проходов)" << endl;


		}break;
			//Степень
			//	Интерпретатор языка программирования Base_ABC умеет выполнять присваивания типа A : = B * C(A, B, C - имена некоторых переменных), но не умеет 
			//выполнять операцию возведения в натуральную степень.Поэтому вычисления выражения типа AN можно заменить серией команд умножения.
			//		Например, команду X : = A5 можно записать серией из трёх команд
			//		R1 : = A * A
			//		R2 : = A * R1
			//		X : = R1 * R2
			//			За заданным N нужно найти минимальное количество команд присвоения с одним умножением в каждой для вычисления AN.
			//		Во входном файле число N(2≤N≤2000).
			//		В выходной файл нужно записать одно число – ответ к задаче.

		case 2: {
			short int geam[11];
			short int count = 0, n, i = 0, count1 = 0;
			geam[0] = 1;
			for (int i = 1; i <= 10; i++)
			{
				geam[i] = geam[i - 1] * 2;
				/*cout << geam[i]<<endl;*/
			}
			cout << "Введите число n: ";
			cin >> n;
			while (n != 0)
			{
				count = 0;
				i = 0;
				while (n >= geam[i])
				{
					count++;
					i++;
				}
				/*cout << count << endl;*/
				if (count != 1)
					count1 += count - 1;
				else
					count1 += count;
				n = n - geam[count - 1];

				cout << "count " << count << endl;
				cout << "count1 " << count1 << endl;
				cout << "n " << n << endl;
			}
			cout << "Кол-во шагов: " << count1 << endl;

			//int a, n,i;
			//
			//cout << "Введите число a: ";
			//cin >> a;

			//n = 2 + rand() % 20;
			//cout << "Степень: " << n << endl;
			//vector<int>m(n);
			//
			//for (int i = 3; i <= n; i++) 
			//{
			//	m[1] = a;
			//	m[2] = a*a;
			//	m[i] = m[i - 2] * m[2];
			//	cout << "m[" << i << "]" << m[i] << endl;
			//}
			///*cout << "степень числа a: " << m[n] << endl;*/


		}break;
		}
	} while (n > 0);
}
