#ifndef SCALEPANEL_H
#define SCALEPANEL_H

//(*Headers(ScalePanel)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/spinbutt.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include "OvniMain.h"

class ScalePanel: public wxDialog
{
	public:

		ScalePanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ScalePanel();

		//(*Declarations(ScalePanel)
		wxButton* Button_Annuler;
		wxButton* Button_Appliquer;
		wxButton* Button_Valider;
		wxCheckBox* CheckBox_ScaleUnique;
		wxSpinButton* SpinButton_X;
		wxSpinButton* SpinButton_Y;
		wxSpinButton* SpinButton_Z;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxTextCtrl* TextCtrl_Increment;
		wxTextCtrl* TextCtrl_ScaleX;
		wxTextCtrl* TextCtrl_ScaleY;
		wxTextCtrl* TextCtrl_ScaleZ;
		//*)
		double ScaleX, ScaleY, ScaleZ;

	protected:

		//(*Identifiers(ScalePanel)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL2;
		static const long ID_SPINBUTTON1;
		static const long ID_TEXTCTRL3;
		static const long ID_SPINBUTTON2;
		static const long ID_TEXTCTRL4;
		static const long ID_SPINBUTTON3;
		static const long ID_CHECKBOX1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(ScalePanel)
		void OnClose(wxCloseEvent& event);
		void OnTextCtrl_IncrementText(wxCommandEvent& event);
		void OnButton_ValiderClick(wxCommandEvent& event);
		void OnTextCtrl_ScaleXText(wxCommandEvent& event);
		void OnTextCtrl_ScaleYText(wxCommandEvent& event);
		void OnTextCtrl_ScaleZText(wxCommandEvent& event);
		void OnCheckBox_ScaleUniqueClick(wxCommandEvent& event);
		void OnSpinButton_XChange(wxSpinEvent& event);
		void OnSpinButton_YChange(wxSpinEvent& event);
		void OnSpinButton_ZChange(wxSpinEvent& event);
		void OnButton_AppliquerClick(wxCommandEvent& event);
		void OnButton_AnnulerClick(wxCommandEvent& event);
		void OnSpinButton_XChangeUp(wxSpinEvent& event);
		void OnSpinButton_XChangeDown(wxSpinEvent& event);
		void OnSpinButton_YChangeUp(wxSpinEvent& event);
		void OnSpinButton_YChangeDown(wxSpinEvent& event);
		void OnSpinButton_ZChangeUp(wxSpinEvent& event);
		void OnSpinButton_ZChangeDown(wxSpinEvent& event);
		void OnInit(wxInitDialogEvent& event);
		//*)
//		void ToDo();
		void Init_Centre_Scale();
		void Appliquer_Scale_Visuelle();
		wxString wxTexte;
		bool   Synchrones;
		double Incr;
        OvniFrame* MAIN;

		DECLARE_EVENT_TABLE()
};

#endif
