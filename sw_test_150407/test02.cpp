#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Answer[200] = {0, };
char Input[4096] = {0, };

int main()
{
	int   T;        
	int   i, l;
	cin >> T;

	for(i = 0; i < T; i++)
	{
		scanf("%s", Input);
		int len = strlen(Input);
		int n=0; 
		bool isFirst = true;
		int key = 0;
		int answer_idx = 0;

		while(n < len){
			if(isFirst){
				for(int index=0; index<3; index++){
					key *= 2;
					if(Input[n+index] == '1'){
						key += 1;
					}
				}
				n += 3;
				isFirst = false;
			}
			else{
				int value = 0;
				for(int index=0; index<8; index++){
					value *= 2;
					if(Input[n+index] == '1'){
						value += 1;
					}
				}
				n += 8;
				Answer[answer_idx] = 'A' + (value - key);
				answer_idx += 1;
			}
		}
		Answer[answer_idx] = '\0';

		cout << "#" << i+1 << " " << Answer << endl;
		for(l=0 ; l < 200 ; l++)
			Answer[l] = 0;
	}

	return 0;
}

