#ifndef __DATABASE_H_
#define __DATABASE_H_

#define DB "library.db"

// MEMBER definition
typedef struct
{
    char id[6];
    char name[50];
    int deposit;
} MEMBER;

// BOOK definition
typedef struct
{
    char id[6];
    char name[50];
    char author[50];
    char pub[50];
    int price;
} BOOK;

// Member function
int insert_member(MEMBER m);
int find_member(char *id);
int del_member(char *id);

// Book functions
int insert_book(BOOK bk);
int find_book(char *id);
int del_book(char *id);

// Issue and return function
int issue_book(char *bk_id, char *m_id);
int return_book(char *bk_id, char *m_id);

#endif
