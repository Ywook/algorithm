#include<iostream>
#include<string>
#include<queue>
#include<map>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(){
    int n = 3;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 0)
            {
                temp = 9;
            }
            start = start * 10 + temp;
        }
    }
    queue<int> q;
    map<int, int> d;
    d[start] = 0;
    q.push(start);

    while(!q.empty()){
        int now = q.front(); q.pop();
        string now_str = to_string(now);
        int z = now_str.find('9');
        int y = z/3;
        int x = z%3;

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3){
                string next = now_str;
                swap(next[y*3 + x], next[ny*3 + nx]);
                int n = stoi(next);
                if(d.count(n) == 0){
                    d[n] = d[now] + 1;
                    q.push(n);
                }
            }
        }
    }

    if(d.count(123456789) == 0){
        cout<<"-1"<<endl;
    }else{
        cout<<d[123456789]<<endl;
    }
}
