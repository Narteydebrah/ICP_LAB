#include<fstream>
#include<vector>
#include<iostream>
#include<iterator>
#include <algorithm>
#include "block.h"
using namespace std;

class rectBlocks{
 public:
vector<Rect> dime;
vector<Rect> Blocks(ifstream& file) {
if(file.is_open()){
Rect block;
while(!file.eof()){
file>>block.width >>block.height >>block.length;
dime.push_back(block);
}

}return dime;
}};

class sqrBaseRectBlocks: public rectBlocks{
public:
vector<baserectblocks> sqrd;
vector<baserectblocks>bsqrblocks(vector<Rect>var){
for(Rect x:var){
if(x.width==x.height){
    baserectblocks basesqr;
    basesqr.width=x.width;
    basesqr.length=x.length;
    sqrd.push_back(basesqr);}}
    return sqrd;
}
};

class cuboidblocks : public sqrBaseRectBlocks {
public:
    vector<cuboid>cubeblocks;
    vector<cuboid>basecube(vector<baserectblocks>var){
 for(baserectblocks x:var){
    if(x.width==x.length){
        cuboid cubeblock;
        cubeblock.length=x.length;
        cubeblocks.push_back(cubeblock);
    }
 }   return cubeblocks;
    }

};

class cylindricalblocks: public sqrBaseRectBlocks{
public:
    vector<cylinder>cylinderdim;
    void rcylinder(vector<baserectblocks>var){
        for(baserectblocks x: var){
            cylinder cylinderblock;
            cylinderblock.diameter=x.width;
            cylinderblock.height=x.length;
            cylinderdim.push_back(cylinderblock);
        }
        double pi=2*acos(0.0);
        cout<<pi<<endl;
        vector<int>Varea;
        vector <int> Vvolume;
        for(cylinder z:cylinderdim){
            int height=z.height;
            int r=z.diameter/2;
            int area=(2*pi*r*height)+(2*pi*r*r);
            int vol=pi*r*2*height;
            Varea.push_back(area);
            Vvolume.push_back(vol);
        }
        sort(Varea.begin(),Varea.end());
        sort(Vvolume.begin(),Vvolume.end());
        cout <<"The area in ascending order: ";
        for(int q:Varea){
            cout<<q<<" "<<endl;
        }
        cout <<"The volumes in ascending order: ";
        for(int w:Vvolume){
            cout<<w<<" "<<endl;
        };

                     }
    };

    class  sphereBlocks : public cuboidblocks {

public:
   vector<int> spheredim;
   void rsphere(vector<cuboid>var){
   for(cuboid v:var){
    int sStruct;
    sStruct = v.length;
    spheredim.push_back(sStruct);
   }
   sort(spheredim.begin(), spheredim.end());
    double pi = 2 * acos(0.0);
    cout <<"The diameters in ascending order: ";
    for(int e: spheredim){
    cout <<e<<" "<<endl;
   };
   cout<<"The surface areas in ascending order: ";
   for(int e: spheredim){
        int r = e/2;
        int area = 4*pi*r*r; //Calculate for area
        cout << area<<" "<<endl;
                  };
                  cout<<"The surface volume in ascending order: ";
                  for(int e:spheredim){
                    int r=e/2;
                    int vol=4/3*pi*r*r*r;
                    cout<<vol<<" "<<endl;
                  }
}    };



int main(){
ifstream data("dataBlocks.dat");
rectBlocks recc;
vector<Rect> rectDime = recc.Blocks(data);

sqrBaseRectBlocks sqre;
vector<baserectblocks> sqreDime = sqre.bsqrblocks(rectDime);

cuboidblocks cube;
vector<cuboid> cubeDime = cube.basecube(sqreDime);

cylindricalblocks cylinder;
cylinder.rcylinder(sqreDime);

sphereBlocks sphericalblocks;
sphericalblocks.rsphere(cubeDime);
return 0;
}
