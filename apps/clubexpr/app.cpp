#include "app.h"
#include "../apps_container.h"
#include "clubexpr_icon.h"
#include "../i18n.h"

using namespace Poincare;

using namespace Shared;

namespace ClubExpr {

I18n::Message App::Descriptor::name() {
  return I18n::Message::ClubExprApp;
}

I18n::Message App::Descriptor::upperName() {
  return I18n::Message::ClubExprAppCapital;
}

const Image * App::Descriptor::icon() {
  return ImageStore::ClubexprIcon;  // e instead of E because of Inliner
}

App * App::Snapshot::unpack(Container * container) {
  return new App(container, this);
}

void App::Snapshot::reset() {
  m_clubexprStore.deleteAll();
}

App::Descriptor * App::Snapshot::descriptor() {
  static Descriptor descriptor;
  return &descriptor;
}

ClubExprStore * App::Snapshot::clubexprStore() {
  return &m_clubexprStore;
}

void App::Snapshot::tidy() {
  m_clubexprStore.tidy();
}

App::App(Container * container, Snapshot * snapshot) :
  TextFieldDelegateApp(container, snapshot, &m_editExpressionController),
  m_localContext((GlobalContext *)((AppsContainer *)container)->globalContext(), snapshot->clubexprStore()),
  m_historyController(&m_editExpressionController, snapshot->clubexprStore()),
  m_editExpressionController(&m_modalViewController, &m_historyController, snapshot->clubexprStore())
{
}

Context * App::localContext() {
  return &m_localContext;
}

}
