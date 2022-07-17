#include <stdio.h>
#include <stdbool.h>
#include <math.h>

struct Point {
    int x;
    int y;
};
struct Circle{
    struct Point *center;
    float radius;

};

void swap(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void firstUpdate(int *a,int *b) {
	int temp = *a + *b;
    *b = abs(*a - *b);
	*a = temp;
}
void secondUpdate(int *a,int *b, int n) {
	*a = *a - n;
    *b = *b + n;
}
bool intersects(struct Circle *c1, struct Circle *c2){
    /*
     * I defined two circles intersecting
     * if they have one or more common points
     * on the 2d plane
     */

    float distance = sqrtf( powf(c1->center->x - c2->center->x, 2) + powf(c1->center->y - c2->center->y, 2) );
    return ( fabsf(c1->radius - c2->radius) <= distance) && (distance <= c1->radius + c2->radius);
}

int main() {
    int a, b;
	
	int *pa = &a, *pb = &b;
	
    printf("Give the Numbers a and b:");
    scanf("%d %d", &a, &b);
    swap(pa, pb);
    printf("Swapped Numbers: a->%d b->%d\n", a, b);
    firstUpdate(pa, pb);
    printf("Numbers After First Update: a->%d b->%d\n", a, b);
    struct Point p1;
    p1.x = a;
    p1.y = b;
    int n;
    printf("Number n for Second Update:");
    scanf("%d", &n);
    secondUpdate(pa, pb, n);
    printf("Numbers After Second Update: a->%d b->%d\n", a, b);
    struct Point p2;
    p2.x = a;
    p2.y = b;
    struct Circle c1;
    c1.center = &p1;
    printf("Radius of Fist Circle:");
    scanf("%f", &c1.radius);
    struct Circle c2;
    c2.center = &p2;
    printf("Radius of Second Circle:");
    scanf("%f", &c2.radius);
    if(intersects(&c1,&c2)){
        printf("Circles are Intersected");
    }else{
        printf("Circles are NOT Intersected");
    }



    return 0;
}



/*
 The output is 48.
 When the function is called, the pointer variable ptr initially contains
 the address of the num variable but the value in that address is never
 used in the function. The function just reassigns the address contained
 in ptr to that of the temporary variable temp in the same function.
 Therefore, neither the address contained in p nor the value of num is changed.
*/

