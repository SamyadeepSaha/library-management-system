#include"database.h"
#include<stdio.h>
#include<stdlib.h>
#include<sqlite3.h>
#include<string.h>

MEMBER found_member;
BOOK found_book;
int found;

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

int member_callback(void *NotUsed, int argc, char **argv, char **azColname)
{
    NotUsed = 0;
    found = 1;
    strcpy(found_member.id, argv[0] ? argv[0] : "NULL");
    strcpy(found_member.name, argv[1] ? argv[1] : "NULL");
    found_member.deposit = atoi((char*)(argv[2]));
    return 0;
}

int find_member(char *id)
{
    int status;
    found = 0;
    sqlite3 *db;
    char *err_msg = 0;
    char *sql = sqlite3_mprintf("SELECT * FROM members where id = '%s';", id);
    if(sqlite3_open(DB, &db) == SQLITE_OK)
    {
        if(sqlite3_exec(db, sql, member_callback, 0, &err_msg) == SQLITE_OK)
            printf("SQL query successful\n");
        else
            status = printf("SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
    }
    return status;
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

int book_callback(void *NotUsed, int argc, char **argv, char **azColname)
{
    NotUsed = 0;
    found = 1;
    strcpy(found_book.id, argv[0] ? argv[0] : "NULL");
    strcpy(found_book.name, argv[1] ? argv[1] : "NULL");
    strcpy(found_book.author, argv[2] ? argv[2] : "NULL");
    strcpy(found_book.pub, argv[3] ? argv[3] : "NULL");
    found_book.price = atoi((char*)(argv[4]));
    return 0;
}

int find_book(char *id)
{
    int status;
    found = 0;
    sqlite3 *db;
    char *err_msg = 0;
    char *sql = sqlite3_mprintf("SELECT * FROM books where id = '%s';", id);
    if(sqlite3_open(DB, &db) == SQLITE_OK)
    {
        if(sqlite3_exec(db, sql, book_callback, 0, &err_msg) == SQLITE_OK)
            printf("SQL query successful\n");
        else
            status = printf("SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
    }
    //printf("flag\n %s \n %s \n %d", found_book.name, found_book.author, found_book.price);
    return status;
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

