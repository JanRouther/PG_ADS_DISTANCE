#define _CRT_SECURE_NO_WARNINGS

#include<cstdlib>
#include<stdio.h>
#include <algorithm>
using namespace std; 
void bubbleSort(int a[], int length)
{
        int i, j, temp;

        for (i = 0; i < length; i++)
        {
                for (j = 0; j < length - i - 1; j++)
                {
                        if (a[j + 1] < a[j])
                        {
                                temp = a[j];
                                a[j] = a[j + 1];
                                a[j + 1] = temp;
                        
}
                
}
        
}
}
int plusproste(int x[], int n)
{
	bubbleSort(x,n);
	int rezultat = 0;
	int suma = 0;
	for (int i = 0; i < n; i++) {
		rezultat += (x[i] * i - suma);
		suma += x[i];
	}
	return rezultat;
}
int sumaplus(int x[], int y[], int n)
{
	return plusproste(x, n) + plusproste(y, n);
}
int krzyz(int x[], int y[], int n)
{
	int suma = 0;
	for (int i =0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			suma += max(abs(x[i]-x[j]),abs(y[i]-y[j]));
		}
	}
	return suma /(n * (n- 1));
}

int pluszdwoma(int x[], int n,int l)
{
	int suma = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			suma += min(abs(x[i] - x[j]), l - abs(x[i] - x[j]));	
		}
	}
	return suma;
}
int sumapluszdwoma(int x[], int y[], int n,int l)
{
	return pluszdwoma(x, n,l) + pluszdwoma(y, n,l);

}
int sumapluszjednym(int x[], int y[], int n,int l)
{
	return pluszdwoma(x, n,l)+ 2*(plusproste(y, n));
}
int krzyzzdwiema(int x[], int y[], int n,int l)
{
	int suma = 0;
	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a = min(abs(x[i] - x[j]), (l - abs(x[i] - x[j]) ));
			b = min(abs(y[i] - y[j]), (l - abs(y[i] - y[j]) ));
			suma += max(a, b);
		}
	}	
	return suma / (n * (n - 1));
}
int krzyzzjedna(int x[], int y[], int n,int l)
{
	int suma = 0;
	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a = min(abs(x[i] - x[j]), (l - abs(x[i] - x[j])));
			b = abs(y[i] - y[j]);
			suma += max(a, b);
		}
	}
	return suma / (n * (n - 1));
}
void ukos(int size, int k)
{
	if (k != 2 || (!(size & 1)))
		printf("Inf\n");
	else
	{
	int buf = size >> 1;
	printf("%i\n", (((buf * size) + buf) * size) / ((size * size) - 1));
	}
}
void plusak(int l, int k)
{
	int *x = (int*)malloc(l*l*sizeof(int));
	int *y = (int*)malloc(l*l*sizeof(int));
	int q = 0;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j <l; j++)
		{
			y[q] = i;
			x[q] = j;
			q++;
		}
	}
	int n = l*l;
	if(k==0)
		printf("%i\n",(2 * sumaplus(x, y, n)) / (n* (n- 1)));
	else if(k==1)
		printf("%i\n",sumapluszjednym(x, y, n,l)/ (n* (n- 1)));
	else
		printf("%i\n", sumapluszdwoma(x, y, n,l) / (n * (n - 1)));
	free(x);
	free(y);
}
void krzyzyk(int l, int k)
{
	int* x = (int*)malloc(l * l * sizeof(int));
	int* y = (int*)malloc(l * l * sizeof(int));
	int q = 0;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l; j++)
		{
			y[q] = i;
			x[q] = j;
			q++;
		}
	}
	int n = l*l;
	if (k == 0)
		printf("%i\n", krzyz(x, y, n));
	else if (k == 1)
		printf("%i\n",krzyzzjedna(x, y, n,l));
	else
		printf("%i\n", krzyzzdwiema(x, y, n,l));
	free(x);
	free(y);
}
int main() {
	int o, d, l, k, h;
	scanf("%i", &o);
	while (o>0) {
		scanf("%i %i %i %i", &d, &l, &k, &h);
		if (h == 1)
			plusak(l, k);
		else if (h == 0)
			krzyzyk(l, k);
		else
			ukos(l,k);
		o -= 1;
	}
}