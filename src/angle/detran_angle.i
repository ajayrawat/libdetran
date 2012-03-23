//----------------------------------*-C++-*----------------------------------//
/*!
 * \file   detran_angle.i
 * \author Jeremy Roberts
 * \brief  Python interface for detran angular system.
 */
//---------------------------------------------------------------------------//

%module detran_angle
%{
#include "Definitions.hh"
#include "Constants.hh"
#include "Quadrature.hh"
#include "GaussLegendre.hh"  
%}

// Load the standard library interfaces.
%include std_vector.i
%include std_string.i

// Load the vector maps.  Note, I am a bit unhappy with
// how it's all used.  They work *if* I declare the class
// interface below.  Otherwise, just including e.g.
// Mesh2D doesn't allow the maps, since I'm using 
// typedefs on the input arguments.  There should be an
// easy way around this, but I'm not a SWIG pro.
%include std_vec_typemap.i

%include "Quadrature.hh"
%include "GaussLegendre.hh"

namespace std
{
  %template(vec_int) vector<int>;
  %template(vec_dbl) vector<double>;
}

namespace detran
{

} // end namespace detran_utils

//---------------------------------------------------------------------------//
//              end of detran_angle.i
//---------------------------------------------------------------------------//





