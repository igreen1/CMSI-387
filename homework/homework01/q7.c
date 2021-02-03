#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[128];
    printf("Please input name:\n");
    scanf("%s", name);

    int age;
    printf("Please input age:\n");
    scanf("%d", &age);

    int class_year;
    printf("Please input class year:\n");
    scanf("%d", &class_year);

    int height;
    printf("Please input height:\n");
    scanf("%d", &height);

    int weight;
    printf("Please input weight:\n");
    scanf("%d", &weight);

    char city_of_birth[128];
    printf("Please input city of birth:\n");
    scanf("%s", city_of_birth);

    printf("current name is %s.\n", name);

    printf("current age is %d.\n", age);

    printf("current class year is %d.\n", class_year);

    printf("current height is %d.\n", height);

    printf("current weight is %d.\n", weight);

    printf("current city of birth is %s.\n", city_of_birth);
    return 0;
}