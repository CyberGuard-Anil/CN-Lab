#include <stdio.h>
struct dob { int day, month, year; };
struct student_info {
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void printByValue(struct student_info s) {
    printf("\n[By Value] Roll: %d, Name: %s, CGPA: %.2f, Age: %d/%d/%d\n", s.roll_no, s.name, s.CGPA, s.age.day, s.age.month, s.age.year);
}
void printByAddress(struct student_info *s) {
    printf("[By Address] Roll: %d, Name: %s, CGPA: %.2f, Age: %d/%d/%d\n", s->roll_no, s->name, s->CGPA, s->age.day, s->age.month, s->age.year);
}

int main() {
    struct student_info si = {23053765, "Anil", 8.5, {25,05, 2003}};
    printByValue(si);
    printByAddress(&si);
    return 0;
}

