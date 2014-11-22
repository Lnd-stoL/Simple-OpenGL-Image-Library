
#include "query_extensions_gl32.h"

#include <glbinding/gl/gl32core.h>
#include <string.h>

using namespace std;
using namespace gl32core;


bool fast_strcmp (char *str1, char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)  return false;

        ++str1;
        ++str2;
    }

    return *str1 == *str2;
}


int gl32_check_extension_supported (const char *ext_name_to_check)
{
    int ext_count = 0;
    glGetIntegerv (GL_NUM_EXTENSIONS, &ext_count);

    for (int i = 0; i < ext_count; ++i)
    {
        if (fast_strcmp ((char *)ext_name_to_check, (char*) glGetStringi (GL_EXTENSIONS, i)))
        {
            return 1;
        }
    }

    return 0;
}
