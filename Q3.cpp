#include <iostream>
#include <vector>

class SpinningKey{

public:
    int headOffset=0;
    std::vector<int> posssibleValues;
    void moveHeadOffset(int offsetVal){
        this->headOffset+=offsetVal;


        if(this->headOffset>=posssibleValues.size())
            this->headOffset%=(int)posssibleValues.size();
        while(this->headOffset<0)
            this->headOffset+=this->posssibleValues.size();
    }
    int readValue(){
        return posssibleValues[headOffset];
    }
    SpinningKey(std::vector<int> *possibleValues){
        this->posssibleValues=*possibleValues;
        this->headOffset=0;
    }
    SpinningKey(){
        headOffset=0;

    }
};
int main() {
    int spinnerCount,valuesPerSpinner;
    std::cin>>spinnerCount>>valuesPerSpinner;
    std::vector<SpinningKey> keys(spinnerCount);
    int temp;
    for(int i=0;i<spinnerCount;++i)
    {
        auto tempVec=new std::vector<int>(valuesPerSpinner);
        for(int j=0;j<valuesPerSpinner;++j)
            std::cin>>(*tempVec)[j];
        keys[i]=SpinningKey(tempVec);
    }
    int guideCount;
    std::cin>>guideCount;
    auto guideSpinnerValues=new std::vector<int>(guideCount);
    for(int i=0;i<guideCount;++i)
        std::cin>>(*guideSpinnerValues)[i];
    SpinningKey guideSpin(guideSpinnerValues);
    int moveCount;
    std::cin>>moveCount;
    int i=0;
    for(;i<moveCount;i++)
    {
        SpinningKey& activeSpinner=keys[i%spinnerCount];
        activeSpinner.moveHeadOffset(guideSpin.readValue());
        guideSpin.moveHeadOffset(1);
    }
    int until=i%spinnerCount;
    for(i=until;i<spinnerCount;i++)
        std::cout<<keys[i].readValue();
    for(i=0;i<until;i++)
        std::cout<<keys[i].readValue();

    return 0;
}