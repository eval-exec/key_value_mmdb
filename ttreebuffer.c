//
// Created by slarsar on 3/9/19.
//
//created ttreebuffer

#include <stdio.h>
#include <string.h>
#include <tkPort.h>
#include "ttreebuffer.h"

void parseinput(char *string){
    char * delim;
    delim = " ";

    copy_string = malloc(150*sizeof(char));
    memset(copy_string,0,150* sizeof(char));
    char * token;
    token = NULL;





    memset(par1,0,50*sizeof(char));
    memset(par2,0,50*sizeof(char));
    memset(par3,0,50*sizeof(char));

    strcpy(copy_string,string);

//    printf("copystring is %s\n ",copy_string);
//    printf("string  is %s   \n",string);

    token = strtok(copy_string,delim);

    if (token != NULL){
//        printf(" token1 is %s\n",token);
        strcpy(par1,token);
    }


    token = strtok(NULL,delim);

    if (token != NULL){
//        printf(" token2 is %s \n",token);

        strcpy(par2,token);
    }

    token = strtok(NULL,delim);
    if (token != NULL){
//        printf("token3 is %s\n",token);

        strcpy(par3,token);
    }
    free(copy_string);
}

void parse_file(char * string){
    char * buf;
    char * delim;

    delim = NULL;
    delim = ",";
    char * token;
    token = NULL;

    buf = malloc(1000*sizeof(char));
    memset(buf,0, 1000*sizeof(char));

    if (!parf0){
        parf0 =malloc(500*sizeof(char));
    }

    memset(parf0,0, 500*sizeof(char));

    if (!parf1){
        parf1 =malloc(500*sizeof(char));
    }

    memset(parf1,0, 500*sizeof(char));

    strcpy(buf, string);
    token = strtok(buf, delim);
    if(token != NULL) {
        strcpy(parf0, token);
    }
    token = strtok(NULL, delim);
    if (token != NULL){
        strcpy(parf1, token);
    }
    free(buf);
}





//
//int parseinput(char *string){
//    char * delim;
//    char (char * )parame[3];
//
//
//    delim = " ";
//    int ipar = 0;
//    for (ipar = 0; ipar < strlen(string);ipar++){
//
//
//
//    }
//}