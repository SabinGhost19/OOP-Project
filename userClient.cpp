#include "userClient.h"

UserClient::UserClient() {}

std::string UserClient::GetRole(){this->rol;}

std::string UserClient::getEmail() {
    return email;
}

std::string UserClient::getParola() {
    return parola;
}

std::string UserClient::getNume() {
    return nume;
}


std::string UserClient::getPrenume() {
    return prenume;
}


std::string UserClient::getTelefon() {
    return telefon;
}


std::string UserClient::getDataNasterii() {
    return dataNasterii;
}


std::string UserClient::getTara() {
    return tara;
}


std::string UserClient::getOras() {
    return oras;
}


std::string UserClient::getJudet() {
    return judet;
}


std::string UserClient::getStrada() {
    return strada;
}


std::string UserClient::getScara() {
    return scara;
}


std::string UserClient::getNumar() {
    return numar;
}


std::string UserClient::getNumarApartament() {
    return numarApartament;
}


std::string UserClient::getCodPostal() {
    return codPostal;
}
std::string UserClient::getTara_F() {
    return tara_F;
}

std::string UserClient::getOras_F() {
    return oras_F;
}

std::string UserClient::getJudet_F() {
    return judet_F;
}

std::string UserClient::getStrada_F() {
    return strada_F;
}

std::string UserClient::getScara_F() {
    return scara_F;
}

std::string UserClient::getNumar_F() {
    return numar_F;
}

std::string UserClient::getNumarApartament_F() {
    return numarApartament_F;
}

std::string UserClient::getCodPostal_F() {
    return codPostal_F;
}


void UserClient::AddToCart(float price){
    this->current_command+=price;
}


void UserClient::SetComment(std::string str){
    this->comment=str;
}
void UserClient::SetNota(std::string str){
    this->nota=str;
}
std::string UserClient::GetComment(){
    return this->comment;
}
std::string UserClient::GetNota(){
    return this->nota;
}

void UserClient::addProductToCart(std::string titlu,std::string price){

    std::pair<std::string, std::string> myPair(titlu, price);
    this->lista_produse.push_back(myPair);
    this->product_count++;
}
int UserClient::GetProductCount(){return this->product_count;}

std::vector<std::pair<std::string,std::string>> UserClient::GetListaProduse(){return this->lista_produse;}

void UserClient::setEmail(const std::string &email) { this->email = email; }
void UserClient::setParola(const std::string &parola) { this->parola = parola; }
void UserClient::setNume(const std::string &nume) { this->nume = nume; }
void UserClient::setPrenume(const std::string &prenume) { this->prenume = prenume; }
void UserClient::setTelefon(const std::string &telefon) { this->telefon = telefon; }
void UserClient::setDataNasterii(const std::string &dataNasterii) { this->dataNasterii = dataNasterii; }

void UserClient::setTara(const std::string &tara) { this->tara = tara; }
void UserClient::setOras(const std::string &oras) { this->oras = oras; }
void UserClient::setJudet(const std::string &judet) { this->judet = judet; }
void UserClient::setStrada(const std::string &strada) { this->strada = strada; }
void UserClient::setScara(const std::string &scara) { this->scara = scara; }
void UserClient::setNumar(const std::string &numar) { this->numar = numar; }
void UserClient::setNumarApartament(const std::string &numarApartament) { this->numarApartament = numarApartament; }
void UserClient::setCodPostal(const std::string &codPostal) { this->codPostal = codPostal; }

void UserClient::setTara_F(const std::string &tara) { this->tara_F = tara; }
void UserClient::setOras_F(const std::string &oras) { this->oras_F = oras; }
void UserClient::setJudet_F(const std::string &judet) { this->judet_F = judet; }
void UserClient::setStrada_F(const std::string &strada) { this->strada_F = strada; }
void UserClient::setScara_F(const std::string &scara) { this->scara_F = scara; }
void UserClient::setNumar_F(const std::string &numar) { this->numar_F = numar; }
void UserClient::setNumarApartament_F(const std::string &numarApartament) { this->numarApartament_F = numarApartament; }
void UserClient::setCodPostal_F(const std::string &codPostal) { this->codPostal_F = codPostal; }


float UserClient::getCommandPrice(){return this->current_command;}
