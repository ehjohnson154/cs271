/****************************************
 * C-ploration 1 for CS 271
 * 
 * [NAME] $Eric Johnson$
 * [TERM] FALL $2022$
 * 
 ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Function: add
 * -------------
 * calculates the sum from 0..N. 
 *   e.g., add(5) => 15
 *  
 * n:   size of the given array
 *
 * returns: sum of values 1 to N
 */
int add(int n)
{
    /** Your CODE here **/
	return ((n * (n + 1)) / 2);
	
}   


/* Function: fib
 * -------------
 * calculates the Nth Fibonacci number using recursion. 
 *   e.g., fib(10) => 55
 *
 * n: the Fibonacci number to calculate
 *
 * returns: Nth Fibonacci number
 */
int fib(int n)
{
    /** Your CODE here **/
	
	if (n <= 1){
     return n;
	}
    return fib(n - 1) + fib(n - 2);
}
 
 
/* Function: max
 * -------------
 * find the largest value in an array. 
 *   e.g., max([1,3,2,5,4], 5) => 5
 *
 * arr: array of integers 
 * n:   size of arr
 *
 * returns: largest value in arr
 */
int max(int arr[], int n)
{
    /** Your CODE here **/
	int i;
	int big = arr[0];
	
	for (i = 1; i < n; i++){
		if (arr[i] > big)
		{
			big = arr[i];
		}
	}
	return big;
}

/* Function: sum
 * -------------
 * calculates the sum of values in an array. 
 *   e.g., sum([1,3,2,5,4], 5) => 15
 *
 * arr: array of integers
 * n:   size of arr
 *
 * returns: sum of values in arr
 */
int sum(int arr[], int n)
{
    /** Your CODE here **/
	
	int i;
	int total = arr[0];
	
	for (i = 1; i < n; i++){
		total = (total + arr[i]);
	}
	return total;
}


/* Function: pie
 * -------------
 * estimate PI using Leibniz formula.
 *   e.g. pie(5) => 3.339683
 *
 * Leibniz formula
 *     π/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
 *  
 * n: number of terms to use in Leibiz formula
 *
 */
double pie(long int n){
    /** Your CODE here **/
	
	long int i = 0;
	double sum= 0.0; 
	double term = 0.0;
	double pi = 0.0;
	
	
	for(i=0;i< n;i++){
		term = pow(-1, i) / (2*i+1);
		sum += term;
		}
		pi = 4 * sum;
		return pi;
		} 


/* Function: main
 * -------------
 * parses command line arguments and executes appropriate function.
 *
 * =========================
 * DO NOT EDIT MAIN FUNCTION
 * =========================
 *
 * usage:
 *  -add N            : sum 0..N
 *  -fib N            : find Nth Fibonacci
 *  -max X1 X2 ... XN : largest value in array [X1, X2, ..., XN]
 *  -sum X1 X2 ... XN : add values in array [X1, X2, ..., XN] 
 *  -pie N            : estimate PI using N terms
 * 
 * argc: number of arguments
 * argv: array of arguments (array of array of chars)
 *
 * returns: 0 if no errors, 1 otherwise.
 */
int main(int argc, char** argv)
{
    // note: argv[0] is always the function name; in this case "main"
    //   thus, the first argument will be argv[1]
    if (argc < 3){
        // generate error: we require at least two arguments
        fprintf(stderr, "[error] Insufficient arguments.\n");
        return -1;
    }
    
    if (argv[1][0] != '-'){
        // generate error: we require a command that starts with hyphen
        fprintf(stderr, "[error] Unknown command %s. Did you forget '-'?\n", argv[1]);
        return -1;
    }
    
    // put remaining args into int array
    int offset = 2;
    int n = argc - offset;
    int* arr = malloc((n)*sizeof(int)); 
    for(int j=offset; j<argc; j++)
        arr[j-offset] = atoi(argv[j]);
        
    if (!strcmp(argv[1], "-add")){ 
        // find the sum of 1..N 
        int result = add(arr[0]);
        printf("Sum of 1 to %d is %d.\n", arr[0], result);
    }else if (!strcmp(argv[1], "-fib")){ 
        // find the Nth Fibonacci number
        int result = fib(arr[0]);
        printf("Fibonacci of %d is %d.\n", arr[0], result);
    }else if (!strcmp(argv[1], "-sum")){ 
        // find the sum of the arguments
        int total = sum(arr, n);
        printf("Sum of the numbers is %d.\n", total);
    }else if (!strcmp(argv[1], "-max")){
        // find the largest number of the arguments
        int biggest = max(arr, n);
        printf("Largest number is %d.\n", biggest);
    }else if (!strcmp(argv[1], "-pie")){ 
        // approximate PI with Leibniz
        double pie_result = pie(arr[0]);
        printf("PI(e) is %.6f.\n", pie_result);
    }else{
        // incorrect command, exit with error
        fprintf(stderr, "[error] Unknown command %s.\n", argv[1]);
        return 1;
    }
    return 0;
}