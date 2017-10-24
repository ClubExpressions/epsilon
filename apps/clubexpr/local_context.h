#ifndef CLUBEXPR_LOCAL_CONTEXT_H
#define CLUBEXPR_LOCAL_CONTEXT_H

#include <poincare.h>
#include "clubexpr_store.h"

namespace ClubExpr {

class LocalContext : public Poincare::Context {
public:
  LocalContext(Poincare::GlobalContext * parentContext, ClubExprStore * clubexprStore);
  void setExpressionForSymbolName(Poincare::Expression * expression, const Poincare::Symbol * symbol) override;
  const Poincare::Expression * expressionForSymbol(const Poincare::Symbol * symbol) override;
private:
  Poincare::Evaluation<double> * ansValue();
  ClubExprStore * m_clubexprStore;
  Poincare::GlobalContext * m_parentContext;
};

}

#endif
