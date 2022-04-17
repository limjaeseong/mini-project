#include <stdio.h>
#ifndef PRO
#define PRO
typedef struct{
	char name[20];
	char info[20];
	char weight[20];
	int price;
	int deliver;
} Product;
void readProduct(Product p);
#endif

void listProduct(Product *p, int count);
int selectDataNo(Product *p, int count);
void saveData(Product *p, int count);
int loadData(Product *p);
void searchProduct(Product *p, int count);
void searchPrice(Product *p, int count);
void searchDeliver(Product *p, int count);

