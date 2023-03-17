# Coding-Two_Final-Project

# Particle Lines 3D

### Video Link: https://youtu.be/kHwjgu0urqM

This program uses the openFrameworks library to create an animation of particles moving in 3D space. The particles are represented by spheres and are connected by lines as they move around the space. The spheres change color as they move, creating a dynamic and colorful visual effect.

### Setup
In the setup() function, we set the frame rate to 60 frames per second and set the window title to "openFrameworks". We also set the background color to a gray shade and enable depth testing for 3D drawing. Finally, we set the primitive mode for the mesh to lines.

### Update
In the update() function, we add new particles to the location and direction lists, with each particle moving in a random direction. We then update the location of each particle by adding its direction vector. If a particle has moved too far away from the origin, we remove it from the location and direction lists. We then add the location of each particle as a vertex to the mesh and set its color based on its distance from the origin.
Finally, we create connections between nearby particles by adding indices to the mesh.

### Draw
In the draw() function, we begin the camera and rotate it around the X and Y axes. We then draw the mesh vertices as points and add a sphere to each vertex with a random warm hue. We end the camera to finish the drawing.

Overall, this program creates a visually pleasing 3D animation of moving particles that is both dynamic and colorful.
