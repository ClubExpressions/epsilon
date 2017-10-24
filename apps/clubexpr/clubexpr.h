#ifndef CLUBEXPR_CLUBEXPR_H
#define CLUBEXPR_CLUBEXPR_H

#include <escher.h>
#include <poincare.h>

namespace ClubExpr {

class ClubExpr {
public:
  ClubExpr();
  ~ClubExpr(); // Delete expression and layout, if needed
  ClubExpr& operator=(const ClubExpr& other);
  ClubExpr(const ClubExpr& other) = delete;
  ClubExpr(ClubExpr&& other) = delete;
  ClubExpr& operator=(ClubExpr&& other) = delete;
  /* c.reset() is the equivalent of c = ClubExpr() without copy assingment. */
  void reset();
  const char * inputText();
  const char * outputText();
  Poincare::Expression * input();
  Poincare::ExpressionLayout * inputLayout();
  Poincare::Evaluation<double> * output(Poincare::Context * context);
  Poincare::ExpressionLayout * outputLayout(Poincare::Context * context);
  void setContent(const char * c, Poincare::Context * context);
  bool isEmpty();
  void tidy();
private:
  char m_inputText[::TextField::maxBufferSize()];
  char m_outputText[2*::TextField::maxBufferSize()];
  Poincare::Expression * m_input;
  Poincare::ExpressionLayout * m_inputLayout;
  Poincare::Evaluation<double> * m_output;
  Poincare::ExpressionLayout * m_outputLayout;
};

}

#endif
