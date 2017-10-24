#include "local_context.h"
#include <string.h>
using namespace Poincare;

namespace ClubExpr {

LocalContext::LocalContext(GlobalContext * parentContext, ClubExprStore * clubexprStore) :
  m_clubexprStore(clubexprStore),
  m_parentContext(parentContext)
{
}

Evaluation<double> * LocalContext::ansValue() {
  if (m_clubexprStore->numberOfClubExprs() == 0) {
    return m_parentContext->defaultExpression();
  }
  ClubExpr * lastClubExpr = m_clubexprStore->clubexprAtIndex(m_clubexprStore->numberOfClubExprs()-1);
  return lastClubExpr->output(m_parentContext);
}

void LocalContext::setExpressionForSymbolName(Expression * expression, const Symbol * symbol) {
  if (symbol->name() != Symbol::SpecialSymbols::Ans) {
    m_parentContext->setExpressionForSymbolName(expression, symbol);
  }
}

const Expression * LocalContext::expressionForSymbol(const Symbol * symbol) {
  if (symbol->name() == Symbol::SpecialSymbols::Ans) {
    return ansValue();
  } else {
    return m_parentContext->expressionForSymbol(symbol);
  }
}

}
