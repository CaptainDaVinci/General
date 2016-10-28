/*  This program is meant to impliment some
    basic functions in C.
    The following program calculates the area of
    Circle, Rectangle, Square and a Triangle.*/


#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    float radius, length, breadth, a, b, c,s;
    float area;

    // To take in users choice
    printf("Select the shape for which area is to be found\n");
    printf("1.Circle\n");
    printf("2.Rectangle\n");
    printf("3.Square\n");
    printf("4.Triangle\n");
    scanf("%d",&n );
    switch (n)

    {
          //calculates area of circle.
          case 1:
          printf("Enter the radius of the Circle\n");
          scanf("%f",&radius);
          area = 3.142 * radius * radius;
          printf("Area of the Circle = %.2f",area);
          break;
          // calculates area of rectangle.
          case 2:
          printf("Enter the length and breadth of the rectangle\n" );
          printf("Length = ");
          scanf("%f",&length );
          printf("Breadth = ");
          scanf("%f",&breadth );
          area = length*breadth;
          printf("Area of the rectangle=%.2f",area);
          break;
          // calculates area of square.
          case 3:
          printf("Enter the length of the side\n");
          scanf("%f", &length);
          area=length*length;
          printf("Area of the square = %.2f", area);
          break;
          // calculates area of triangle.
          case 4:
          printf("Enter the lenth of three sides of the Triangle\n");
          printf("a = ");
          scanf("%f",&a);
          printf("b = " );
          scanf("%f",&b );
          printf("c = " );
          scanf("%f",&c );
          s = (a+b+c)/2;
          area = sqrt (s*(s-a)*(s-b)*(s-c));
          printf("Area of the triangle is= %.2f\n", area);
          break;
    }
    // Prompts user in case of incorrect input.
    if (n > 4 || n < 1)
    {
        printf("You entered the worng value\n" );
    }
    return 0;


}
