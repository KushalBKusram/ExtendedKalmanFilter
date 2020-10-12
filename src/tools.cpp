#include "tools.h"
#include <iostream>

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;
using std::cout;
using std::endl;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
   * TODO: Calculate the RMSE here.
   */
  VectorXd rmse(4);
  rmse << 0,0,0,0;

  // check the validity of the following inputs:
  //  * the estimation vector size should not be zero
  //  * the estimation vector size should equal ground truth vector size
    if(estimations.size() != ground_truth.size() || estimations.size() < 1){
        cout << "ERROR!" << endl;
        return rmse;
    }
  // TODO: accumulate squared residuals
  for (size_t i=0; i < estimations.size(); ++i) {
    // ... your code here
    VectorXd residual = estimations[i] - ground_truth[i];
    residual = residual.array()*residual.array();
    rmse += residual;
  }

  // TODO: calculate the mean
    rmse = rmse/estimations.size();
  // TODO: calculate the squared root
    rmse = rmse.array().sqrt();
  // return the result
  return rmse;
}

MatrixXd Tools::CalculateJacobian(const VectorXd& x_state) {
  /**
   * TODO:
   * Calculate a Jacobian here.
   */
  MatrixXd Hj(3,4);
  // recover state parameters
  float px = x_state(0);
  float py = x_state(1);
  float vx = x_state(2);
  float vy = x_state(3);


  float c1 = px * px + py * py;
  float c2 = sqrt(c1);
  float c3 = c1 * c2;

   // Sanity check to avoid division by zero
	if (std::abs(c1) < 0.0001) {
		std::cout << "Error in CalculateJacobian. Division by zero." << std::endl;
		return Hj;
	}

	// Actually compute Jacobian matrix
	Hj << (px / c2), (py / c2), 0, 0,
		-(py / c1), (px / c1), 0, 0,
		py * (vx*py - vy*px) / c3, px * (vy*px - vx*py) / c3, px / c2, py / c2;

	return Hj;
}
