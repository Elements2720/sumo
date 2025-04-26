char data0;

void forward() {
    PORTD.F0 = 1;
    PORTD.F1 = 0;
    PORTD.F2 = 1;
    PORTD.F3 = 0;
}

void backward() {
    PORTD.F0 = 0;
    PORTD.F1 = 1;
    PORTD.F2 = 0;
    PORTD.F3 = 1;
}

void left() {
    PORTD.F0 = 0;
    PORTD.F1 = 1;
    PORTD.F2 = 1;
    PORTD.F3 = 0;
}

void right() {
    PORTD.F0 = 1;
    PORTD.F1 = 0;
    PORTD.F2 = 0;
    PORTD.F3 = 1;
}

void stop() {
    PORTD.F0 = 0;
    PORTD.F1 = 0;
    PORTD.F2 = 0;
    PORTD.F3 = 0;
}

void Rotation0() //0 Degree
{
  unsigned int i;
  for (i = 0; i < 50; i++) {
    PORTB.F0 = 1;
    Delay_us(800); // pulse of 800us
    PORTB.F0 = 0;
    Delay_us(19200);
  }
}

void Rotation90() //90 Degree
{
  unsigned int i;
  for (i = 0; i < 50; i++) {
    PORTB.F0 = 1;
    Delay_us(1500); // pulse of 1500us
    PORTB.F0 = 0;
    Delay_us(18500);
  }
}

void Rotation180() //180 Degree

{
  unsigned int i;
  for (i = 0; i < 50; i++) {
    PORTB.F0 = 1;
    Delay_us(2200); // pulse of 2200us
    PORTB.F0 = 0;
    Delay_us(17800);
  }
}

void main() {
    TRISB = 0x00;
    TRISD = 0x00; // Output for motors
    TRISC = 0b10000000; // RC7 input (RX), RC6 output (TX)
    UART1_Init(9600);
    Delay_ms(100);

    while (1) {
        if (UART1_Data_Ready()) {
            data0 = UART1_Read();

            switch (data0) {
            case 'F':
                forward();
                break;
            case 'B':
                backward();
                break;
            case 'L':
                left();
                break;
            case 'R':
                right();
                break;
            case 'S':
                stop();
                break;
            case '0':
                Rotation0();
                break;
            case '1':
                Rotation90();
                break;
            case '2':
                Rotation180();
                break;
            }
        }
    }
}
