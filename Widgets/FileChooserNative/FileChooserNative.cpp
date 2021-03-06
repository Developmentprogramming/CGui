#include "./FileChooserNative.hh"

namespace CGui
{
	FileChooserNative::FileChooserNative(GtkFileChooserNative* file_chooser_native)
	{
		this->SetNativeDialog(GTK_NATIVE_DIALOG(file_chooser_native));
		this->SetFileChooser(GTK_FILE_CHOOSER(m_NativeDialog));
	}

	FileChooserNative::FileChooserNative(const char* title, Window& parent, FileChooserAction action, const char* accept_label, const char* cancel_label)
	{
		m_NativeDialog = GTK_NATIVE_DIALOG(gtk_file_chooser_native_new(title, GTK_WINDOW(parent.GetWidget()), (GtkFileChooserAction)action, accept_label, cancel_label));
		this->SetNativeDialog(m_NativeDialog);
		this->SetFileChooser(GTK_FILE_CHOOSER(m_NativeDialog));
	}

	void FileChooserNative::AcceptLabel(const char* label)
	{
		gtk_file_chooser_native_set_accept_label(GTK_FILE_CHOOSER_NATIVE(m_NativeDialog), label);
	}

	const char* FileChooserNative::AcceptLabel()
	{
		return gtk_file_chooser_native_get_accept_label(GTK_FILE_CHOOSER_NATIVE(m_NativeDialog));
	}

	void FileChooserNative::CancelLabel(const char* label)
	{
		gtk_file_chooser_native_set_cancel_label(GTK_FILE_CHOOSER_NATIVE(m_NativeDialog), label);
	}

	const char* FileChooserNative::CancelLabel()
	{
		return gtk_file_chooser_native_get_cancel_label(GTK_FILE_CHOOSER_NATIVE(m_NativeDialog));
	}
	bool FileChooserNative::IsFileChooserNative()
	{
		return GTK_IS_FILE_CHOOSER_NATIVE(m_NativeDialog);
	}
}