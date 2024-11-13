#include<bits/stdc++.h> 
using namespace std;

class Image{
    private:
        int width,height;
        vector<vector<int>>pixels;

    public:
        Image(int w,int h):width(w),height(h),pixels(h,vector<int>(w,255)){}

        void loadFromFile(const string&filename){
            ifstream file(filename);
            if(!file.is_open()){
                cerr<<"Error:Could not open the file!"<<endl;
                return;
            }
            file>>width>>height;
            pixels.resize(height,vector<int>(width));
            for(int i=0;i<height;++i){
                for(int j=0;j<width;++j){
                    file>>pixels[i][j];
                }
            }
            file.close();
        }

        void saveToFile(const string&filename)const{
            ofstream file(filename);
            file<<width<<" "<<height<<"\n";
            for(int i=0;i<height;++i){
                for(int j=0;j<width;++j){
                    file<<pixels[i][j]<<" ";
                }
                file<<"\n";
            }
            file.close();
        }

        void applyGrayscale(){
            for(int i=0;i<height;++i){
                for(int j=0;j<width;++j){
                    int gray=pixels[i][j];
                    pixels[i][j]=gray;
                }
            }
            cout<<"Applied grayscale.\n";
        }

        void applyBlur(int kernelSize=3){
            vector<vector<int>>temp=pixels;
            int offset=kernelSize/2;
            for(int i=offset;i<height-offset;++i){
                for(int j=offset;j<width-offset;++j){
                    int sum=0;
                    for(int ki=-offset;ki<=offset;++ki){
                        for(int kj=-offset;kj<=offset;++kj){
                            sum+=temp[i+ki][j+kj];
                        }
                    }
                    pixels[i][j]=sum/(kernelSize*kernelSize);
                }
            }
            cout<<"Applied blur.\n";
        }

        void display()const{
            for(const auto&row:pixels){
                for(int pixel:row){
                    cout<<pixel<<" ";
                }
                cout<<"\n";
            }
        }
};

int main(){
    string filename;
    cout<<"Enter the path to your image file (text format):";
    cin>>filename;

    Image img(0,0);
    img.loadFromFile(filename);

    int choice;
    do{
        cout<<"\nBasic Image Processor\n";
        cout<<"1.Apply Grayscale\n";
        cout<<"2.Apply Blur\n";
        cout<<"3.Display Image\n";
        cout<<"4.Save and Exit\n";
        cout<<"Choose an option:";
        cin>>choice;

        switch(choice){
            case 1:
                img.applyGrayscale();
                break;
            case 2:
                img.applyBlur();
                break;
            case 3:
                img.display();
                break;
            case 4:
                cout<<"Saving and exiting...\n";
                img.saveToFile("output_image.txt");
                break;
            default:
                cout<<"Invalid option.Please try again.\n";
        }
    }while(choice!=4);

    return 0;
}
