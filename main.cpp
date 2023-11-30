#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

int main(int argc, char *argv[])
{
    doctest::Context context;
    int doctest_result = context.run();

    return doctest_result;
}
