#include <string>
using namespace std;
int list[30];

int solution(string S)
{
    int answer = 0;
    
    for(int i = 0; i < S.size(); i++){
        list[S[i] - 'a']++;
    }

    for(int i = 0; i < 30; i++){        
        if(list[i]!= 0 && list[i]%2 == 1){
            answer++;
        }
    }
    return answer;
}

int main(){
    cout<<solution("aabbbccd")<<endl;
    return 0;
}