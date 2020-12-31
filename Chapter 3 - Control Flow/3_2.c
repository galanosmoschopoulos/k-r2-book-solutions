#include <stdio.h>

#define MAX_CHARS 1000

int get_line(char s[], int lim);
void escape(char s[], char t[]);
void escape_reverse(char s[], char t[]);

int main()
{
    char line[MAX_CHARS];
    char processed[MAX_CHARS];

    get_line(line, MAX_CHARS);
    escape(line, processed);
    printf("%s\n", processed);

    get_line(line, MAX_CHARS);
    escape_reverse(line, processed);
    printf("%s\n", processed);

    return 0;
}

void escape_reverse(char s[], char t[])
{
    int i, j;
    for (i=j=0; s[i] != '\0'; ++i) {

        if (s[i] == '\\') {
            switch (s[i++ + 1]) {
                case 'n':
                    t[j++] = '\n';
                    break;
                case 't':
                    t[j++] = '\t';
                    break;
                case '\\':
                    t[j++] = '\\';
                    break;
                case 'a':
                    t[j++] = '\a';
                    break;
                case 'b':
                    t[j++] = '\b';
                    break;
                case 'f':
                    t[j++] = '\f';
                    break;
                case 'r':
                    t[j++] = '\r';
                    break;
                case 'v':
                    t[j++] = '\v';
                    break;
                case '?':
                    t[j++] = '\?';
                    break;
                case '\'':
                    t[j++] = '\'';
                    break;
                case '\"':
                    t[j++] = '\"';
                    break;
                default:
                    break;
            }
        }
        else {
            t[j++] = s[i];
        }
    }
    t[j] = '\0';
}

void escape(char s[], char t[])
{
    int c, i, j;
    for (i=j=0; (c=s[i]) != '\0'; ++i) {
        switch (c) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\\':
                t[j++] = '\\';
                t[j++] = '\\';
                break;
            case '\a':
                t[j++] = '\\';
                t[j++] = 'a';
                break;
            case '\b':
                t[j++] = '\\';
                t[j++] = 'b';
                break;
            case '\f':
                t[j++] = '\\';
                t[j++] = 'f';
                break;
            case '\r':
                t[j++] = '\\';
                t[j++] = 'r';
                break;
            case '\v':
                t[j++] = '\\';
                t[j++] = 'v';
                break;
            case '\?':
                t[j++] = '\\';
                t[j++] = '\?';
                break;
            case '\'':
                t[j++] = '\\';
                t[j++] = '\'';
                break;
            case '\"':
                t[j++] = '\\';
                t[j++] = '\"';
                break;
            default:
                t[j++] = c;
                break;
        }
    }
    t[j] = '\0';
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}