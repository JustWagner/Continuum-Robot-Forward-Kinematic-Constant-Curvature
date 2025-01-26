# Continuum-Robot-Forward-Kinematic-Constant-Curvature
A forward kinematic for a continuum robot with a variable number of segments of any length. This model uses the constant curvature assumption meaning each segment bends in the shape of a circle segment. 
All the theory can be found [here](https://www.frontiersin.org/journals/robotics-and-ai/articles/10.3389/frobt.2020.630245/full).


## Input Format
Start by selecting the number of segments, start with the base segment and end with the tip. Each segment requires 3 floats: angle compared to the previous segment or ground for the base segment, curvature of the segment, and length of the segment. The variables are stored in three vectors. One for angles, one for curvature and one for length of segment.

An angle of **0** means that the segment has the same curvature orientation as the previous segment. For the first segment **0** means that the segment is directly alligned with the X-axis and bends in the positive direction. A value of  **π{\displaystyle \pi }/2** would mean that the ground segment is bending in the positive Y-axis direction for the first segment, or has a **90 degrees** offset for all future segments 

Curvature here is defined as one divided by the radius of such a circle. This means that for example if a segment has the length of **5** a curvature of **π{\displaystyle \pi }/10** would equal to a 90 degree bend. 
So if we want to calculate the curvature for a 90 degree bend with lenght **5**, we can calculate the radius for a circle with circumference of **20**. The circumference of a circle is **r2π{\displaystyle \pi }** with r being the radius. In this example **r** is equal to **20/2π{\displaystyle \pi }**, which means that **1/r** can be written as **π{\displaystyle \pi }/10**.

## Constant Curv Forward function and output
This function calculates the forward kinematic. It takes 3 vectors storing the segment angles, curvs and lenghts. The output is in form of a float pointer storing x, y and z coordinates, where 0/0/0 is the center of the base of the robot.
