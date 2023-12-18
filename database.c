#include"database.h"
#include<stdio.h>
#include<sqlite3.h>

int add_member(MEMBER *m)
{
    sqlite3 *db;
    char *err_msg = 0;
    char *sql = 0;
    int status = 0;
    sprintf(sql,"insert into members values('%s', '%s', '%d');", m->id, m->name, m->deposit);
    if(sqlite3_open(DB, &db) == SQLITE_OK)
    {
        if(sqlite3_exec(db, sql, 0, 0, &err_msg) == SQLITE_OK)
            printf("SQL insertion successful\n");
        else
            status = printf("SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
    }
    return status;
}

int find_member(char *id)
{
    return 0;
}

int del_member(char *id)
{
    return 0;
}

int add_book(BOOK *bk)
{
    sqlite3 *db;
    char *err_msg = 0;
    char *sql = 0;
    int status = 0;
    sprintf(sql,"insert into books values('%s', '%s', '%s', '%s', '%d');", bk->id, bk->name, bk->author, bk->pub, bk->price);
    if(sqlite3_open(DB, &db) == SQLITE_OK)
    {
        if(sqlite3_exec(db, sql, 0, 0, &err_msg) == SQLITE_OK)
            printf("SQL insertion successful\n");
        else
            status = printf("SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
    }
    return status;
}

int find_book(char *id)
{
    return 0;
}

int del_book(char *id)
{
    return 0;
}

int issue_book(char *bk_id, char *m_id)
{
    return 0;
}

int return_book(char *bk_id, char *m_id)
{
    return 0;
}

