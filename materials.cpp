#include <iostream>
using namespace std;

class Material
{
public:
    // Принимает на вход величину деформации.
    // Возвращает величину напряжения, посчитанную с учётом реологии материала.
    virtual float getStress(float strain) = 0;
};

class ElasticMaterial: public Material{
    private:
    float E{};

    public:
    ElasticMaterial(float elasticModulus){
        E = elasticModulus;
    }

    float getStress(float strain){
        return E*strain;
    }
};

class PlasticMaterial: public Material{
    private:
    float E{}, S{};

    public:
    PlasticMaterial(float elasticModulus, float strainLimit){
        E = elasticModulus;
        S = strainLimit;
    }

    float getStress(float strain){
        return strain < S ? strain * E : S * E;
    }
};

int main(){
    Material* m;
    m = new ElasticMaterial(100);
    cout << "Material stress is: " << m->getStress(0.1) << endl;
    delete m;
    m = new PlasticMaterial(100, 0.01);
    cout << "Material stress is: " << m->getStress(0.1) << endl;
    delete m;
}