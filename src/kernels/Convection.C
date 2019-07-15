#include "Convection.h"

registerMooseObject("adeApp", Convection);

template <>
InputParameters
validParams<Convection>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredParam<RealVectorValue>("velocity", "Velocity Vector");
  return params;
}

Convection::Convection(const InputParameters & parameters)
  : // You must call the constructor of the base class first
    Kernel(parameters),
    _velocity(getParam<RealVectorValue>("velocity"))
{
}

Real
Convection::computeQpResidual()
{
  // velocity * _grad_u[_qp] is actually doing a dot product
  return _test[_i][_qp] * (_velocity * _grad_u[_qp]);
}

Real
Convection::computeQpJacobian()
{
  // the partial derivative of _grad_u is just _grad_phi[_j]
  return _test[_i][_qp] * (_velocity * _grad_phi[_j][_qp]);
}
