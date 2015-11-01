#include <iostream>
using namespace std;
#include <stack>

int main(void){

  int test_case = 78;
  int first_one = 0;
  int one_after_zero = 0;
  int count_one = 0;
  int count_zero = 0;

  while(test_case != 0){
    if(test_case % 2 == 1){
      count_one += 1;
      if(first_one == 0){
        first_one = 1;
      }
    } else {
      count_zero += 1;
      if(first_one == 1){
        one_after_zero = 1;
      }
    }
    test_case /= 2;
    if(first_one == 1 && one_after_zero == 1){
      break;
    }
  }
  if(test_case == 0){


  } else {
    test_case += 1;
    count_one -= 1;
    test_case *= 2;
    while((count_one + count_zero) != 0){

      test_case *= 2;
      count_zero -= 1;
    }

  }



}