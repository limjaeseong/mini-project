#include <stdio.h>
#include "product.h"

int createProduct(Product *p){
	printf("제품명은? ");
	scanf("%s",p->name);
	printf("제품정보는? ");
	scanf("%s",p->info);
	printf("제품무게는? ");
	scanf("%s",p->weight);
	printf("가격은? ");
	scanf("%d",&p->price);
	printf("배송은?(1:새벽배송/2:택배배송) ");
	scanf("%d",&p->deliver);
	return 1;
}
void readProduct(Product p){
	printf("제품명:%s\n",p.name);
	printf("제품정보:%s\n",p.info);
	printf("가격:%d\n",p.price);
	printf("무게:%s\n",p.weight);
	printf("배송:%d\n",p.deliver);
}
int updateProduct(Product *p){
	printf("제품명은? ");
	scanf("%s",p->name);
	printf("제품정보는? ");
	scanf("%s",p->info);
	printf("제품무게는? ");
	scanf("%s",p->weight);
	printf("가격은? ");
	scanf("%d",&p->price);
	printf("배송은?(1:새벽배송/2:택배배송) ");
	scanf("%d",&p->deliver);
	return 1;
}
int deleteProduct(Product *p){
	p->price = -1;
	return 1;
}
int selectMenu(){
	int menu;
	printf("\n===제품===\n");
	printf("1. 제품조회\n");
	printf("2. 제품추가\n");
	printf("3. 제품수정\n");
	printf("4. 제품삭제\n");
	printf("5. 파일저장\n");
	printf("6. 제품검색\n");
	printf("7. 가격검색\n");
	printf("8. 배송검색\n");
	printf("0. 종료\n");
	printf("=> 원하는 메뉴는? \n");
	scanf("%d",&menu);
	return menu;
}
