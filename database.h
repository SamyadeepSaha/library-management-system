#ifndef __DATABASE_H_
#define __DATABASE_H_

#define DB "library.db"

// MEMBER definition
typedef struct
{
    char id[];
    char name[];
    int deposit;
} MEMBER;

// BOOK definition
typedef struct
{
    char id[];
    char name[];
    char author[];
    char pub[];
    int price;
} BOOK;

// Member function
int add_member(MEMBER *bk);
int find_member(char *id);
int del_member(char *id);

// Book functions
int add_book(BOOK *bk);
int find_book(char *id);
int del_book(char *id);

// Issue and return function
int issue_book(char *bk_id, char *m_id);
int return_book(char *bk_id, char *m_id);

#endif
