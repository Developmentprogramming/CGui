#pragma once

#include "../Widget.hh"
#include "../Window/Window.hh"

namespace CGui
{
	class Assistant : public Window
	{
	public:
		Assistant();
		void CurrentPage(int page);
		int CurrentPage();
		int NumPage();
		Widget NthPage(int page);
		int PrependPage(Widget& page);
		int AppendPage(Widget& page);
		int InsertPage(Widget& page, int position);
		void RemovePage(int position);
		void PageType(Widget& page, AssistantPageType type);
		AssistantPageType PageType(Widget& page);
		void PageTitle(Widget& page, const char* title);
		const char* PageTitle(Widget& page);
		void PageComplete(Widget& page, bool complete);
		bool PageComplete(Widget& page);
		void PageHasPadding(Widget& page, bool has_padding);
		bool PageHasPadding(Widget& page);
		void AddActionWidget(Widget& child);
		void RemoveActionWidget(Widget& child);
		void UpdateButtonsState();
		void Commit();
		void NextPage();
		void PrevPage();

	private:
		static unsigned int m_ref_count;
	};
}