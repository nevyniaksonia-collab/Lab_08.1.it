#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(const char* str)
{
    if (str == nullptr)
        return 0;
    size_t len = strlen(str);
    if (len < 2)
        return 0;

    int count = 0;
    for (size_t i = 0; i + 1 < len; ++i)
    {
        if (str[i] == 'n' && str[i + 1] == 'o')
            ++count;
        else if (str[i] == 'o' && str[i + 1] == 'n')
            ++count;
    }
    return count;
}

char* Replace(const char* str)
{
    if (str == nullptr)
        return nullptr;

    size_t len = strlen(str);
    if (len < 2)
    {
        char* result = new char[len + 1];
        strcpy(result, str);
        return result;
    }

    size_t max_new_len = 2 * len + 1;
    char* tmp = new char[max_new_len];
    char* t = tmp;

    size_t i = 0;
    while (i + 1 < len)
    {
        if (str[i] == 'n' && str[i + 1] == 'o')
        {
            *t++ = '*';
            *t++ = '*';
            *t++ = '*';
            *t = '\0';
            i += 2;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    if (i < len)
    {
        *t++ = str[i++];
        *t = '\0';
    }

    return tmp;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, sizeof(str));

    int pairs = Count(str);
    cout << "String contained " << pairs << " groups of 'no' or 'on'." << endl;

    if (pairs > 0)
    {
        char* result = Replace(str);
        if (result != nullptr)
        {
            cout << "Original string : " << str << endl;
            cout << "Modified string : " << result << endl;
            delete[] result;
        }
        else
        {
            cout << "Replacement failed (nullptr returned)." << endl;
        }
    }
    else
    {
        cout << "'no' or 'on' not found" << endl;
    }

    return 0;
}