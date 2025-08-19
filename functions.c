
#include <unistd.h>
#include <stdlib.h>

int     ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *init_total(char *num1, char *num2)
{
    int         i;
    char    *res;

    i = ft_strlen(num1) * ft_strlen(num2);
    res = malloc(sizeof(char) * (i + 2));
    res[i + 1] = '\0';
    while (i >= 0)
        res[i--] = '0';
    return (res);
}

int     add_char(char *res, int c1, int c2, int index, int temp)
{
    if ((c1 * c2 + temp) > 9)
        res[index] = (c1 * c2 + temp) % 10 + '0';
    else
        res[index] = (c1 * c2 + temp) + '0';
    return ((c1 * c2 + temp - (c1 * c2 + temp) % 10) / 10);
}

char    *multiply(char c, char *num)
{
    int         i;
    int         c2;
    int         temp;
    char    *res;

    temp = 0;
    i = ft_strlen(num) - 1;
    res = malloc(sizeof(char) * i);
    res[i] = '\0';
    while (i >= 0)
    {
        c2 = num[i] - '0';
        temp = add_char(res, c - '0', c2, i + 1, temp);
        i--;
    }
    if (temp != 0)
        res[0] = temp + '0';
    else
        res[0] = '0';
    res[ft_strlen(num) + 1] = '\0';
    return (res);
}

char    *add(char *total, char *temp_add, int weight, int len)
{
    int     i;
    int     c1;
    int     c2;
    int     temp;
    int     sum;

    i = weight;
    temp = 0;
    sum = 0;
    while (i < weight + ft_strlen(temp_add))
    {
        c1 = total[len - i] - '0';
        c2 = temp_add[ft_strlen(temp_add) - 1 - i + weight] - '0';
        sum = c1 + c2 + temp;
        total[len - i] = sum % 10 + '0';
        temp = (sum - sum % 10) / 10;
        i++;
    }
    return (total);
}

void    print_total(char *total)
{
    int     i;

    i = 0;
    while (total[i] == '0' && total[i])
        i++;
    while (total[i])
    {
        write(1, &total[i], 1);
        i++;
    }
    write(1, "\n", 1);
}