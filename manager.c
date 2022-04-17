#include <stdio.h>
#include <string.h>
#include "manager.h"

void listProduct(Product *p, int count){
        for(int i=0; i<count; i++){
                if(p[i].price == -1) continue;
                printf("%2d",i+1);
                readProduct(p[i]);
        }
        printf("\n");
}
int selectDataNo(Product *p, int count){
        int no;
        listProduct(p,count);
        printf("번호는(취소:0)? ");
        scanf("%d",&no);
        return no;
}
void saveData(Product *p, int count){
    FILE *fp;
    fp = fopen("product.txt", "wt");

    for(int i=0; i < count; i++){
        if(p[i].price == -1) continue;
        fprintf(fp, "%s %s %s %d %d\n",p[i].name,p[i].info,p[i].weight,p[i].price,p[i].deliver);
    }
    fclose(fp);
    printf("저장됨!\n");
}

int loadData(Product *p){
    int i =0;
    FILE *fp;
    fp = fopen("product.txt", "rt");
    if(fp == NULL){
        fclose(fp);
        printf("=> 파일 없음\n");
        return 0;
    }else {
        for(; i < 20; i++){
             fscanf(fp, "%s", p[i].name);
             if(feof(fp)) break;
             fscanf(fp, "%s", p[i].info);
             fscanf(fp, "%s", p[i].weight);
             fscanf(fp, "%d", &p[i].price);
             fscanf(fp, "%d", &p[i].deliver);
        }
        fclose(fp);
        printf("=> 로딩 성공!\n");
        return i;
    }
}

void searchProduct(Product *p, int count){
    int scnt = 0;
    char search[20];

    printf("검색할 제픔은? ");
    scanf("%s", search);

    for(int i=0; i <count; i++){
        if(p[i].price == -1) continue;
        if(strstr(p[i].name, search)){
            printf("%2d", i+1);
            readProduct(p[i]);
            scnt++;
        }
    }
    if(scnt == 0){
        printf("=> 검색된 데이터 없음!");
    }
    printf("\n");
}
void searchPrice(Product *p, int count){
    int scnt = 0;
    int search;

    printf("검색할 가격은? ");
    scanf("%d", &search);

    for(int i=0; i <count; i++){
        if(p[i].price == -1) continue;
        if(search == p[i].price){
            printf("%2d", i+1);
            readProduct(p[i]);
            scnt++;
        }
    }
    if(scnt == 0){
        printf("=> 검색된 데이터 없음!");
    }
    printf("\n");
}
void searchDeliver(Product *p, int count){
    int scnt = 0;
    int search;

    printf("검색할 배송은? ");
    scanf("%d", &search);

    for(int i=0; i <count; i++){
        if(p[i].price == -1) continue;
        if(search == p[i].deliver){
            printf("%2d", i+1);
            readProduct(p[i]);
            scnt++;
        }
    }
    if(scnt == 0){
        printf("=> 검색된 데이터 없음!");
    }
    printf("\n");
}
