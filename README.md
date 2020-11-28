# Extended Kalman Filter

## Description
#### (Part of Self Driving Car Engineer program by Udacity)
Extended Kalman Filter implements a Kalman filter to track a bicycle's position and velocity in 2D using the simulated lidar and radar measurements provided by Udacity. 

## Documentation
### Project Directory
**src:** The main source code directory. <br/>
**data:** Contains the simulated data provided by Udacity for the course. <br/>

## Requirements
The project depends on [Term 2 Simulator](https://github.com/udacity/self-driving-car-sim/releases), [uWebSocketIO](https://github.com/uNetworking/uWebSockets) and [Eigen](https://gitlab.com/libeigen/eigen). 

## Usage
1. Clone the repository.
2. Create a directory named `external` 
3. Place Eigen, uWebSocketIO libraries in `external` and proceed to create `build` at the root of this project. You may have to build the libraries based on your OS, platform and other variables. 
4. `cd build`
5. `cmake ..`
6. `make`
7. You can run the project with the command `./ExtendedKF`
8. The above command essentially opens a socket listening to data from [Term 2 Simulator](https://github.com/udacity/self-driving-car-sim/releases). 
9. Proceed to open Term 2 Simulator and select the "EKF and UKF" option
10. You can observe the output in your console!

## License
Licensed under the [MIT License](https://www.github.com/KushalBKusram/ExtendedKalmanFilter/main/LICENSE).
