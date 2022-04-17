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
#endif
int createProduct(Product *p);
void readProduct(Product p);
int updateProduct(Product *p);
int deleteProduct(Product *p);
int selectMenu();
