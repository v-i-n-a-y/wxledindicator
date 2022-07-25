#include <wx/wx.h>
#include <wx/graphics.h>

class Led : public wxWindow
{
    public:
        Led(wxWindow *parent, wxWindowID id, wxPoint Position, int Size, char color);
        wxWindow *m_parent;

        char col;
        int x0,y0,x1,y1,D1,D2;
        bool FlagStatus = false;

        void SetStatus(bool status);
        void OnPaint(wxPaintEvent& event);
        void SetColor(char color);
};
