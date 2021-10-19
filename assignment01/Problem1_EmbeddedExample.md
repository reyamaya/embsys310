#Microwave Oven.

A microwave oven has a control unit comprised of a microcontroller that receives input from a keypad. 
The input is used by main to jump into a subroutine (like a switch statement). The subroutine generates a 
PWM signal for a given number of seconds that powers on the magnetic unit.

Though this control unit is application specific, and it does not receive more than a few inputs at a time, 
it still poses many development challenges. There is a keypad and screen that shows the input. Also, pressing 
the start button turns the magnet motor and microwave on. However, different modes are supposed to turn the magnet 
on and operate it for a specific amount of time. It is easy to see the magnet moving (probably) without the chassis 
on the microwave. However, once the microwave is enclosed, the magnet cannot be seen moving nor can the output from
the microcontroller be measured. Furthermore, the only way to actually see the output from the microcontroller is to 
probe on the desired output. Another challenge that this control unit presents is cost. Since microwaves are not expensive
pieces of appliances, the cost of these units is critical. A sophisticated microcontroller could have additional features 
that won’t be used and those features could add to the overall BOM cost. Therefore, for an application specific type of unit, 
as for a microwave, the number of features should be minimized and a more constraint unit should be chosen in order to reduce 
the overall microcontroller cost.
