#pragma once

#include "TimeDerivative.h"

class TimeDerivative;

template <>
InputParameters validParams<TimeDerivative>();

class TimeDerivative : public TimeDerivative
{
public:
  TimeDerivative(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

  Real _time_coefficient;
};
