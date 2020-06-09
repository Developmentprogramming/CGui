#pragma once

#include <iostream>
#include <gtk/gtk.h>
#include <variant>

namespace CGui
{
  enum class WindowType { TOPLEVEL, POPUP };
  enum class WindowPos { NONE, CENTER, MOUSE, CENTER_ALWAYS, CENTER_ON_PARENT };

  enum class BoxType { HORIZONTAL, VERTICAL };
  enum class BoxAddType { START, END };

  enum class Alignments { FILL, BEGIN, LAST, CENTER, BASELINE };

  enum class Events { CLICKED, DELETE, TOGGLED, CHANGED, ENTER, ACTIVATE };

  enum class RevealerTransition { NONE, CROSSFADE, SLIDE_RIGHT, SLIDE_LEFT, SLIDE_UP, SLIDE_DOWN };

  enum class MessageType { INFO, WARNING, QUESTION, ERROR, OTHER };

  enum class Policy { ALWAYS, AUTOMATIC, NEVER, EXTERNAL };

  enum class Action { OPEN, SAVE, SELECT_FOLDER, CREATE_FOLDER };

  enum class Priority : unsigned short { FALLBACK = 1, THEME = 200, SETTINGS = 400, APPLICATION = 600, USER = 800 };

  enum class BaselinePosition { TOP, CENTER, BOTTOM };

  namespace Converter
  {
	class Convert
	{
		public:
		/*std::variant<GtkAlign, GtkOrientation, GtkWindowType, GtkWindowPosition, GtkRevealerTransitionType, GtkMessageType, GtkPolicyType, GtkFileChooserAction, const char*> ConvertToGtkCode(std::variant<Alignments, BoxType, WindowType, WindowPos, Transition, MessageType, Events, Policy, Action> data)
		{
			std::variant<GtkAlign, GtkOrientation, GtkWindowType, GtkWindowPosition, GtkRevealerTransitionType, GtkMessageType, GtkPolicyType, GtkFileChooserAction, const char*> retValue;
			if (data.index() == 0)
				return GetGtkCode(std::get<Alignments>(data));
			else if (data.index() == 1)
				return GetGtkCode(std::get<BoxType>(data));
			else if (data.index() == 2)
				return GetGtkCode(std::get<WindowType>(data));
			else if (data.index() == 3)
				return GetGtkCode(std::get<WindowPos>(data));
			else if (data.index() == 4)
				return GetGtkCode(std::get<RevealerTransition>(data));
			else if (data.index() == 5)
				return GetGtkCode(std::get<MessageType>(data));
			else if (data.index() == 6)
				return GetGtkCode(std::get<Events>(data));
			else if (data.index() == 7)
				return GetGtkCode(std::get<Policy>(data));
			else if (data.index() == 8)
				return GetGtkCode(std::get<Action>(data));
			return retValue;
		}*/

		const char* GetGtkCode(Events event)
		{
			switch (event)
			{
			case Events::CLICKED:
				return "clicked";
				break;
			case Events::DELETE:
				return "delete-event";
				break;
			case Events::TOGGLED:
				return "toggled";
				break;
			case Events::CHANGED:
				return "changed";
				break;
			case Events::ENTER:
				return "enter";
				break;
			case Events::ACTIVATE:
				return "activate";
				break;

			default:
				return "changed";
			}
		}

		auto BoxFuncPtr(BoxAddType type)
		{
			switch (type)
			{
			case BoxAddType::START:
				return gtk_box_pack_start;
				break;

			case BoxAddType::END:
				return gtk_box_pack_end;
				break;

			default:
				return gtk_box_pack_start;
			}
		}

		auto HeaderbarFuncPtr(BoxAddType type)
		{
			switch (type)
			{
			case BoxAddType::START:
				return gtk_header_bar_pack_start;
				break;
			case BoxAddType::END:
				return gtk_header_bar_pack_end;
				break;

				default:
				return gtk_header_bar_pack_start;
			}
		}

		static Convert &GetInstance()
		{
			static Convert instance;
			return instance;
		}

		Convert(const Convert&) = delete;
		Convert(const Convert&&) = delete;
		Convert& operator=(const Convert&) = delete;

		private:
		Convert()
		{  }

