#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Headerbar/Headerbar.hh"
#include "../../Pixbuf/Pixbuf/Pixbuf.hh"
#include "../../Misc/AccelGroup/AccelGroup.hh"

namespace CGui
{
	class Window : public virtual Widget, public virtual Container<Window>
	{
	public:
		Window(WindowType type, const char* title, WindowPos pos, bool initialize = true);
		Window(GtkWindow* window);
		void Icon(const char* filename);
		void DefaultSize(unsigned int width, unsigned int height);
		Requisition DefaultSize();
		void Headerbar(CGui::Headerbar& hb);
		CGui::Headerbar Headerbar();
		void Resizable(bool resizable);
		bool Resizable();
		void AddAccelGroup(AccelGroup group);
		void RemoveAccelGroup(AccelGroup group);
		void Title(const char* title);
		const char* Title();
		void Maximize();
		bool IsMaximized();
		void Unmaximize();
		void Fullscreen();
		void Unfullscreen();
		void IConify();
		void Deiconify();
		void Position(WindowPos pos);
		WindowPositionData Position();
		bool ActivateFocus();
		bool ActivateDefault();
		void Modal(bool modal);
		bool Modal();
		void Gravity(CGui::Gravity gravity);
		CGui::Gravity Gravity();
		void TransientFor(Window& parent);
		Window TransientFor();
		void AttachedTo(Widget& attach_widget);
		Widget AttachedTo();
		void DestroyWithParent(bool destroy);
		bool DestroywithParent();
		void HideHeaderbarWhenMaximized(bool hide);
		bool HideHeaderbarWhenMaximized();
		bool IsActive();
		bool HasToplevelFocus();
		Vector<Window> ListToplevels();
		void Focus(Widget& focus);
		Widget Focus();
		void DefaultWidget(Widget& default_widget);
		Widget DefaultWidget();
		void Present();
		void Close();
		void Stick();
		void Unstick();
		void KeepAbove(bool keep_above);
		void KeepBelow(bool keep_below);
		void Decorated(bool decorated);
		bool Decorated();
		void Deletable(bool deleteable);
		bool Deletable();
		void SkipTaskbarHint(bool skip);
		bool SkipTaskbarHint();
		void SkipPagerHint(bool skip);
		bool SkipPagerHint();
		void UrgencyHint(bool urgency);
		bool UrgencyHint();
		void AcceptFocus(bool accept);
		bool AcceptFocus();
		void FocusOnMap(bool focus);
		bool FocusOnMap();
		void StartupId(const char* startup_id);
		void Icon(Pixbuf& icon);
		Pixbuf Icon();
		void IconList(Vector<Pixbuf>& list);
		Vector<Pixbuf> IconList();
		void Iconname(const char* iconname);
		const char* Iconname();
		Requisition Size();
		WindowType Type();
		void Move(int x, int y);
		void Resize(int width, int height);
		void FocusVisible(bool visible);
		bool FocusVisible();
		void HasUserRefCount(bool has);
		bool IsWindow();

		static void DefaultIconList(Vector<Pixbuf>& list);
		static Vector<Pixbuf> DefaultIconList();
		static void DefaultIconname(const char* name);
		static const char* DefaultIconname();
		static void AutoStartupNotification(bool setting);
		static void InteractiveDebugging(bool enable);

		void ErrorMessage();
		bool HasError();

	protected:
		GError* m_Error;
		Window();

		void SetWindow(GtkWindow* window);

	private:
		static unsigned int m_RefCount;
	};
}