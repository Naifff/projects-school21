#include <fcgi_stdio.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  while (FCGI_Accept() >= 0) {
    printf("Content-type: text/html\r\n");
    printf("\r\n");
    printf("<title>Hello world!</title>");
    printf("<h1>Hello world!</h1>");
  }

  return 0;
}