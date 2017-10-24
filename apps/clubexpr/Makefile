snapshots += ClubExpr::App::Snapshot
snapshot_headers += apps/clubexpr/app.h

app_objs += $(addprefix apps/clubexpr/,\
  app.o\
  clubexpr.o\
  clubexpr_store.o\
  edit_expression_controller.o\
  history_view_cell.o\
  history_controller.o\
  local_context.o\
  scrollable_expression_view.o\
  selectable_table_view.o\
  text_field.o\
)

i18n_files += $(addprefix apps/clubexpr/,\
  base.de.i18n\
  base.en.i18n\
  base.es.i18n\
  base.fr.i18n\
  base.pt.i18n\
)

tests += $(addprefix apps/clubexpr/test/,\
  clubexpr_store.cpp\
)
test_objs += $(addprefix apps/clubexpr/, clubexpr.o clubexpr_store.o)

app_images += apps/clubexpr/clubexpr_icon.png

