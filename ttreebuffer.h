//
// Created by vory on 3/9/19.
//

#ifndef __TTREEBUFFER_H__
#define __TTREEBUFFER_H__


struct item *all_items, *cur_item;

int token1;

char * parf0;
char * parf1;
void parseinput(char *string);
void parse_file(char *string);
enum commands{
    FIND=0,
    INSERT,
    DELETE,
    PRINT,
};
char * file_line;
char * copy_string;
enum commands COMMANDS;
char * par1;
char * par2;
char * par3;

long int * insertkey;




#endif //__TTREEBUFFER_H__
