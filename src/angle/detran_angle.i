//----------------------------------*-C++-*----------------------------------//
/**
 *  @file   detran_angle.i
 *  @author Jeremy Roberts
 *  @brief  Python interface for detran angular system.
 */
//---------------------------------------------------------------------------//

%include "utilities/detran_utilities.i"

// Base angle classes and utilities
%include "Quadrature.hh"
%include "ProductQuadrature.hh"
%include "QuadratureMOC.hh"
%include "MomentToDiscrete.hh"
%include "QuadratureFactory.hh"

%template(QuadratureSP)         detran_utilities::SP<detran_angle::Quadrature>;
%template(ProductQuadratureSP)  detran_utilities::SP<detran_angle::ProductQuadrature>;
%template(QuadratureMOCSP)      detran_utilities::SP<detran_angle::QuadratureMOC>;
%template(MomentToDiscreteSP)   detran_utilities::SP<detran_angle::MomentToDiscrete>;

%inline
{

// Cast from base quadrature to product quadrature
detran_utilities::SP<detran_angle::ProductQuadrature> 
cast_base_to_product(detran_utilities::SP<detran_angle::Quadrature>* q)
{
  return detran_utilities::SP<detran_angle::ProductQuadrature>(*q);
} 

// Cast from base quadrature to moc quadrature
detran_utilities::SP<detran_angle::QuadratureMOC> 
cast_base_to_moc(detran_utilities::SP<detran_angle::Quadrature>* q)
{
  return detran_utilities::SP<detran_angle::QuadratureMOC>(*q);
} 

}

//---------------------------------------------------------------------------//
//              end of detran_angle.i
//---------------------------------------------------------------------------//
