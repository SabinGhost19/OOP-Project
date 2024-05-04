CREATE PROCEDURE AdaugaCont
	@Email varchar(50),
	@Parola varchar(50),
	@Functie varchar(50)
AS
BEGIN
	INSERT INTO Cont(Email,Parola,Functie)
	VALUES(@Email,@Parola,@Functie)
END;
GO

CREATE PROCEDURE AdaugaClient
	@IDCont int,
	@Nume varchar(50),
	@Prenume varchar(50),
	@Telefon varchar(11),
	@DataNasterii date,
	@IDAdresaFacturare int = NULL,
	@IDAdresaLivrare int = NULL
AS
BEGIN
	INSERT INTO Client (IDCont, Nume, Prenume, Telefon, IDAdresaFacturare, IDAdresaLivrare, DataNasterii)
    VALUES (@IDCont, @Nume, @Prenume, @Telefon, @IDAdresaFacturare, @IDAdresaLivrare, @DataNasterii);
END;
GO

CREATE PROCEDURE AdaugaAdresa
    @CodPostal varchar(10),
    @Tara varchar(30),
    @Judet varchar(20),
    @Oras varchar(30),
    @Strada varchar(60),
    @Numar varchar(15),
    @Scara varchar(10) = NULL,
    @NrApartament int =NULL
AS
BEGIN
    INSERT INTO Adresa (CodPostal, Tara, Judet, Oras, Strada, Numar, Scara, NrApartament)
    VALUES (@CodPostal, @Tara, @Judet, @Oras, @Strada, @Numar, @Scara, @NrApartament);
END;
GO

CREATE PROCEDURE AdaugaProducator
    @IDCont int,
    @NumeProducator varchar(100)
AS
BEGIN
    INSERT INTO Producator (IDCont, NumeProducator)
    VALUES (@IDCont, @NumeProducator);
END;
GO

CREATE PROCEDURE AdaugaRecenzie
    @IDCont int,
    @IDProdus int,
    @NotaRecenzie int,
    @Comentariu varchar(1000) = NULL
AS
BEGIN
    INSERT INTO Recenzie (IDCont, IDProdus, NotaRecenzie, Comentariu)
    VALUES (@IDCont, @IDProdus, @NotaRecenzie, @Comentariu);
END;
GO

CREATE PROCEDURE AdaugaProdus
    @IDProducator int,
    @IDCategorie int,
    @NumeProdus varchar(200),
    @DescriereProdus varchar(4000),
    @Stoc int,
    @Pret decimal(4)
AS
BEGIN
    INSERT INTO Produs (IDProducator, IDCategorie, NumeProdus, DescriereProdus, Stoc, Pret)
    VALUES (@IDProducator, @IDCategorie, @NumeProdus, @DescriereProdus, @Stoc, @Pret);
END;
GO

CREATE PROCEDURE AdaugaImagineProdus
    @IDProdus int,
    @Imagine varbinary(MAX)
AS
BEGIN
    INSERT INTO ImaginiProdus (IDProdus, Imagine)
    VALUES (@IDProdus, @Imagine);
END;
GO

CREATE PROCEDURE VerificaContInregistrat
    @Email varchar(50),
    @Parola varchar(50)
AS
BEGIN
    DECLARE @ContExista bit;
    IF EXISTS (SELECT 1 FROM Cont WHERE Email = @Email AND Parola = @Parola)
        SET @ContExista = 1;
    ELSE
        SET @ContExista = 0;
    SELECT @ContExista AS ContInregistrat;
END;
GO