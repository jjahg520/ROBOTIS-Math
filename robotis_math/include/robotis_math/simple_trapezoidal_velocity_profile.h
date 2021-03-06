/*******************************************************************************
 * Copyright (c) 2016, ROBOTIS CO., LTD.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of ROBOTIS nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************/

/*
 * simple_trapezoidal_velocity_profile.h
 *
 *  Created on: 2016. 8. 24.
 *      Author: Jay Song
 */

#ifndef ROBOTIS_MATH_TRAPEZOIDAL_VELOCITY_PROFILE_H_
#define ROBOTIS_MATH_TRAPEZOIDAL_VELOCITY_PROFILE_H_

#define EIGEN_NO_DEBUG
#define EIGEN_NO_STATIC_ASSERT

#include "robotis_linear_algebra.h"
#include "robotis_math_base.h"

namespace robotis_framework
{
class SimpleTrapezoidalVelocityProfile
{
public:
  SimpleTrapezoidalVelocityProfile();
  ~SimpleTrapezoidalVelocityProfile();

  void setVelocityBaseTrajectory(double init_pos, double final_pos, double acceleration, double max_velocity);
  void setVelocityBaseTrajectory(double init_pos, double final_pos, double acceleration, double deceleration, double max_velocity);
  void setTimeBaseTrajectory(double init_pos, double final_pos, double accel_time, double total_time);
  void setTimeBaseTrajectory(double init_pos, double final_pos, double accel_time, double decel_time, double total_time);

  double getPosition(double time);
  double getVelocity(double time);
  double getAcceleration(double time);

  void setTime(double time);
  double getPosition();
  double getVelocity();
  double getAcceleration();

  double getTotalTime();
  double getConstantVelocitySectionStartTime();
  double getDecelerationSectionStartTime();

private:
  Eigen::MatrixXd pos_coeff_accel_section_;
  Eigen::MatrixXd vel_coeff_accel_section_;

  Eigen::MatrixXd pos_coeff_const_section_;
  Eigen::MatrixXd vel_coeff_const_section_;

  Eigen::MatrixXd pos_coeff_decel_section_;
  Eigen::MatrixXd vel_coeff_decel_section_;

  Eigen::MatrixXd time_variables_;

  double acceleration_;
  double deceleration_;
  double max_velocity_;

  double initial_pos_;

  double current_time_;
  double current_pos_;
  double current_vel_;
  double current_acc_;

  double final_pos_;

  double accel_time_;
  double const_time_;
  double decel_time_;

  double const_start_time_;
  double decel_start_time_;
  double total_time_;
};

}

#endif /* ROBOTIS_MATH_TRAPEZOIDAL_VELOCITY_PROFILE_H_ */
