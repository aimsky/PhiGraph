#include </opt/lampp/include/mysql.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "phigraph.h"
using namespace std;
MYSQL* conn;
MYSQL_RES *res;
MYSQL_ROW row;
static char *server_args[] =
{
    "this_program",       /* this string is not used */
    "--datadir=.",
    "--key_buffer_size=32M"
};
static char *server_groups[] =
{
    "embedded",
    "server",
    "this_program_SERVER",
    (char *)NULL
};


uphiLong outOffset(char** vertexId,uphiLong* offset,unsigned long vertexNum,bool s){
  uphiLong edgesNum = 0;
  char *tempsql;
  for(phiLong i = 0;i < vertexNum;i++){
    //char sql[100];
    if(s){
      char sql[100] = "select * from userrelation where suid=";
      tempsql = strcat(sql,vertexId[i]);
    }else{
      char sql[100] = "select * from userrelation where tuid=";
      tempsql = strcat(sql,vertexId[i]);
    }

    //char *tempsql = strcat(sql,vertexId[i]);
    //printf("%s\n",sql );
    if (mysql_query(conn, tempsql))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    res = mysql_store_result(conn);
    unsigned long of = (unsigned long) mysql_num_rows(res);
    //printf("%ld\n", of);
    if(i!=(vertexNum -1)){
      offset[i+1] = offset[i]+of;
    }

    edgesNum += of;
    // if(i < 10){
    //   printf("offset[%d]=%lu\n",i,offset[i] );
    //
    // }else{
    //   break;
    // }
  }
  return edgesNum;
}

uphiLong findIndex(char** st,char* s,phiLong num){
  for(phiLong i= 0;i < num;i++){
    if(strcmp(st[i],s) == 0){
      return i;
    }
  }
}

void outEdges(char** vertexId,uphiLong* edges,unsigned long edgesNum,unsigned long vertexNum,bool s,int id){
  phiLong j=0;
  char *tempsql;
  for(phiLong i = 0;i < vertexNum;i++){
    //char sql[100] = s;
    if(s){
      char sql[100] = "select * from userrelation where suid=";
      tempsql = strcat(sql,vertexId[i]);
    }else{
      char sql[100] = "select * from userrelation where tuid=";
      tempsql = strcat(sql,vertexId[i]);
    }
    //printf("%s\n",tempsql );
    if (mysql_query(conn, tempsql))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    res = mysql_store_result(conn);
    //unsigned long of = (unsigned long) mysql_num_rows(res);
    //printf("edges:\n");
    while ((row = mysql_fetch_row(res)) != NULL){
      //printf("%s\n",row[1] );
      phiLong temp = findIndex(vertexId,row[id],vertexNum);
      edges[j] = temp;

      //printf("edges[%d]=%ld\n",j,edges[j] );
      j++;
    }
    // if(i > 4){
    //   break;
    // }
  }
}



