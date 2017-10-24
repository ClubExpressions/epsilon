#ifndef CLUBEXPR_SELECTABLE_TABLE_VIEW_H
#define CLUBEXPR_SELECTABLE_TABLE_VIEW_H

#include <escher.h>
#include "history_view_cell.h"
namespace ClubExpr {

class ClubExprSelectableTableView : public ::SelectableTableView {
public:
  ClubExprSelectableTableView(Responder * parentResponder, TableViewDataSource * dataSource,
    SelectableTableViewDataSource * selectionDataSource, SelectableTableViewDelegate * delegate = nullptr);
  void scrollToCell(int i, int j) override;
  void scrollToSubviewOfTypeOfCellAtLocation(HistoryViewCell::SubviewType subviewType, int i, int j);
};

}

#endif
