#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//������ ������, ��������, ��� �� ������������� ����, � ������� ��, ���� ��� ����.

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
	//������� ���������� 2 ����� �������

}

void print(char* m, int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		printf("%c", m[i]);
	}

	printf("\n");
}
//������� ������� �����



int main()
{
	printf("Enter a string \n");

	char s[100];
	int a[50][3] = {0};
	//fgets(s, 100, stdin);
	gets(s);
	//����������� ������ �� �����

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

	//������� ���-�� ��������

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

	//������������ ������� � ��������� ������ � ����� ����

	j = 0;

	while (a[j][1] != 0)
	{
		k++;

		j++;
	}
	//������� ���-�� ����

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
	//��������������� ����� ���������� ������� ��� �������� �� ������

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
	//���������� � 3 ������� ������� 1 ��� 2 � ����������� �� ���������� ��������

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
	//��������������� ����� ���������� ������� ��� �������� �� ������

	printf("Repeating words: \n");

	for (i = 0; i < k; i++)
	{
		if (a[i][2] == 1)
		{
			print(s, a[i][0], a[i][1]);
		}
	}
	//����� ������������� ���� � 1 � 3 �������
	
	return 0;
}
