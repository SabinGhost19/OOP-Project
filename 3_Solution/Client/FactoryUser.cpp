#include "FactoryUser.h"
#include <sstream>


FactoryUser::FactoryUser() {


}
void FactoryUser::Initializing(){
    UserRequest userReq;
    userReq.Answer();
    userReq.Answer();
    if(strcmp(userReq.answer,"0")==0){
        this->rol=0;
    }else if(strcmp(userReq.answer,"1")){
        this->rol=1;
    }else if(strcmp(userReq.answer,"2")){
        this->rol=2;
   }
}
void FactoryUser::setRol(int rol_param){
    this->rol=rol_param;
}


UserCompany*FactoryUser::ConstrucCompanytUser(int ID){

    std::vector<std::string> vec=this->new_request->GetCredentials();

    //parsare si introducere stringuri




    // // Folosim std::stringstream pentru a separa datele
    // std::stringstream ss(credentials);
    // std::string token;

    // // Folosim std::getline pentru a extrage fiecare token pe baza delimitatorului '#'
    // std::getline(ss, id, '#');
    // std::getline(ss, rol, '#');
    // std::getline(ss, email, '#');
    // std::getline(ss, parola, '#');
    // std::getline(ss, nume, '#');

    // std::getline(ss, codPostal, '#');
    // std::getline(ss, tara, '#');
    // std::getline(ss, judet, '#');
    // std::getline(ss, oras, '#');
    // std::getline(ss, strada, '#');
    // std::getline(ss, numar, '#');
    // std::getline(ss, scara, '#');
    // std::getline(ss, NrApartament, '#');

    std::string id,rol,email, parola,
        nume, codPostal, tara,judet,oras, strada,
        numar,scara,NrApartament,total_profit;

    id=vec[0];
    rol=vec[1];
    email=vec[2];
    parola=vec[3];
    nume=vec[4];

    codPostal=vec[5];
    tara=vec[6];
    judet=vec[7];
    oras=vec[8];
    strada=vec[9];
    numar=vec[10];
    scara=vec[11];
    NrApartament=vec[12];
    total_profit=vec[13];

    this->new_request->Clear();

    //afisare pt debugging
    std::cout << "Email: " << email << std::endl;
    std::cout << "Parola: " << parola << std::endl;
    std::cout << "Nume: " << nume << std::endl;
    std::cout << "Tara: " << tara << std::endl;
    std::cout << "Oras: " << oras << std::endl;
    std::cout << "Judet: " << judet << std::endl;
    std::cout << "Strada: " << strada << std::endl;
    std::cout << "Numar: " << numar << std::endl;
    std::cout << "Cod Postal: " << codPostal << std::endl;

    UserCompany*new_user=new UserCompany();

    new_user->setEmail(email);
    new_user->setParola(parola);
    new_user->setNume(nume);
    new_user->setTara(tara);
    new_user->setOras(oras);
    new_user->setJudet(judet);
    new_user->setStrada(strada);
    new_user->setNumar(numar);
    new_user->setCodPostal(codPostal);
    new_user->setScara(scara);
    new_user->setNrApp(NrApartament);
    new_user->setProfit(total_profit);


    return new_user;


}

