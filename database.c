#include"database.h"
#include<stdio.h>
#include<sqlite3.h>

int insert_member(MEMBER m)
{
    sqlite3 *db;
    char *err_msg = 0;
    char *sql = sqlite3_mprintf("insert into members values('%s', '%s', %d);", m.id, m.name, m.deposit);
    int status = 0;
    //int count = printf("insert into members values('%s', '%s', %d);", m.id, m.name, m.deposit);
    //printf("%d", count);
    if(sqlite3_open(DB, &db) == SQLITE_OK)
    {
        if(sqlite3_exec(db, sql, 0, 0, &err_msg) == SQLITE_OK)
            printf("SQL insertion successful\n");
        else
            status = printf("SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
    }
    sqlite3_free(sql);
    return status;
}

int find_member(char *id)
{
    return 0;
}

int del_member(char *id)
{
    sqlite3 *db;
    char *err_msg = 0;
    int status = 0;
    char *sql = sqlite3_mprintf("delete from members where id = '%s';", id);
    if(sqlite3_open(DB, &db) == SQLITE_OK)
    {
        if(sqlite3_exec(db, sql, 0, 0, &err_msg) == SQLITE_OK)
            printf("SQL deletion successful\n");
        else
            status = printf("SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
    }
    return status;
}

int insert_book(BOOK bk)
{
    sqlite3 *db;
    char *err_msg = 0;
    int status = 0;
    char *sql = sqlite3_mprintf("insert into books values('%s', '%s', '%s', '%s', '%d');", bk.id, bk.name, bk.author, bk.pub, bk.price);
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
    sqlite3 *db;
    char *err_msg = 0;
    int status = 0;
    char *sql = sqlite3_mprintf("delete from books where id = '%s';", id);
    if(sqlite3_open(DB, &db) == SQLITE_OK)
    {
        if(sqlite3_exec(db, sql, 0, 0, &err_msg) == SQLITE_OK)
            printf("SQL deletion successful\n");
        else
            status = printf("SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
    }
    return status;
}

int issue_book(char *bk_id, char *m_id)
{
    sqlite3 *db;
    char *err_msg = 0;
    int status = 0;
    char *sql = sqlite3_mprintf("insert into issue values('%s', '%s', date('now'));", bk_id, m_id);
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
    return 0;
}

int return_book(char *bk_id, char *m_id)
{
    sqlite3 *db;
    char *err_msg = 0;
    int status = 0;
    char *sql = sqlite3_mprintf("delete from issue where book_id = '%s' and member_id = '%s';", bk_id, m_id);
    if(sqlite3_open(DB, &db) == SQLITE_OK)
    {
        if(sqlite3_exec(db, sql, 0, 0, &err_msg) == SQLITE_OK)
            printf("SQL deletion successful\n");
        else
            status = printf("SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
    }
    return status;
}

