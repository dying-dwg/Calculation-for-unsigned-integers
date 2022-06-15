/* Вычисление для беззнаковых целых чисел */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{

    unsigned short int A, B, C;
    unsigned int P, Rem;

    printf("Enter A, B and C: ");
    scanf_s("%hu %hu %hu", &A, &B, &C);

    __asm
    {
        movzx EAX, A
        mul EAX
        mov EBX, 8
        mul EBX
        mov P, EAX

        movzx EAX, A
        movzx EBX, C
        mul EBX
        mov EBX, 4
        mul EBX
        sub P, EAX

        movzx EBX, B
        movzx EAX, P

        cdq
        div EBX

        mov P, EAX      // Помещаю результат в переменную для вывода
        mov Rem, EDX    // Помещаю остаток в переменную для вывода (если его нет, то будет 0)

    }

    printf("\n P = %u \n Rem = %u", P, Rem);


    return 0;
}