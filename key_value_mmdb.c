#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "ttree.h"
#include "ttree_defs.h"
#include "ttreebuffer.h"
#include "uthash.h"
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"


struct hash_struct *test1_users;
struct hash_struct *s;

struct item {
    long int key;
};

static int __cmpfunc(void *key1, void *key2) {
    return (*(int *) key1 - *(int *) key2);
}

static void usage(const char *appname) {
    fprintf(stderr, "Usage: %s <positive number of keys>\n", appname);
    exit(EXIT_SUCCESS);
}

int bcount = 0;

int main(int argc, char *argv[]) {
    int num_keys, i, ret;
    Ttree ttree;
    TtreeNode *tnode;
    struct item *all_items, *cur_item;
    char input[256];
    num_keys = 12278;
    FILE *fp;
    fp = fopen("/home/vory/programing/c/key_value_mmdb/xlarge.del", "r");
    char *buf;
    par1 = malloc(50 * sizeof(char));
    par2 = malloc(50 * sizeof(char));
    par3 = malloc(50 * sizeof(char));
    char *printid;
    char * printidstring;
    char *printname;
    char *print_very_long;
    print_very_long = malloc(num_keys*1000);
    printidstring = malloc(500);
    printname= malloc(500);
    printid= malloc(500);

    all_items = calloc(num_keys, sizeof(all_items));
    file_line = malloc(1000 * sizeof(char));
    memset(file_line, 0, 1000 * sizeof(char));

    parf0 = malloc(500 * sizeof(char));
    parf1 = malloc(500 * sizeof(char));


    while (fgets(file_line, 1000, fp)) {


        parse_file(file_line);
        all_items[bcount].key = strtol(parf0, NULL, 10);

        bcount++;


        hash_name = malloc(500 * sizeof(char));
        memset(hash_name, 0, 500 * sizeof(char));
        hash_user_id = strtol(parf0, NULL, 10);
        strcpy(hash_name, parf1);
//		printf("hash_user_id\t%ld,\t\thash_name \t%s\n", hash_user_id, hash_name);
        s = find_user(hash_user_id);
        if (s == NULL) { add_user(hash_user_id, hash_name); }
//        printf("%ld,%s\n", hash_user_id, hash_name);
        free(hash_name);
        memset(file_line, 0, 1000 * sizeof(char));


    }
    free(file_line);


    ret = ttree_init(&ttree, 8, false, __cmpfunc, struct item, key);
    if (ret < 0) {
        fprintf(stderr, "Failed to initialize T*-tree. [ERR=%d]\n", ret);
        free(all_items);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < num_keys; i++) {
        ret = ttree_insert(&ttree, &all_items[i]);
        //printf("aaaInserting keys to the tree...\n");

        if (ret < 0) {
            fprintf(stderr, "Failed to insert item %d with key %ld! [ERR=%d]\n", i, all_items[i].key, ret);
            free(all_items);
            exit(EXIT_FAILURE);
        }
    }


//    for (i = 0; i < num_keys; i++) {
//
//        printf("%ld ", all_items[i].key);
//    }

//     printf("}\n");
//    printf("%d",sizeof(char[1 - 2 * !(cond)]));
//    printf("%ld",(  (size_t)&(((struct item *)0)->key) - (size_t)((struct item *)0)          ));
///////////////////////////printf sorted keys:///////////////////////////////////
//    printf("\nSorted keys:\n");
//    printf("{ ");
//    tnode = ttree_node_leftmost(ttree.root);
//    while (tnode) {
//        tnode_for_each_index(tnode, i) {
//            printf("%d ", *(int *) tnode_key(tnode, i));
//        }
//        tnode = tnode->successor;
//    }
//    printf("}\n");

    char *inputline;

    inputline = (char *) malloc(150);
    memset(inputline, 0, 150);
    int cmpp1;
/////////////////////////////////////////////////////////////////
printf("PLEASE INPUT HERE:");
    while ((strncmp(inputline, "EXIT", 4)) != 0) {

        fgets(inputline, 100, stdin);

//        printf("inputline is %s", inputline);

        parseinput(inputline);
        if (!strncmp(par1, "EXIT", 4)) break;
        char *out_buff;
        out_buff = malloc(1000);
        memset(out_buff, 0, 1000);
        insertkey = (long int *) malloc(20 * sizeof(long int));
        memset(insertkey, 0, 20 * sizeof(long int));
        void *res;

        if (strncmp(par1, "FIND", 4) == 0) {
            printf("receive FIND \n");
            COMMANDS = FIND;
        }

        if (strncmp(par1, "INSERT", 6) == 0) {
            printf("receive INSERT\n");
            COMMANDS = INSERT;
        }

        if (strncmp(par1, "DELETE", 6) == 0) {
            printf("receive DELETE \n");
            COMMANDS = DELETE;
        }

        if (strncmp(par1, "PRINT", 5) == 0) {
            printf("receive PRINT \n");
            COMMANDS = PRINT;
        }

        switch (COMMANDS) {
            case FIND:
//                printf("NOW IN FIND SWITCH \n");
                finds = find_user(strtol(par2, NULL, 10));
                if (finds != NULL) {

                    strcpy(out_buff, finds->name);
                } else {
                    strcpy(out_buff, "key  NOT FOUND!");
                }
                printf("FIND OUT PUT IS :%s\n", out_buff);
                break;
            case INSERT:
                printf("RECEIVE INSERT\n");
                finds = find_user(strtol(par2, NULL, 10));
                if (finds == NULL) {

                    printf("The key you want to insert doesn't in MMDB\n .......Inerting now......\n");
                } else {
                    printf( "key already EXIST!!!\n!");
                    break;
                }
                *insertkey = strtol(par2, NULL, 10);
                printf("inserkey = %ld\n", *insertkey);
                ret = ttree_insert(&ttree, insertkey);

                strcpy(hash_name, par3);
                hash_user_id = strtol(par2, NULL, 10);
                add_user(hash_user_id, hash_name);
                if (ret < 0) {

                    fprintf(stdout, "Failed to insert  key %ld!\n",  strtol(par2,NULL,100));

                }else{
                    printf("SUCCESSFULLY INSERTED %ld",hash_user_id);
                }

                ////insert to ttree ,& insert to hash_table////
                break;
            case DELETE:
                *insertkey = strtol(par2, NULL, 10);

                finds = find_user(*insertkey);
                if(finds == NULL){
                    printf("KEY DOESN'T EXIT\n");
                    break;

                }
                else{
                    printf("key  %ld deleted ! ", *insertkey);
                }

                ttree_delete(&ttree, &insertkey);
                delete_user(finds);
                res = ttree_delete(&ttree, insertkey);
                if (res == NULL) {
                    printf("Failed to delete item %ld on step ",strtol(par2, NULL, 10));
                }

                break;
            case PRINT:
                printf("go print\n");


                for (s = test1_users; s != NULL; s = s->hh.next) {


                    memset(printid, 0, 500 * sizeof(char));
                    memset(printname, 0, 500 * sizeof(char));
                    strcpy(printname, s->name);

                    sprintf(printidstring,"%ld",s->user_id);
                    strcpy(printid, printidstring);
                    strcat(print_very_long, printid);;
                    strcat(print_very_long, printname);
                }
                printf("%s",print_very_long);

                break;
            default:
                printf("this is default\n");
                strcpy(out_buff, "switch go to default");
                break;
        }
        printf("PLEASE INPUT HERE:");
    }

    free(par1);
    free(par2);
    free(par3);
    fclose(fp);
    ttree_destroy(&ttree);
    free(all_items);
    exit(EXIT_SUCCESS);
}