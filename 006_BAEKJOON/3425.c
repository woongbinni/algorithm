#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef enum _operation
{
    NUM = 1,
    POP,
    INV,
    DUP,
    SWP,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD
} operation;

typedef struct _instruction
{
    operation opr;
    long long num;
} instruction;

long long stack[100010];
instruction ins_set[100010];
int ins_count = 0;
int stack_count = 0;

int simulate(int ins_num)
{
    int isError = FALSE;
    switch (ins_set[ins_num].opr)
    {
    case NUM:
        stack[stack_count] = ins_set[ins_num].num;
        stack_count += 1;
        break;
    case POP:
        if (stack_count == 0)
        {
            isError = TRUE;
        }
        else
        {
            stack_count -= 1;
        }
        break;
    case INV:
        if (stack_count == 0)
        {
            isError = TRUE;
        }
        else
        {
            stack[stack_count-1] = 0 - stack[stack_count-1];
        }
        break;
    case DUP:
        if (stack_count == 0)
        {
            isError = TRUE;
        }
        else
        {
            stack[stack_count] = stack[stack_count - 1];
            stack_count += 1;
        }
        break;
    case SWP:
        if (stack_count < 2)
        {
            isError = TRUE;
        }
        else
        {
            long long temp = stack[stack_count - 1];
            stack[stack_count - 1] = stack[stack_count - 2];
            stack[stack_count - 2] = temp;
        }
        break;
    case ADD:
        if (stack_count < 2)
        {
            isError = TRUE;
        }
        else
        {
            stack[stack_count - 2] += stack[stack_count - 1];
            stack_count -= 1;
        }
        break;
    case SUB:
        if (stack_count < 2)
        {
            isError = TRUE;
        }
        else
        {
            stack[stack_count - 2] -= stack[stack_count - 1];
            stack_count -= 1;
        }
        break;
    case MUL:
        if (stack_count < 2)
        {
            isError = TRUE;
        }
        else
        {
            stack[stack_count - 2] *= stack[stack_count - 1];
            stack_count -= 1;
        }
        break;
    case DIV:
        if (stack_count < 2)
        {
            isError = TRUE;
        }
        else if (stack[stack_count - 1] == 0)
        {
            isError = TRUE;
        }
        else
        {
            stack[stack_count - 2] /= stack[stack_count - 1];
            stack_count -= 1;
        }
        break;
    case MOD:
        if (stack_count < 2)
        {
            isError = TRUE;
        }
        else if (stack[stack_count - 1] == 0)
        {
            isError = TRUE;
        }
        else
        {
            stack[stack_count - 2] %= stack[stack_count - 1];
            stack_count -= 1;
        }
        break;
    default:
        break;
    }
    if (stack[stack_count - 1] > 1000000000 || stack[stack_count - 1] < -1000000000)
    {
        isError = TRUE;
    }
    return isError;
}

void print_stack(){
    printf("%d [", stack_count);
    for(int i=0; i<stack_count; ++i){
        printf("%lld ", stack[i]);
    }
    printf("]\n");
}

int main()
{
    char input[100];
    int test_count;

    while (1)
    {
        scanf("%s", input);
        if (strcmp("END", input) == 0)
        {
            scanf("%d", &test_count);
            for (int i = 0; i < test_count; ++i)
            {
                int isError = 0;
                scanf("%lld", &(stack[0]));
                stack_count = 1;
                for (int j = 0; j < ins_count; ++j)
                {
                    isError = simulate(j);
                    // print_stack();
                    if (isError == TRUE)
                    {
                        break;
                    }
                }
                if (stack_count == 1 && isError != TRUE)
                {
                    printf("%lld\n", stack[0]);
                }
                else
                {
                    printf("ERROR\n");
                }
            }
            printf("\n");
            ins_count = 0;
        }

        if (strcmp("QUIT", input) == 0)
        {
            break;
        }
        if (strcmp("NUM", input) == 0)
        {
            ins_set[ins_count].opr = NUM;
            int temp;
            scanf("%d", &temp);
            ins_set[ins_count].num = temp;
            ins_count += 1;
        }
        if (strcmp("POP", input) == 0)
        {
            ins_set[ins_count].opr = POP;
            ins_count += 1;
        }
        if (strcmp("INV", input) == 0)
        {
            ins_set[ins_count].opr = INV;
            ins_count += 1;
        }
        if (strcmp("DUP", input) == 0)
        {
            ins_set[ins_count].opr = DUP;
            ins_count += 1;
        }
        if (strcmp("SWP", input) == 0)
        {
            ins_set[ins_count].opr = SWP;
            ins_count += 1;
        }
        if (strcmp("ADD", input) == 0)
        {
            ins_set[ins_count].opr = ADD;
            ins_count += 1;
        }
        if (strcmp("SUB", input) == 0)
        {
            ins_set[ins_count].opr = SUB;
            ins_count += 1;
        }
        if (strcmp("MUL", input) == 0)
        {
            ins_set[ins_count].opr = MUL;
            ins_count += 1;
        }
        if (strcmp("DIV", input) == 0)
        {
            ins_set[ins_count].opr = DIV;
            ins_count += 1;
        }
        if (strcmp("MOD", input) == 0)
        {
            ins_set[ins_count].opr = MOD;
            ins_count += 1;
        }
    }

    return 0;
}