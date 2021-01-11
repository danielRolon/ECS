#include <iostream>
#include <tools/handleText.h>

CharArray2 split(const char* string, char div)
{
    size_t length = strlen(string);
    size_t k_length = 0;


    // cuenta cuantas vces se encuentra el divisdor
    int counter = 1;

    for (size_t i = 0; i < length; ++i)
    {
        if (string[i] == div)
        {
            ++k_length;  
        }
    }

    char** strings = new char*[k_length+1];
    size_t k = 0;
    size_t last_div = 0;

    for (size_t i = 0; i < length; ++i)
    {
        if (string[i] == div)
        {
            if (k == 0)
            {   
                size_t tam_k_str = i-last_div;
                strings[k] = new char[tam_k_str];
                memcpy(strings[k], &string[last_div], tam_k_str);
                strings[k][tam_k_str] = '\0';
            }
            else
            {
                size_t tam_k_str = i-last_div;
                strings[k] = new char[tam_k_str];
                memcpy(strings[k], &string[last_div+1], tam_k_str);
                //strings[k][tam_k_str-1] = '\0';
            }
            
            ++k;
            last_div = i;

            if (k == k_length)
            {
                size_t tam_k_str = length-last_div-1;
                std::cout << k << " " << tam_k_str;
                //strings[k-1] = new char[tam_k_str];
                /*memcpy(strings[k], &string[last_div+1], tam_k_str);
                /*strings[k][tam_k_str] = '\0';
                break;*/
            }
            counter++;
        }
    }
    //counter++;
    CharArray2 charArray2;
    charArray2.data = strings; 
    charArray2.length = counter+1;

    return charArray2;
}