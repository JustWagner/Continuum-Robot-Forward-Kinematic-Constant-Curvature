# Continuum-Robot-Forward-Kinematic-Constant-Curvature
A forward kinematic for a continuum robot with a variable number of segments of any length. This model uses the constant curvature assumption meaning each segment bends in the shape of a circle segment. Curvature here is defined as one divided by the radius of such a circle.


# Input Format
after selecting the number of segments start with the base segment and end with the tip. Each segment requires 3 floats: angle compared to the previous segment / ground, curvature of the segment, and length of the segment.
