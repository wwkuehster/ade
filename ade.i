[Mesh]
  file = trialmesh.inp
[]

[Variables]
  [./convected]
    order = FIRST
    family = LAGRANGE
  [../]
  [./diffused]
    order = FIRST
    family = LAGRANGE
  [../]
[]

[Kernels]
  [./mat_diff]
    type= CoefDiffusion
    variable = convected
    coef = 0.1
    block = 'Surface1_TRI3'
  [../]
  [./vug_diff]
    type = CoefDiffusion
    variable = convected
    coef = 0.9
    block = 'Surface2_TRI3'
  [../]

  [./conv]
    type = Convection
    variable = convected
    velocity = '.1 0 0'
  [../]
  
  [./compare]
    type = Diffusion
    variable = diffused
  [../]

  [./euler_diff]
    type = TimeDerivative
    variable = diffused
    time_coefficient = 1.0
  [../]
  [./euler_ade]
    type = TimeDerivative
    variable = convected
    time_coefficient = 1.0
  [../]
[]

[BCs]
   [./compare_left]
    type = DirichletBC
    variable = diffused
    value = 0
    boundary = 'LeftSide'
  [../]

  [./compare_right]
    type = DirichletBC
    variable = diffused
    value = 1
    boundary = 'RightSide'
  [../]

   [./left_diffused]
    type = DirichletBC
    variable = convected
    boundary = 'RightSide'
    value = 1
  [../]

  [./right_diffused]
    type = DirichletBC
    variable = convected
    boundary = 'LeftSide'
    value = 0
  [../]

  [./left_convected]
    type = DirichletBC
    variable = convected
    boundary = 'LeftSide'
    value = 0
  [../]

  [./right_convected]
    type = DirichletBC
    variable = convected
    boundary = 'RightSide'
    value = 1
  [../]
[]

[Executioner]
  type = Transient
  solve_type = 'PJFNK'
  num_steps = 100
  dt = .01
[]

[Outputs]
  execute_on = 'timestep_end'
  exodus = true
  checkpoint = true
[]
