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
  return 0;
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
  printf("Enter your choice: ");
  scanf("%d",operation);
  do {
    if (!isInputValid(*operation)) {
            printf("Input is not valid, try again\n\n");
        }
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
