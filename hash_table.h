//
// Created by vory on 3/11/19.
//

#ifndef KEY_VALUE_MMDB_HASH_TABLE_H
#define KEY_VALUE_MMDB_HASH_TABLE_H

#include "uthash.h"
struct hash_struct {
    long int user_id;            /* we'll use this field as the key */
    char name[50];
    UT_hash_handle hh; /* makes this structure hashable */
};
struct hash_struct *test1_users;
struct hash_struct * s;
void add_user(long int user_id, char *name);
struct hash_struct *find_user(long int user_id);

struct  hash_struct * finds;

long int hash_user_id;
char *hash_name;
void delete_user(struct hash_struct *user);
#endif //KEY_VALUE_MMDB_HASH_TABLE_H
