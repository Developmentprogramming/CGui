#include "./ToolPalette.hh"

namespace CGui
{
	ToolPalette::ToolPalette() : Container(this), Orientable(this)
	{
		m_Widget = gtk_tool_palette_new();
		this->SetContext(m_Widget);
		this->SetScrollable(GTK_SCROLLABLE(m_Widget));
	}

	ToolPalette::ToolPalette(GtkToolPalette* tool_palette) : Container(this), Orientable(this)
	{
		m_Widget = GTK_WIDGET(tool_palette);
		this->SetContext(m_Widget);
		this->SetScrollable(GTK_SCROLLABLE(tool_palette));
	}

	void ToolPalette::Exclusive(ToolItemGroup& group, bool exclusive)
	{
		gtk_tool_palette_set_exclusive(GTK_TOOL_PALETTE(m_Widget), GTK_TOOL_ITEM_GROUP(group.GetWidget()), exclusive);
	}

	bool ToolPalette::Exclusive(ToolItemGroup& group)
	{
		return gtk_tool_palette_get_exclusive(GTK_TOOL_PALETTE(m_Widget), GTK_TOOL_ITEM_GROUP(group.GetWidget()));
	}

	void ToolPalette::Expand(ToolItemGroup& group, bool expand)
	{
		gtk_tool_palette_set_expand(GTK_TOOL_PALETTE(m_Widget), GTK_TOOL_ITEM_GROUP(group.GetWidget()), expand);
	}

	bool ToolPalette::Expand(ToolItemGroup& group)
	{
		return gtk_tool_palette_get_expand(GTK_TOOL_PALETTE(m_Widget), GTK_TOOL_ITEM_GROUP(group.GetWidget()));
	}

	void ToolPalette::GroupPosition(ToolItemGroup& group, int pos)
	{
		gtk_tool_palette_set_group_position(GTK_TOOL_PALETTE(m_Widget), GTK_TOOL_ITEM_GROUP(group.GetWidget()), pos);
	}

	int ToolPalette::GroupPosition(ToolItemGroup& group)
	{
		return gtk_tool_palette_get_group_position(GTK_TOOL_PALETTE(m_Widget), GTK_TOOL_ITEM_GROUP(group.GetWidget()));
	}

	void ToolPalette::IconSize(CGui::IconSize size)
	{
		gtk_tool_palette_set_icon_size(GTK_TOOL_PALETTE(m_Widget), (GtkIconSize)size);
	}

	CGui::IconSize ToolPalette::IconSize()
	{
		return (CGui::IconSize)gtk_tool_palette_get_icon_size(GTK_TOOL_PALETTE(m_Widget));
	}

	void ToolPalette::UnsetIconSize()
	{
		gtk_tool_palette_unset_icon_size(GTK_TOOL_PALETTE(m_Widget));
	}

	void ToolPalette::Style(ToolbarStyle style)
	{
		gtk_tool_palette_set_style(GTK_TOOL_PALETTE(m_Widget), (GtkToolbarStyle)style);
	}

	ToolbarStyle ToolPalette::Style()
	{
		return (ToolbarStyle)gtk_tool_palette_get_style(GTK_TOOL_PALETTE(m_Widget));
	}

	void ToolPalette::UnsetStyle()
	{
		gtk_tool_palette_unset_style(GTK_TOOL_PALETTE(m_Widget));
	}

	void ToolPalette::AddDragDest(Widget& w, DestDefaults flags, ToolPaletteDragTargets targets, DragAction action)
	{
		gtk_tool_palette_add_drag_dest(GTK_TOOL_PALETTE(m_Widget), w.GetWidget(), (GtkDestDefaults)flags, (GtkToolPaletteDragTargets)targets, (GdkDragAction)action);
	}

	ToolItemGroup ToolPalette::DropGroup(int x, int y)
	{
		return ToolItemGroup(gtk_tool_palette_get_drop_group(GTK_TOOL_PALETTE(m_Widget), x, y));
	}

	ToolItem ToolPalette::DropItem(int x, int y)
	{
		return ToolItem(gtk_tool_palette_get_drop_item(GTK_TOOL_PALETTE(m_Widget), x, y));
	}

	void ToolPalette::DragSource(ToolPaletteDragTargets targets)
	{
		gtk_tool_palette_set_drag_source(GTK_TOOL_PALETTE(m_Widget), (GtkToolPaletteDragTargets)targets);
	}

	bool ToolPalette::IsToolPalette()
	{
		return GTK_IS_TOOL_PALETTE(m_Widget);
	}

}