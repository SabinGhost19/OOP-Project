CREATE TABLE Adresa
(
	IDAdresa int IDENTITY(1,1) NOT NULL PRIMARY KEY,
	CodPostal varchar(10) NOT NULL,
	Tara varchar(20) NOT NULL,
	Judet varchar(20) NOT NULL,
	Oras varchar(20) NOT NULL,
	Strada varchar(50) NOT NULL,
	Numar varchar(15) NOT NULL,
	Scara varchar(10),
	NrApartament int,
)

INSERT INTO Adresa (CodPostal,Tara,Judet,Oras,Strada,Numar) VALUES ('02957','Romania','Bihor','Oradea','BD. REVOLUTIEI','51')

CREATE TABLE ContClient
(
	IDCont int IDENTITY(1,1) NOT NULL PRIMARY KEY,
	Email varchar(50),
	Parola varchar(50),
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

	CONSTRAINT FK_ContClientInregistrat FOREIGN KEY (IDClient) REFERENCES ContClient(IDCont),
	CONSTRAINT FK_AdresaFact FOREIGN KEY (IDAdresaFacturare) REFERENCES Adresa(IDAdresa),
	CONSTRAINT FK_AdresaLiv FOREIGN KEY (IDAdresaFacturare) REFERENCES Adresa(IDAdresa),
)

INSERT INTO Client (IDCont,Nume,Prenume,Telefon,IDAdresaFacturare,DataNasterii) VALUES (1,'ROSCA','GEORGE','0755591286',1,'2003-10-28')