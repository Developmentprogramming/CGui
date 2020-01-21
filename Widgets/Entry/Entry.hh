#pragma once

#include "../Widget.hh"

namespace CGui
{
  class Entry : public widget
  {
    public:
      Entry();
      Entry(const gchar *placeholdertext);
      void Name(const char *name);
      const char *Name();
      void Editable(bool editable);
      bool Editable();
      void Visibility(bool visibility);
      bool Visibility();
      void Sensitive(bool sensitive);
      void Align(Alignments halign, Alignments valign);
      void SizeRequest(guint x, guint y);
      void StyleClass(const gchar *classname);
      void Text(const char *text);
      const char *Text();
      void Show();
      GtkWidget *GetWidget();

    private:
      GtkWidget *entry;
  };

  Entry::Entry()
  { entry = gtk_entry_new(); }

  Entry::Entry(const gchar *placeholdertext)
  {
    entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), placeholdertext);
  }

  void Entry::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(entry), name); }

  const char *Entry::Name()
  { return gtk_widget_get_name(GTK_WIDGET(entry)); }

  void Entry::Editable(bool editable)
  { gtk_editable_set_editable(GTK_EDITABLE(entry), editable); }

  bool Entry::Editable()
  { return gtk_editable_get_editable(GTK_EDITABLE(entry)); }

  void Entry::Visibility(bool visibility)
  { gtk_entry_set_visibility(GTK_ENTRY(entry), visibility); }

  bool Entry::Visibility()
  { return gtk_entry_get_visibility(GTK_ENTRY(entry)); }

  void Entry::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(entry), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(entry), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void Entry::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(entry), sensitive); }

  void Entry::SizeRequest(guint x, guint y)
  { gtk_widget_set_size_request(GTK_WIDGET(entry), x, y); }

  void Entry::StyleClass(const gchar *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(entry))), classname); }

  void Entry::Text(const char *text)
  { gtk_entry_set_text(GTK_ENTRY(entry), text); }

  const char *Entry::Text()
  { return gtk_entry_get_text(GTK_ENTRY(entry)); }

  void Entry::Show()
  { gtk_widget_show(GTK_WIDGET(entry)); }

  GtkWidget *Entry::GetWidget()
  { return entry; }
}
