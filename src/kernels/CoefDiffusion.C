//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "CoefDiffusion.h"

registerMooseObject("adeApp", CoefDiffusion);

template <>
InputParameters
validParams<CoefDiffusion>()
{
  InputParameters params = validParams<Kernel>();
  params.set<Real>("coef") = 0.0;
  return params;
}

CoefDiffusion::CoefDiffusion(const InputParameters & parameters)
  : Kernel(parameters), _coef(getParam<Real>("coef"))
{
}

Real
CoefDiffusion::computeQpResidual()
{
  return _coef * _grad_test[_i][_qp] * _grad_u[_qp];
}

Real
CoefDiffusion::computeQpJacobian()
{
  return _coef * _grad_test[_i][_qp] * _grad_phi[_j][_qp];
}
