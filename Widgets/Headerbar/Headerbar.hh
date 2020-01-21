#pragma once

#include "../Widget.hh"

namespace CGui
{
  class Headerbar : public widget
  {
    public:
      Headerbar(const gchar *title = "", const gchar *subtitle = "");
      void Name(const char *name);
      const char *Name();
      template<typename addtype> void Add(BoxAddType type, addtype &w);
      void Sensitive(bool sensitive);
      void Align(Alignments halign, Alignments valign);
      void SizeRequest(guint x, guint y);
      void StyleClass(const gchar *classname);
      void Show();
      GtkWidget *GetWidget();

    private:
      GtkWidget *headerbar;
  };

  Headerbar::Headerbar(const gchar *title, const gchar *subtitle)
  {
    headerbar = gtk_header_bar_new();
    gtk_header_bar_set_title(GTK_HEADER_BAR(headerbar), title);
    gtk_header_bar_set_subtitle(GTK_HEADER_BAR(headerbar), subtitle);
  }

  void Headerbar::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(headerbar), name); }

  const char *Headerbar::Name()
  { return gtk_widget_get_name(GTK_WIDGET(headerbar)); }

  template<typename addtype> void Headerbar::Add(BoxAddType type, addtype &w)
  {
    switch (type)
    {
      case START:
        gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), w.GetWidget());
        break;
      case END:
        gtk_header_bar_pack_end(GTK_HEADER_BAR(headerbar), w.GetWidget());
        break;
    }
  }

  void Headerbar::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(headerbar), sensitive); }

  void Headerbar::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(headerbar), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(headerbar), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void Headerbar::SizeRequest(guint x, guint y)
  { gtk_widget_set_size_request(GTK_WIDGET(headerbar), x, y); }

  void Headerbar::StyleClass(const gchar *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(headerbar))), classname); }

  void Headerbar::Show()
  { gtk_widget_show(GTK_WIDGET(headerbar)); }

  GtkWidget *Headerbar::GetWidget()
  { return headerbar; }
}
