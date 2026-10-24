#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

using namespace std;

class Kisi{
    protected:
        int kimlik_no;
        string ad_soyad;
        int yas;

    public:
        Kisi(int k, string ad, int y){
            kimlik_no = k;
            ad_soyad = ad;
            yas = y;
        }
        int getKimlik(){
            return kimlik_no;
        }  
        virtual ~Kisi(){
            cout << "Kisi silindi" << endl;
        }
        virtual void bilgiYazdir() = 0;
        virtual double Maas() = 0;
};
class Hasta : public Kisi{
    private:
        string tani;
        double tedavi_ucret;
    
    public:
        Hasta(int k, string ad, int y, string t, double tu) : Kisi(k, ad, y){
            tani = t;
            tedavi_ucret = tu;
        }
        void bilgiYazdir() override{
            cout << "Kimlik no: " << kimlik_no << endl << "Ad soyad: " << ad_soyad << endl << "Yas: " << yas << endl << "Tani: " << tani << endl << "Tedavi ucreti: " << tedavi_ucret << endl;
        }
        double Maas() override{
            return tedavi_ucret;
        }
};
class Doktor : public Kisi{
    private:
        string uzmanlik;
        double maas_d;
    
    public:
        Doktor(int k, string ad, int y, string u, double m) : Kisi(k, ad, y){
            uzmanlik = u;
            maas_d = m;
        }
        double Maas() override{
            return maas_d;
        }
        void bilgiYazdir() override{
            cout << "Kimlik no: " << kimlik_no << endl << "Ad soyad: " << ad_soyad << endl << "Yas: " << yas << endl << "Uzmanlik: " << uzmanlik << endl << "Maas: " << maas_d << endl;
        }
};
class Hemsire : public Kisi{
    private:
        string vardiya;
        double maas_h;
        
    public:
        Hemsire(int k, string ad, int y, string v, double m): Kisi(k, ad, y){
            vardiya = v;
            maas_h = m;
        }
        double Maas() override{
            return maas_h;
        }
        void bilgiYazdir() override{
            cout << "Kimlik no: " << kimlik_no << endl << "Ad soyad: " << ad_soyad << endl << "Yas: " << yas << endl << "Vardiya: " << vardiya << endl << "Maas: " << maas_h << endl;    
        }
};

int main() {
    vector<Kisi*> kisiler;
    kisiler.push_back(new Doktor(12423, "Ahmet", 29, "Kardiyoloji", 120000));
    kisiler.push_back(new Hemsire(34423, "Sıla", 34, "Gece", 100000));
    kisiler.push_back(new Doktor(24292, "Elif", 25, "Ortopedi", 135000));
    kisiler.push_back(new Hasta(32832, "Mehmet", 40, "Kırık", 20000));
    
    for(size_t i=0;i<kisiler.size();i++){
        kisiler[i] -> bilgiYazdir();
    }
    size_t maas = 0;
    for(size_t a=0;a<kisiler.size();a++){
        if(kisiler[a]->Maas() > kisiler[maas]->Maas()){
            maas = a;
        }
    }
    cout << "En fazla maasa sahip kisi: " << endl;
    kisiler[maas]->bilgiYazdir();

    int kimlik_no = 0;
    cout << "Kimlik numarasi girin: " << endl;
    cin >> kimlik_no;

    bool bulundu = false;
    for(size_t b =0;b<kisiler.size();b++){
        if(kisiler[b]->getKimlik() == kimlik_no){
            kisiler[b]->bilgiYazdir();
            bulundu = true;
            break;
        }
    }
    if(!bulundu){
        cout << "Kimlik bulunamadi!" << endl;
    }
    try{
        double maas_;
        cout << "Bir maas miktari girin: " << endl;
        cin >> maas_;
        if(maas_ < 0){
            throw invalid_argument("Maas negatif olamaz");
        }
        for(size_t c=0;c<kisiler.size();c++){
            if(kisiler[c]->Maas() < maas_){
                kisiler[c]->bilgiYazdir();
            }
        }
    }
    catch(const invalid_argument& e){
        cout << "Aralik hatasi!" << e.what() << endl;
    }
    
    for(size_t i=0;i<kisiler.size();i++){
        delete kisiler[i];
    }

    return 0;
}

