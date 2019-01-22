//Kalli Bonin and Alexander Dineen
//Question 1 - Counting Green

void measure_green(int time, int power, int &green, int &notGreen)
{
	const float ONE_CM = 180.0 / PI * 2.75;
	time1[T1] = 0;
	motor[motorA] = motor[motorC] = power;
	while ( time1[T1] < time)
		{
			while ((float)nMotorEncoder[motorA] < ONE_CM)
			{}
				if (SensorValue[S2] == (int)colorGreen)
						green++;
					else
						notGreen++;
					nMotorEncoder[motorA] = 0;
		}
	motor[motorA] = motor[motorC] = 0;
}

task main()
{
	int green = 0, notGreen = 0;

	SensorType[S1] = sensorEV3_Touch;
	SensorType[S2] = sensorEV3_Color;
	wait1Msec(50);
	SensorMode[S2] = modeEV3Color_Color;
	wait1Msec(50);

	displayString(3, "13 Monday");

	while (!SensorValue[S1]){}
	while (SensorValue[S1]){}


	while(!getButtonPress(buttonAny)){}
	while(!getButtonPress(buttonDown))
	{
		if(getButtonPress(buttonLeft))
		{
			while(getButtonPress(buttonLeft)){}
			measure_green(2000, 75, green, notGreen);
		}
		else if(getButtonPress(buttonRight))
		{
			while(getButtonPress(buttonRight)){}
			measure_green(3000, 50, green, notGreen);
		}
		else if(getButtonPress(buttonEnter))
		{
			while(getButtonPress(buttonEnter)){}
			measure_green(4000, 25, green, notGreen);

		}
		displayString(2, "Green: %d Not Green: %d", green, notGreen);
	}
	while(getButtonPress(buttonDown)){}
}
/*
	Final values:
	Green: 78
	Not Green: 106

	Reflection:
	Since green has blue and yellow in it, the robot will miss detect
	occasionally. As well, LED does not produce uniform pattern each color. 
	Because of this, when it is very close to the mat, some colors reflect 
	and reach the sensor, while some do not. 
	
	If we were going to detect a certain type of green and we need to be more
	accurate, we could use the getColorRGB function to calculate a threshold
	or tolerance to better detect green using the color sensor.
	
	The height that the color sensor is off the table affects the measurements
	taken by that sensor. To ensure we are getting the most accurate readings
	we need to place it at the correct height which we can determine through 
	tests.
	
	

*/
