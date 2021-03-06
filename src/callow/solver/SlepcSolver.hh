//----------------------------------*-C++-*----------------------------------//
/**
 *  @file   SlepcSolver.hh
 *  @author robertsj
 *  @date   Sep 25, 2012
 *  @brief  SlepcSolver class definition.
 */
//---------------------------------------------------------------------------//

#ifndef callow_SLEPCSOLVER_HH_
#define callow_SLEPCSOLVER_HH_

#include "EigenSolver.hh"

#ifdef CALLOW_ENABLE_SLEPC

namespace callow
{

/**
 *  @class SlepcSolver
 *  @brief Solve the eigenvalue problem with SLEPc
 */
class SlepcSolver: public EigenSolver
{

public:

  //-------------------------------------------------------------------------//
  // TYPEDEFS
  //-------------------------------------------------------------------------//

  typedef EigenSolver               Base;
  typedef Base::SP_matrix           SP_matrix;
  typedef Base::SP_solver           SP_solver;
  typedef Base::SP_vector           SP_vector;

  //-------------------------------------------------------------------------//
  // CONSTRUCTOR & DESTRUCTOR
  //-------------------------------------------------------------------------//

  SlepcSolver(const double tol,
              const int    maxit);

  virtual ~SlepcSolver();

  //-------------------------------------------------------------------------//
  // PUBLIC FUNCTIONS
  //-------------------------------------------------------------------------//

  /**
   *  @brief Sets the operators for the problem.
   *
   *  This allows for the system
   *  @param A      left side operator
   *  @param B      optional right side operator (to be inverted)
   *  @param db     optional database for solver and preconditioner options
   */
  virtual void set_operators(SP_matrix A,
                             SP_matrix B = SP_matrix(0),
                             SP_db db = SP_db(0));


private:

  //-------------------------------------------------------------------------//
  // DATA
  //-------------------------------------------------------------------------//

  // expose base members
  using Base::d_tolerance;
  using Base::d_maximum_iterations;
  using Base::d_name;
  using Base::d_residual_norm;
  using Base::d_number_iterations;
  using Base::d_A;
  using Base::d_B;
  using Base::d_solver;
  using Base::d_monitor_level;
  using Base::d_lambda;

  /// SLEPc solver object
  EPS d_slepc_solver;

  //-------------------------------------------------------------------------//
  // ABSTRACT INTERFACE -- ALL EIGENSOLVERS MUST IMPLEMENT THIS
  //-------------------------------------------------------------------------//

  virtual void solve_impl(Vector &x, Vector &x0);


};

} // end namespace callow

#include "SlepcSolver.i.hh"

#endif // CALLOW_ENABLE_SLEPC

#endif /* callow_SLEPCSOLVER_HH_ */
