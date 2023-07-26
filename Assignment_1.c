/*
<----------------------------------------------------Problem Statement------------------------------------->
You are required to write a C/C++ program to perform the following tasks:
1. Generate 500 random integers and store them in an array.
2. Determine the highest base for each integer in the array using the formula:
Highest base of an integer = max(all the digits in an integer) + 1

For example, the highest base of 456 = max(4,5,6) = 6+1 = 7

3. Calculate the highest base of all the integers in the array, which will always
lie in the range [2, 10].

4. Compute that how many integers belong to each base (Frequency of Integers belonging to each base).

5. Plot the frequency distribution of bases in the range [2, 10].
*/

#include <stdio.h>     // Through this directive( preprocessor directive ) I included the header file stdio.h for standard input/output operations and it provides functions like printf and scanf which are used for reading input and printing output.
#include <stdlib.h>    // This directive( preprocessor directive )includes the header file stdlib.h for the standard library as it contains functions for memory allocation and many more.

#define NUM_RANDOM_NUMBERS 100   // print---->100_random_numbers
#define SCALING_FACTOR 1000      // manipulate---->values
#define SHIFTING_VALUE 1000      // shifting---->data
#define NUM_BASES 9              // total---->bases( although by defining this early we can access it for whole program ( we can directly change the value form here No need to go through with complete code ) )

int calculateBaseFrequency(int randomNumbers[], int baseFrequency[]);     // function prototype---->declaration of a function------>two parameters----an array of integers randomNumbers[] and array of integers baseFrequency[]---->calculate frequency of occurrences of different bases---->stores the frequency in the baseFrequency array---->return integer value
void printBaseFrequency(int baseFrequency[]);                             // function prototype---->declaration of a function------>one parameter----array of integers baseFrequency[]---->displays the frequency distribution of bases ---->return type--->void--->not return any value.
void printFrequencyDistribution(int baseFrequency[]);                     // function prototype---->declaration of a function------>one parameter----array of integers baseFrequency[]----> displays the detailed frequency distribution of bases ---->return type--->void--->not return any value.

int main()                                                                           // calling---->starts
{
    int randomNumbers[NUM_RANDOM_NUMBERS];                                           // int array randomNumbers is declared to store NUM_RANDOM_NUMBERS random integers
    int baseFrequency[NUM_BASES] = {0};                                              // int array baseFrequency is declared and initialized with all element to zero now this array will be used to store the frequency of integers belonging to each base.

    printf("\n\t%d random numbers ->\n\n\t\t", NUM_RANDOM_NUMBERS);                 
    for (int i = 0; i < NUM_RANDOM_NUMBERS; i++)
    {                                                                                // prints---->random numbers(NUM_RANDOM_NUMBER)---->display on screen using the rand() function along with SCALING_FACTOR and SHIFTING_VALUE the generated random numbers are stored in the randomNumbers array.
        randomNumbers[i] = rand() % SCALING_FACTOR + SHIFTING_VALUE;
        printf("%d ", randomNumbers[i]);
    }
    printf("\n\n\tFrequency of Integers belonging to each base ->\n");
    calculateBaseFrequency(randomNumbers, baseFrequency);                           // calculateBaseFrequency(randomNumbers, baseFrequency); This function is called to calculate the frequency of integers belonging to each base. It takes the randomNumbers array and the baseFrequency array as parameters.
    printBaseFrequency(baseFrequency);                                              // function is called to print and displays the frequency of integers belonging to each base

    printf("\n\n\tFrequency Distribution over different bases on x-axis -->\n");    // function is called to print the frequency distribution over different bases on the x-axis.
    printFrequencyDistribution(baseFrequency);

    return 0;                                                                       // indicating successful execution of the program
}

/*
now we will create a function base(int n) takes integer n as input and finds the largest digit present in the number
now there will be two integer variables let (r and m) r is used to store the remainder of n when divided by 10, and m is used to store the maximum digit
now we will put a conditions that while loop continues until n becomes zero

Once the loop finishes, the function returns the maximum digit m found in the original number n.

lastly this function calculates the maximum digit (base) of a given number n
For example, if n is 75324, the function will return 7 (as it is the largest digit in the number)
*/

int base(int n)
{
    int r, m = 0;
    while (n)
    {
        r = n % 10;
        if (m < r)
            m = r;
        n = n / 10;
    }
    return m;
}

int calculateBaseFrequency(int randomNumbers[], int baseFrequency[])
{
    for (int i = 0; i < NUM_RANDOM_NUMBERS; i++)
    {                                                                           // calculateBaseFrequency iterates through the elements of the randomNumbers array it calculates the largest digit (base) using the base() function and then increments the corresponding base's frequency count in the baseFrequency array if the base is between 2 and 10 (inclusive). lastly it finding the frequency of integers belonging to each base between 2 and 10 in the randomNumbers array and updating the baseFrequency array accordingly.
        int currentBase = base(randomNumbers[i]);
        if (currentBase >= 2 && currentBase <= 10)
        {
            baseFrequency[currentBase - 2]++;
        }
    }
}

void printBaseFrequency(int baseFrequency[])
{
    for (int i = 0; i < NUM_BASES; i++)                          // printBaseFrequency prints the frequency of integers belonging to each base between 2 and 10, which is stored in the baseFrequency array and It displays the base number and its corresponding frequency on the screen.
    {
        printf("\n\t\tBase %d -> %d", i + 2, baseFrequency[i]);
    }
}

void printFrequencyDistribution(int baseFrequency[])
{
    int maxFrequency = baseFrequency[0];
    for (int i = 1; i < NUM_BASES; i++)
    {
        if (baseFrequency[i] > maxFrequency)
        {
            maxFrequency = baseFrequency[i];
        }
    }

    for (int i = maxFrequency; i >= 0; i--)                   // printFrequencyDistribution prints a graph of the frequency distribution of bases between 2 and 10 and the base numbers are shown below the graph in ascending order from 2 to 10 and height of each column depend on the base or the frequency of each number
    {
        printf("\t\t");
        for (int j = 0; j < NUM_BASES; j++)
        {
            if (baseFrequency[j] > i)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    printf("\t\t");
    for (int i = 2; i <= 10; i++)
        printf("%d ", i);
}
