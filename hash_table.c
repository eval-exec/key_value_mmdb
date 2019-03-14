//
// Created by vory on 3/11/19.
//

#include "hash_table.h"
#include "uthash.h"


//struct hash_struct *test1_users = NULL;
void add_user(long int user_id, char *name) {
    struct hash_struct *s;

    HASH_FIND_INT(test1_users, &user_id, s);  /* id already in the hash? */
    if (s==NULL) {
        s = (struct hash_struct *)malloc(sizeof *s);
        s->user_id = user_id;
        HASH_ADD_INT( test1_users, user_id, s );  /* id: name of key field */
    }
    strcpy(s->name, name);
}

struct hash_struct *find_user(long int user_id)
{
    struct hash_struct *s;

    HASH_FIND_INT( test1_users, &user_id, s );  /* s: output pointer */
    return s;
}
void delete_user(struct hash_struct *user) {
    HASH_DEL(test1_users, user);  /* user: pointer to deletee */
    free(user);             /* optional; it's up to you! */
}
