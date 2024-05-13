#include "userCompany.h"

UserCompany::UserCompany() {}

void UserCompany::setId(const std::string &value) {
    id = value;
}
void UserCompany::setRol(const std::string &value) {
    rol = value;
}
void UserCompany::setEmail(const std::string &value) {
    email = value;
}
void UserCompany::setParola(const std::string &value) {
    parola = value;
}
void UserCompany::setNume(const std::string &value) {
    nume = value;
}
void UserCompany::setCodPostal(const std::string &value) {
    codPostal = value;
}
void UserCompany::setTara(const std::string &value) {
    tara = value;
}
void UserCompany::setJudet(const std::string &value) {
    judet = value;
}
void UserCompany::setOras(const std::string &value) {
    oras = value;
}
void UserCompany::setStrada(const std::string &value) {
    strada = value;
}
void UserCompany::setNumar(const std::string &value) {
    numar = value;
}
void UserCompany::setScara(const std::string &value){
    scara=value;
}
void UserCompany::setNrApp(const std::string &value){
    nrApp=value;
}

// Getteri
std::string UserCompany::getScara() const {
    return scara;
}
std::string UserCompany::getNrApp() const {
    return nrApp;
}
std::string UserCompany::getId() const {
    return id;
}
std::string UserCompany::getRol() const {
    return rol;
}
std::string UserCompany::getEmail() const {
    return email;
}
std::string UserCompany::getParola() const {
    return parola;
}
std::string UserCompany::getNume() const {
    return nume;
}
std::string UserCompany::getCodPostal() const {
    return codPostal;
}
std::string UserCompany::getTara() const {
    return tara;
}
std::string UserCompany::getJudet() const {
    return judet;
}
std::string UserCompany::getOras() const {
    return oras;
}
std::string UserCompany::getStrada() const {
    return strada;
}
std::string UserCompany::getNumar() const {
    return numar;
}
