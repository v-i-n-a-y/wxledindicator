#include "led_widget.h"

Led::Led(wxWindow *parent, wxWindowID id, wxPoint Position, int Size, char color)
    : wxWindow(parent, id, Position, wxSize(Size,Size),wxTRANSPARENT_WINDOW,'R')
{
    m_parent = parent;
    Connect(wxEVT_PAINT, wxPaintEventHandler(Led::OnPaint));
    col = color;
    SetWindowStyleFlag(wxTRANSPARENT_WINDOW);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
}

void Led::SetStatus(bool status)
{
    FlagStatus = status;    
    Refresh();
}

void Led::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);

    wxGraphicsContext *gc = wxGraphicsContext::Create(dc);

    D1 = GetClientSize().GetX();

    // Generar paradas de la gradiente
    wxGraphicsGradientStops stops;

    if(FlagStatus)
    {
        switch(col)
        {
            case 'r':
            case 'R':   stops.Add(wxColor(255,255,255),0.0f);
                        stops.Add(wxColor(255,0,0),1.0f);
                        break;

            case 'g':
            case 'G':   stops.Add(wxColor(255,255,255),0.0f);
                        stops.Add(wxColor(0,255,0),1.0f);
                        break;

            case 'b':
            case 'B':   stops.Add(wxColor(255,255,255),0.0f);
                        stops.Add(wxColor(0,0,255),1.0f);
                        break;

            case 'y':
            case 'Y':   stops.Add(wxColor(255,255,255),0.0f);
                        stops.Add(wxColor(255,255,0),1.0f);
                        break;

            default :   stops.Add(wxColor(255,255,255),0.0f);
                        stops.Add(wxColor(255,0,0),1.0f);
                        break;
        }
    }
    else
    {
        switch(col)
        {
            case 'r':
            case 'R':   stops.Add(wxColor(128,0,0),0.0f);
                        stops.Add(wxColor(0,0,0),1.0f);
                        break;

            case 'g':
            case 'G':   stops.Add(wxColor(0,128,0),0.0f);
                        stops.Add(wxColor(0,0,0),1.0f);
                        break;

            case 'b':
            case 'B':   stops.Add(wxColor(0,0,128),0.0f);
                        stops.Add(wxColor(0,0,0),1.0f);
                        break;

            case 'y':
            case 'Y':   stops.Add(wxColor(128,128,0),0.0f);
                        stops.Add(wxColor(0,0,0),1.0f);
                        break;

            default :   stops.Add(wxColor(128,0,0),0.0f);
                        stops.Add(wxColor(0,0,0),1.0f);
                        break;
        }
    }
    
    gc->SetPen(wxPen(wxColor(0,0,0), 1, wxTRANSPARENT));
    gc->SetBrush(gc->CreateLinearGradientBrush(0,0,D1,D1,wxColor(35,35,35),wxColor(180,180,180)));
    gc->DrawEllipse(0,0,D1,D1);

    D2 = (2*D1)/3;
    x1 = D1/6;
    y1 = x1;

    gc->SetBrush(gc->CreateRadialGradientBrush(D1/2,D1/2,D1/2,D1/2,D2/2,stops));
    gc->DrawEllipse(x1,y1,D2,D2);

    delete gc;
}

void Led::SetColor(char color)
{
    col = color;
    Refresh();
}

