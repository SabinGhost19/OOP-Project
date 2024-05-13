#ifndef USERCOMPANY_H
#define USERCOMPANY_H
#include"user.h"

class UserCompany: public User
{
private:
    std::string id;
    std::string rol;
    std::string email;
    std::string parola;
    std::string nume;
    std::string codPostal;
    std::string tara ;
    std::string judet ;
    std::string oras ;
    std::string strada ;
    std::string numar ;
    std::string scara;
    std::string nrApp;

public:
    UserCompany();

    void setId(const std::string &value);
    void setRol(const std::string &value);
    void setEmail(const std::string &value);
    void setParola(const std::string &value);
    void setNume(const std::string &value);
    void setCodPostal(const std::string &value);
    void setTara(const std::string &value);
    void setJudet(const std::string &value);
    void setOras(const std::string &value);
    void setStrada(const std::string &value);
    void setNumar(const std::string &value);
    void setScara(const std::string &value);
    void setNrApp(const std::string &value);

    // Getteri
    std::string getId() const;
    std::string getRol() const;
    std::string getEmail() const;
    std::string getParola() const;
    std::string getNume() const;
    std::string getCodPostal() const;
    std::string getTara() const;
    std::string getJudet() const;
    std::string getOras() const;
    std::string getStrada() const;
    std::string getNumar() const;
    std::string getScara() const;
    std::string getNrApp() const;
};

#endif // USERCOMPANY_H
