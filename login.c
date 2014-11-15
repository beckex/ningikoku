#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

#define SERVER ("localhost")
#define USER ("296user")
#define DBPWD ("abc123")
#define DATABASE ("honordb")

const int isLogin(const char* username, const char* password){
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

   char *query;
   int result=0;


   conn = mysql_init(NULL);
   /* Connect to database */
   if (!mysql_real_connect(conn, SERVER,
         USER, DBPWD, DATABASE, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   /* send SQL query */
   asprintf(&query, "SELECT * FROM users WHERE name=\"%s\" AND password=\"%s\"", username, password);

   if (mysql_query(conn, query)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   res = mysql_use_result(conn);
   /* output table name */
   if ((row = mysql_fetch_row(res)) != NULL){
   	result=1;
   }
   /* close connection */
   //free(query);
   mysql_free_result(res);
   mysql_close(conn);
   return result;
}

void addUser(const char *username, const char*password){
	MYSQL *conn;
	MYSQL_ROW row;

   char *query;

   conn = mysql_init(NULL);
   /* Connect to database */
   if (!mysql_real_connect(conn, SERVER,
         USER, DBPWD, DATABASE, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

   asprintf(&query, "INSERT INTO users(name, password) VALUES(\"%s\", \"%s\")", username, password);

   if (mysql_query(conn, query)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

   //free(query);
   mysql_close(conn);
}


int main(){
	addUser("monkey", "banana");
	printf("%d\n", isLogin("monkey", "banana"));
}
