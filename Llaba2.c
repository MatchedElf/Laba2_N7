#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//¬вести строку, вы€снить, нет ли повтор€ющихс€ слов, и вывести их, если они есть.

int sravn(char* m, int a, int b, int c, int d)
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
				if (m[i] != m[j])
				{
					return 0;
				}
			j++;
		}

		return 1;
	}
	//‘ункци€ сравнивает 2 слова массива

}

void print(char* m, int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		printf("%c", m[i]);
	}

	printf("\n");
}
//‘ункци€ выводит слово



int main()
{
	printf("Enter a string \n");

	char s[100];
	int a[50][3] = {0};
	//fgets(s, 100, stdin);
	gets(s);
	//—формирован массив из ввода

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

	//ѕодсчет кол-ва символов

	for (int i = 0; i <= len - 1; i++)
	{
		if (((s[i] != ' ') & (s[i] != '\t')) & (t == 0))
		{
			a[j][t] = i;

			t = 1;

		}

		if (((s[i] == ' ') || (s[i] == '\t')) & (t == 1))
		{

			a[j][t] = i - 1;

			j++;

			t = 0;

		}

		if ((s[i + 1] == '\0') & (t == 1))
		{
			a[j][1] = i;

		}

	}

	//‘ормирование массива с индексами начала и конца слов

	j = 0;

	while (a[j][1] != 0)
	{
		k++;

		j++;
	}
	//подсчет кол-ва слов

	/*
	for (i = 0; i < 10; i++)
	{
		printf("\n");
		for (j = 0; j < 3; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	*/
	//вспомогательный вывод двумерного массива дл€ проверки на ошибки

	printf("\n");
	
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < k; j++)
		{
			if ((i != j) & (a[i][2] != 2))
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

	printf("\n");

	/*for (i = 0; i < 10; i++)
	{
		printf("\n");
		for (j = 0; j < 3; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	*/
	//вспомогательный вывод двумерного массива дл€ проверки на ошибки

	printf("Repeating words: \n");

	for (i = 0; i < k; i++)
	{
		if (a[i][2] == 1)
		{
			print(s, a[i][0], a[i][1]);
		}
	}
	//вывод повтор€ющихс€ слов с 1 в 3 столбце
	
	return 0;
}
