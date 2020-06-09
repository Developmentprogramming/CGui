#include "./Headerbar.hh"

namespace CGui
{
	Headerbar::Headerbar(const char *title, const char *subtitle) : Container(this)
	{
	widget = gtk_header_bar_new();
	gtk_header_bar_set_title(GTK_HEADER_BAR(widget), title);
	gtk_header_bar_set_subtitle(GTK_HEADER_BAR(widget), subtitle);
	this->SetContext(widget);
	}

	void Headerbar::Add(BoxAddType type, Widget& w)
	{
		auto func = Converter::Convert::GetInstance().HeaderbarFuncPtr(type);
		func(GTK_HEADER_BAR(widget), w.GetWidget());
		children.Insert((void*)& w);
	}

	void Headerbar::AddStart(Widget& w)
	{
		this->Add(BoxAddType::START, w);
	}

	void Headerbar::AddEnd(Widget& w)
	{
		this->Add(BoxAddType::END, w);
	}
};
