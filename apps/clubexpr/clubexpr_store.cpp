#include "clubexpr_store.h"
#include <assert.h>
using namespace Poincare;

namespace ClubExpr {

ClubExprStore::ClubExprStore() :
  m_startIndex(0)
{
}

ClubExpr * ClubExprStore::push(const char * text, Context * context) {
  ClubExpr * result = &m_clubexprs[m_startIndex];
  result->setContent(text, context);
  m_startIndex++;
  if (m_startIndex >= k_maxNumberOfClubExprs) {
    m_startIndex = 0;
  }
  return result;
}

ClubExpr * ClubExprStore::clubexprAtIndex(int i) {
  int j = 0;
  ClubExpr * currentCalc = &m_clubexprs[m_startIndex];
  ClubExpr * previousCalc = nullptr;
  while (j <= i) {
    if (!currentCalc++->isEmpty()) {
      previousCalc = currentCalc - 1;
      j++;
    }
    if (currentCalc >= m_clubexprs + k_maxNumberOfClubExprs) {
      currentCalc = m_clubexprs;
    }
  }
  return previousCalc;
}

int ClubExprStore::numberOfClubExprs() {
  ClubExpr * currentCalc= m_clubexprs;
  int numberOfClubExprs = 0;
  while (currentCalc < m_clubexprs + k_maxNumberOfClubExprs) {
    if (!currentCalc++->isEmpty()) {
      numberOfClubExprs++;
    }
  }
  return numberOfClubExprs;
}

void ClubExprStore::deleteClubExprAtIndex(int i) {
  int numberOfCalc = numberOfClubExprs();
  assert(i >= 0 && i < numberOfCalc);
  int indexFirstCalc = m_startIndex;
  while (m_clubexprs[indexFirstCalc].isEmpty()) {
    indexFirstCalc++;
    if (indexFirstCalc == k_maxNumberOfClubExprs) {
      indexFirstCalc = 0;
    }
    assert(indexFirstCalc != m_startIndex);
  }
  int absoluteIndexClubExprI = indexFirstCalc+i;
  absoluteIndexClubExprI = absoluteIndexClubExprI >= k_maxNumberOfClubExprs ? absoluteIndexClubExprI - k_maxNumberOfClubExprs : absoluteIndexClubExprI;

  int index = absoluteIndexClubExprI;
  for (int k = i; k < numberOfCalc-1; k++) {
    int nextIndex = index+1 >= k_maxNumberOfClubExprs ? 0 : index+1;
    m_clubexprs[index] = m_clubexprs[nextIndex];
    index++;
    if (index == k_maxNumberOfClubExprs) {
      index = 0;
    }
  }
  m_clubexprs[index].reset();
  m_startIndex--;
  if (m_startIndex == -1) {
    m_startIndex = k_maxNumberOfClubExprs-1;
  }
}

void ClubExprStore::deleteAll() {
  m_startIndex = 0;
  for (int i = 0; i < k_maxNumberOfClubExprs; i++) {
    m_clubexprs[i].reset();
  }
}

void ClubExprStore::tidy() {
  for (int i = 0; i < k_maxNumberOfClubExprs; i++) {
    m_clubexprs[i].tidy();
  }
}

}
