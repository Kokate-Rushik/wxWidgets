//Code by Kokate Rushik
//Compile : g++ tut1.cpp -o tut1 `wx-config --cxxflags --libs`
//Output : ./tut1

#include<wx/wx.h>

class MyApp : public wxApp {
	public:
		virtual bool OnInit();
};

class MyFrame : public wxFrame {
	public:
		MyFrame(const wxString &title);
		
		void OnQuit(wxCommandEvent &event);
		void OnAbout(wxCommandEvent &event);
		
	private:
		DECLARE_EVENT_TABLE()
};

DECLARE_APP(MyApp)
IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
	MyFrame *frame = new MyFrame(wxT("Miniamal wxWidgets App"));
	frame->Show(true);
	return true;
}

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
	EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
END_EVENT_TABLE()

void MyFrame::OnAbout(wxCommandEvent &event) {
	wxString msg;
	msg.Printf(wxT("Hello and Welcome to %s"), wxVERSION_STRING);
	wxMessageBox(msg, wxT("About Minimal"), wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnQuit(wxCommandEvent &event) {
	Close();
}

//#include<mondrian.xpm>

MyFrame::MyFrame(const wxString &title) 
		: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 350)) {
	//SetIcon(wxICON(mondrian_xpm));
	
	wxMenu *fileMenu = new wxMenu;
		
	wxMenu *helpMenu = new wxMenu;
	helpMenu -> Append(wxID_ABOUT, wxT("&About...\tF1"), wxT("Show about dialog"));
	
	fileMenu -> Append(wxID_EXIT, wxT("E&xit\tAlt-X"), wxT("Quit this Program"));
	
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar -> Append(fileMenu, wxT("&File"));
	menuBar -> Append(helpMenu, wxT("&Help"));
	
	SetMenuBar(menuBar);
	
	CreateStatusBar(2);
	SetStatusText(wxT("Welcome to wxWidgets!"));
}
