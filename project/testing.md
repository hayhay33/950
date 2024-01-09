
## Go / No-Go Testing

Test all aspects of the system (rocket and sensor board), showing that both operate as expected.  Specifically, tests include:

1. Bench test - validate that the system works while sitting on the workbench and that all sensors are calibrated.  Data plots must indicate passing of this test.  Video should show the LEDs indicating when the sensor package is waiting for the time delay and when it is taking data.

2. Pendulum test - attach the sensor board (with battery) to different lengths of strings.  Take data while the sensor board swings back and forth.  Show that the measured 3D acceleration can be used in a way to provide the angle and velocity of the sensor board as it swings.  Show that the period of the pendulum is as expected from an analytic solution.  If your team is focusing on simulations, you should have a simulation of the pendulum that shows that you are getting consistent results between the measurements and the simulations.

3. Parachute test - While the sensor board is running and installed into your rocket, open the rocket and remove the parachute, but do not unfold it.  Drop it from a 4th floor (EECS or Robotics) so that the parachute has time to open and fully deploy.  You may want to practice this on something besides your rocket, so that you know that it will work (i.e., attatch your parachute to a mass that is comparable to your rocket and practice folding and dropping the system). You also may want to do a couple of tests with no sensor board on your rocket, so that the system has less weight and the terminal velocity is lower, so if there is terminal failure your rocket won't be destroyed. You have to show video of the final complete drop and the acceleration results during the test.

4. Drop test - This will be the scariest test.  Drop your fully assembled rocket with sensor package installed and running from 2 meters height, with the nose cone pointed towards the ground.  Do this over a grassy area, so that the rocket does not impact a super hard surface.  You have to show video of this being done and the acceleration results during the test.

5. Elevator test - You must find a building that is at least 10 stories and ride an elevator from the bottom floor to at least the 10th floor. The sensor package must be taking data during the elevator ride and should be placed on the floor so that it is measuring the acceleration of the elevator.  There should be at least two stops on the way to the 10th floor, so the stopping and starting can be noted and correlated with the pressure data.  The pressure must be converted to altitude.  The acceleration should be integrated to be converted into velocity and altitude.  The pressure / altitude must be differentiated to convert it to velocity and acceleration.  Plots need to show the results of this test.

6. Simulation test - Show that your rocket with the sensor board incorporated will reach at least 500 ft and will not exceed 1200 ft with one of the recommended motors.  The exact motor that your group would like will be specified with this test.  Plots will prove that this test passed.

All tests need to be presented at the Go/No-Go meeting.  Each team must pass all tests before being OKed for launch.

