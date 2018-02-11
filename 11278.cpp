#include <cstdio>
#include <cstring>
char map[260];


int main() {
    char line[2005];
    for (int i = 0; i < 256; i++) {
        map[i] = i;
    }
    map['4'] = 'q';
    map['5'] = 'j';
    map['6'] = 'l';
    map['7'] = 'm';
    map['8'] = 'f';
    map['9'] = 'p';
    map['0'] = '/';
    map['-'] = '[';
    map['='] = ']';
    map['q'] = '4';
    map['w'] = '5';
    map['e'] = '6';
    map['r'] = '.';
    map['t'] = 'o';
    map['y'] = 'r';
    map['u'] = 's';
    map['i'] = 'u';
    map['o'] = 'y';
    map['p'] = 'b';
    map['['] = ';';
    map[']'] = '=';
    map['a'] = '7';
    map['s'] = '8';
    map['d'] = '9';
    map['f'] = 'a';
    map['g'] = 'e';
    map['j'] = 't';
    map['k'] = 'd';
    map['l'] = 'c';
    map[';'] = 'k';
    map['\''] = '-';
    map['z'] = '0';
    map['x'] = 'z';
    map['c'] = 'x';
    map['v'] = ',';
    map['b'] = 'i';
    map['m'] = 'w';
    map[','] = 'v';
    map['.'] = 'g';
    map['/'] = '\'';
    map['$'] = 'Q';
    map['%'] = 'J';
    map['^'] = 'L';
    map['&'] = 'M';
    map['*'] = 'F';
    map['('] = 'P';
    map[')'] = '?';
    map['_'] = '{';
    map['+'] = '}';
    map['Q'] = '$';
    map['W'] = '%';
    map['E'] = '^';
    map['R'] = '>';
    map['T'] = 'O';
    map['Y'] = 'R';
    map['U'] = 'S';
    map['I'] = 'U';
    map['O'] = 'Y';
    map['P'] = 'B';
    map['{'] = ':';
    map['}'] = '+';
    map['A'] = '&';
    map['S'] = '*';
    map['D'] = '(';
    map['F'] = 'A';
    map['G'] = 'E';
    map['J'] = 'T';
    map['K'] = 'D';
    map['L'] = 'C';
    map[':'] = 'K';
    map['"'] = '_';
    map['Z'] = ')';
    map['X'] = 'Z';
    map['C'] = 'X';
    map['V'] = '<';
    map['B'] = 'I';
    map['M'] = 'W';
    map['<'] = 'V';
    map['>'] = 'G';
    map['?'] = '"';
    while (fgets(line, 2005, stdin) != NULL) {
        int cur = 0;
        while (cur < strlen(line)) {
            printf("%c", map[line[cur]]);
            cur++;
        }
        //printf("\n");
    }
}