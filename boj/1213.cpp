#include <iostream>

using namespace std;
int alphabet[27];
char ans[51];
int main(){
    string s;
    cin>>s;
    int center = -1;
    for(int i = 0; i < s.size(); i++){
        alphabet[s[i] - 'A']++;
    }

    for(int i = 0; i < 26; i ++){
        int check = alphabet[i] %2;
        if(check){
            if(center == -1){
                center = i;
            }else{
                cout<<"I'm Sorry Hansoo"<<endl;
                exit(0);
            }
        }
    }
    for(int i = 0; i <= 'Z' - 'A'; i++){
        if(alphabet[i]){
            for(int j =0; j < alphabet[i]/2; j++){
                printf("%c", i + 'A');
            }
        }
    }

    if(center != -1){
        printf("%c", center + 'A');
    }
    for(int i = 'Z'-'A'; i >=0; i--){
        if (alphabet[i])
        {
            for (int j = 0; j < alphabet[i] / 2; j++)
            {
                printf("%c", i + 'A');
            }
        }
    }
    printf("\n");
}