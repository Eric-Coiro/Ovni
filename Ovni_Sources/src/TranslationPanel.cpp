#include "TranslationPanel.h"

//(*InternalHeaders(TranslationPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(TranslationPanel)
const long TranslationPanel::ID_STATICTEXT1 = wxNewId();
const long TranslationPanel::ID_TEXTCTRL1 = wxNewId();
const long TranslationPanel::ID_STATICTEXT2 = wxNewId();
const long TranslationPanel::ID_TEXTCTRL2 = wxNewId();
const long TranslationPanel::ID_BUTTON1 = wxNewId();
const long TranslationPanel::ID_STATICTEXT3 = wxNewId();
const long TranslationPanel::ID_TEXTCTRL3 = wxNewId();
const long TranslationPanel::ID_SPINBUTTON1 = wxNewId();
const long TranslationPanel::ID_STATICTEXT4 = wxNewId();
const long TranslationPanel::ID_TEXTCTRL4 = wxNewId();
const long TranslationPanel::ID_SPINBUTTON2 = wxNewId();
const long TranslationPanel::ID_STATICTEXT5 = wxNewId();
const long TranslationPanel::ID_TEXTCTRL5 = wxNewId();
const long TranslationPanel::ID_SPINBUTTON3 = wxNewId();
const long TranslationPanel::ID_STATICTEXT6 = wxNewId();
const long TranslationPanel::ID_TEXTCTRL6 = wxNewId();
const long TranslationPanel::ID_SPINBUTTON4 = wxNewId();
const long TranslationPanel::ID_STATICTEXT7 = wxNewId();
const long TranslationPanel::ID_TEXTCTRL7 = wxNewId();
const long TranslationPanel::ID_SPINBUTTON5 = wxNewId();
const long TranslationPanel::ID_STATICTEXT8 = wxNewId();
const long TranslationPanel::ID_TEXTCTRL8 = wxNewId();
const long TranslationPanel::ID_SPINBUTTON6 = wxNewId();
const long TranslationPanel::ID_BUTTON2 = wxNewId();
const long TranslationPanel::ID_BUTTON3 = wxNewId();
//*)

wxString format_1 = _T("%4.2f");    // Format pour les écritures des multiples du pas grossier
wxString format_2 = _T("%5.3f");    // Format pour les écritures avec le pas fin

BEGIN_EVENT_TABLE(TranslationPanel,wxDialog)
	//(*EventTable(TranslationPanel)
	//*)
END_EVENT_TABLE()

