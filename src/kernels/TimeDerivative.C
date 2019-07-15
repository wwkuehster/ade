#include "TimeDerivative.h"

#include "Material.h"

registerMooseObject("adeApp", TimeDerivative);

template <>
InputParameters
validParams<TimeDerivative>()
{
  InputParameters params = validParams<TimeDerivative>();
  params.addParam<Real>("time_coefficient", 1.0, "Time Coefficient");
  return params;
}

ExampleTimeDerivative::ExampleTimeDerivative(const InputParameters & parameters)
  : TimeDerivative(parameters),
    _time_coefficient(getParam<Real>("time_coefficient"))
{
}

Real
ExampleTimeDerivative::computeQpResidual()
{
  return _time_coefficient * TimeDerivative::computeQpResidual();
}

Real
ExampleTimeDerivative::computeQpJacobian()
{
  return _time_coefficient * TimeDerivative::computeQpJacobian();
}
