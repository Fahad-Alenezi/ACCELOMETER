//THIS IS MBED 5 VERSION







#include "mbed.h"

#define Blinking_RATE 250ms



#define max_value 1



#define Vref  3.3



#define x_zero 0.5

#define y_zero 0.5

#define z_zero 0.5



#define voltage_sensitivty_x 0.3



#define voltage_sensitivty_y 0.3



#define voltage_sensitivty_z 0.3





Serial device(USBTX, USBRX); // tx, rx



AnalogIn xpin(A0);

AnalogIn   ypin(A1);

AnalogIn   zpin(A2);

float x,y,z;



float xv,yv,zv;







int main()

{

    

    

     device.baud(9600);

    while (true) {





x = xpin.read();

y = ypin.read();

z = zpin.read();



xv = (x/max_value*Vref-x_zero)/voltage_sensitivty_x;



yv = (y/max_value*Vref-y_zero)/voltage_sensitivty_y;



zv = (z/max_value*Vref-z_zero)/voltage_sensitivty_z;





        printf(" X: %.2f* ",xv);

        printf(" Y: %.2f ",yv);

        printf(" Z: %.2f ",zv);

        printf(" .\r \n");





  wait_ms(1000);

        




    }

}



