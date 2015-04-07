#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int N;
int AnswerN;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;


	for(test_case = 1; test_case <= T; ++test_case)
	{


		cin >> N;

		char** map = new char*[N];
		char** result = new char*[N];
		for(int i = 0; i < N ; i++) {
			map[i] = new char[N];
			result[i] = new char[N];
			for(int j = 0 ; j < N ; j++) {
				cin >> map[i][j];
				result[i][j] = map[i][j];
				if(map[i][j] == ' ' || map[i][j] == '\n'){
					cin >> map[i][j];
					result[i][j] = map[i][j];
				}
			}
		}

		for(int i=0;i<N; i++){
			for(int j=0; j<N; j++){
				if(map[i][j] == 'A'){
					for(int k=0; k<N; k++){
						int min = (i-1)<0 ? 0 : i-1;
						int max = (i+1)>=N ? N-1 : i+1;
						if(k>=min && k<=max)
							result[k][j] = 'X';
					}
					for(int k=0; k<N; k++){
						int min = (j-1)<0 ? 0 : j-1;
						int max = (j+1)>=N ? N-1 : j+1;
						if(k>=min && k<=max)
						result[i][k] = 'X';
					}
				}
				if(map[i][j] == 'B'){
					for(int k=0; k<N; k++){
						int min = (i-2)<0 ? 0 : i-2;
						int max = (i+2)>=N ? N-1 : i+2;
						if(k>=min && k<=max)
						result[k][j] = 'X';
					}
					for(int k=0; k<N; k++){
						int min = (j-2)<0 ? 0 : j-2;
						int max = (j+2)>=N ? N-1 : j+2;
						if(k>=min && k<=max)
						result[i][k] = 'X';
					}
				}
				if(map[i][j] == 'C'){
					for(int k=0; k<N; k++){
						int min = (i-3)<0 ? 0 : i-3;
						int max = (i+3)>=N ? N-1 : i+3;
						if(k>=min && k<=max)
						result[k][j] = 'X';
					}
					for(int k=0; k<N; k++){
						int min = (j-3)<0 ? 0 : j-3;
						int max = (j+3)>=N ? N-1 : j+3;
						if(k>=min && k<=max)
						result[i][k] = 'X';
					}
				}
			}
		}

		AnswerN = 0;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(result[i][j] == 'H')
					AnswerN += 1;
			}
		}

		cout << "#" << test_case << " " << AnswerN << endl;

		for(int i = 0; i < N ; i++) {
			delete[] map[i];
			delete[] result[i];
		}
		delete[] map;
		delete[] result;

	}

	return 0;
}
