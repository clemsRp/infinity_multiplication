
#include <unistd.h>
#include <stdlib.h>

void    print_total(char *total);
int     ft_strlen(char *str);
int     add_char(char *res, int c1, int c2, int index, int temp);
char    *init_total(char *num1, char *num2);
char    *multiply(char c, char *num);
char    *add(char *total, char *temp_add, int weight, int len);

void    algo(char *num1, char *num2)
{
    int         i;
    int         weight;
    int         len;
    char    *total;
    char    *temp_add;

    weight = 0;
    len = ft_strlen(num1) * ft_strlen(num2);
    i = ft_strlen(num1) - 1;
    total = init_total(num1, num2);
    while (i >= 0)
    {
        temp_add = multiply(num1[i], num2);
        total = add(total, temp_add, weight, len);
        free(temp_add);
        weight++;
        i--;
    }
    print_total(total);
    free(total);
}

int     main(int argc, char *argv[])
{
    if (argc != 3)
    {
        write(1, "Nombre d'arguments invalides.\n", 30);
        return (0);
    }
    algo(argv[1], argv[2]);
    return (0);
}