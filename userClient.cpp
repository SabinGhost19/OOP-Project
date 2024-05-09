#include "userClient.h"

UserClient::UserClient() {}

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
void UserClient::AddToCart(float price){
    this->current_command+=price;
}

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
float UserClient::getCommandPrice(){return this->current_command;}
