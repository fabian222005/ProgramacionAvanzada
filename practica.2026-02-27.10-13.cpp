#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define PROPORTION_16_9 16.0f/9.0f

class display_properties{
    public:
        display_properties(int x_pix,int y_pix, string MonitorName, int range = 256){
            x_pixels = x_pix;
            y_pixels = y_pix;
            color_bitDepth = int(sqrt(range)); // 8, 16 bits
            m_name = MonitorName;
        }
        display_properties(int x_pix,int proportion, string MonitorName, int range = 256){
            x_pixels = x_pix;
            y_pixels = x_pix * proportion;
            color_bitDepth = int(sqrt(range)); // 8, 16 bits
            m_name = MonitorName;
        }
        void get_display_properties();
    private:
        uint x_pixels;
        uint y_pixels;
        uint color_bitDepth;
        string m_name;
};
void display_properties::get_display_properties(){
    cout << "Nombre del Monitor: "<<m_name<<endl;
    cout << "Resolución: "<<x_pixels << "px x "<<y_pixels <<"px"<<endl;
    cout << "Bits: "<<color_bitDepth<<endl;
}

int main(){

    display_properties DELL(1440,720,"DELL FHD 15inch Monitor");

    DELL.get_display_properties();
}