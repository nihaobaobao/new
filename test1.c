// C���Ե������Ǳ��������ݲ����Ϳ��ƽṹ(if,for��)����Ҫ�ǳ���ĵײ��߼��� 
#include <stdio.h>

// ����һ����
#define PI 3.14159

// ��������
double calculateCircleArea(double radius);
void printMessage(const char* message);

int main() {
    // ��������
    int number = 10, i = 0;
    double radius = 5.0;
    char character = 'A';

    // ��ӡ��Ϣ
    printf("Hello, World!\n");
    printMessage("Welcome to C Programming.");

    // ���ú�������Բ�����
    double area = calculateCircleArea(radius);
    printf("The area of a circle with radius %lf is %lf\n", radius, area);

    // ������ - if���
    if (number > 5) {
        printf("The number is greater than 5.\n");
    } else {
        printf("The number is less than or equal to 5.\n");
    }

    // ������ - forѭ��
    for (i = 0; i < 5; i++) {
        printf("Loop iteration %d\n", i);
    }

    // ������ - whileѭ��
    int j = 0;
    while (j < 3) {
        printf("Inside while loop %d\n", j);
        j++;
    }

    // ������ - do-whileѭ��
    do {
        printf("Inside do-while loop %d\n", j);
        j++;
    } while (j < 5);

    // ����
    int array[5] = {1, 2, 3, 4, 5};
    for (i = 0; i < 5; i++) {
        printf("Array element at index %d is %d\n", i, array[i]);
    }

    // ָ��
    int *ptr = &number;
    printf("The value of number is %d and its address is %p\n", *ptr, (void*)ptr);

    // �ṹ��
    typedef struct {
        int id;
        char name[50];
    } Student;
    Student stu = {1, "John Doe"};
    printf("Student ID: %d, Name: %s\n", stu.id, stu.name);

    // ����ֵ
    return 0;
}

// ��������
double calculateCircleArea(double radius) {
    return PI * radius * radius;
}

// ��������
void printMessage(const char* message) {
    printf("%s\n", message);
}