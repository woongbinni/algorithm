#include<stdio.h>
 
unsigned int arr[100001];
 
int main() {
    int n, m;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%u", &(arr[i]));
    }

    unsigned int result = 0xFFFFFFFF;
    unsigned int len = 0;
    
    int left = 0; 
    int right = 0;
    unsigned int sum = arr[0];
 
    while (left <= right && right < n) {
 
        if (sum < m) {
            if (right < n) {
                right += 1;
                sum += arr[right];
            }
        }
        else if (sum >= m) {
            len = right - left + 1;
            if (result > len) {
                result = len;
            }
 
            if (left <= right) {
                sum -= arr[left];
                left++;
            }
        }
    }
 
    if (result == 0xFFFFFFFF) {
        printf("0\n");
    }
    else {
        printf("%u\n", result);
    }
 
}