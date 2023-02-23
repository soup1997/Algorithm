#include <stdio.h>
#include <string.h>
int main()
{
    char croatian[101] = { NULL };
    int cnt = 0;
    gets(croatian);
    for (int i = 0; i <= strlen(croatian); i++)
    {
        if (croatian[i] == NULL)
        {
            break;
        }
        if (croatian[i] == 'n' || croatian[i] == 'l')
        {
            if (croatian[i + 1] == 'j')
            {
                continue;
            }
        }
        else if (croatian[i] == 'c' || croatian[i] == 's' || croatian[i] == 'z')
        {
            if (croatian[i + 1] == '=' || croatian[i + 1] == '-')
            {
                continue;
            }
        }
        else if (croatian[i] == 'd')
        {
            if (croatian[i + 1] == '-')
            {
                continue;
            }
            if (croatian[i + 1] == 'z' && croatian[i + 2] == '=')
            {
                continue;
            }
        }
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
