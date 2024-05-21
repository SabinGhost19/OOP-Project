#ifndef USERCLIENT_H
#define USERCLIENT_H


#include "user.h"

typedef struct Card{
    std::string Number;
    std::string Nume_Detinator;
    std::string Data;
    std::string cvc;
}Card;


class UserClient : public User
{
private:

    Card*card=nullptr;
    std::string id;
    std::string rol;

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
    std::string numarApartament ;
    std::string codPostal ;

    std::string tara_F;
    std::string oras_F;
    std::string judet_F;
    std::string strada_F;
    std::string scara_F;
    std::string numar_F;
    std::string numarApartament_F;
    std::string codPostal_F;

    float current_command=0.0 ;
    int product_count = 0 ;

    std::string nota;
    std::string comment;

    std::vector<std::pair<std::string,std::string>>lista_produse;

    std::vector<std::pair<std::string,std::string>>cart;
public:
    std::vector<std::pair<std::string,std::string>>getCart();
    void setToCart(std::string,std::string);
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
    std::string getTara_F(); // Funcții cu nume modificat
    std::string getOras_F();
    std::string getJudet_F();
    std::string getStrada_F();
    std::string getScara_F();
    std::string getNumar_F();
    std::string getNumarApartament_F();
    std::string getCodPostal_F();
    std::string GetRole();
    float getCommandPrice();
    Card*GetCard();
    std::vector<std::pair<std::string,std::string>> GetListaProduse();

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
    void setCard(Card*card);


    void setTara_F(const std::string &tara) ;
    void setOras_F(const std::string &oras) ;
    void setJudet_F(const std::string &judet);
    void setStrada_F(const std::string &strada) ;
    void setScara_F(const std::string &scara) ;
    void setNumar_F(const std::string &numar);
    void setNumarApartament_F(const std::string &numarApartament) ;
    void setCodPostal_F(const std::string &codPostal);


    void AddToCart(float price);
    void addProductToCart(std::string,std::string);
    int GetProductCount();

    void SetComment(std::string str);
    void SetNota(std::string str);
    std::string GetComment();
    std::string GetNota();

    UserClient();
};

#endif // USERCLIENT_H