TranslationPanel::TranslationPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(TranslationPanel)
	Create(parent, id, _T("Translation"), wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(441,223));
	Move(wxPoint(30,30));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _T("Pas grossier"), wxPoint(8,12), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	TextCtrl_PasGrossier = new wxTextCtrl(this, ID_TEXTCTRL1, _T("0.20"), wxPoint(104,8), wxSize(96,24), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _T("Pas fin"), wxPoint(256,12), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	TextCtrl_PasFin = new wxTextCtrl(this, ID_TEXTCTRL2, _T("0.01"), wxPoint(320,8), wxSize(96,24), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	Button_Valider = new wxButton(this, ID_BUTTON1, _T("Valider la modification du Pas"), wxPoint(48,40), wxSize(336,24), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _T("Translation en X"), wxPoint(8,92), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText3->SetForegroundColour(wxColour(255,0,0));
	TextCtrl_XG = new wxTextCtrl(this, ID_TEXTCTRL3, _T("0.0"), wxPoint(104,88), wxSize(96,24), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	SpinButton_XG = new wxSpinButton(this, ID_SPINBUTTON1, wxPoint(200,88), wxSize(17,24), wxSP_VERTICAL|wxSP_ARROW_KEYS, _T("ID_SPINBUTTON1"));
	SpinButton_XG->SetRange(-10, 10);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _T("Affiner en X"), wxPoint(248,92), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText4->SetForegroundColour(wxColour(255,0,0));
	TextCtrl_XF = new wxTextCtrl(this, ID_TEXTCTRL4, _T("0.000"), wxPoint(320,88), wxSize(96,24), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	SpinButton_XF = new wxSpinButton(this, ID_SPINBUTTON2, wxPoint(416,88), wxSize(17,24), wxSP_VERTICAL|wxSP_ARROW_KEYS, _T("ID_SPINBUTTON2"));
	SpinButton_XF->SetRange(-10, 10);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _T("Translation en Y"), wxPoint(8,124), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticText5->SetForegroundColour(wxColour(0,128,0));
	TextCtrl_YG = new wxTextCtrl(this, ID_TEXTCTRL5, _T("0.0"), wxPoint(104,120), wxSize(96,24), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	SpinButton_YG = new wxSpinButton(this, ID_SPINBUTTON3, wxPoint(200,120), wxSize(17,24), wxSP_VERTICAL|wxSP_ARROW_KEYS, _T("ID_SPINBUTTON3"));
	SpinButton_YG->SetRange(-10, 1000);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _T("Affiner en Y"), wxPoint(248,124), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticText6->SetForegroundColour(wxColour(0,128,0));
	TextCtrl_YF = new wxTextCtrl(this, ID_TEXTCTRL6, _T("0.000"), wxPoint(320,120), wxSize(96,24), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	SpinButton_YF = new wxSpinButton(this, ID_SPINBUTTON4, wxPoint(416,120), wxSize(17,24), wxSP_VERTICAL|wxSP_ARROW_KEYS, _T("ID_SPINBUTTON4"));
	SpinButton_YF->SetRange(-10, 10);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _T("Translation en Z"), wxPoint(8,156), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	StaticText7->SetForegroundColour(wxColour(0,0,255));
	TextCtrl_ZG = new wxTextCtrl(this, ID_TEXTCTRL7, _T("0.0"), wxPoint(104,152), wxSize(96,24), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	SpinButton_ZG = new wxSpinButton(this, ID_SPINBUTTON5, wxPoint(200,152), wxSize(17,24), wxSP_VERTICAL|wxSP_ARROW_KEYS, _T("ID_SPINBUTTON5"));
	SpinButton_ZG->SetRange(-10, 10);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _T("Affiner en Z"), wxPoint(248,156), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	StaticText8->SetForegroundColour(wxColour(0,0,255));
	TextCtrl_ZF = new wxTextCtrl(this, ID_TEXTCTRL8, _T("0.000"), wxPoint(320,152), wxSize(96,24), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	SpinButton_ZF = new wxSpinButton(this, ID_SPINBUTTON6, wxPoint(416,152), wxSize(17,24), wxSP_VERTICAL|wxSP_ARROW_KEYS, _T("ID_SPINBUTTON6"));
	SpinButton_ZF->SetRange(-10, 10);
	Button_OK = new wxButton(this, ID_BUTTON2, _T("OK"), wxPoint(104,192), wxSize(104,24), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button_Annuler = new wxButton(this, ID_BUTTON3, _T("Annuler"), wxPoint(232,192), wxSize(104,24), 0, wxDefaultValidator, _T("ID_BUTTON3"));

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&TranslationPanel::OnTextCtrl_PasGrossierText);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&TranslationPanel::OnTextCtrl_PasFinText);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TranslationPanel::OnButton_ValiderClick);
	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&TranslationPanel::OnTextCtrl_XGText);
	Connect(ID_SPINBUTTON1,wxEVT_SCROLL_LINEUP,(wxObjectEventFunction)&TranslationPanel::OnSpinButton_XGChangeUp);
	Connect(ID_SPINBUTTON1,wxEVT_SCROLL_LINEDOWN,(wxObjectEventFunction)&TranslationPanel::OnSpinButton_XGChangeDown);
	Connect(ID_SPINBUTTON2,wxEVT_SCROLL_LINEUP,(wxObjectEventFunction)&TranslationPanel::OnSpinButton_XFChangeUp);
	Connect(ID_SPINBUTTON2,wxEVT_SCROLL_LINEDOWN,(wxObjectEventFunction)&TranslationPanel::OnSpinButton_XFChangeDown);
	Connect(ID_SPINBUTTON3,wxEVT_SCROLL_LINEUP,(wxObjectEventFunction)&TranslationPanel::OnSpinButton_YGChangeUp);
	Connect(ID_SPINBUTTON3,wxEVT_SCROLL_LINEDOWN,(wxObjectEventFunction)&TranslationPanel::OnSpinButton_YGChangeDown);
	Connect(ID_SPINBUTTON4,wxEVT_SCROLL_LINEUP,(wxObjectEventFunction)&TranslationPanel::OnSpinButton_YFChangeUp);
	Connect(ID_SPINBUTTON4,wxEVT_SCROLL_LINEDOWN,(wxObjectEventFunction)&TranslationPanel::OnSpinButton_YFChangeDown);
	Connect(ID_SPINBUTTON5,wxEVT_SCROLL_LINEUP,(wxObjectEventFunction)&TranslationPanel::OnSpinButton_ZGChangeUp);
	Connect(ID_SPINBUTTON5,wxEVT_SCROLL_LINEDOWN,(wxObjectEventFunction)&TranslationPanel::OnSpinButton_ZGChangeDown);
	Connect(ID_SPINBUTTON6,wxEVT_SCROLL_LINEUP,(wxObjectEventFunction)&TranslationPanel::OnSpinButton_ZFChangeUp);
	Connect(ID_SPINBUTTON6,wxEVT_SCROLL_LINEDOWN,(wxObjectEventFunction)&TranslationPanel::OnSpinButton_ZFChangeDown);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TranslationPanel::OnButton_OKClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TranslationPanel::OnButton_AnnulerClick);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&TranslationPanel::OnInit);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&TranslationPanel::OnClose);
	//*)
	this->MAIN = dynamic_cast<OvniFrame*>(parent);
}

TranslationPanel::~TranslationPanel()
{
	//(*Destroy(TranslationPanel)
	//*)
}


void TranslationPanel::OnClose(wxCloseEvent& event)
{
    tx = ty = tz = 0.0;
    Pas_X = Pas_Y = Pas_Z = Pas_XG = Pas_YG = Pas_ZG = Pas_XF = Pas_YF = Pas_ZF = 0.0;
    Hide();
}

void TranslationPanel::OnButton_ValiderClick(wxCommandEvent& event)
{
    Pas_G = wxAtof(TextCtrl_PasGrossier->GetValue());
    Pas_F = wxAtof(TextCtrl_PasFin->GetValue());
}

void TranslationPanel::OnInit(wxInitDialogEvent& event)
{
    Pas_G = wxAtof(TextCtrl_PasGrossier->GetValue());
    Pas_F = wxAtof(TextCtrl_PasFin->GetValue());
    // Tout remettre à 0
    tx = ty = tz = 0.0 ;
    Pas_X = Pas_Y = Pas_Z = Pas_XG = Pas_YG = Pas_ZG = Pas_XF = Pas_YF = Pas_ZF = 0.0;
    SpinButton_XG->SetValue(0);
    SpinButton_XF->SetValue(0);
    SpinButton_YG->SetValue(0);
    SpinButton_YF->SetValue(0);
    SpinButton_ZG->SetValue(0);
    SpinButton_ZF->SetValue(0);
    wxTexte.Printf(format_1,tx);
    TextCtrl_XG->SetValue(wxTexte);
    TextCtrl_YG->SetValue(wxTexte);
    TextCtrl_ZG->SetValue(wxTexte);
    TextCtrl_XF->SetValue(wxTexte);
    TextCtrl_YF->SetValue(wxTexte);
    TextCtrl_ZF->SetValue(wxTexte);
}

void TranslationPanel::OnTextCtrl_XGText(wxCommandEvent& event)
{
    // Pour une éventuelle entrée directe !
}

void TranslationPanel::OnSpinButton_XGChangeUp(wxSpinEvent& event)
{
    tx = +Pas_G;
    OnSpinButton_XGChange(event);
}

void TranslationPanel::OnSpinButton_XGChangeDown(wxSpinEvent& event)
{
    tx = -Pas_G;
    OnSpinButton_XGChange(event);
}

void TranslationPanel::OnSpinButton_XGChange(wxSpinEvent& event)
{
    ty = tz = 0.0;
    Pas_XG += tx ;
    tx     -= Pas_XF;               // Tenir compte d'un Pas_XF précédent
    Pas_XF  = 0.0;
    Pas_X   = Pas_XG;
    wxTexte.Printf(format_1,Pas_XG);
    TextCtrl_XG->SetValue(wxTexte);
    TextCtrl_XF->SetValue(wxTexte);
    SpinButton_XG->SetValue(0);     // Par précaution, mais la valeur ne sert plus directement
    SpinButton_XF->SetValue(0);     // Idem
    event.Skip();                   // Utile ?
    Appliquer_Translation(tx, ty, tz);
}

void TranslationPanel::OnSpinButton_XFChangeUp(wxSpinEvent& event)
{
    tx = +Pas_F;
    OnSpinButton_XFChange(event);
}

void TranslationPanel::OnSpinButton_XFChangeDown(wxSpinEvent& event)
{
    tx = -Pas_F;
    OnSpinButton_XFChange(event);
}

void TranslationPanel::OnSpinButton_XFChange(wxSpinEvent& event)
{
    ty = tz = 0.0;
    Pas_XF += tx ;
    Pas_X   = Pas_XG + Pas_XF;      // Pour afficher le déplacement total en X dans TextCtrl_XF
    wxTexte.Printf(format_2,Pas_X);
    TextCtrl_XF->SetValue(wxTexte);
    SpinButton_XF->SetValue(0);     // Par précaution, mais la valeur ne sert plus directement
    event.Skip();                   // Utile ?
    Appliquer_Translation(tx, ty, tz);
}

void TranslationPanel::OnSpinButton_YGChangeUp(wxSpinEvent& event)
{
    ty = +Pas_G;
    OnSpinButton_YGChange(event);
}

void TranslationPanel::OnSpinButton_YGChangeDown(wxSpinEvent& event)
{
    ty = -Pas_G;
    OnSpinButton_YGChange(event);
}

void TranslationPanel::OnSpinButton_YGChange(wxSpinEvent& event)
{
    tx = tz = 0.0;
    Pas_YG += ty ;
    ty     -= Pas_YF;
    Pas_YF  = 0.0;
    Pas_Y   = Pas_YG;
    wxTexte.Printf(format_1,Pas_YG);
    TextCtrl_YG->SetValue(wxTexte);
    TextCtrl_YF->SetValue(wxTexte);
    SpinButton_YG->SetValue(0);
    SpinButton_YF->SetValue(0);
    event.Skip();
    Appliquer_Translation(tx, ty, tz);
}

void TranslationPanel::OnSpinButton_YFChangeUp(wxSpinEvent& event)
{
    ty = +Pas_F;
    OnSpinButton_YFChange(event);
}

void TranslationPanel::OnSpinButton_YFChangeDown(wxSpinEvent& event)
{
    ty = -Pas_F;
    OnSpinButton_YFChange(event);
}

void TranslationPanel::OnSpinButton_YFChange(wxSpinEvent& event)
{
    tx = tz = 0.0;
    Pas_YF += ty ;
    Pas_Y   = Pas_YG + Pas_YF;
    wxTexte.Printf(format_2,Pas_Y);
    TextCtrl_YF->SetValue(wxTexte);
    SpinButton_YF->SetValue(0);
    event.Skip();
    Appliquer_Translation(tx, ty, tz);
}

void TranslationPanel::OnSpinButton_ZGChangeUp(wxSpinEvent& event)
{
    tz = +Pas_G;
    OnSpinButton_ZGChange(event);
}

void TranslationPanel::OnSpinButton_ZGChangeDown(wxSpinEvent& event)
{
    tz = -Pas_G;
    OnSpinButton_ZGChange(event);
}

void TranslationPanel::OnSpinButton_ZGChange(wxSpinEvent& event)
{
    tx = ty = 0.0;
    Pas_ZG += tz ;
    tz     -= Pas_ZF;
    Pas_ZF  = 0.0;
    Pas_Z   = Pas_ZG;
    wxTexte.Printf(format_1,Pas_ZG);
    TextCtrl_ZG->SetValue(wxTexte);
    TextCtrl_ZF->SetValue(wxTexte);
    SpinButton_ZG->SetValue(0);
    SpinButton_ZF->SetValue(0);
    event.Skip();
    Appliquer_Translation(tx, ty, tz);
}

void TranslationPanel::OnSpinButton_ZFChangeUp(wxSpinEvent& event)
{
    tz = +Pas_F;
    OnSpinButton_ZFChange(event);
}

void TranslationPanel::OnSpinButton_ZFChangeDown(wxSpinEvent& event)
{
    tz = -Pas_F;
    OnSpinButton_ZFChange(event);
}

void TranslationPanel::OnSpinButton_ZFChange(wxSpinEvent& event)
{
    tx = ty = 0.0;
    Pas_ZF += tz ;
    Pas_Z   = Pas_ZG + Pas_ZF;
    wxTexte.Printf(format_2,Pas_Z);
    TextCtrl_ZF->SetValue(wxTexte);
    SpinButton_ZF->SetValue(0);
    event.Skip();
    Appliquer_Translation(tx, ty, tz);
}

void TranslationPanel::OnTextCtrl_PasFinText(wxCommandEvent& event)
{
    // Pour une éventuelle entrée directe (à valider par un return ?) => Bouton Valider n'est pas nécessaire !
    Pas_F = wxAtof(TextCtrl_PasFin->GetValue());
}

void TranslationPanel::OnTextCtrl_PasGrossierText(wxCommandEvent& event)
{
    Pas_G = wxAtof(TextCtrl_PasGrossier->GetValue());
}

void TranslationPanel::Appliquer_Translation(double tx, double ty, double tz)
{
    BddInter *Element = MAIN->Element;

    Sommet *sommet_courant;
    Object *objet_courant;
    std::vector<int> NumerosSommets;
    unsigned int o, i, j, n_val;
    int indice;
    if (Element->mode_selection == Element->selection_objet) {
        if (Element->listeObjets.empty()) {
            wxMessageDialog *query = new wxMessageDialog(NULL, _T("Aucun Objet sélectionné !"), _T("Avertissement"),
                                                 wxOK | wxICON_INFORMATION ); // Avec l'icône wxICON_QUESTION, l'affichage reste silencieux (wxICON_INFORMATION + logique, mais bruyant !!)
            query->ShowModal();
            query->Destroy();
            return;
        }
        auto it = Element->listeObjets.begin();
        for (i=0; i<Element->listeObjets.size(); i++, it++) {
            for (j=0; j<Element->Objetlist[*it].Sommetlist.size(); j++) {
                sommet_courant = &(Element->Objetlist[*it].Sommetlist[j]);
                sommet_courant->point[0] += tx;
                sommet_courant->point[1] += ty;
                sommet_courant->point[2] += tz;
            }
        }

        // Rien à faire sur les normales car elles ne changent pas sur un objet complet

    } else if(Element->mode_selection == Element->selection_facette) {

        for (o=0; o<Element->Objetlist.size(); o++) {               // Traiter les objets indépendamment
            Element->listePoints.clear();
            objet_courant = &(Element->Objetlist[o]);
            for (i=0; i<objet_courant->Nb_facettes; i++) {
                if (objet_courant->Facelist[i].selected) {          // Ne prendre en compte que les facettes sélectionnées
                    // Récupérer la liste des sommets de la facette. Ranger dans listePoints sans compter les sommets communs à plusieurs facettes
                    NumerosSommets = objet_courant->Facelist[i].getF_sommets();
                    for (j=0; j<NumerosSommets.size(); j++) {
                        indice = NumerosSommets[j] -1;
                        auto jt = std::find(Element->listePoints.begin(),Element->listePoints.end(),indice);    // Ce sommet est-il déjà dans la liste ?
                        if (jt == Element->listePoints.end() || Element->listePoints.empty()) {                     // Non
                            Element->listePoints.push_front(indice);                                                // L'ajouter à la liste des points
                        }
                    }
                }
            }
            // Établir en même temps la liste des facettes qui utilisent ces sommets
            n_val   = Element->listePoints.size();
            if (n_val == 0) continue;   // Passer à l'objet suivant si la liste est vide
            auto jt = Element->listePoints.begin();
            Element->listeFacettes.clear();
            for (j=0; j<n_val; j++, jt++) {
                sommet_courant = &(objet_courant->Sommetlist[*jt]);
                sommet_courant->point[0] += tx;                          // Translation des sommets
                sommet_courant->point[1] += ty;
                sommet_courant->point[2] += tz;
                unsigned int n_fac = objet_courant->Pointslist[*jt].IndicesFacettes.size();
                for (i=0; i<n_fac; i++) {
                    indice  = objet_courant->Pointslist[*jt].IndicesFacettes[i];
                    auto ft = std::find(Element->listeFacettes.begin(),Element->listeFacettes.end(),indice);// La facette est-elle déjà dans la liste ?
                    if (ft == Element->listeFacettes.end() || Element->listeFacettes.empty()) {                 // Non
                        Element->listeFacettes.push_front(indice);                                              // L'ajouter à la liste des facettes
                    }
                }
            }
            // Recalculer les normales aux barycentres des facettes de la liste
            n_val   = Element->listeFacettes.size();
            auto ft = Element->listeFacettes.begin();
            for (i=0; i<n_val; i++, ft++) {
                Element->Calcul_Normale_Barycentre(o,*ft);
                // Compléter la liste des sommets avec tous ceux de chaque facette de la liste
                NumerosSommets = objet_courant->Facelist[*ft].getF_sommets();
                for (j=0; j<NumerosSommets.size(); j++) {
                    indice = NumerosSommets[j] -1;
                    auto jt = std::find(Element->listePoints.begin(),Element->listePoints.end(),indice);    // Ce sommet est-il déjà dans la liste ?
                    if (jt == Element->listePoints.end() || Element->listePoints.empty()) {                     // Non
                        Element->listePoints.push_front(indice);                                                // L'ajouter à la liste des points
                    }
                }
            }
            // Recalculer la normale en chacun des sommets de la nouvelle liste des sommets complétée
            if (objet_courant->Nb_vecteurs != 0) {  // Ne rien faire s'il n'y a pas déjà de normales aux sommets
                n_val = Element->listePoints.size();
                jt    = Element->listePoints.begin();
                for (j=0; j<n_val; j++, jt++) Element->GenereNormale_1_Sommet(objet_courant,*jt,*jt); // Attention ici, les "vecteurs" doivent exister
            }
        }
        Element->listePoints.clear();
        Element->listeFacettes.clear();
    } else {
        // Ici on est en mode_point
        for (o=0; o<Element->Objetlist.size(); o++) {               // Traiter les objets indépendamment
            Element->listePoints.clear();
            objet_courant = &(Element->Objetlist[o]);
            for (i=0; i<objet_courant->Nb_sommets; i++) {
                if (objet_courant->Sommetlist[i].selected) {        // Ne prendre en compte que les sommets sélectionnés
                    auto jt = std::find(Element->listePoints.begin(),Element->listePoints.end(),i);     // Ce sommet est-il déjà dans la liste ?
                    if (jt == Element->listePoints.end() || Element->listePoints.empty()) {                 // Non
                        Element->listePoints.push_front(i);                                                 // L'ajouter à la liste des points
                    }
                }
            }
            // Établir en même temps la liste des facettes qui utilisent ces sommets
            n_val   = Element->listePoints.size();
            if (n_val == 0) continue;   // Passer à l'objet suivant si la liste est vide
            auto jt = Element->listePoints.begin();
            Element->listeFacettes.clear();
            for (j=0; j<n_val; j++, jt++) {
                sommet_courant = &(objet_courant->Sommetlist[*jt]);
                sommet_courant->point[0] += tx;                          // Translation des sommets
                sommet_courant->point[1] += ty;
                sommet_courant->point[2] += tz;
                unsigned int n_fac = objet_courant->Pointslist[*jt].IndicesFacettes.size();
                for (i=0; i<n_fac; i++) {
                    indice  = objet_courant->Pointslist[*jt].IndicesFacettes[i];
                    auto ft = std::find(Element->listeFacettes.begin(),Element->listeFacettes.end(),indice);// La facette est-elle déjà dans la liste ?
                    if (ft == Element->listeFacettes.end() || Element->listeFacettes.empty()) {                 // Non
                        Element->listeFacettes.push_front(indice);                                              // L'ajouter à la liste des facettes
                    }
                }
            }
            // Recalculer les normales aux barycentres des facettes de la liste
            n_val   = Element->listeFacettes.size();
            auto ft = Element->listeFacettes.begin();
            for (i=0; i<n_val; i++, ft++) {
                Element->Calcul_Normale_Barycentre(o,*ft);
                // Compléter la liste des sommets avec tous ceux de chaque facette de la liste
                NumerosSommets = objet_courant->Facelist[*ft].getF_sommets();
                for (j=0; j<NumerosSommets.size(); j++) {
                    indice = NumerosSommets[j] -1;
                    auto jt = std::find(Element->listePoints.begin(),Element->listePoints.end(),indice);    // Ce sommet est-il déjà dans la liste ?
                    if (jt == Element->listePoints.end() || Element->listePoints.empty()) {                     // Non
                        Element->listePoints.push_front(indice);                                                // L'ajouter à la liste des points
                    }
                }
            }
            // Recalculer la normale en chacun des sommets de la nouvelle liste des sommets complétée
            if (objet_courant->Nb_vecteurs != 0) {  // Ne rien faire s'il n'y a pas déjà de normales aux sommets
                n_val = Element->listePoints.size();
                jt    = Element->listePoints.begin();
                for (j=0; j<n_val; j++, jt++) Element->GenereNormale_1_Sommet(objet_courant,*jt,*jt); // Attention ici, les "vecteurs" doivent exister
            }
        }
        Element->listePoints.clear();
        Element->listeFacettes.clear();
    }

    Element->bdd_modifiee = true;
    Element->m_gllist = 0;
    Element->searchMin_Max();
    Element->Refresh();
}

void TranslationPanel::OnButton_OKClick(wxCommandEvent& event)
{
    wxCloseEvent close_event;
    OnClose(close_event);
}

void TranslationPanel::OnButton_AnnulerClick(wxCommandEvent& event)
{
    Appliquer_Translation(-Pas_X, -Pas_Y, -Pas_Z);  // Remettre dans l'état initial
    wxCloseEvent close_event;
    OnClose(close_event);
}

//void TranslationPanel::ToDo()
//{
//    wxMessageDialog *query = new wxMessageDialog(NULL, _T("Pas encore opérationnel\nSimulation interface OK"), _T("Avertissement"),
//                                                 wxOK | wxICON_INFORMATION ); // Avec l'icône wxICON_QUESTION, l'affichage reste silencieux (wxICON_INFORMATION + logique, mais bruyant !!)
//    query->ShowModal();
//    query->Destroy();
//}
