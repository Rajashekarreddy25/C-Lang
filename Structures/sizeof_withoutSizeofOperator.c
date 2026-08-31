#include<stdio.h>
struct student{
char name[20];
int roll;
float marks;
};
int main(){
struct student s[2];
int size=(char *)&s[1]-(char *)&s[0];
printf("sizeof structure without sizeof %d\n",size);
printf("%lu\n",sizeof(struct student));
}
