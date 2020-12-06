#include <stdio.h>
#include <string.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";
char* ForceSearch(char text[], char key[])
{
    int i;
    int start;
    int key_len;
    int text_len;
    int pos=0;
    key_len=strlen(key);
    text_len=strlen(text);
    start=0;
    for(start=0;start<text_len;start++){
        for(i=0;i<key_len;i++){
          if(text[start+i]==key[pos]){
              pos++;
           if(key_len==pos){
               return &text[start];  
          }
        }else{
            break;
        }
    }
             pos=0;
  }
           return NULL;
}

char* BMSearch(char text[], char key[])
{
    int index;
    int text_len=0;
    int key_len;
    int pos,i,t,z=0;
    i=0;
    t=0;
 while(1)
 {
     if(text[text_len]=='\0')
     {
         break;
     }
     text_len++;
 }
 text_len=text_len-1;


key_len=0;
while(1)
{
    if(key[key_len]=='\0')
    {
        break;
    }
    key_len++;
}
char table[256];
for(z=0;z<256;z++)
{
    table[z]=key_len;
}
for(z=key_len;z>0;z--)
{
    table[key[z-1]]=i;
    i++;
}
index=key_len-1;
while(index<=text_len)
{
    for(pos=key_len-1;pos>=0;pos--)
    {
        if(text[index]==key[pos])
    {
        if(pos==0&&text[index]==key[pos])
        {
            return &text[index];
        }
    }
    else
    {
      break;
    }
    index--;
}
if(index+table[text[index]]<t)
{
    index=index+1;
}
else{
    index=index+table[text[index]];
}
t=index;
}
return NULL;
}
int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}