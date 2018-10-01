/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: 2DHIF
 * ---------------------------------------------------------
 * Exercise Number: 1
 * Title:			Hello World
 * Author:			Jan Fischlmayr
 * ----------------------------------------------------------
 * Description:
 * A simple programm.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <float.h>
#include <stdbool.h>

void userInput(int* operation);
void getOperands(double* firstOperand, double* secondOperand);

int main(int argc, char const *argv[]) {
  int operation;
  double firstOperand;
  double secondOperand;
  printf("Simple calculator\n");
  printf("=================\n\n");
  userInput(&operation);
  getOperands(&firstOperand, &secondOperand);
  calculate(&firstOperand, &secondOperand, &operation);
  return 0;
}

bool proveOperation(double operationResult, double* result){
  if (operationResult > DBL_MAX)
    {
        printf("Overflow!\n");
        return false;
    }
    else if (operationResult < DBL_MIN)
    {
        printf("Underflow!\n");
        return false;
    }

    *result = operationResult;
return true;
}

void calculate(double* firstOperand, double* secondOperand, int* operation){
  double result;
  switch(*operation)
  {
    case 1:
        proveOperation(*firstOperand + *secondOperand, &result);
        break;
    case 2:
        result = *firstOperand - *secondOperand;
        break;
    case 3:
        proveOperation(*firstOperand * *secondOperand, &result);
        break;
    case 4:
        if (*secondOperand == 0) {
          printf("Division by zero!\n");
          return;
        }
        result = *firstOperand / *secondOperand;
        break;
    printf("Result: %lf", result);
  }
}

void getOperands(double* firstOperand, double* secondOperand) {
    printf("Please enter the first operand: ");
    scanf("%lf", firstOperand);
    printf("Please enter the second operand: ");
    scanf("%lf", secondOperand);
}

bool isInputValid(int operation);
void userInput(int* operation) {
  printf("Choose one of the following operations:\nAdd (1)\nSubtract (2)\nMultiply (3)\nDivide (4)\nStop program (-1)\n");
  do {
    if (!isInputValid(*operation)) {
        printf("Input is not valid, try again\n\n");
    }
    printf("Enter your choice: ");
    scanf("%d",operation);
} while(!isInputValid(*operation));
}

bool isInputValid(int operation) {
  if (operation >= -1 && operation <= 4) {
    return true;
  }
  else{
    return false;
  }
}
