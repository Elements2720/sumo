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
