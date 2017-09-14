# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program
---
# Description
Separate PID controllers are used for controlling steering wheel values and throttle values. All the values are tuned manually. Please click on the image below to watch video.

[![Project Video](http://img.youtube.com/vi/UWhDe0RZqkg/0.jpg)](https://youtu.be/UWhDe0RZqkg)

## PID Description

### P Component
P component is proportionate to input error. The P component is calculated using (-Kp * error). As error increases P component increases in opposite direction minimizing the error. However P Component does not converge error to zero but has got oscillation effect on the error. Below graph shows steering wheel angle if only Kp is set to 0.5 and Kd and Ki are set to zero.

![alt P-Controller](https://raw.githubusercontent.com/mrai1983/PIDController/master/P-Controller.png)

### D Component
D component monitors rate of change of error. As rate of change error reduces subtraction of D Component inhibits rapid change in error due to P Component. Below graph shows steering wheel values with Kd= 10 and Kp = 0.5.

![PD-Component](https://raw.githubusercontent.com/mrai1983/PIDController/master/PD-Controller.png)

### I Component
I Component is integral of all the previous error. Subtracting I Component from PD Error component results in removal of any offset. As our PD error graph is close to offset zero this component might not have any major impact. Below figure shows a plot of steering wheel values with Kp = 0.5, Kd = 10, Ki = 0.000001.

![PID Controller](https://raw.githubusercontent.com/mrai1983/PIDController/master/PID.png)

### Steering Wheel Angle
Kp, Kd and Ki values are initially assigned to zero. First Kp is incremented manually till car is able to complete track with oscillations. Car was able to complete track with oscillations with Kp = 0.5. Then Kd was incremented to reduce oscillations. The oscillations reduces at Kd = 10. Ki was selected to be 0.000001.

### Throttle Control
Kp, Kd and Ki values for throttle controller are initially assigned to zero. The basic idea behind controlling throttle is that the throttle value increases when cross track error reduces and throttle value reduces if cross track error is more. To introduce this behavior I have used (fabs(cte) - 1) as input to Update error. If cte value is closer to zero this results in increase in throttle. As cte increases this reduces throttle. If fabs(cte) is greater than one car applies breaks and slows. 

I have tested the code for multiple runs and car runs within track.




