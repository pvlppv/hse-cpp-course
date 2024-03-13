// include some definitions needed for woring with standard input/output (streams)
#include <iostream>
#include <climits>

// the entrypoint of the application
int main()
{
    // put a string literal "Hello world!" to the standard output stream in order 
    // to print it at the console, which is normally associated with this stream
    std::cout << "Hello world!";


    size_t s1 = sizeof(char);
    size_t s2 = sizeof(short);
    size_t s3 = sizeof(int);
    size_t s4 = sizeof(long);
    size_t s5 = sizeof(long long);



    // must return a "errorlevel code": 0 is for OK
    return 0;
}
