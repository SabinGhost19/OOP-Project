#include "FactoryUser.h"
#include"UserClientRequest.h"
#include <sstream>

FactoryUser::FactoryUser() {}


UserClient*FactoryUser::ConstructClientUser(int ID){

    UserRequest*new_request=new UserClientRequest(std::to_string(ID));
    new_request->Request();
    std::string credentials=new_request->GetCredentials();

    //parsare si introducere stringuri

    std::string email, parola, nume, prenume, telefon, dataNasterii, tara, oras, judet, strada, scara, numar, numarApartament, codPostal;

    // Folosim std::stringstream pentru a separa datele
    std::stringstream ss(credentials);
    std::string token;

    // Folosim std::getline pentru a extrage fiecare token pe baza delimitatorului '#'
    std::getline(ss, email, '#');
    std::getline(ss, parola, '#');
    std::getline(ss, nume, '#');
    std::getline(ss, prenume, '#');
    std::getline(ss, telefon, '#');
    std::getline(ss, dataNasterii, '#');
    std::getline(ss, tara, '#');
    std::getline(ss, oras, '#');
    std::getline(ss, judet, '#');
    std::getline(ss, strada, '#');
    std::getline(ss, scara, '#');
    std::getline(ss, numar, '#');
    std::getline(ss, numarApartament, '#');
    std::getline(ss, codPostal, '#');

    //afisare pt debugging
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

    return new_user;
}
