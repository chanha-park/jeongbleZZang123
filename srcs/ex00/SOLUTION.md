# Solution of Ex00.

## Model answer code

```c
#include <unistd.h>
int ft_isdigit(char c)
{
    return ('0' <= c && c <= '9');
}
void eleven_number_checker(const char *str)
{
    int     phone_number;
    int     i;
    if (!str)
        return ;
    phone_number = 0;
    i = 0;
    while (*(str + i))
    {
        if (ft_isdigit(*(str + i)))
        {
            phone_number++;
            if (phone_number == 11)
            {
                write(1, str + i - 10, 11);
                write(1, "\n", 1);
                return ;
            }
        }
        else
            phone_number = 0;
        i++;
    }
    write(1, "KO\n", 3);
    return ;
}
```


## Learning Objectives

Experience the hassle of pattern matching without using regular expressions
