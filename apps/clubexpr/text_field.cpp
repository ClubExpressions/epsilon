#include "text_field.h"

namespace ClubExpr {

TextField::TextField(Responder * parentResponder, char * textBuffer, size_t textBufferSize, TextFieldDelegate * delegate) :
  ::TextField(parentResponder, textBuffer, textBuffer, textBufferSize, delegate, false)
{
  setEditing(true);
}

bool isDigit(char c) {
  if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
      c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
    return true;
  }
  return false;
}

bool TextField::handleEvent(Ion::Events::Event event) {
  // TODO: internationalisation and accents on Carré and Opposé
  if (event == Ion::Events::Back) {
    return false;
  }
  if (event == Ion::Events::Backspace) {
    // This is a quite special handling of Backspace!
    // We try to eat as many chars as possible to speed up editing.
    // pv is the previous char
    char pv = text()[cursorLocation()-1];
    if (isDigit(pv) || pv == '(' || pv == ')') {
      // We delete digits and parens one char by one char:
      deleteCharPrecedingCursor();
      return true;
    } else if (pv == ' ') {
      // Before this space, there could be more to delete.
      deleteCharPrecedingCursor();
      bool running = true;
      while (cursorLocation() > 0 && running) {
          pv = text()[cursorLocation()-1];
          if (isDigit(pv) || pv == ' ' || pv == ')') {
            running = false;
          }
          if (running) deleteCharPrecedingCursor();
      }
    } else {
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
  // Other
  if (event == Ion::Events::Exp) {
    insertTextAtLocation(pciap?"exp ":"(exp ", cursorLocation());
    setCursorLocation(cursorLocation() + (pciap?4:5));
    return true;
  }
  if (event == Ion::Events::Ln) {
    insertTextAtLocation(pciap?"ln ":"(ln ", cursorLocation());
    setCursorLocation(cursorLocation() + (pciap?3:4));
    return true;
  }
  if (event == Ion::Events::Log) {
    insertTextAtLocation(pciap?"log ":"(log ", cursorLocation());
    setCursorLocation(cursorLocation() + (pciap?4:5));
    return true;
  }
  if (event == Ion::Events::Cosine) {
    insertTextAtLocation(pciap?"cos ":"(cos ", cursorLocation());
    setCursorLocation(cursorLocation() + (pciap?4:5));
    return true;
  }
  if (event == Ion::Events::Sine) {
    insertTextAtLocation(pciap?"sin ":"(sin ", cursorLocation());
    setCursorLocation(cursorLocation() + (pciap?4:5));
    return true;
  }
  if (event == Ion::Events::Tangent) {
    insertTextAtLocation(pciap?"tan ":"(tan ", cursorLocation());
    setCursorLocation(cursorLocation() + (pciap?4:5));
    return true;
  }
  return(::TextField::handleEvent(event));
}

}
