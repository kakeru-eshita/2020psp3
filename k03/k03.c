#include <stdio.h>
#include <string.h>
#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int start,pos,key_len,text_len;
    key_len=strlen(key);
    text_len=strlen(text);
    key_len=key_len-1;
    text_len=text_len-1;
    for(start=0;;start++)
    {
        for(pos=0;;pos++)
        {  
            if(text[start+pos]==key[pos]){
                if(key_len==pos){
                    return &text[start];
                }   
            }
            else{
            break;
            }
        }
        if(start>text_len){
        break;
        }
    }

return NULL;
}

char* BMSearch(char text[], char key[])
{
//  ここを実装する
int key_len,index,start,i,pos,text_len,h;
int table[256];
    
key_len=strlen(key);
text_len=strlen(text);
for(i=0;i<256;i++){
table[i]=key_len;
}
key_len=key_len-1;

for(index=key_len;index>=0;index--){
table[key[index]]=key_len-index;  
}

index=key_len;
pos=key_len;
text_len=text_len-1;

while(1){
    if(text[index]==key[pos]){
        if(pos==0){
            return &text[index];
        }
        index--;
        pos--;
    }
    else{
    h=index;
    index=index+table[text[index]];
    pos=key_len;
        if(index<=h){
            index=h+1;
        }
    }
    if(index>text_len){
        break;
    }
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