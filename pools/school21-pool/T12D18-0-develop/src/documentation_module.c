#include "documentation_module.h"

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(int(*validate) (char*), ...) {
    va_list list;
    va_start(list, validate);
    int a = va_arg(list, int);
    printf("%d", a);
    va_end(list);
    return 0;
}
