#include <stdio.h>

void escape(char s[], char t[]) {
    int i, j;
    i = 0;
    j = 0;
    while (t[i]!='\0') {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;  
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;  
            default:
                s[j++] = t[i];
                break;
        }
        i++;  
    }
    s[j] = '\0';  
}

void unescape(char s[], char t[]) {
    int i, j;
    i = 0;
    j = 0;
    while (t[i]!='\0') {
        if(t[i]=='\\'){
			switch(t[++i]){
				case 'n':
					s[j++]='\n';
					break;
				case 't':
					s[j++]='\t';
					break;	
				default:
					s[j++]='\\';
					s[j++]=t[i];
					break;		
			}
		} 
		else{
			s[j++] = t[i];
		}
		i++;
    }
    s[j] = '\0';  
}

int main() {
    char t[] = "Hello\tWorld\n";
    char s[100];
    escape(s, t);
    printf("Escaped: %s\n", s);
	char u[100];
    unescape(u, s);
    printf("Unscaped: %s", u);
    return 0;
}
