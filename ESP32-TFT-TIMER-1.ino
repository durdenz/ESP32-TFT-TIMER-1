hw_timer_t *Timer0 = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
 
void IRAM_ATTR onTimer0()
{
    portENTER_CRITICAL_ISR(&timerMux);
    Serial.println("Timer0 IRQ Handler Entered");
    portEXIT_CRITICAL_ISR(&timerMux);
}
void setup()
{
    Serial.begin(9600);

    Timer0 = timerBegin(1000000); // Timer Frequency in HZ, 1000000 = 1 MHZ
    timerAttachInterrupt(Timer0, &onTimer0);
    timerAlarm(Timer0, 1000000,true, 0); // Set Timer to call handler every 1000000 ticks = 1000 milliseconds
}
void loop()
{
    // Do Nothing!
}