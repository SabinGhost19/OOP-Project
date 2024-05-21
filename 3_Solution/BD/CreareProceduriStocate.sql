
SELECT * FROM Cont

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

EXEC GetCategoryID "Laptopuri"

CREATE PROCEDURE GetProdusePaginate
    @NumarPagina int
AS
BEGIN
    DECLARE @PageSize int = 10; -- Numărul de produse pe pagină
    DECLARE @Offset int = (@NumarPagina - 1) * @PageSize; -- Calculăm offset-ul

    -- Selectăm produsele folosind OFFSET FETCH
    SELECT P.IDProdus, P.NumeProdus, P.DescriereProdus, P.Stoc, P.Pret
    FROM Produs P
    ORDER BY P.IDProdus
    OFFSET @Offset ROWS -- Sărim peste numărul de rânduri corespunzător paginii
    FETCH NEXT @PageSize ROWS ONLY; -- Fetchăm următoarele @PageSize rânduri
END

SELECT * FROM Cont

INSERT INTO Categorie (NumeCategorie) VALUES ('ELECTRONICS');
INSERT INTO Categorie (NumeCategorie) VALUES ('CLOTHING');
INSERT INTO Categorie (NumeCategorie) VALUES ('BOOKS');
INSERT INTO Categorie (NumeCategorie) VALUES ('BEAUTY');
INSERT INTO Categorie (NumeCategorie) VALUES ('FOOD');
INSERT INTO Categorie (NumeCategorie) VALUES ('SPORTS');

EXEC GetProdusePaginate 3

SELECT * FROM Cont

CREATE PROCEDURE VerificaExistentaEmail
    @Email varchar(50),
    @ExistaCont varchar(2) OUTPUT
AS
BEGIN
    SET NOCOUNT ON;

    IF EXISTS (SELECT 1 FROM Cont WHERE Email = @Email)
    BEGIN
        SET @ExistaCont = CAST(1 AS varchar(2));
    END
    ELSE
    BEGIN
        SET @ExistaCont = CAST(0 AS varchar(2));
    END
END;

CREATE PROCEDURE GetContIdByEmailAndPassword
    @Email varchar(50),
    @Parola varchar(50)
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @ContID int;

    -- Obține ID-ul contului bazat pe email și parolă
    SELECT @ContID = IDCont
    FROM Cont
    WHERE Email = @Email AND Parola = @Parola;

    -- Returnează ID-ul contului
    SELECT @ContID AS ContID;
END;

CREATE PROCEDURE AdaugaInfoClient
	@IDCont int,
	@Nume varchar(50),
	@Prenume varchar(50),
	@Telefon varchar(11),
	@DataNasterii varchar(15),
	@IDClient varchar(20) OUTPUT
AS
BEGIN
	INSERT INTO Client (IDCont,Nume, Prenume, Telefon, IDAdresaFacturare, IDAdresaLivrare, DataNasterii,Balanta)
    VALUES (@IDCont,@Nume, @Prenume, @Telefon, NULL, NULL, CAST(@DataNasterii AS date),0);

	SET @IDClient = CAST(SCOPE_IDENTITY() AS varchar(20));
END;

SELECT* FROM Cont

CREATE PROCEDURE GetCategoryID
(
    @NumeCategorie varchar(100)
)
AS
BEGIN
    SET NOCOUNT ON;

    SELECT IDCategorie
    FROM Categorie
    WHERE NumeCategorie = @NumeCategorie;
END;

exec GetCategoryID 'Laptopuri'

select * from Produs

DROP PROCEDURE AdaugaProdus

CREATE PROCEDURE AdaugaProdus
(
    @IDProducator int,
    @IDCategorie int,
    @NumeProdus varchar(200),
    @DescriereProdus varchar(4000),
    @StocVarchar varchar(10), -- Stocul va fi transmis ca varchar
    @PretVarchar varchar(10), -- Pretul va fi transmis ca varchar
    @IDProdus varchar(20) OUTPUT
)
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @Stoc int;
    DECLARE @Pret decimal(4);

    -- Conversie Stoc
    SET @Stoc = CONVERT(int, @StocVarchar);
    
    -- Conversie Pret
    SET @Pret = CONVERT(decimal(4), @PretVarchar); -- Am presupus 2 zecimale pentru pret

    -- Adaugă produsul în tabelul Produs
    INSERT INTO Produs (IDProducator, IDCategorie, NumeProdus, DescriereProdus, Stoc, Pret)
    VALUES (@IDProducator, @IDCategorie, @NumeProdus, @DescriereProdus, @Stoc, @Pret);

    -- Returnează ID-ul produsului nou adăugat
    SET @IDProdus = CAST(SCOPE_IDENTITY() AS varchar(20));
