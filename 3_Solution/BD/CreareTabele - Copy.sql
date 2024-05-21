
CREATE TABLE Adresa
(
	IDAdresa int IDENTITY(1,1) NOT NULL PRIMARY KEY,
	CodPostal varchar(10) NOT NULL,
	Tara varchar(30) NOT NULL,
	Judet varchar(20) NOT NULL,
	Oras varchar(30) NOT NULL,
	Strada varchar(60) NOT NULL,
	Numar varchar(15) NOT NULL,
	Scara varchar(10),
	NrApartament int,
)


CREATE TABLE Cont
(
	IDCont int IDENTITY(1,1) NOT NULL PRIMARY KEY,
	Email varchar(50),
	Parola varchar(50),
	Functie varchar(50)
)

CREATE TABLE Client
(
	IDClient int IDENTITY(1,1) NOT NULL PRIMARY KEY,
	IDCont int NOT NULL,
	Nume varchar(50),
	Prenume varchar(50),
	Telefon varchar(11),
	IDAdresaFacturare int,
	IDAdresaLivrare int,
	DataNasterii date,
	Balanta decimal(5),

	CONSTRAINT FK_ContClientInregistrat FOREIGN KEY (IDCont) REFERENCES Cont(IDCont),
	CONSTRAINT FK_AdresaFact FOREIGN KEY (IDAdresaFacturare) REFERENCES Adresa(IDAdresa),
	CONSTRAINT FK_AdresaLiv FOREIGN KEY (IDAdresaFacturare) REFERENCES Adresa(IDAdresa),
)


CREATE TABLE Categorie
(
	IDCategorie int IDENTITY(1,1) NOT NULL PRIMARY KEY,
	NumeCategorie varchar(100),
)


CREATE TABLE Producator
(
	IDProducator int IDENTITY(1,1) NOT NULL PRIMARY KEY,
	IDCont int NOT NULL,
	IDAdresaFiscala int NOT NULL,
	NumeProducator varchar(100),

	CONSTRAINT FK_Cont FOREIGN KEY (IDCont) REFERENCES Cont(IDCont)
	CONSTRAINT FK_AdresaFiscala FOREIGN KEY (AdresaFiscala) REFERENCES Adresa(IDAdresa)
)


CREATE TABLE Produs
(
	IDProdus int IDENTITY(1,1) NOT NULL PRIMARY KEY,
	IDProducator int NOT NULL,
	IDCategorie int NOT NULL,
	NumeProdus varchar(200),
	DescriereProdus varchar(4000),
	Stoc int,
	Pret decimal(4),

	CONSTRAINT FK_Producator FOREIGN KEY (IDProducator) REFERENCES Producator(IDProducator),
	CONSTRAINT FK_Categorie FOREIGN KEY (IDCategorie) REFERENCES Categorie(IDCategorie)
)

CREATE TABLE ImaginiProdus
(
	IDImagine int IDENTITY(1,1) NOT NULL PRIMARY KEY,
	IDProdus int NOT NULL,
	Imagine varbinary(MAX),

	CONSTRAINT FK_Produs FOREIGN KEY (IDProdus) REFERENCES Produs(IDProdus)
)

CREATE TABLE Recenzie
(
	IDRecenzie int IDENTITY(1,1) NOT NULL PRIMARY KEY,
	IDCont int NOT NULL,
	IDProdus int NOT NULL,
	NotaRecenzie int NOT NULL,
	Comentariu varchar(1000),

	CONSTRAINT FK_ContRecenzie FOREIGN KEY (IDCont) REFERENCES Cont(IDCont),
	CONSTRAINT FK_ProdusRecenzionat FOREIGN KEY (IDProdus) REFERENCES Produs(IDProdus)
)

CREATE TABLE CosCumparaturi
(
	IDClient int NOT NULL,
	IDProdus int NOT NULL,
	Cantitate int,

	CONSTRAINT FK_ContCosCumparaturi FOREIGN KEY (IDClient) REFERENCES Client(IDClient),
	CONSTRAINT FK_ProdusCosCumparaturi FOREIGN KEY (IDProdus) REFERENCES Produs(IDProdus)
)