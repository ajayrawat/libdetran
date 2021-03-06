//----------------------------------*-C++-*----------------------------------//
/**
 *  @file   MatrixDense.hh
 *  @brief  MatrixDense
 *  @author Jeremy Roberts
 *  @date   Jan 7, 2013
 */
//---------------------------------------------------------------------------//

#ifndef callow_MATRIXDENSE_HH_
#define callow_MATRIXDENSE_HH_

#include "MatrixBase.hh"
#include <ostream>
#include <vector>
#include <string>

namespace callow
{


/**
 *  @class MatrixDense
 *  @brief Dense matrix
 *
 *  This is a simple matrix stored in row-major format.  It should
 *  be easy enough to use BLAS routines.
 *
 *  Note, PETSc is accessible, but note that PETSc uses a column-major
 *  order (like Fortran).  Hence, we switch the sizes and use transpose
 *  by default.
 */

class CALLOW_EXPORT MatrixDense: public MatrixBase
{

public:

  //---------------------------------------------------------------------------//
  // ENUMERATIONS
  //---------------------------------------------------------------------------//

  enum insert_type
  {
    INSERT, ADD, END_INSERT_TYPE
  };

  //---------------------------------------------------------------------------//
  // TYPEDEFS
  //---------------------------------------------------------------------------//

  typedef detran_utilities::SP<MatrixDense>  SP_matrix;

  //---------------------------------------------------------------------------//
  // CONSTRUCTOR & DESTRUCTOR
  //---------------------------------------------------------------------------//

  // construction with sizing but deferred allocation
  MatrixDense(const int m, const int n, const double v = 0.0);
  // copy constructor
  MatrixDense(const MatrixDense &A);
  // destructor
  virtual ~MatrixDense();
  // sp constructor
  static SP_matrix Create(const int m, const int n, const double v = 0.0);

  //---------------------------------------------------------------------------//
  // PUBLIC FUNCTIONS
  //---------------------------------------------------------------------------//

  /// add one value (return false if can't add)
  bool insert(int  i, int  j, double  v, const int type = INSERT);
  /// add a row  (return false if can't add)
  bool insert_row(int  i, double *v, const int type = INSERT);
  /// add a column  (return false if can't add)
  bool insert_col(int  j, double *v, const int type = INSERT);

  /// value at a cardinal index
  const double& operator[](const int p) const;
  double& operator[](const int p);

  /// value at ij and returns 0 if not present
  const double& operator()(const int i, const int j) const;
  double& operator()(const int i, const int j);

  // get underlying storage and indexing. careful!
  double* values() {return d_values;}

  /// print (i, j, v) to ascii file with 1-based indexing for matlab
  void print_matlab(std::string filename = "matrix.out") const;

  //---------------------------------------------------------------------------//
  // ABSTRACT INTERFACE -- ALL MATRICES MUST IMPLEMENT
  //---------------------------------------------------------------------------//

  // doesn't do anything for dense matrix
  void assemble(){ /* ... */ }
  // action y <-- A * x
  void multiply(const Vector &x,  Vector &y);
  // action y <-- A' * x
  void multiply_transpose(const Vector &x, Vector &y);
  // pretty print to screen
  void display() const;

protected:

  //---------------------------------------------------------------------------//
  // DATA
  //---------------------------------------------------------------------------//

  /// expose base members
  using MatrixBase::d_m;
  using MatrixBase::d_n;
  using MatrixBase::d_is_ready;

#ifdef CALLOW_ENABLE_PETSC
  using MatrixBase::d_petsc_matrix;
#endif

  /// matrix elements
  double* d_values;

};

CALLOW_TEMPLATE_EXPORT(detran_utilities::SP<MatrixDense>)

} // end namespace callow

// Inline members
#include "MatrixDense.i.hh"

#endif // callow_MATRIXDENSE_HH_

//---------------------------------------------------------------------------//
//              end of file MatrixDense.hh
//---------------------------------------------------------------------------//
