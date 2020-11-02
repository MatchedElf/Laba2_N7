#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define Letter_Cheeeck ( ( (s[i] > 64) && (s[i] < 91) ) || ( (s[i] > 96) && (s[i] < 123) ) || ( (s[i] > 127) && (s[i] < 176) ) || ( (s[i] > 223) && (s[i] < 240) ) )
//Упрощенная запись проверки символа на то, является ли он буквой

//Ввести строку, выяснить, нет ли повторяющихся слов, и вывести их, если они есть.

int sravn(unsigned char* m, int a, int b, int c, int d)
{
	int j = c;
 
	if ((b - a) != (d - c))
	{
		return 0;
	}


	else
	{
		for (int i = a; i <= b; i++)
		{
			if ( ( (m[i] > 64) && (m[i] < 91) ) || ( (m[i] > 127) && (m[i] < 144) ) )
			{
				if ( (m[i] != m[j]) && (m[i] != m[j] - 32) )
				{
					return 0;
				}
			}

			if ( ( (m[i] > 96) & (m[i] < 123)) || ((m[i] > 159) & (m[i] < 176) ) )
			{
				if ( (m[i] != m[j]) && (m[i] != m[j] + 32) )
				{
					return 0;
				}
			}

			if ( (m[i] > 143) && (m[i] < 160) ) 
			{
				if ((m[i] != m[j]) && (m[i] != m[j - 80]))
				{
					return 0;
				}
			}

			if ((m[i] > 223) && (m[i] < 240))
			{
				if ((m[i] != m[j]) && (m[i] != m[j + 80]))
				{
					return 0;
				}
			}

			j++;
		}

		return 1;
	}
	//Функция сравнивает 2 слова массива

}

void print(unsigned char* m, int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		printf("%c", m[i]);
	}

	printf("\n");
}
//Функция выводит слово



int main()
{
	printf("Enter a string \n");

	unsigned char s[100];

	int a[50][3] = {0};

	//fgets(s, 100, stdin);

	gets(s);
	//Сформирован массив из ввода

	int i = 0;
	int j = 0;
	int len = 0;
	int k = 0;
	int t = 0;

	while (s[i] != '\0')
	{
		len++;

		i++;
	}

	//Подсчет кол-ва символов

	for (int i = 0; i <= len - 1; i++)
	{
		if ( Letter_Cheeeck && (t == 0) )
		{
			a[j][t] = i;

			t = 1;

		}

		if ( ( !(Letter_Cheeeck) ) && (t == 1) )
		{ 

			a[j][t] = i - 1;

			j++;

			t = 0;

		}

		if ((s[i + 1] == '\0') && (t == 1))
		{
			a[j][1] = i;

		}

	}

	//Формирование массива с индексами начала и конца слов

	j = 1;

	while (a[j][1] != 0)
	{
		k++;

		j++;
	}
	//подсчет кол-ва слов
	
	for (i = 0; i <= k; i++)
	{
		for (j = 0; j <= k; j++)
		{
			if ((i != j) && (a[i][2] != 2))
			{
				if (sravn(s, a[i][0], a[i][1], a[j][0], a[j][1]) == 1)
				{
					a[i][2] = 1;

					a[j][2] = 2;
				}
			}
		}
	}
	//добавление в 3 столбец массива 1 или 2 в зависимости от результата проверки

	printf("\nRepeating words: \n");

	for (i = 0; i <= k; i++)
	{
		if (a[i][2] == 1)
		{
			print(s, a[i][0], a[i][1]);
		}
	}
	//вывод повторяющихся слов с 1 в 3 столбце
	
	return 0;
}

