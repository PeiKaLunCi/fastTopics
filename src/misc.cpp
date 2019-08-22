#include "misc.h"

using namespace arma;

// FUNCTION DEFINITIONS
// --------------------
// Return a or b, which ever is smaller.
double min (double a, double b) {
  double y;
  if (a < b)
    y = a;
  else
    y = b;
  return y;
}

// Get the indices of the nonzeros in the jth column of sparse matrix A.
//
//   i = find(A.col(j));
//
void getnonzeroindicesincol (const sp_mat& A, uvec& i, uint j) {
  sp_mat::const_col_iterator ai = A.begin_col(j);
  sp_mat::const_col_iterator an = A.end_col(j);
  for (uint t = 0; ai != an; ++ai, ++t)
    i(t) = ai.row();
}

// Add b[i] to each row A[i,].
void addtorows (mat& A, const vec& b) {
  uint n = A.n_rows;
  for (uint i = 0; i < n; i++)
    A.row(i) += b(i);
}

// Scale each column A[,i] by b[i].
void scalecols (mat& A, const vec& b) {
  uint n = A.n_cols;
  for (uint i = 0; i < n; i++)
    A.col(i) *= b(i);
}

// Normalize each row of A so that the entries in each row sum to 1.
void normalizerows (mat& A) {
  uint n = A.n_rows;
  vec  b = sum(A,1);
  for (uint i = 0; i < n; i++) 
    A.row(i) /= b(i);
}
