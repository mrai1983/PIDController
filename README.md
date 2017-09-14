# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program
---
##Description
Separate PID controllers are used for controlling steering wheel values and throttle values. All the values are tuned manually.

###Steering Wheel Angle
Kp, Kd and Ki values are initially assigned to zero. First Kp is incremented manually till car is able to complete track with oscillations. Car was able to complete track with oscillations with Kp = 0.5. Then Kd was incremented to reduce oscillations. The oscillations reduces at Kd = 10. Ki was selected to be .009.

###Throttle Control
Kp, Kd and Ki values for throttle controller are initially assigned to zero. The basic idea behind controlling throttle is that the throttle value increases when cross track error reduces and throttle value reduces if cross track error is more. To introduce this behavior I have used (fabs(cte) - 1) as input to Update error. If cte value is closer to zero this results in increase in throttle. As cte increases this reduces throttle. If fabs(cte) is greater than one car applies breaks and slows. 

I have tested the code for multiple runs and car runs within track.




