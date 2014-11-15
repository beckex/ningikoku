#include <mysql/my_global.h>
#include <mysql/mysql.h>
#include <stdlib.h>
void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}
int main(int argc, char ** argv)
{
  MYSQL * con = mysql_init(NULL);
  if(con== NULL)
    {
      fprintf(stderr, "%s\n",mysql_error(con));
      exit(1);
    }
  if(mysql_real_connect(con, "localhost", "296user","abc123","honordb",0,NULL,0) == NULL)
    {
      finish_with_error(con);
    }
   if(mysql_query(con, "CREATE TABLE Users(ID INT, Name TEXT, Passwod TEXT)")) */
     {  
        finish_with_error(con); 
     } 
  if(mysql_query(con, "CREATE TABLE Info(ID INT, Latitude FLOAT, Longitude FLOAT, Message TEXT)"))
    {
      finish_with_error(con);
    }
  mysql_close(con);
  exit(0);
}

