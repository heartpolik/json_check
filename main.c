#include <stdlib.h>
#include <stdio.h>
#include "json_valid.h"


int main() {
//Open file to read
    FILE *fp;
    fp = fopen("/home/polik/Documents/qt/json/test.txt", "r");

    if(fp==NULL) {
        printf("FILE NOT FOUND!\n");
        exit(1);
      }
//Read file and find syntax error
    while (!feof(fp))
    {
        JSON_checker jc = new_JSON_checker(20);
          for (;;) {
              int next_char = fgetc(fp);
              if (next_char <= 0) {
                  break;
              }
              if (!JSON_checker_char(jc, next_char)) {
                  printf( "JSON_checker_char: syntax error\n");
                  exit(1);
              }
          }
//Display message if find syntax error
          if (!JSON_checker_done(jc)) {
              printf( "JSON_checker_end: syntax error\n");
              exit(1);
          }
//Display  Vallid if all OK!!
          else{
              printf("JSON Vallid!!!!!!");
          return 0;
          }
    }
}
