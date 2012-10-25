//----------------------------------*-C++-*----------------------------------//
/**
 *  @file   EigenPI.cc
 *  @author robertsj
 *  @date   Apr 10, 2012
 *  @brief  EigenPI class definition.
 */
//---------------------------------------------------------------------------//

#include "EigenPI.hh"
#include <iostream>

namespace detran
{

//---------------------------------------------------------------------------//
template <class D>
EigenPI<D>::EigenPI(SP_mg_solver mg_solver)
  : Base(mg_solver)
  , d_aitken(false)
{

  if (d_input->check("eigen_aitken"))
    d_aitken = d_input->template get<int>("eigen_aitken");

}
//---------------------------------------------------------------------------//
// EXPLICIT INSTANTIATIONS
template class EigenPI<_1D>;
template class EigenPI<_2D>;
template class EigenPI<_3D>;

} // end namespace detran

//---------------------------------------------------------------------------//
//              end of EigenPI.cc
//---------------------------------------------------------------------------//