int main(void)
{
    if (mysql_server_init(sizeof(server_args) / sizeof(char *),server_args, server_groups))
        printf("init suscess\n" );

    char *server = "localhost";
    char *user = "root";
    char *password = "wbgood";
    char *database = "webdataset";
    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server,
                            user, password, database, 0, NULL, 0))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    char* sql = "select * from user;";
    if (mysql_query(conn, sql))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    res = mysql_store_result(conn);
    unsigned long vertexNum = (unsigned long) mysql_num_rows(res);
    printf("vertexNum=%lu\n",vertexNum );

    char** vertexId = phimalloc(char*,vertexNum);
    uphiLong* offset = phimalloc(uphiLong,vertexNum);
    //utput table name */
    //printf("MySQL Tables in mysql database:\n");
    int i=0;
    while ((row = mysql_fetch_row(res)) != NULL){
      vertexId[i] = row[0];
      // if(i < 10){
      //   printf("vertexId = %s\n", vertexId[i] );
      // }
      i++;

    }

    //const char* sql ;//= "select * from user;";
    //char sql[100]="select * from userrelation where suid=";
    offset[0] = 0;
    uphiLong edgesNum = outOffset(vertexId,offset,vertexNum,true);

    printf("edges=%ld\n",edgesNum );

    uphiLong* edges =phimalloc(uphiLong,edgesNum);

    outEdges(vertexId,edges,edgesNum,vertexNum,true,1);
    PhiGraphIO csrio(vertexNum,edgesNum,offset,edges);// =new PhiGraphIO;
    csrio.writeGraphToFile("webcsrdata");

    printf("ru du\n");

    edgesNum = outOffset(vertexId,offset,vertexNum,false);

    //printf("edges=%ld\n",edgesNum );

    //uphiLong* edges =phimalloc(uphiLong,edgesNum);

    outEdges(vertexId,edges,edgesNum,vertexNum,false,0);
    PhiGraphIO cscio(vertexNum,edgesNum,offset,edges);
    cscio.writeGraphToFile("webcscdata");
    // for(phiLong i = 0;i < vertexNum;i+,edg+){
    //   char sql[100] = "select * from userrelation where suid=";
    //   char *tempsql = strcat(sql,vertexId[i]);
    //   //printf("%s\n",sql );
    //   if (mysql_query(conn, tempsql))
    //   {
    //       fprintf(stderr, "%s\n", mysql_error(conn));
    //       exit(1);
    //   }
    //   res = mysql_store_result(conn);
    //   unsigned long of = (unsigned long) mysql_num_rows(res);
    //   //printf("%ld\n", of);
    //   if(i!=(vertexNum -1)){
    //     offset[i+1] = offset[i]+of;
    //   }
    //   edgesNum += of;
    //   //free(tempsql);
    //   //printf("%ld\n",offset[i] );
    //
    //
    // }

    // phiLong j=0;
    // for(phiLong i = 0;i < vertexNum;i++){
    //   char sql[100] = "select * from userrelation where suid=";
    //   char *tempsql = strcat(sql,vertexId[i]);
    //   //printf("%s\n",sql );
    //   if (mysql_query(conn, tempsql))
    //   {
    //       fprintf(stderr, "%s\n", mysql_error(conn));
    //       exit(1);
    //   }
    //   res = mysql_store_result(conn);
    //   unsigned long of = (unsigned long) mysql_num_rows(res);
    //   printf("edges:\n");
    //   while ((row = mysql_fetch_row(res)) != NULL){
    //     printf("%s\n",row[1] );
    //     phiLong temp = findIndex(vertexId,row[1],vertexNum);
    //     edges[j] = temp;
    //
    //     printf("%ld\n",edges[j] );
    //     j++;
    //   }
    //   //printf("%ld\n",offset[i] );
    //   //free(tempsql);
    //
    //
    // }
    for(phiLong i = 0;i < 10;i++){
      printf("%ld\n",offset[i] );
    }


      //printf("%ld\n", row[0]);
    //row = mysql_fetch_row(res);
    //row = mysql_fetch_row(res);
    //cout<<row[0];

    // printf ("Number of rows: %lu\n", (unsigned long) mysql_num_rows(res));
    // MYSQL_FIELD *field;
    // while ((field = mysql_fetch_field(res)))
    // {
    //     printf("field name %s\n", field->name);
    // }
    // int num_fields = mysql_num_fields(res);
    // for (int i = 0; i < num_fields; i++)
    // {
    //     field = mysql_fetch_field_direct(res, i);
    //     printf("Field %u is %s\n", i, field->name);
    // }
    // if (!mysql_set_character_set(conn, "utf8"))
    // {
    //     MY_CHARSET_INFO cs;
    //     mysql_get_character_set_info(conn, &cs);
    //     printf("character set information:\n");
    //     printf("character set name: %s\n", cs.name);
    //     printf("collation name: %s\n", cs.csname);
    //     printf("comment: %s\n", cs.comment);
    //     printf("directory: %s\n", cs.dir);
    //     printf("multi byte character min. length: %d\n", cs.mbminlen);
    //     printf("multi byte character max. length: %d\n", cs.mbmaxlen);
    // }
    /* close connection */
    mysql_free_result(res);
    mysql_close(conn);
    /* Use any MySQL API functions here */
    mysql_server_end();
    return EXIT_SUCCESS;
}
