#include <stdio.h>
#include <wiringPi.h>

int main(int argc, char *argv[])
{

	//Initializing GPIO Pins using WiringPilibrary
     if (wiringPiSetup () == -1)
    return 1 ;

    pinMode (0, OUTPUT) ;         // aka BCM_GPIO pin 17
    pinMode (2, OUTPUT) ;


    digitalWrite (0,1) ;
    digitalWrite (2,1);
    //delay(5000);  Tested delay
    delay (50);



        int i,j,r,decimal,binary[26],k;

        for(k=0; k< 26; k++)
        {
                binary[k]=0;
        }

//        printf("Enter decimal number");
  //      scanf("%d", &decimal);
	decimal = atoi(argv[1]);

	i=25;

	while(decimal > 0)
	{
	 if (decimal % 2 == 0)
		{
		binary[i]=0;
		}
	else
		{
		binary[i]=1;
		}
	i--;
	decimal = decimal/2;
	}
	for (j=0; j <26; j++)
	{
	printf("%d", binary[j]);
	if (binary[j] == 0){
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
        delay (50);
        digitalWrite (0, 0) ;
       digitalWrite (2, 0) ;

	return 0;
}
