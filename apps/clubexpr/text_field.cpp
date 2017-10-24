#include "text_field.h"

namespace ClubExpr {

TextField::TextField(Responder * parentResponder, char * textBuffer, size_t textBufferSize, TextFieldDelegate * delegate) :
  ::TextField(parentResponder, textBuffer, textBuffer, textBufferSize, delegate, false)
{
  setEditing(true);
}

bool TextField::handleEvent(Ion::Events::Event event) {
  // TODO: internationalisation and accents on Carré and Opposé
  if (event == Ion::Events::Back) {
    return false;
  }
  if (event == Ion::Events::Backspace) {
    deleteCharPrecedingCursor();
    while ((cursorLocation() > 0) &&
           (text()[cursorLocation()-1] != '(') &&
           (text()[cursorLocation()-1] != ')') &&
           (text()[cursorLocation()-1] != ' ')) {
      deleteCharPrecedingCursor();
    }
    return true;
  }
  // pciap means "previous char is a parens"
  bool pciap = (cursorLocation() > 0) && (text()[cursorLocation()-1] == '(');
  // elosb means "at beginning or space or parens before"
  bool abosopb = (cursorLocation() == 0) || (text()[cursorLocation()-1] == ' ');
  if (event == Ion::Events::Minus) {
    insertTextAtLocation(pciap?"Diff ":"(Diff ", cursorLocation());
    setCursorLocation(cursorLocation() + (pciap?5:6));
    return true;
  }
  if (event == Ion::Events::Division) {
    insertTextAtLocation(pciap?"Quotient ":"(Quotient ", cursorLocation());
    setCursorLocation(cursorLocation() + (pciap?9:10));
    return true;
  }
  if (event == Ion::Events::Space && abosopb) {
    insertTextAtLocation(pciap?"Oppose ":"(Oppose ", cursorLocation());
    setCursorLocation(cursorLocation() + (pciap?7:8));
    return true;
  }
  if (event == Ion::Events::LowerV && abosopb) {
    insertTextAtLocation(pciap?"Inverse ":"(Inverse ", cursorLocation());
    setCursorLocation(cursorLocation() + (pciap?8:9));
    return true;
  }
  if (event == Ion::Events::Multiplication) {
    insertTextAtLocation(pciap?"Produit ":"(Produit ", cursorLocation());
    setCursorLocation(cursorLocation() + (pciap?8:9));
    return true;
  }
  if (event == Ion::Events::Plus) {
    insertTextAtLocation(pciap?"Somme ":"(Somme ", cursorLocation());
    setCursorLocation(cursorLocation() + (pciap?6:7));
    return true;
  }
  if (event == Ion::Events::Power) {
    insertTextAtLocation(pciap?"Puissance ":"(Puissance ", cursorLocation());
    setCursorLocation(cursorLocation() + (pciap?10:11));
    return true;
  }
  if (event == Ion::Events::Sqrt) {
    insertTextAtLocation(pciap?"Racine ":"(Racine ", cursorLocation());
    setCursorLocation(cursorLocation() + (pciap?7:8));
    return true;
  }
  if (event == Ion::Events::Square) {
    insertTextAtLocation(pciap?"Carre ":"(Carre ", cursorLocation());
    setCursorLocation(cursorLocation() + (pciap?6:7));
    return true;
  }
  // Pi Imaginary Exp Ln Log Cosine Sine Tangent
  return(::TextField::handleEvent(event));
}

}
