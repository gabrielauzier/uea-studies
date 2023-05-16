typedef char string[255];

typedef struct ImaginaryNumber ImaginaryNumber;

typedef enum { sum, subtract, multiply } ImaginaryNumberOperations;

void show_imaginary_number(ImaginaryNumber *src, string title);
void delete_imaginary_number(ImaginaryNumber *src);

ImaginaryNumber * create_imaginary_number(float real, float imag);
ImaginaryNumber * sum_imaginary_numbers(ImaginaryNumber *num1, ImaginaryNumber *num2);
ImaginaryNumber * subtract_imaginary_numbers(ImaginaryNumber *num1, ImaginaryNumber *num2);
ImaginaryNumber * multiply_imaginary_numbers(ImaginaryNumber *num1, ImaginaryNumber *num2);
ImaginaryNumber * calculate(ImaginaryNumber *num1, ImaginaryNumber *num2, ImaginaryNumberOperations operation);
