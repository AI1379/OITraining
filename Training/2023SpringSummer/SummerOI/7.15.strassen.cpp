#include <bits/stdc++.h>
using namespace std;
template <typename T> class Matrix {
private:
  typedef T Type;
  Type **_head = nullptr;
  size_t _row = -1, _column = -1;

  void alloc(size_t r, size_t c) {
    // Allocate
    _head = (Type **)malloc(r * (sizeof(Type *)));
    for (size_t i = 0; i < r; i++) {
      _head[i] = (Type *)malloc(c * (sizeof(Type)));
    }
  }
  void fill(size_t lr, size_t lc, size_t rr, size_t rc, Type val) {
    // Fill
    lr--;
    lc--;
    rr--;
    rc--;
    for (size_t i = lr; i <= rr; i++) {
      for (size_t j = lc; j <= rc; j++) {
        _head[i][j] = val;
      }
    }
  }
  void copy(const Matrix<Type> &M) {
    _row = M.row();
    _column = M.column();
    alloc(M.row(), M.column());
    for (size_t i = 0; i < _row; i++) {
      for (size_t j = 0; j < _column; j++) {
        _head[i][j] = M._head[i][j];
      }
    }
  }

public:
  static Matrix<Type> StrassenMultiply(const Matrix<Type> &A,
                                       const Matrix<Type> &B) {
    if (A.size() == B.size() && A.size() == 1) {
      return Matrix<Type>({{A.at(1, 1) * B.at(1, 1)}});
    } else {
      auto A11 = A.part(1, 1, A.row() / 2, A.column() / 2);
      auto A12 = A.part(1, A.column() / 2 + 1, A.row() / 2, A.column());
      auto A21 = A.part(A.row() / 2 + 1, 1, A.row(), A.column() / 2);
      auto A22 =
          A.part(A.row() / 2 + 1, A.column() / 2 + 1, A.row(), A.column());
      auto B11 = B.part(1, 1, B.row() / 2, B.column() / 2);
      auto B12 = B.part(1, B.column() / 2 + 1, B.row() / 2, B.column());
      auto B21 = B.part(B.row() / 2 + 1, 1, B.row(), B.column() / 2);
      auto B22 =
          B.part(B.row() / 2 + 1, B.column() / 2 + 1, B.row(), B.column());
      auto P1 = StrassenMultiply(A11, B12 - B22);
      auto P2 = StrassenMultiply(A11 + A12, B22);
      auto P3 = StrassenMultiply(A21 + A22, B11);
      auto P4 = StrassenMultiply(A22, B21 - B11);
      auto P5 = StrassenMultiply(A11 + A22, B11 + B22);
      auto P6 = StrassenMultiply(A12 - A22, B21 + B22);
      auto P7 = StrassenMultiply(A11 - A21, B11 + B12);
      auto C11 = P5 + P4 - P2 + P6;
      auto C12 = P1 + P2;
      auto C21 = P3 + P4;
      auto C22 = P5 + P1 - P3 - P7;
      Matrix<Type> ans(A.row(), A.column());
      for (size_t i = 1; i <= A.row() / 2; i++) {
        for (size_t j = 1; j <= A.column() / 2; j++) {
          ans.modify(i, j, C11.at(i, j));
        }
        for (size_t j = A.column() / 2 + 1; j <= A.column(); j++) {
          ans.modify(i, j, C12.at(i, j - A.column() / 2));
        }
      }
      for (size_t i = A.row() / 2 + 1; i <= A.row(); i++) {
        for (size_t j = 1; j <= A.column() / 2; j++) {
          ans.modify(i, j, C21.at(i - A.row() / 2, j));
        }
        for (size_t j = A.column() / 2 + 1; j <= A.column(); j++) {
          ans.modify(i, j, C22.at(i - A.row() / 2, j - A.column() / 2));
        }
      }
      return ans;
    }
  }

  static Matrix<Type> NaiveMultiply(const Matrix<Type> &A,
                                    const Matrix<Type> &B) {
    Matrix<Type> ans(A.row(), B.column());
    for (size_t i = 1; i <= A.row(); i++) {
      for (size_t j = 1; j <= B.column(); j++) {
        for (size_t k = 1; k <= A.column(); k++) {
          ans.modify(i, j, ans.at(i, j) + (A.at(i, k) * B.at(k, j)));
        }
      }
    }
    return ans;
  }

public:
  // Construction Functions
  Matrix() = default;
  Matrix(size_t r, size_t c) {
    _row = r;
    _column = c;
    alloc(r, c);
    fill(1, 1, _row, _column, 0);
  }
  Matrix(Matrix<Type> const &M) { copy(M); }
  Matrix<Type> &operator=(const Matrix &M) {
    copy(M);
    return *this;
  }
  Matrix(std::initializer_list<std::initializer_list<Type>> const &IM) {
    int r = IM.size(), c = 0;
    std::vector<std::vector<Type>> M;
    for (auto il : IM) {
      std::vector<Type> tmp(il);
      c = std::max(static_cast<typename std::vector<Type>::size_type>(c),
                   tmp.size());
      M.push_back(tmp);
    }
    alloc(r, c);
    fill(1, 1, r, c, 0);
    _row = r;
    _column = c;
    for (size_t i = 0; i < M.size(); i++) {
      for (size_t j = 0; j < M[i].size(); j++) {
        _head[i][j] = M[i][j];
      }
    }
  }

  // Destruction Function
  virtual ~Matrix() {
    for (size_t i = 0; i < _row; i++) {
      free(_head[i]);
    }
    free(_head);
  }

  // IO Functions
  inline Type at(size_t r, size_t c) const {
    if (r > _row || c > _column) {
      return -1;
    }
    return _head[r - 1][c - 1];
  }
  inline void modify(size_t r, size_t c, Type val) {
    if (r > _row || c > _column) {
      return;
    }
    _head[r - 1][c - 1] = val;
  }
  void show() {
    for (size_t i = 0; i < _row; i++) {
      for (size_t j = 0; j < _column; j++) {
        std::cout << _head[i][j] << ' ';
      }
      std::cout << std::endl;
    }
  }

  // Argument Functions
  inline size_t row() const { return _row; }
  inline size_t column() const { return _column; }
  inline size_t size() const { return _row * _column; }
  Matrix<Type> part(size_t lr, size_t lc, size_t rr, size_t rc) const {
    lr--;
    lc--;
    rr--;
    rc--;
    Matrix<Type> M(rr - lr + 1, rc - lc + 1);
    for (size_t i = lr; i <= rr; i++) {
      for (size_t j = lc; j <= rc; j++) {
        M.modify(i - lr + 1, j - lc + 1, _head[i][j]);
      }
    }
    return M;
  }

  // Arithmetic Functions
  inline Matrix<Type> operator+(const Matrix<Type> &rhs) const {
    if (this->_row == rhs._row && this->_column == rhs._column) {
      Matrix<Type> ans(_row, _column);
      for (size_t i = 1; i <= _row; i++) {
        for (size_t j = 1; j <= _column; j++) {
          ans.modify(i, j, at(i, j) + rhs.at(i, j));
        }
      }
      return ans;
    } else {
      return *this;
    }
  }
  inline Matrix<Type> operator-(const Matrix<Type> &rhs) const {
    if (this->_row == rhs._row && this->_column == rhs._column) {
      Matrix<Type> ans(_row, _column);
      for (size_t i = 1; i <= _row; i++) {
        for (size_t j = 1; j <= _column; j++) {
          ans.modify(i, j, at(i, j) - rhs.at(i, j));
        }
      }
      return ans;
    } else {
      return *this;
    }
  }
  inline Matrix<Type> operator*(const Matrix<Type> &rhs) const {
    if (this->_column != rhs.row()) {
      return *this;
    } else {
      // Judge with algorithm will be used
      int align = std::ceil(std::log2(
          std::max({this->row(), this->column(), rhs.row(), rhs.column()})));
      if (std::pow(align, 2.73) * 3 >=
          this->row() * this->column() * rhs.column()) {
        // std::cerr << "Use Naive Multiply Method" << std::endl;
        return NaiveMultiply(*this, rhs);
      } else {
        // std::cerr << "Use Strassen Multiply Method" << std::endl;
        Matrix<Type> alignA(1 << align, 1 << align);
        Matrix<Type> alignB(1 << align, 1 << align);
        for (size_t i = 1; i <= this->row(); i++) {
          for (size_t j = 1; j <= this->column(); j++) {
            alignA.modify(i, j, this->at(i, j));
          }
        }
        for (size_t i = 1; i <= rhs.row(); i++) {
          for (size_t j = 1; j <= rhs.column(); j++) {
            alignB.modify(i, j, rhs.at(i, j));
          }
        }
        return StrassenMultiply(alignA, alignB)
            .part(1, 1, this->row(), rhs.column());
      }
    }
  }
  inline void quickPow(Matrix<Type> &Res, size_t x) const {
    if (x > 0) {
      auto a(*this);
      while (x) {
        if (x & 1)
          Res = Res * a;
        a = a * a;
        x >>= 1;
      }
    } else {
      return;
    }
  }
};
#define ll long long
ll n, m, s, q;
int main() {
  ll u, v, w;
  cin >> n >> m >> s >> q;
  Matrix<ll> mat(n, n);
  Matrix<ll> ans(n, n);
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v >> w;
    mat.modify(u, v, w);
    ans.modify(i, i, 1ll);
  }
  mat.quickPow(ans, s);
  while (q--) {
    cin >> u >> v;
    cout << ans.at(u, v) << endl;
  }
  return 0;
}