UserClient*FactoryUser::ConstrucClienttUser(int ID){

    std::vector<std::string> vec=this->new_request->GetCredentials();

    //parsare si introducere stringuri

    std::string id,rol,email, parola,
        nume, prenume, telefon, dataNasterii,codPostal, tara,judet,oras, strada,
        numar, scara, numarApartament,
        codPostal_F, tara_F,judet_F,oras_F, strada_F,
        numar_F, scara_F, numarApartament_F;

    // Folosim std::stringstream pentru a separa datele
    // std::stringstream ss(credentials);
    // std::string token;

    // // Folosim std::getline pentru a extrage fiecare token pe baza delimitatorului '#'
    // std::getline(ss, id, '#');
    // std::getline(ss, rol, '#');
    // std::getline(ss, email, '#');
    // std::getline(ss, parola, '#');
    // std::getline(ss, nume, '#');
    // std::getline(ss, prenume, '#');
    // std::getline(ss, telefon, '#');
    // std::getline(ss, dataNasterii, '#');

    // std::getline(ss, codPostal, '#');
    // std::getline(ss, tara, '#');
    // std::getline(ss, judet, '#');
    // std::getline(ss, oras, '#');
    // std::getline(ss, strada, '#');
    // std::getline(ss, numar, '#');
    // std::getline(ss, scara, '#');
    // std::getline(ss, numarApartament, '#');

    // std::getline(ss, codPostal_F, '#');
    // std::getline(ss, tara_F, '#');
    // std::getline(ss, judet_F, '#');
    // std::getline(ss, oras_F, '#');
    // std::getline(ss, strada_F, '#');
    // std::getline(ss, numar_F, '#');
    // std::getline(ss, scara_F, '#');
    // std::getline(ss, numarApartament_F, '#');

    // //afisare pt debugging

    id=vec[0];
    rol=vec[1];
    email=vec[2];
    parola=vec[3];
    nume=vec[4];
    prenume=vec[5];
    telefon=vec[6];
    dataNasterii=vec[7];
    codPostal=vec[8];
    tara=vec[9];
    judet=vec[10];
    oras=vec[11];
    strada=vec[12];
    numar=vec[13];
    scara=vec[14];
    numarApartament=vec[15];

    codPostal_F=vec[16];
    tara_F=vec[17];
    judet_F=vec[18];
    oras_F=vec[19];
    strada_F=vec[20];
    numar_F=vec[21];
    scara_F=vec[22];
    numarApartament_F=vec[23];

    this->new_request->Clear();

    std::cout << "Email: " << email << std::endl;
    std::cout << "Parola: " << parola << std::endl;
    std::cout << "Nume: " << nume << std::endl;
    std::cout << "Prenume: " << prenume << std::endl;
    std::cout << "Telefon: " << telefon << std::endl;
    std::cout << "Data Nasterii: " << dataNasterii << std::endl;
    std::cout << "Tara: " << tara << std::endl;
    std::cout << "Oras: " << oras << std::endl;
    std::cout << "Judet: " << judet << std::endl;
    std::cout << "Strada: " << strada << std::endl;
    std::cout << "Scara: " << scara << std::endl;
    std::cout << "Numar: " << numar << std::endl;
    std::cout << "Numar Apartament: " << numarApartament << std::endl;
    std::cout << "Cod Postal: " << codPostal << std::endl;

    UserClient*new_user=new UserClient();

    new_user->setEmail(email);
    new_user->setParola(parola);
    new_user->setNume(nume);
    new_user->setPrenume(prenume);
    new_user->setTelefon(telefon);
    new_user->setDataNasterii(dataNasterii);
    new_user->setTara(tara);
    new_user->setOras(oras);
    new_user->setJudet(judet);
    new_user->setStrada(strada);
    new_user->setScara(scara);
    new_user->setNumar(numar);
    new_user->setNumarApartament(numarApartament);
    new_user->setCodPostal(codPostal);

    new_user->setTara_F(tara_F);
    new_user->setOras_F(oras_F);
    new_user->setJudet_F(judet_F);
    new_user->setStrada_F(strada_F);
    new_user->setScara_F(scara_F);
    new_user->setNumar_F(numar_F);
    new_user->setNumarApartament_F(numarApartament_F);
    new_user->setCodPostal_F(codPostal_F);

   return new_user;

}

void FactoryUser::ConstructUser(){

    UserRequest*new_request=nullptr;

    if(this->rol==1){
    this->new_request=new UserRequest("1");
    this->new_request->setCredentialSize(14);
    this->new_request->Request();
    //this->ConstrucCompanytUser(1);

    }
    else if(this->rol==0){
    this->new_request=new UserRequest("0");
    this->new_request->setCredentialSize(24);
    this->new_request->Request();
    //this->ConstrucClienttUser(0);

    }
}