END;

DROP PROCEDURE AdaugaImagineProdus


CREATE PROCEDURE AdaugaImagineProdus
    @IDProdus INT,
    @CaleImagine varchar(150)
AS
BEGIN
    SET NOCOUNT ON;

    -- Verificăm dacă produsul există înainte de a adăuga imaginea
    IF EXISTS (SELECT 1 FROM Produs WHERE IDProdus = @IDProdus)
    BEGIN
        -- Adăugăm imaginea în tabelul ImaginiProdus
        INSERT INTO ImaginiProdus (IDProdus, Imagine)
        VALUES (@IDProdus, @CaleImagine);

        PRINT 'Imagine adăugată cu succes.';
    END
    ELSE
    BEGIN
        PRINT 'Produsul nu există. Nu s-a putut adăuga imaginea.';
    END
END

 SELECT * FROM Producator

DROP PROCEDURE NumaraInregistrariImaginiProdus

CREATE PROCEDURE NumaraInregistrariImaginiProdus
AS
BEGIN
    DECLARE @NumarInregistrari INT;

    -- Selectează numărul de înregistrări din tabela ImaginiProdus
    SELECT @NumarInregistrari = COUNT(*) FROM ImaginiProdus;

    -- Returnează numărul de înregistrări
    SELECT CAST(@NumarInregistrari AS varchar(50)) AS NumarInregistrariImaginiProdus;
END;

EXEC NumaraInregistrariImaginiProdus

CREATE PROCEDURE AdaugaInfoProducator
    @IDCont int,
    @NumeCompanie varchar(100),
	@IDAdresaFiscala int,
    @IDProducatorOutput varchar(20) OUTPUT -- Parametru pentru returnarea ID-ului produsătorului
AS
BEGIN
    SET NOCOUNT ON;

    -- Inserează în tabelul Producator
    INSERT INTO Producator (IDCont, NumeProducator, IDAdresaFiscala)
    VALUES (@IDCont, @NumeCompanie, @IDAdresaFiscala);

    -- Obține ID-ul produsătorului inserat
    SET @IDProducatorOutput = CAST(SCOPE_IDENTITY() AS varchar(20));
END;

declare @output varchar(20)
EXEC AdaugaInfoProducator 78,'COMPANIETEST',39,@output output
print 'outputul este' + @output

SELECT * FROM Producator



select * from cont,adresa

declare @output int
EXEC AdaugaInfoProducator 34,'PCGARAGE',30,@output

select * from Cont
select * from Adresa
select * from Producator

DROP PROCEDURE GetClientIDFromContID

CREATE PROCEDURE GetClientIDFromContID
	@IDCont int
AS
BEGIN
	SET NOCOUNT ON;

	SELECT IDClient AS IDClient
	FROM Client
	WHERE IDCont = @IDCont;
END;

EXEC GetClientIDFromContID 34

