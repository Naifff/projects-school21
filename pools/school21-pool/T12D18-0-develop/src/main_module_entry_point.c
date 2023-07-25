#include <stdio.h>
#include <stdarg.h>
#include "print_module.h"
#include "documentation_module.h"
#ifdef MACROQ1
#define Q() print_log(print_char, Module_load_success_message)
#endif  // MACROQ1


int main() {
    Q();
    return 0;
}
