#ifndef USERCLIENT_H
#define USERCLIENT_H
#include"user.h"
#include<iostream>
#include<string.h>

class UserClient : public User
{
private:


    std::string email;
    std::string parola;
    std::string nume;
    std::string prenume;
    std::string telefon;
    std::string dataNasterii;
    std::string tara;
    std::string oras;
    std::string judet;
    std::string strada;
    std::string scara;
    std::string numar;
    std::string numarApartament;
    std::string codPostal;
public:

    std::string getEmail();
    std::string getParola();
    std::string getNume();
    std::string getPrenume();
    std::string getTelefon();
    std::string getDataNasterii();
    std::string getTara();
    std::string getOras();
    std::string getJudet();
    std::string getStrada();
    std::string getScara();
    std::string getNumar();
    std::string getNumarApartament();
    std::string getCodPostal();

    void setEmail(const std::string &email);
    void setParola(const std::string &parola) ;
    void setNume(const std::string &nume) ;
    void setPrenume(const std::string &prenume) ;
    void setTelefon(const std::string &telefon) ;
    void setDataNasterii(const std::string &dataNasterii) ;
    void setTara(const std::string &tara) ;
    void setOras(const std::string &oras) ;
    void setJudet(const std::string &judet);
    void setStrada(const std::string &strada) ;
    void setScara(const std::string &scara) ;
    void setNumar(const std::string &numar);
    void setNumarApartament(const std::string &numarApartament) ;
    void setCodPostal(const std::string &codPostal);

    UserClient();
};

#endif // USERCLIENT_H