		/*GtkFileChooserAction GetGtkCode(Action action)
		{
			switch (action)
			{
			case Action::OPEN:
				return GTK_FILE_CHOOSER_ACTION_OPEN;
				break;
			case Action::SAVE:
				return GTK_FILE_CHOOSER_ACTION_SAVE;
				break;
			case Action::SELECT_FOLDER:
				return GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER;
				break;
			case Action::CREATE_FOLDER:
				return GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER;
				break;

			default:
				return GTK_FILE_CHOOSER_ACTION_OPEN;
			}
		}

		GtkPolicyType GetGtkCode(Policy policy)
		{
			switch (policy)
			{
			case Policy::AUTOMATIC:
				return GTK_POLICY_AUTOMATIC;
				break;
			case Policy::NEVER:
				return GTK_POLICY_NEVER;
				break;
			case Policy::ALWAYS:
				return GTK_POLICY_ALWAYS;
				break;

			default:
				return GTK_POLICY_AUTOMATIC;
			}
		}

		GtkMessageType GetGtkCode(MessageType messagetype)
		{
			switch (messagetype)
			{
			case MessageType::INFO:
				return GTK_MESSAGE_INFO;
				break;
			case MessageType::WARNING:
				return GTK_MESSAGE_WARNING;
				break;
			case MessageType::QUESTION:
				return GTK_MESSAGE_QUESTION;
				break;
			case MessageType::ERROR:
				return GTK_MESSAGE_ERROR;
				break;
			case MessageType::OTHER:
				return GTK_MESSAGE_OTHER;
				break;

			default:
				return GTK_MESSAGE_OTHER;
			}
		}

		GtkRevealerTransitionType GetGtkCode(RevealerTransition transition)
		{
			switch (transition)
			{
			case RevealerTransition::SLIDE_UP:
				return GTK_REVEALER_TRANSITION_TYPE_SLIDE_UP;
				break;
			case RevealerTransition::SLIDE_DOWN:
				return GTK_REVEALER_TRANSITION_TYPE_SLIDE_DOWN;
				break;
			case RevealerTransition::SLIDE_LEFT:
				return GTK_REVEALER_TRANSITION_TYPE_SLIDE_LEFT;
				break;
			case RevealerTransition::SLIDE_RIGHT:
				return GTK_REVEALER_TRANSITION_TYPE_SLIDE_RIGHT;
				break;
			case RevealerTransition::CROSSFADE:
				return GTK_REVEALER_TRANSITION_TYPE_CROSSFADE;
				break;

			default:
				return GTK_REVEALER_TRANSITION_TYPE_NONE;
			}
		}

		const char *GetGtkCode(Events event)
		{
			switch (event)
			{
			case Events::CLICKED:
				return "clicked";
				break;
			case Events::DELETE:
				return "delete-event";
				break;
			case Events::TOGGLED:
				return "toggled";
				break;
			case Events::CHANGED:
				return "changed";
				break;
			case Events::ENTER:
				return "enter";
				break;
			case Events::ACTIVATE:
				return "activate";
				break;

			default:
				return "changed";
			}
		}

		GtkWindowType GetGtkCode(WindowType data)
		{
			switch (data)
			{
			case WindowType::TOPLEVEL:
				return GTK_WINDOW_TOPLEVEL;
			break;
			case WindowType::POPUP:
				return GTK_WINDOW_POPUP;
			break;

			default:
				return GTK_WINDOW_TOPLEVEL;
			}
		}

		GtkWindowPosition GetGtkCode(WindowPos data)
		{
			switch (data)
			{
			case WindowPos::CENTER:
				return GTK_WIN_POS_CENTER;
				break;
			case WindowPos::MOUSE:
				return GTK_WIN_POS_MOUSE;
				break;
			case WindowPos::CENTER_ALWAYS:
				return GTK_WIN_POS_CENTER_ALWAYS;

			default:
				return GTK_WIN_POS_CENTER;
			}
		}

		GtkAlign GetGtkCode(Alignments data)
		{
			switch (data)
			{
			case Alignments::BEGIN:
				return GTK_ALIGN_START;
			break;
			case Alignments::FILL:
				return GTK_ALIGN_FILL;
			break;
			case Alignments::LAST:
				return GTK_ALIGN_END;
			break;
			case Alignments::CENTER:
				return GTK_ALIGN_CENTER;
			break;

			default:
				return GTK_ALIGN_CENTER;
			}
		}

		GtkOrientation GetGtkCode(BoxType data)
		{
			switch (data)
			{
			case BoxType::VER:
				return GTK_ORIENTATION_VERTICAL;
			break;
			case BoxType::HOR:
				return GTK_ORIENTATION_HORIZONTAL;
			break;

			default:
				return GTK_ORIENTATION_VERTICAL;
			}
		}*/
	};
  }
}