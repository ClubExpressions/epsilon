#ifndef CLUBEXPR_CLUBEXPR_STORE_H
#define CLUBEXPR_CLUBEXPR_STORE_H

#include "clubexpr.h"

namespace ClubExpr {

class ClubExprStore {
public:
  ClubExprStore();
  ClubExpr * clubexprAtIndex(int i);
  ClubExpr * push(const char * text, Poincare::Context * context);
  void deleteClubExprAtIndex(int i);
  void deleteAll();
  int numberOfClubExprs();
  void tidy();
  static constexpr int k_maxNumberOfClubExprs = 10;
private:
  int m_startIndex;
  ClubExpr m_clubexprs[k_maxNumberOfClubExprs];
};

}

#endif
