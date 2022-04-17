#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "manager.h"

int main(void){
#ifdef DEBUG
	printf("DEBUGMODE\n");
#endif
	Product plist[100];
	int count = 0, menu;
	int index = 0;

	count = loadData(plist);
	index = count;

	while(1){
		menu = selectMenu();
		if(menu == 0) break;
		if(menu == 1 || menu == 3 || menu == 4){
			if(count == 0) continue;
		}
		if(menu == 1){
			if (count>0){
				listProduct(plist, index);
			}	
		}else if (menu == 2){
			count += createProduct(&plist[index++]);
			printf("=> 추가됨!\n");
		}else if (menu == 3){
			int no = selectDataNo(plist, index);
			if(no == 0){
				printf("=>취소됨!\n");
				continue;
			}
			updateProduct(&plist[no-1]);
		}else if (menu == 4){
			int no = selectDataNo(plist,index);
			if(no == 0){
				printf("=>취소됨!\n");
				continue;
			}
			int del;
			printf("삭제하시겠습니까?(삭제:1)");
			scanf("%d",&del);
			if (del == 1){
				if(deleteProduct(&plist[no-1])) count--;
				printf("=> 삭제됨!\n");
			}
		}else if (menu == 5){
			saveData(plist, index);
		}else if (menu == 6){
			searchProduct(plist, index);
		}else if (menu == 7){
			searchPrice(plist, index);
		}else if (menu == 8){
			searchDeliver(plist, index);
		}
		count++;
	}
	printf("종료됨!\n");
#ifdef DEBUG
	printf("DEBUGMODE END\n");
#endif
	return 0;
}
