//
//  main.c
//  memoryMap
//
//  Created by Abdullah Kheruwala on 10/6/17.
//  Copyright © 2017 Abdullah Kheruwala. All rights reserved.
//

/*
 Abdullah Kheruwala
 UCID: amk75
 CS 288 2017F Section 101
 HW 01
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {
    int *ptr;
    int systemFormat = sizeof(ptr);
    
    printf("00000000000000 +------+------+------+------+------+------+------+------+\n");
    printf("               +------+------+------+------+------+------+------+------+\n");
    printf("               +------+------+------+------+------+------+------+------+\n");
    
    printf("%p",(void*) &argc);
    printf(" | ");
    unsigned char *a = (unsigned char *)&argc;
    for(int i=0; i<systemFormat; i++)
    {
        
        printf(" %02x  | ", a[i]);
    }
    printf(" argc\n");
    printf("               +------+------+------+------+------+------+------+------+\n");
    
    printf("%p", *argv);
    printf(" | ");
    unsigned char *b = (unsigned char *)&argv;
    
    for(int i=0; i<systemFormat; i++)
    {
        printf(" %02x  | ", b[i]);
    }
    
    printf(" argv\n");
    printf("               +------+------+------+------+------+------+------+------+\n");
    printf("               +------+------+------+------+------+------+------+------+\n");
    
    
    for(int i=0;i<argc;i++)
    {
        printf("%p", &argv[i]);
        printf(" | ");
        unsigned char *c = (unsigned char *)&argv[i];
        for(int j=0; j<systemFormat; j++)
        {
            printf(" %02x  | ",c[j]);
        }
        printf(" argv+%d",i);
        printf("\n");
        printf("               +------+------+------+------+------+------+------+------+\n");
        printf("               +------+------+------+------+------+------+------+------+\n");
    }
    
    
    for(int i=0;i<argc;i++){
        char * str=argv[i];
        int index=0;
        int addressAdder = 0;
        printf("               +------+------+------+------+------+------+------+------+\n");
        for(int j=0; j<strlen(str)/systemFormat; j++){
            printf("%p",(void*) argv[i]+addressAdder);
            printf(" |  ");
            for(int l=0;l<systemFormat;l++){
                printf("%c   |  ",str[index++]);
            }
            printf("\n");
            printf("               +------+------+------+------+------+------+------+------+\n");
            addressAdder += systemFormat;
        }
        if(strlen(str)%systemFormat > 0){
            printf("%p",(void*) argv[i]+addressAdder);
            printf(" |  ");
            for(int j=index;j<strlen(str);j++){
                printf("%c   |  ",str[j]);
                
            }
            printf("00  |");
            int a = (systemFormat-1) - (strlen(str)%systemFormat);
            for(int z=0; z<a; z++)
            {
                printf("%*c", 6,' ');
                printf("|");
            }
            printf("\n");
            printf("               +------+------+------+------+------+------+------+------+\n");
            printf("               +------+------+------+------+------+------+------+------+\n");
        }
        
        
    }
    printf("               +------+------+------+------+------+------+------+------+\n");
    printf("ffffffffffffff +------+------+------+------+------+------+------+------+\n");
    return 0;
}




