#include<stdio.h>
#include <wiringPi.h>

int main(int argc, char *argv[] )
  {

    //Initializing GPIO Pins using WiringPilibrary
     if (wiringPiSetup () == -1)
    return 1 ;

    pinMode (0, OUTPUT) ;         // aka BCM_GPIO pin 17
    pinMode (2, OUTPUT) ;


    digitalWrite (0,1) ;
    digitalWrite (2,1);
    delay(5000);
    //delay (2000);
//    printf("Input number is %s\n", argv[1]);


    long int decimalNumber,remainder,quotient;
    int binaryNumber[100],i=1,j;

    //printf("Enter any decimal number: ");
    //scanf("%ld",&decimalNumber);
    decimalNumber = atoi(argv[1]);
    quotient = decimalNumber;
//    printf("Input number is ", decimalNumber);

    while(quotient!=0){
         binaryNumber[i++]= quotient % 2;
         quotient = quotient / 2;
    }


    printf("Equivalent binary value of decimal number %ld: ",decimalNumber);
    for(j = i -1 ;j> 0;j--)
         {
         printf("%d",binaryNumber[j]);
         if (binaryNumber[j] == 0){
                digitalWrite (0, 0) ;       // On
                digitalWrite (2, 1) ;
                delay (.04);
             }  else {
                digitalWrite (0, 1) ;       // On
                digitalWrite (2, 0) ;
                delay (.04);
             }
	       digitalWrite (2, 1);
	       digitalWrite (0, 1);
               delay(0.5);
             }
             digitalWrite (0, 1) ;
             digitalWrite (2, 1) ;
             delay (2000);
             digitalWrite (0, 0) ;
             digitalWrite (2, 0) ;
             return 0;

}
