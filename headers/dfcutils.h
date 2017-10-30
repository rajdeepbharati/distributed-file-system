#include "netutils.h"
#include "utils.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#ifndef DFCUTILS_H
#define DFCUTILS_H

#define DFC_SERVER_CONF "Server"
#define DFC_USERNAME_CONF "Username"
#define DFC_PASSWORD_CONF "Password"
#define DFC_PASSWORD_DELIM ": "
#define DFC_USERNAME_DELIM ": "

#define DFC_LIST_CMD "LIST"
#define DFC_GET_CMD "GET "
#define DFC_PUT_CMD "PUT "
#define DFC_MKDIR_CMD "MKDIR "
enum DFCConstants {
  PASSWORD_FLAG = 0,
  USERNAME_FLAG = 1
};

typedef struct dfc_server_struct {
  char* name;
  char* address;
  int port;
} dfc_server_struct;

typedef struct dfc_conf_struct {
  dfc_server_struct* servers[MAXSERVERS];
  user_struct* user;
  int server_count;
} dfc_conf_struct;

void read_dfc_conf(char*, dfc_conf_struct*);
bool check_dfc_server_struct(dfc_server_struct**);
void insert_dfc_server_conf(char*, dfc_conf_struct*);
void insert_dfc_user_conf(char*, dfc_conf_struct*, char*, int);
bool split_file_to_pieces(char*, file_split_struct*, int);
bool combine_file_from_pieces(char*, file_split_struct*);
void print_dfc_conf_struct(dfc_conf_struct*);
void free_dfc_conf_struct(dfc_conf_struct*);
void free_dfc_server_struct(dfc_server_struct*);
#endif
