typedef char string[255];

typedef struct ComplexNumber ComplexNumber;

typedef enum { sum, subtract, multiply, divide } ComplexNumberOperations;

void show_imaginary_number(ComplexNumber *src, string title);
void delete_imaginary_number(ComplexNumber *src);

ComplexNumber * create_complex_number(float real, float imag);
ComplexNumber * sum_complex_numbers(ComplexNumber *num1, ComplexNumber *num2);
ComplexNumber * subtract_complex_numbers(ComplexNumber *num1, ComplexNumber *num2);
ComplexNumber * multiply_complex_numbers(ComplexNumber *num1, ComplexNumber *num2);
ComplexNumber * divide_complex_numbers(ComplexNumber *num1, ComplexNumber *num2);
ComplexNumber * calculate(ComplexNumber *num1, ComplexNumber *num2, ComplexNumberOperations operation);