EXEC AdaugaInfoClient(

select * from Client

select * from Cont

exec AdaugaInfoClient 1,'ROSCA','GEORGE','0755591286','2010-10-10'

SELECT * FROM CLIENT



SELECT * FROM Client
SELECT * FROM Adresa

DROP PROCEDURE AdaugaAdresa

CREATE PROCEDURE AdaugaAdresa
    @CodPostal VARCHAR(10),
    @Tara VARCHAR(30),
    @Judet VARCHAR(20),
    @Oras VARCHAR(30),
    @Strada VARCHAR(60),
    @Numar VARCHAR(15),
    @Scara VARCHAR(10) = NULL,
    @NrApartament INT = NULL,
	@IDAdresa INT OUTPUT
AS
BEGIN
    INSERT INTO Adresa (CodPostal, Tara, Judet, Oras, Strada, Numar, Scara, NrApartament)
    VALUES (@CodPostal, @Tara, @Judet, @Oras, @Strada, @Numar, @Scara, @NrApartament);

    SET @IDAdresa = CAST(SCOPE_IDENTITY() AS varchar(20));
END;

SELECT * FROM Client

EXEC SetAdreseClient 14, 11 , 10

DROP PROCEDURE 

CREATE PROCEDURE SetAdreseClient
    @IDClient int,
    @IDAdresaFacturare int,
    @IDAdresaLivrare int
AS
BEGIN
    UPDATE Client
    SET IDAdresaFacturare = @IDAdresaFacturare,
        IDAdresaLivrare = @IDAdresaLivrare
    WHERE IDClient = @IDClient;
END;


SELECT * FROM Adresa
SELECT * FROM Client


CREATE PROCEDURE AdaugaProducator
    @IDCont int,
    @NumeProducator varchar(100)
AS
BEGIN
    INSERT INTO Producator (IDCont, NumeProducator)
    VALUES (@IDCont, @NumeProducator);
END;
GO

SELECT * FROM Recenzie


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

DROP PROCEDURE SeteazaAdreseClient

CREATE PROCEDURE SeteazaAdreseClient
    @IDClient int,
    @IDAdresaLivrare int,
    @IDAdresaFacturare int
AS
BEGIN

    -- Actualizează adresa de livrare pentru client
    UPDATE Client
    SET IDAdresaLivrare = @IDAdresaLivrare
    WHERE IDClient = @IDClient;

    -- Actualizează adresa de facturare pentru client
    UPDATE Client
    SET IDAdresaFacturare = @IDAdresaFacturare
    WHERE IDClient = @IDClient;
END;

SELECT * FROM Client
SELECT * FROM Adresa

CREATE PROCEDURE VerificaContInregistrat
    @Email varchar(50),
    @Parola varchar(50)
AS
BEGIN
	SELECT Functie
	FROM Cont
	WHERE Email = @Email AND Parola = @Parola
END;
GO

EXEC VerificaContInregistrat 'mihaigeorge985@yahoo.com' , parola

CREATE PROCEDURE GetClientByEmailAndPassword
    @Email varchar(50),
    @Parola varchar(50)
AS
BEGIN
    SET NOCOUNT ON;

    SELECT 
        Cl.IDClient,
        Cl.Nume,
        Cl.Prenume,
        Cl.Telefon,
        Cl.DataNasterii,
        Cl.Balanta,
        AdresaFacturare.CodPostal AS CodPostalFacturare,
        AdresaFacturare.Tara AS TaraFacturare,
        AdresaFacturare.Judet AS JudetFacturare,
        AdresaFacturare.Oras AS OrasFacturare,
        AdresaFacturare.Strada AS StradaFacturare,
        AdresaFacturare.Numar AS NumarFacturare,
        AdresaFacturare.Scara AS ScaraFacturare,
        AdresaFacturare.NrApartament AS NrApartamentFacturare,
        AdresaLivrare.CodPostal AS CodPostalLivrare,
        AdresaLivrare.Tara AS TaraLivrare,
        AdresaLivrare.Judet AS JudetLivrare,
        AdresaLivrare.Oras AS OrasLivrare,
        AdresaLivrare.Strada AS StradaLivrare,
        AdresaLivrare.Numar AS NumarLivrare,
        AdresaLivrare.Scara AS ScaraLivrare,
        AdresaLivrare.NrApartament AS NrApartamentLivrare
    FROM 
        Client Cl
    INNER JOIN 
        Cont C ON Cl.IDCont = C.IDCont
    LEFT JOIN 
        Adresa AdresaFacturare ON Cl.IDAdresaFacturare = AdresaFacturare.IDAdresa
    LEFT JOIN 
        Adresa AdresaLivrare ON Cl.IDAdresaLivrare = AdresaLivrare.IDAdresa
    WHERE 
        C.Email = @Email
        AND C.Parola = @Parola;
END;
GO

select * from Producator

CREATE PROCEDURE GetProducerInfoByEmailAndPassword
    @Email varchar(50),
    @Parola varchar(50)
AS
BEGIN
    SET NOCOUNT ON;

    SELECT P.IDProducator, P.NumeProducator, A.CodPostal, A.Tara, A.Judet, A.Oras, A.Strada, A.Numar, A.Scara, A.NrApartament, P.Profit
    FROM Producator P
    INNER JOIN Cont C ON P.IDCont = C.IDCont
    INNER JOIN Adresa A ON P.IDAdresaFiscala = A.IDAdresa
    WHERE C.Email = @Email AND C.Parola = @Parola;
END

EXEC GetProducerInfoByEmailAndPassword 'EmagSRL@gmail.com' , 'passwdEMAG'
Select * from ImaginiProdus
CREATE PROCEDURE GetProducerProductsByProducerEmailAndPassword
    @Email varchar(50),
    @Parola varchar(50)
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @IDProducator int;

    SELECT @IDProducator = P.IDProducator
    FROM Producator P
    INNER JOIN Cont C ON P.IDCont = C.IDCont
    WHERE C.Email = @Email AND C.Parola = @Parola;

    SELECT Pr.IDProdus, Pr.NumeProdus, Pr.DescriereProdus, Pr.Stoc, Pr.Pret
    FROM Produs Pr
    WHERE Pr.IDProducator = @IDProducator;
END 


CREATE PROCEDURE SelectAllProducts
AS
BEGIN
    SELECT 
        P.IDProdus,
        PR.NumeProducator,
        C.NumeCategorie,
        P.NumeProdus,
        P.DescriereProdus,
        P.Stoc,
        P.Pret
    FROM 
        Produs AS P
    INNER JOIN 
        Producator AS PR ON P.IDProducator = PR.IDProducator
    INNER JOIN 
        Categorie AS C ON P.IDCategorie = C.IDCategorie;
END;

CREATE PROCEDURE SelectImaginiProdus
    @IDProdus int
AS
BEGIN
    SELECT Imagine
    FROM ImaginiProdus
    WHERE IDProdus = @IDProdus;
END;

SELECT* FROM Produs

EXEC SelectImaginiProdus 1

EXEC SelectAllProducts 

DROP PROCEDURE AdaugaRecenzie

EXEC AdaugaRecenzie 1,1,1,'NU ISI FACE TREABA, SUNT PROFUND DEZAMAGIT'

SELECT * FROM Recenzie

CREATE PROCEDURE AdaugaRecenzie
    @IDClient int,
    @IDProdus int,
    @NotaRecenzie int,
    @Comentariu varchar(1000)
AS
BEGIN
    SET NOCOUNT ON;

    -- Verificăm dacă clientul există
    IF NOT EXISTS (SELECT 1 FROM Client WHERE IDClient = @IDClient)
    BEGIN
        RETURN;
    END;

    -- Verificăm dacă produsul există
    IF NOT EXISTS (SELECT 1 FROM Produs WHERE IDProdus = @IDProdus)
    BEGIN
        RETURN;
    END;

    -- Verificăm dacă recenzia pentru același produs de la același client există deja
    -- IF EXISTS (SELECT 1 FROM Recenzie WHERE IDClient = @IDClient AND IDProdus = @IDProdus)
    -- BEGIN
    --    RETURN;
    -- END;

    -- Adăugăm recenzia în baza de date
    INSERT INTO Recenzie (IDClient, IDProdus, NotaRecenzie, Comentariu)
    VALUES (@IDClient, @IDProdus, @NotaRecenzie, @Comentariu);
END;


CREATE PROCEDURE GetClientNameByID
    @IDClient int
AS
BEGIN
    SELECT Nume + ' ' + Prenume AS NumePrenume
    FROM Client
    WHERE IDClient = @IDClient;
END;

SELECT * FROM Client
EXEC GetClientNameByID 1

DROP PROCEDURE SelectRecenziiByIDProdus

CREATE PROCEDURE SelectRecenziiByIDProdus
    @IDProdus int
AS
BEGIN
    SELECT 
        Rec.IDClient,
        Rec.NotaRecenzie,
        Rec.Comentariu
    FROM 
        Recenzie Rec
    INNER JOIN 
        Client Cl ON Rec.IDClient = Cl.IDClient
    WHERE 
        Rec.IDProdus = @IDProdus;
END;

SELECT * FROM Produs

EXEC AdaugaRecenzie 1,1,5,'Sunt foarte multumit de acest produs, chiar isi face treaba'

SELECT * FROM Cont

EXEC SelectRecenziiByIDProdus 1

DROP PROCEDURE CumparaProdus

CREATE PROCEDURE CumparaProdus
    @IDProdus int,
    @Cantitate int
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @CantitateActuala int;

    -- Obține cantitatea actuală a produsului
    SELECT @CantitateActuala = Stoc
    FROM Produs
    WHERE IDProdus = @IDProdus;

    -- Verifică dacă produsul există și dacă cantitatea poate fi scazută din stoc
    IF EXISTS (SELECT 1 FROM Produs WHERE IDProdus = @IDProdus)
    BEGIN
        IF @CantitateActuala >= @Cantitate
        BEGIN
            -- Scade cantitatea din stoc
            UPDATE Produs
            SET Stoc = Stoc - @Cantitate
            WHERE IDProdus = @IDProdus;

			DECLARE @IDProducator int
			DECLARE @PretProdus decimal(10,2)
			
			SELECT @IDProducator = IDProducator , @PretProdus = Pret
			FROM Produs
			WHERE IDProdus = @IDProdus;

			UPDATE Producator
			SET Profit =  Profit + @PretProdus * @Cantitate
			WHERE IDProducator = @IDProducator
        END
    END
END;
GO

SELECT * FROM Producator

EXEC CumparaProdus 1,1

SELECT * FROM CardClient

DELETE FROM CardClient

DROP PROCEDURE AdaugaCardClient

CREATE PROCEDURE AdaugaCardClient
    @IDClient int,
    @NumarCard varchar(50),
    @NumeDetinator varchar(50),
    @DataExpirare varchar(10), -- Varchar pentru data
    @CVC int
AS
BEGIN
    SET NOCOUNT ON;

    -- Adaugam cardul in tabelul CardClient
    INSERT INTO CardClient (IDClient, NumarCard, NumeDetinator, DataExpirare, CVC)
    VALUES (@IDClient, @NumarCard, @NumeDetinator, CAST(@DataExpirare AS date), @CVC);
END;


CREATE PROCEDURE InformatiiCardClient
    @IDClient int
AS
BEGIN
    SET NOCOUNT ON;

    SELECT NumarCard, NumeDetinator, DataExpirare, CVC
    FROM CardClient
    WHERE IDClient = @IDClient;
END;

EXEC InformatiiCardClient 1


CREATE PROCEDURE SchimbaParolaClient
    @IDClient int,
    @NouaParola varchar(50)
AS
BEGIN
    UPDATE Cont
    SET Parola = @NouaParola
    WHERE IDCont = (SELECT IDCont FROM Client WHERE IDClient = @IDClient)
END

SELECT * FROM Client

EXEC SchimbaParolaClient 1,'parola'

CREATE PROCEDURE AdaugaBaniLaBalanta
    @IDClient int,
    @SumaBani decimal(10, 2)
AS
BEGIN
    SET NOCOUNT ON;

    -- Actualizare balanță
    UPDATE Client
    SET Balanta = Balanta + @SumaBani
    WHERE IDClient = @IDClient;


END;


CREATE PROCEDURE SelectListedProducts
	@IDProducator int
AS
BEGIN
    SELECT 
        P.IDProdus,
        PR.NumeProducator,
        C.NumeCategorie,
        P.NumeProdus,
        P.DescriereProdus,
        P.Stoc,
        P.Pret
    FROM 
        Produs AS P
    INNER JOIN 
        Producator AS PR ON P.IDProducator = PR.IDProducator
    INNER JOIN 
        Categorie AS C ON P.IDCategorie = C.IDCategorie
	WHERE
		P.IDPRoducator = @IDProducator;
END;



CREATE PROCEDURE UpdatePretProdus
    @IDProdus int,
    @PretNou decimal(10,2)
AS
BEGIN
    -- Actualizează prețul produsului specificat
    UPDATE Produs
    SET Pret = @PretNou
    WHERE IDProdus = @IDProdus;
END;
GO

CREATE PROCEDURE UpdateCantitateProdus
    @IDProdus int,
    @StocNou int
AS
BEGIN
    -- Actualizează prețul produsului specificat
    UPDATE Produs
    SET Stoc = @StocNou
    WHERE IDProdus = @IDProdus;
END;
GO

CREATE PROCEDURE SelectAllCategories
AS
BEGIN
	SELECT * 
	FROM Forum
END;
GO

EXEC SelectAllCategories


CREATE PROCEDURE DeterminaDiscutii
	@IDCategorie int
AS
BEGIN
	SELECT NumeUtilizator , Discutie
	FROM Discutii
	WHERE IDCategorieForum=@IDCategorie
END;
GO

EXEC DeterminaDiscutii 1


CREATE PROCEDURE AdaugaPostare
	@IDCategorie int,
	@Nume varchar(100),
	@Post varchar(3000)
AS
BEGIN
	INSERT INTO Discutii(IDCategorieForum,NumeUtilizator,Discutie)
	VALUES (@IDCategorie,@Nume,@Post)
END;

DELETE FROM Produs
WHERE IDProdus=22
SELECT * FROM ImaginiProdus
