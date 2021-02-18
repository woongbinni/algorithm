#include <iostream>
using namespace std;
#include <stdio.h>
#include <queue>
#include <algorithm>

int N, K;
int bag[300001];
typedef struct _jewel {
    int M; 
    int V;
} jewel;
jewel jewels[300001];
priority_queue<int> pq;

bool compare(jewel ja, jewel jb){
    if(ja.M < jb.M){
        return true;
    }
    else if (ja.M == jb.M){
        if(ja.V < jb.V){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

int main(){
    long long answer = 0;
    scanf("%d%d", &N, &K);
    
    for(int i = 0 ; i<N ; i++){
        scanf("%d%d", &(jewels[i].M), &(jewels[i].V));
    }
    
    for(int i = 0 ; i<K ; i++){
        scanf("%d", &(bag[i]));
    }
    
    sort(jewels, jewels+N, compare);
    sort(bag, bag+K);
        
    int index = 0;
    for(int i = 0 ; i<K ; i++){
        while(index<N && jewels[index].M <= bag[i]){
            pq.push(jewels[index].V);
            index += 1;
        }
       
        if(!pq.empty()){
            answer += pq.top();
            pq.pop();
        }
    }
    printf("%lld\n", answer);

    return 0;
}