
#include <iostream>

int global;

int main(int argc, char** argv)
{
    const char* static_string = "alma";
    char local_variable[] = { 'a', 'l', 'm', 'a', 0 };

    char* str1 = new char[16];
    char* str2 = new char[16];

    std::cout << "global rw: " << &global << std::endl;
    std::cout << "glogal ro: " << static_cast<const void*>(static_string) << std::endl;
    std::cout << "local  rw: " << static_cast<void*>(local_variable) << std::endl;
    std::cout << "dynamic a: " << static_cast<void*>(str1) << std::endl;
    std::cout << "dynamic b: " << static_cast<void*>(str2) << std::endl;

    // str1 = "almafa"; // nem mukodik!!!

    delete str1;
    delete str2;

    std::cout << static_cast<void*>(str1) << std::endl;
    std::cout << static_cast<void*>(str2) << std::endl;

    str1 = NULL;
    str2 = nullptr;

    return 0;
}
